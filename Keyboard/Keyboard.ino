#include "KeyboardProxy\KeyboardProxy.h"

using namespace EKEY;

KeyboardProxy kbd{};
void setup() {
	Serial.begin (9600);
	kbd.Init();
} 

void loop() {
	kbd.Excute();
} 