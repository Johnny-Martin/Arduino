#ifndef _KEYBOARDPROXY_H_
#define _KEYBOARDPROXY_H_

#include <stdint.h>
#include <HID.h>
#include "..\Matrix\Matrix.h"
#include "..\Encoder\Encoder.h"
#include "..\VirtualParallelPort\VirtualParallelPort.h"

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
		void Excute(void);
		
	private:
		static const uint8_t m_uParallelPortSize = 8;
		static const uint8_t m_uMaxKeyPressed = 14;
		uint8_t m_aPressedKeys[m_uMaxKeyPressed + 1];
		VirtualParallelPort<m_uParallelPortSize>* m_pRowPort;
		VirtualParallelPort<m_uParallelPortSize>* m_pColumnPort;
		KeyReport m_keyReport;
		Encoder<11,10> m_encoder;
		
		void GetPressedKeys(uint8_t keys[]);
		void GetReport(int8_t encoderRet, uint8_t keys[], KeyReport& report);
	};
}



//////////////////////////////////////////////////////////////////////////////////////////////
namespace EKEY{
	KeyboardProxy::KeyboardProxy():m_keyReport(){
		m_pRowPort    = new VirtualParallelPort<m_uParallelPortSize>(Row);
		m_pColumnPort = new VirtualParallelPort<m_uParallelPortSize>(Col);
		
		m_encoder = Encoder<11,10>();
	}
	
	void KeyboardProxy::Excute(void){
		// Serial.println(666);
		
		int8_t encoderResult = m_encoder.Excute();
		GetPressedKeys(m_aPressedKeys);
		GetReport(encoderResult, m_aPressedKeys, m_keyReport);
		
		HID().SendReport(2, &m_keyReport,sizeof(KeyReport));
	}
	
	void KeyboardProxy::GetPressedKeys(uint8_t keys[]){
		
	}
	
	void KeyboardProxy::GetReport(int8_t encoderRet, uint8_t keys[], KeyReport& report){
		
	}
}
#endif