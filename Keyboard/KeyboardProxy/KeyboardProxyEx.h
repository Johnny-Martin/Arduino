#ifndef _KEYBOARDPROXY_H_
#define _KEYBOARDPROXY_H_

#include <stdint.h>
#include <HID.h>
#include "..\Matrix\Matrix.h"
#include "..\Matrix\Adapter.h"
#include "..\Encoder\Encoder.h"

namespace EKEY{
	class  HIDKeyReport
	{
	public:
		void PushKey();
	private:
	  uint8_t modifiers;
	  uint8_t reserved;
	  uint8_t keys[6];
	};
	
}

//////////////////////////////////////////////////////////////////////////////////////////////
namespace EKEY{
	
}
#endif