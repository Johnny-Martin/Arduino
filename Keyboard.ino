#include "Keyboard.h"
#include"Encoder\Encoder.h"
using namespace ATL;

int count = 0;
Encoder<11, 12> mouseEncoder;
int confirmPin = A0;
void setup() {
   Serial.begin (9600);
   pinMode(confirmPin, INPUT);
   digitalWrite(confirmPin, INPUT_PULLUP);
   Keyboard.begin();
} 

void loop() {
	if(mouseEncoder.Excute2() > 0){
		Serial.println(++count);
	}else if(mouseEncoder.Excute2() < 0){
		Serial.println(--count);
	}
} 