#ifndef _KEYBOARDPROXY_H_
#define _KEYBOARDPROXY_H_

#include <stdint.h>
#include <HID.h>
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
	
	KeyReport GetKeyReportCopy(const KeyReport& obj);
	bool	  IsSameReport(const KeyReport& src, const KeyReport& dst);
	/*1,扫描键盘矩阵，并根据检测到的按键，结合Matrix.h中提供的键位定义，输出按键信息
	 *2,扫描滚轮，并根据按键状态输出滚轮方向。滚轮默认为输出左右箭头；按住Fun输出上下箭头
	 *因为Arduino的IO资源紧缺，无法使用两个滚轮。蓝牙版键盘IO充足的话会再加一个滚轮，
	 *用作鼠标滚轮。
	 */
	class KeyboardProxy{
	public:
		KeyboardProxy();
		void Init(void);
		void SetRowState(const uint8_t* row_vec, uint8_t iRow);
		void GetColumnState(uint8_t iRow, bool bLeftPart, bool bFunPressed);
		void Excute(void);
		
	private:
		Encoder<A5, A4> m_encoder;
		static const uint8_t m_uMaxKeyPressed = 10;
		KeyReport m_keyReport;
		KeyReport m_keyLastReport;
		//Encoder<11,10> m_encoder;
		
		int m_lastKeyValue;
		int m_pressedKeysCount;
		void ClearReport();
		//检测按键是否被按下，若有，直接加入m_keyReport报文的keys数组
		void GetPressedKeys();
		//发送报文前，处理m_keyReport的modifiers字段
		void Report();
		
		bool IsFunKeyPressed();
	};
}

//////////////////////////////////////////////////////////////////////////////////////////////
namespace EKEY{
	void GetKeyReportCopy(const KeyReport& src, KeyReport& dst)
	{
		dst.modifiers = src.modifiers;
		for(uint8_t i=0; i<6; ++i){
			dst.keys[i] = src.keys[i];
		}
	}
	
	bool IsSameReport(const KeyReport& src, const KeyReport& dst)
	{
		for(uint8_t i=0; i<6; ++i){
			if(dst.keys[i] != src.keys[i]) return false;
		}
		
		return dst.modifiers == src.modifiers;
	}
	
	KeyboardProxy::KeyboardProxy()
		:m_keyReport()
		,m_keyLastReport()
		, m_lastKeyValue(0)
		,m_encoder()
		,m_pressedKeysCount(0){
		//m_encoder = Encoder<11,10>();
		Init();
	}
	
	void KeyboardProxy::ClearReport(void){
		m_keyReport.modifiers = 0;
		m_keyReport.reserved  = 0;
		for(uint8_t i=0; i<6; ++i){
			m_keyReport.keys[i] = 0;
		}
		m_pressedKeysCount = 0;
	}
	
	void KeyboardProxy::Init(void){
		for(uint8_t i=0; i<4; ++i){
			pinMode(R_ROW_VEC[i], OUTPUT);
			pinMode(L_ROW_VEC[i], OUTPUT);
		}
	}
	
	void KeyboardProxy::SetRowState(const uint8_t* row_vec, uint8_t iRow){
		for(uint8_t i=0; i<4; ++i){
			if(i != iRow)
				digitalWrite(row_vec[i], LOW);
			else
				digitalWrite(row_vec[i], HIGH);
		}
	}
	
	bool KeyboardProxy::IsFunKeyPressed()
	{
		SetRowState(L_ROW_VEC, 10);
			digitalWrite(FUN_KEY_ROW_PIN, HIGH);
			pinMode(FUN_KEY_COL_PIN, OUTPUT);
			digitalWrite(FUN_KEY_COL_PIN, LOW);
			pinMode(FUN_KEY_COL_PIN, INPUT);
			int value = digitalRead(FUN_KEY_COL_PIN);
		SetRowState(L_ROW_VEC, 10);
		return value == HIGH;
	}
	
	void KeyboardProxy::GetColumnState(uint8_t iRow, bool bLeftPart, bool bFunPressed){
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
				if(bFunPressed){
					curPressedKey	= L_Martix_Fun[rowPos][columnPos];
				}
			}else{
				uint8_t pos 		= R_MatrixAdapter[fakePos];
				uint8_t rowPos 		= pos/10 - 1;
				uint8_t columnPos 	= pos%10 - 1;
				curPressedKey		= R_Martix[rowPos][columnPos];
				if(bFunPressed){
					curPressedKey	= R_Martix_Fun[rowPos][columnPos];
				}
			}
			if(curPressedKey != 0 && curPressedKey != KEY_FUN && m_pressedKeysCount+1 < 6){
				bool bFlag = true;
				for(uint8_t i=0; i<m_pressedKeysCount; ++i){
					if(m_keyReport.keys[i] == curPressedKey){ bFlag = false;}
				}
				if(bFlag){
					m_keyReport.keys[m_pressedKeysCount++] = curPressedKey;
				}
			}
		}
	}
	
	void KeyboardProxy::Excute(void){
		ClearReport();
		GetPressedKeys();
		Report();
	}
	
	void KeyboardProxy::GetPressedKeys(){
		bool bFunPressed = IsFunKeyPressed();
		
		for(uint8_t i=0; i<4; ++i){
			SetRowState(R_ROW_VEC, i);
			GetColumnState(i, false, bFunPressed);
		}
		SetRowState(R_ROW_VEC, 10);
		
		for(uint8_t i=0; i<4; ++i){
			SetRowState(L_ROW_VEC, i);
			GetColumnState(i, true, bFunPressed);
		}
		SetRowState(L_ROW_VEC, 10);
		
		//检测编码器是否有旋转
		int8_t encoderResult = m_encoder.Excute();
		if(encoderResult > 0 && m_pressedKeysCount+1 < 6){
			// m_keyReport.keys[m_pressedKeysCount++] = bFunPressed ? KEY_LARROW : KEY_UARROW;
			Serial.println("CW");
		}else if(encoderResult < 0&& m_pressedKeysCount+1 < 6){
			// m_keyReport.keys[m_pressedKeysCount++] = bFunPressed ? KEY_RARROW : KEY_DARROW;
			Serial.println("CCW");
		}
	}
	
	void KeyboardProxy::Report(){	
		for(uint8_t i=0; i<6; ++i){
			uint8_t& k = m_keyReport.keys[i];
			if (k > KEY_RIGHT_GUI) {			// it's a non-printing key (not a modifier)
				k = k - 136;
			} else if (k >= KEY_LEFT_CTRL) {	// it's a modifier key
				m_keyReport.modifiers |= (1<<(k-128));
				k = 0;
			} else {				// it's a printing key
				k = ASC2HID[k];
			}
		}
		
		if(IsSameReport(m_keyReport, m_keyLastReport)){
			return;
		}
		
		HID().SendReport(2, &m_keyReport, sizeof(KeyReport));
		GetKeyReportCopy(m_keyReport, m_keyLastReport);
		
		// Serial.print("send report, modifiers: ");
		// Serial.print(m_keyReport.modifiers);
		// Serial.print(", keys: ");
		// for(uint8_t i=0; i<6; ++i){
			// Serial.print(m_keyReport.keys[i]);
		// }
		// Serial.println("");
	}
}
#endif