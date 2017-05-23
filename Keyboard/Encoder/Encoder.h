
#ifndef _ENCODER_H_
#define _ENCODER_H_

#include <stdint.h>


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
			pinMode(PinNumberA, INPUT);
			digitalWrite(PinNumberA, INPUT_PULLUP);
			pinMode(PinNumberB, INPUT);
			digitalWrite(PinNumberB, INPUT_PULLUP);
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