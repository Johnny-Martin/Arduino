
#ifndef _ADAPTER_H_
#define _ADAPTER_H_


namespace EKEY{
	const uint8_t R_ROW_YELLOW 	= 4;
	const uint8_t R_ROW_GREEN 	= 3;
	const uint8_t R_ROW_RED 	= 2;

	const uint8_t R_ROW_WHITE 	= 13;

	const uint8_t& R_ROW_1 		= R_ROW_YELLOW;
	const uint8_t& R_ROW_2 		= R_ROW_GREEN;
	const uint8_t& R_ROW_3 		= R_ROW_RED;
	const uint8_t& R_ROW_4 		= R_ROW_WHITE;

	const uint8_t R_ROW_VEC[4] = {4,3,2,13};
	const uint8_t L_ROW_VEC[4] = {A0,A3,A2,A1};
	const uint8_t COLUMN_VEC[8] = {12,11,10,9,8,7,6,5};

	const uint8_t FUN_KEY_ROW_PIN = A2;
	const uint8_t FUN_KEY_COL_PIN = 9;

	//为了节省IO口，当初设计矩阵键盘的时候，采用的是8*8的布线方式(左右两部分分别是4行8列) 
	//为了方便调整键序，需要将8*8的矩阵转换为更直观的10*7。
	//L_MatrixAdapter内的值N是按键在L_Martix数组的位置，通过将N的个位、十位拆分，得到
	//L_Martix的行、列index
	uint8_t L_MatrixAdapter[40] = {
		54,//0
		53,
		52,
		51,
		56, //左键盘第五行只有五个按键，第六个位于右键盘第五行第二个
		0,
		0,
		55,
		0,
		0,
		33,//10
		43,
		42,
		41,
		46,
		45,
		44,
		34,
		0,
		0,
		23,//20
		22,
		32,
		31,
		36,
		35,
		25,
		24,
		0,
		0,
		13,//30
		12,
		11,
		21,
		26,
		16,
		15,
		14,
		0,
		0//39
	};
	
	//右键盘的第五行第二个按键是在左键盘的扫描过程中触发的
	uint8_t R_MatrixAdapter[40] = {
		55,//0
		54,
		53,
		44,
		43,
		42,
		51,
		41,
		0,
		0,
		47,//10
		46,
		45,
		35,
		34,
		33,
		32,
		31,
		0,
		0,
		37,//20
		36,
		26,
		25,
		24,
		23,
		22,
		21,
		0,
		0,
		27,//30
		17,
		16,
		15,
		14,
		13,
		12,
		11,
		0,
		0//39
	};
	
	//为方便配置键盘按键序列，可打印字符(如字母、符号)是以ASCII码的形式写在矩阵中，ctrl等键直接以HID编码写在
	//矩阵中。为了能将ASCII转成HID编码，设立该数组
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