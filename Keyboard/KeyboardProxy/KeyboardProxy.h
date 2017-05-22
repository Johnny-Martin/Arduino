#ifndef _KEYBOARDPROXY_H_
#define _KEYBOARDPROXY_H_

#include <stdint.h>
#include "..\Matrix\Matrix.h"
#include "..\VirtualParallelPort\VirtualParallelPort.h"

namespace EKEY{
	//扫描键盘矩阵，并根据检测到的按键，结合Matrix.h中提供的键位定义，输出按键信息
	class KeyboardProxy{
		VirtualParallelPort* rowPort;
		VirtualParallelPort* columnPort;
	public:
		KeyboardProxy();
	}
}
#endif