#ifndef _KEYBOARDPROXY_H_
#define _KEYBOARDPROXY_H_

#include <stdint.h>
#include <HID.h>
#include "PinDefinition.h"
#include "..\Matrix\Matrix.h"
#include "..\Matrix\Adapter.h"
#include "..\Encoder\Encoder.h"
#include "..\VirtualParallelPort\VirtualParallelPort.h"

bool R_COLUMN_STATE[8] = {0};
uint8_t CurPressedKeys[8] = {0};

namespace EKEY{
	struct  KeyReport
	{
	  uint8_t modifiers;
	  uint8_t reserved;
	  uint8_t keys[6];
	};
	
	/*1,扫描键盘矩阵，并根据检测到的按键，结合Matrix.h中提供的键位定义，输出按键信息
	 *2,扫描滚轮，并根据按键状态输出滚轮方向。滚轮默认为输出左右箭头；按住Fun输出上下箭头
	 *因为Arduino的IO资源紧缺，无法使用两个滚轮。蓝牙版键盘IO充足的话会再加一个滚轮，
	 *用作鼠标滚轮。
	 */
	class KeyboardProxy{
	public:
		KeyboardProxy();
		void Init(void);
		void SetRightRowState(const uint8_t* row_vec, uint8_t iRow);
		void GetRightColumnState(uint8_t iRow, bool bLeftPart);
		void Excute(void);
		
	private:
		static const uint8_t m_uMaxKeyPressed = 10;
		KeyReport m_keyReport;
		//Encoder<11,10> m_encoder;
		
		int m_lastKeyValue;
		int m_pressedKeysCount;
		void ClearReport();
		//检测按键是否被按下，若有，直接加入m_keyReport报文的keys数组
		void GetPressedKeys();
		//发送报文前，处理m_keyReport的modifiers字段
		void Report();
	};
}

//////////////////////////////////////////////////////////////////////////////////////////////
namespace EKEY{
	KeyboardProxy::KeyboardProxy():m_keyReport(),m_lastKeyValue(0),m_pressedKeysCount(0){
		//m_encoder = Encoder<11,10>();
		Init();
	}
	
	void KeyboardProxy::ClearReport(void)
	{
		m_keyReport.modifiers = 0;
		m_keyReport.reserved  = 0;
		for(uint8_t i=0; i<6; ++i){
			m_keyReport.keys[i] = 0;
		}
		m_pressedKeysCount = 0;
	}
	
	void KeyboardProxy::Init(void)
	{
		for(uint8_t i=0; i<4; ++i){
			pinMode(R_ROW_VEC[i], OUTPUT);
			pinMode(L_ROW_VEC[i], OUTPUT);
		}
	}
	
	void KeyboardProxy::SetRightRowState(const uint8_t* row_vec, uint8_t iRow)
	{
		for(uint8_t i=0; i<4; ++i){
			if(i != iRow)
				digitalWrite(row_vec[i], LOW);
			else
				digitalWrite(row_vec[i], HIGH);
		}
	}
	void KeyboardProxy::GetRightColumnState(uint8_t iRow, bool bLeftPart)
	{
		for(uint8_t i=0; i<8; ++i){
			pinMode(COLUMN_VEC[i], OUTPUT);
			digitalWrite(COLUMN_VEC[i], LOW);
			
			pinMode(COLUMN_VEC[i], INPUT);
			int value = digitalRead(COLUMN_VEC[i]);
			if(value != HIGH) continue;
			
			int fakePos = iRow * 10 + i;
			uint8_t curPressedKey = 0;
			if(bLeftPart){
				uint8_t pos 		= L_MatrixAdapter[fakePos];
				uint8_t rowPos 		= pos/10 - 1;
				uint8_t columnPos 	= pos%10 - 1;
				curPressedKey		= L_Martix[rowPos][columnPos];
			}else{
				uint8_t pos 		= R_MatrixAdapter[fakePos];
				uint8_t rowPos 		= pos/10 - 1;
				uint8_t columnPos 	= pos%10 - 1;
				curPressedKey		= R_Martix[rowPos][columnPos];
			}
			if(curPressedKey != 0 && m_pressedKeysCount+1 < 6){
				m_keyReport.keys[m_pressedKeysCount++] = curPressedKey;
			}
		}
	}
	void KeyboardProxy::Excute(void){
		//int8_t encoderResult = m_encoder.Excute();
		ClearReport();
		GetPressedKeys();
		Report();
	}
	
	void KeyboardProxy::GetPressedKeys(){
		for(uint8_t i=0; i<4; ++i){
			SetRightRowState(R_ROW_VEC, i);
			GetRightColumnState(i, false);
		}
		SetRightRowState(R_ROW_VEC, 10);
		
		for(uint8_t i=0; i<4; ++i){
			SetRightRowState(L_ROW_VEC, i);
			GetRightColumnState(i, true);
		}
		SetRightRowState(L_ROW_VEC, 10);
	}
	
	void KeyboardProxy::Report()
	{
		for(uint8_t i=0; i<6; ++i){
			uint8_t& k = m_keyReport.keys[i];
			if (k >= 136) {			// it's a non-printing key (not a modifier)
				k = k - 136;
			} else if (k >= 128) {	// it's a modifier key
				m_keyReport.modifiers |= (1<<(k-128));
				k = 0;
			} else {				// it's a printing key
				k = pgm_read_byte(_asciimap + k);
				if (!k) {
					//setWriteError();
					return;
				}
				if (k & 0x80) {						// it's a capital letter or other character reached with shift
					m_keyReport.modifiers |= 0x02;	// the left shift modifier
					k &= 0x7F;
				}
			}
		}
		
		HID().SendReport(2, &m_keyReport, sizeof(KeyReport));
	}
}
#endif