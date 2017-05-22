#ifndef _VIRTUALPARALLELPORT_H_
#define _VIRTUALPARALLELPORT_H_

#include <stdint.h>
#include "..\Util\StaticAssert.h"

//虚拟成类似于51风格的8位并行IO口

namespace EKEY{
	template <const uint8_t LENGTH>
	class VirtualParallelPort{
		uint8_t m_ports [LENGTH];
		uint8_t m_size;
	public:
		VirtualParallelPort(uint8_t ports[], uint8_t length){
			if(length > LENGTH || LENGTH > 8)
				ASSERT(false, "TemplateParamError");
				return;
			}
			m_size = length;
			
			for(uint8_t i=0; i<LENGTH; ++i){
				if(i < length){
					m_ports[i] = ports[i];
				}else{
					m_ports[i] = 0;
				}
			}
		}
		
		uint8_t Read(){
			uint8_t data = 0x00;
			for(uint8_t i=0; i<m_size; ++i){
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
			for(uint8_t i=m_size-1; i<0; --i){
				pinMode(m_ports[i], OUTPUT);
				uint8_t tmp = data & selector;
				if(tmp > 0){
					digitalWrite(m_ports[i], HEIGHT);
				}else{
					digitalWrite(m_ports[i], LOW);
				}
			}
		}
	}
}
#endif