#include <stdint.h>
#include "KeyboardProxy\KeyboardProxy.h"

using namespace EKEY;

KeyboardProxy kbd;
void setup() {
	Serial.begin (9600);
} 

void loop() {
	kbd.Excute();
} 
