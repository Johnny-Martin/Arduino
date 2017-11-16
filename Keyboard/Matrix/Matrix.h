
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <Keyboard.h>

#define matrixRow 8
#define matrixCol 8
                         
#define KEY_SHIFT 		KEY_LEFT_SHIFT   
#define KEY_CTRL 		KEY_LEFT_CTRL    
#define KEY_ALT 		KEY_LEFT_ALT     
#define KEY_WIN 		KEY_LEFT_GUI     
#define KEY_DEL 		KEY_DELETE       
#define KEY_LARROW 		KEY_LEFT_ARROW   
#define KEY_RARROW 		KEY_RIGHT_ARROW  
#define KEY_DARROW 		KEY_DOWN_ARROW   
#define KEY_UARROW 		KEY_UP_ARROW     
#define KEY_PAGEUP      KEY_PAGE_UP
#define KEY_PAGEDOWN    KEY_PAGE_DOWN
#define KEY_PRTSC        0
#define KEY_BREAK        0

#define KEY_VOLUP        0
#define KEY_VOLDOWN      0
// #define KEY_ESC          0
// #define KEY_BACKSPACE          0

#define KEY_FUN   0xFF
// #define KEY_TAB   0
// #define KEY_F1   0
// #define KEY_F2   0
// #define KEY_F3   0
// #define KEY_F4   0
// #define KEY_F5   0
// #define KEY_F6   0
// #define KEY_F7   0
// #define KEY_F8   0
// #define KEY_F9   0
// #define KEY_F10   0
// #define KEY_F11   0
// #define KEY_F12   0

#define KEY_SPACE ' '
#define KEY_ENTER '\n'
#define KEY_FUN 0xFF
namespace EKEY{
	// uint8_t Row[matrixRow] = {1,2,3,4,5,6,7,8}; 
	// uint8_t Col[matrixCol] = {9,10,11,12,13,A0,A1,A2};
	
	uint8_t L_Martix[5][7] = {
		{'~', 		KEY_F1, 	KEY_F2, 	KEY_F3, 	KEY_F4, 	KEY_F5, 	0},
		{KEY_TAB, 	'Q', 		'W', 		'E', 		'R', 		'T',		0},
		{KEY_FUN, 	'A', 		'S', 		'D', 		'F', 		'G',		0},
		{KEY_SHIFT,	'Z', 		'X', 		'C', 		'V', 		'B',		0},
		{KEY_CTRL,  KEY_WIN,	KEY_ALT, 	KEY_DELETE, KEY_BACKSPACE,KEY_RETURN,0}
	};
	

  	uint8_t R_Martix[5][7] = {
		{KEY_F6, 	KEY_F7, 	KEY_F8, 	KEY_F9, 	KEY_F10, 	KEY_F11, 	KEY_F12},
		{'Y', 		'U', 		'I', 		'O', 		'P', 		'[',/*{*/	']'/*}*/},
		{'H',		'J',		'K',		'L',		';',		'"',/*'*/	'|'/*\*/},
		{'N', 		'M', 		',',/*<*/	'.',/*>*/	'/',/*?*/ 	KEY_UARROW, 0},
		{KEY_SPACE,	KEY_RETURN,	KEY_LARROW,	KEY_DARROW, KEY_RARROW, 0, 			0}
	};
	
	#define SHIFT 0x80
	const uint8_t ASC2HID[128] = {
		0x00,	// NUL
		0x00,	// SOH
		0x00,	// STX
		0x00,	// ETX
		0x00,	// EOT
		0x00,	// ENQ
		0x00,	// ACK  
		0x00,   // BEL
		0x2a,	// BS	Backspace
		0x2b,	// TAB	Tab
		0x28,	// LF	Enter
		0x00,	// VT 
		0x00,	// FF 
		0x00,	// CR 
		0x00,	// SO 
		0x00,	// SI 
		0x00,	// DEL
		0x00,	// DC1
		0x00,	// DC2
		0x00,	// DC3
		0x00,	// DC4
		0x00,	// NAK
		0x00,	// SYN
		0x00,	// ETB
		0x00,	// CAN
		0x00,	// EM 
		0x00,	// SUB
		0x00,	// ESC
		0x00,	// FS 
		0x00,	// GS 
		0x00,	// RS 
		0x00,	// US 
		0x2c,	//  ' '
		0x1e,	// !
		0x34,	// "
		0x20,	// #
		0x21,	// $
		0x22,	// %
		0x24,	// &
		0x34,	// '
		0x26,	// (
		0x27,	// )
		0x25,	// *
		0x2e,	// +
		0x36,	// ,
		0x2d,	// -
		0x37,	// .
		0x38,	// /
		0x27,	// 0
		0x1e,	// 1
		0x1f,	// 2
		0x20,	// 3
		0x21,	// 4
		0x22,	// 5
		0x23,	// 6
		0x24,	// 7
		0x25,	// 8
		0x26,	// 9
		0x33,	// :
		0x33,	// ;
		0x36,	// <
		0x2e,	// =
		0x37,	// >
		0x38,	// ?
		0x1f,	// @
		0x04,	// A
		0x05,	// B
		0x06,	// C
		0x07,	// D
		0x08,	// E
		0x09,	// F
		0x0a,	// G
		0x0b,	// H
		0x0c,	// I
		0x0d,	// J
		0x0e,	// K
		0x0f,	// L
		0x10,	// M
		0x11,	// N
		0x12,	// O
		0x13,	// P
		0x14,	// Q
		0x15,	// R
		0x16,	// S
		0x17,	// T
		0x18,	// U
		0x19,	// V
		0x1a,	// W
		0x1b,	// X
		0x1c,	// Y
		0x1d,	// Z
		0x2f,	// [
		0x31,	// bslash
		0x30,	// ]
		0x23,	// ^
		0x2d,	// _
		0x35,	// `
		0x04,	// a
		0x05,	// b
		0x06,	// c
		0x07,	// d
		0x08,	// e
		0x09,	// f
		0x0a,	// g
		0x0b,	// h
		0x0c,	// i
		0x0d,	// j
		0x0e,	// k
		0x0f,	// l
		0x10,	// m
		0x11,	// n
		0x12,	// o
		0x13,	// p
		0x14,	// q
		0x15,	// r
		0x16,	// s
		0x17,	// t
		0x18,	// u
		0x19,	// v
		0x1a,	// w
		0x1b,	// x
		0x1c,	// y
		0x1d,	// z
		0x2f,	// {
		0x31,	// |
		0x30,	// }
		0x35,	// ~
		0		// DEL
	};

}
#endif