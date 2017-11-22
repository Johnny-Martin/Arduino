#ifndef _KEYBOARDIMPL_H_
#define _KEYBOARDIMPL_H_

#include <stdint.h>
#include <HID.h>
#include "..\Matrix\Matrix.h"
#include "..\Matrix\Adapter.h"
#include "HIDKeyReport.h"


namespace EKEY{
	class KeyboardImpl{
	public:
		void Init(void);
		void Excute(void);
	private:
		void SetRowState(const uint8_t* row_vec, uint8_t iRow);
		bool IsFunKeyPressed();
		void GetColumnState(uint8_t iRow, bool bLeftPart, bool bFunPressed);
		void GetPressedKeys();
		HIDKeyReport m_report;
		HIDKeyReport m_lastReport;
		Encoder<A4, A5> m_encoder;
		
	};
}

//////////////////////////////////////////////////////////////////////////////////////////////
namespace EKEY{
	void KeyboardImpl::Init(void){
		for(uint8_t i=0; i<4; ++i){
			pinMode(R_ROW_VEC[i], OUTPUT);
			pinMode(L_ROW_VEC[i], OUTPUT);
		}
		m_report.Clear();
		m_lastReport.Clear();
	}
	
	void KeyboardImpl::SetRowState(const uint8_t* row_vec, uint8_t iRow){
		for(uint8_t i=0; i<4; ++i){
			if(i != iRow)
				digitalWrite(row_vec[i], LOW);
			else
				digitalWrite(row_vec[i], HIGH);
		}
	}
	
	bool KeyboardImpl::IsFunKeyPressed()
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
	
	void KeyboardImpl::GetColumnState(uint8_t iRow, bool bLeftPart, bool bFunPressed){
		for(uint8_t i=0; i<8; ++i){
			pinMode(COLUMN_VEC[i], OUTPUT);
			digitalWrite(COLUMN_VEC[i], LOW);
			
			pinMode(COLUMN_VEC[i], INPUT);
			int value = digitalRead(COLUMN_VEC[i]);
			if(value != HIGH) continue;
			
			int fakePos = iRow * 10 + i;
			uint8_t curPressedKey 	= 0;
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
			m_report.PushKey(curPressedKey);
		}
	}
	
	void KeyboardImpl::GetPressedKeys(){
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
		
		int8_t dir = m_encoder.Excute();
		if(dir == m_encoder.CW){
			m_report.PushKey(bFunPressed ? KEY_UARROW : KEY_LARROW);
			Serial.println(-1);
		}else if(dir == m_encoder.CCW){
			m_report.PushKey(bFunPressed ? KEY_DARROW : KEY_RARROW);
			Serial.println(1);
		}
	}
	
	void KeyboardImpl::Excute(void){
		m_report.Clear();
		GetPressedKeys();
		if(m_report != m_lastReport){
			m_report.Report();
			m_lastReport = m_report;
		}
		
	}
}
#endif