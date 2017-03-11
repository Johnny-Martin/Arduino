#include "Keyboard.h"
#include"Encoder\Encoder.h"
using namespace ATL;

int count = 0;
Encoder<11, 12> mouseEncoder;

void setup() {
   Serial.begin (9600);
   pinMode(8, INPUT);
   digitalWrite(8, HIGH);
   Keyboard.begin();
} 

void loop() {
	if(mouseEncoder.Excute() > 0){
		Serial.println(++count);
		if(digitalRead(8) == LOW){
			Keyboard.write(KEY_LEFT_ARROW);
		}
	}else if(mouseEncoder.Excute() < 0){
		Serial.println(--count);
		if(digitalRead(8) == LOW){
			Keyboard.write(KEY_RIGHT_ARROW);
		}
	}
} 