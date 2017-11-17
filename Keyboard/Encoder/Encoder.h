
#ifndef _ENCODER_H_
#define _ENCODER_H_

#include <stdint.h>

//编码器正反旋转时，A、B两脚会输出不同的波形，相位差为90。在检测到A脚的跳变沿时
//，检查B脚的电平状态，与A相同即是顺时针，相异则是逆时针(或者反过来)
namespace EKEY{
	template<const uint8_t PinNumberA, const uint8_t PinNumberB>
	class Encoder{
	private:
		uint8_t m_LastState;
	public:
		static const int8_t CW;
		static const int8_t CCW;
		
	public:
		Encoder():m_LastState(LOW){
			pinMode(PinNumberA, INPUT_PULLUP);
			//digitalWrite(PinNumberA, INPUT_PULLUP);
			pinMode(PinNumberB, INPUT_PULLUP);
			//digitalWrite(PinNumberB, INPUT_PULLUP);
		}
		
		int8_t Excute(){
			uint8_t valueA = digitalRead(PinNumberA);
			uint8_t valueB = digitalRead(PinNumberB);
			
			if(valueA != m_LastState){
				m_LastState = valueA;
				
				if(valueA != valueB){
					return CW;
				}else{
					return CCW;
				}
			}
			
			return 0;
		}
		int8_t Excute2(){
			uint8_t valueA = digitalRead(PinNumberA);
			uint8_t valueB = digitalRead(PinNumberB);
			
			if(valueA != m_LastState){
				m_LastState = valueA;
				if(valueA != LOW){
					return CW;
				}else{
					return CCW;
				}
			}
			return 0;
		}
	};
	
	
	template<const uint8_t PinNumberA, const uint8_t PinNumberB>
	const int8_t Encoder<PinNumberA, PinNumberB>::CW = 1;

	template<const uint8_t PinNumberA, const uint8_t PinNumberB>
	const int8_t Encoder<PinNumberA, PinNumberB>::CCW = -1;
}
#endif