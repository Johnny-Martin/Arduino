#include <stdint.h>
#include "KeyboardProxy\KeyboardProxy.h"
#include "KeyboardProxy\KeyboardImpl.h"
using namespace EKEY;

int val; 
int encoder0PinA = A5;
int encoder0PinB = A4;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n = LOW;
uint8_t flag = 1;
EKEY::HIDKeyReport test;


void InitHidReport(){
	pinMode (encoder0PinA,INPUT_PULLUP);
	pinMode (encoder0PinB,INPUT_PULLUP);
}

void TestHIDReport(){
	test.Clear();
	test.PushKey(KEY_LEFT_GUI);
	test.Report();
}

KeyboardProxy kbd;
KeyboardImpl kbd2;

void setup() {
	//InitHidReport();
	Serial.begin (9600);
	
	kbd2.Init();
} 

void loop() {
	//kbd.Excute();
	//TestHIDReport();
	kbd2.Excute();
} 
