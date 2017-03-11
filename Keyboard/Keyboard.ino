#include"Encoder\Encoder.h"
using namespace ATL;

int count = 0;
Encoder<11, 12> mouseEncoder;

void setup() { 
   Serial.begin (9600);
   
} 

 void loop() {
	if(mouseEncoder.Excute() > 0){
		Serial.println(++count);
	}else if(mouseEncoder.Excute() < 0){
		Serial.println(--count);
	}
 } 