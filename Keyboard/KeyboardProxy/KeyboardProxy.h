#ifndef _KEYBOARDPROXY_H_
#define _KEYBOARDPROXY_H_

#include <stdint.h>
#include <Keyboard.h>
#include "..\Matrix\Matrix.h"
#include "..\VirtualParallelPort\VirtualParallelPort.h"

/*
 *
 */
namespace EKEY{
	/*1,扫描键盘矩阵，并根据检测到的按键，结合Matrix.h中提供的键位定义，输出按键信息
	 *2,扫描滚轮，并根据按键状态输出滚轮方向。滚轮默认为输出左右箭头；按住Fun输出上下箭头
	 *因为Arduino的IO资源紧缺，无法使用两个滚轮。蓝牙版键盘IO充足的话会再加一个滚轮，
	 *用作鼠标滚轮。
	 */
	class KeyboardProxy{
	public:
		KeyboardProxy();
		void Init();
		void Excute(void);
		
	private:
		VirtualParallelPort<8>* rowPort;
		VirtualParallelPort<8>* columnPort;
		bool IsFunDbClicked();
		bool IsFunDown();
		
	};
}



//////////////////////////////////////////////////////////////////////////////////////////////
namespace EKEY{
	KeyboardProxy::KeyboardProxy(){
		rowPort    = new VirtualParallelPort<8>(Row, 8);
		columnPort = new VirtualParallelPort<8>(Col, 8);
	}
	
	void KeyboardProxy::Init(){
		Keyboard.begin();
	}
	
	void KeyboardProxy::Excute(void){
		Serial.println(666);
	}

	bool KeyboardProxy::IsFunDbClicked(){
		return false;
	}

	bool KeyboardProxy::IsFunDown(){
		return false;
	}
}
#endif