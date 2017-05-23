#ifndef _VIRTUALPARALLELPORT_H_
#define _VIRTUALPARALLELPORT_H_

#include <stdint.h>
#include "..\Util\StaticAssert.h"

//虚拟成类似于51风格的8位并行IO口(暂时只支持8位，其他位数会编译不过)

namespace EKEY{
	template <const uint8_t LENGTH>
	class VirtualParallelPort{
		uint8_t* m_ports;
	public:
		VirtualParallelPort(uint8_t ports[]){
			ASSERT((LENGTH == 8), TemplateParamError_length_error);
			
			m_ports = ports;
		}
		
		uint8_t Read(){
			uint8_t data = 0x00;
			for(uint8_t i=0; i<LENGTH; ++i){
				pinMode(m_ports[i], INPUT);
				uint8_t value = digitalRead(m_ports[i]);
				if(value == LOW){
					data = (data << i) | 0x00;
				}else{
					data = (data << i) | 0x01;
				}
			}
			return data;
		}
		
		void Write(uint8_t data){
			uint8_t selector = 0x01;
			for(uint8_t i=LENGTH-1; i<0; --i){
				pinMode(m_ports[i], OUTPUT);
				uint8_t tmp = data & selector;
				if(tmp > 0){
					digitalWrite(m_ports[i], HIGH);
				}else{
					digitalWrite(m_ports[i], LOW);
				}
			}
		}
	};
}
#endif