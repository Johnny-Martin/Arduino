#include <stdint.h>
#include "KeyboardProxy\KeyboardProxy.h"
#include "KeyboardProxy\KeyboardImpl.h"
using namespace EKEY;


KeyboardProxy kbd;
KeyboardImpl kbd2;


void setup() {
	Serial.begin (9600);
	
	kbd2.Init();
} 

void loop() {
	//kbd.Excute();
	kbd2.Excute();
} 
