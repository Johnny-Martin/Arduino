
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <Keyboard.h>

#define matrixRow 8
#define matrixCol 8
                         
#define KEY_SHIFT 0   
#define KEY_CTRL 0    
#define KEY_ALT 0     
#define KEY_WIN 0     
#define KEY_DEL 0       
#define KEY_LARROW 0   
#define KEY_RARROW 0  
#define KEY_DARROW 0   
#define KEY_UARROW  0     
#define KEY_PAGEUP       0
#define KEY_PAGEDOWN     0
// #define KEY_HOME         0
// #define KEY_END          0
// #define KEY_INSERT       0
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

namespace EKEY{
	// uint8_t Row[matrixRow] = {1,2,3,4,5,6,7,8}; 
	// uint8_t Col[matrixCol] = {9,10,11,12,13,A0,A1,A2};
	
	uint8_t L_Martix[5][7] = {
		{KEY_ESC, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, 0},
		{0x35, 0x04, 0x05, 0x06, 0x07, 0x08},
		{0},
		{0},
		{0}
	};
	uint8_t R_Martix[5][7] = {0};
	
	#define SHIFT 0x80
	const uint8_t _asciimap[128] = {
		0x00,             // NUL
		0x00,             // SOH
		0x00,             // STX
		0x00,             // ETX
		0x00,             // EOT
		0x00,             // ENQ
		0x00,             // ACK  
		0x00,             // BEL
		0x2a,			// BS	Backspace
		0x2b,			// TAB	Tab
		0x28,			// LF	Enter
		0x00,             // VT 
		0x00,             // FF 
		0x00,             // CR 
		0x00,             // SO 
		0x00,             // SI 
		0x00,             // DEL
		0x00,             // DC1
		0x00,             // DC2
		0x00,             // DC3
		0x00,             // DC4
		0x00,             // NAK
		0x00,             // SYN
		0x00,             // ETB
		0x00,             // CAN
		0x00,             // EM 
		0x00,             // SUB
		0x00,             // ESC
		0x00,             // FS 
		0x00,             // GS 
		0x00,             // RS 
		0x00,             // US 

		0x2c,		   //  ' '
		0x1e|SHIFT,	   // !
		0x34|SHIFT,	   // "
		0x20|SHIFT,    // #
		0x21|SHIFT,    // $
		0x22|SHIFT,    // %
		0x24|SHIFT,    // &
		0x34,          // '
		0x26|SHIFT,    // (
		0x27|SHIFT,    // )
		0x25|SHIFT,    // *
		0x2e|SHIFT,    // +
		0x36,          // ,
		0x2d,          // -
		0x37,          // .
		0x38,          // /
		0x27,          // 0
		0x1e,          // 1
		0x1f,          // 2
		0x20,          // 3
		0x21,          // 4
		0x22,          // 5
		0x23,          // 6
		0x24,          // 7
		0x25,          // 8
		0x26,          // 9
		0x33|SHIFT,      // :
		0x33,          // ;
		0x36|SHIFT,      // <
		0x2e,          // =
		0x37|SHIFT,      // >
		0x38|SHIFT,      // ?
		0x1f|SHIFT,      // @
		0x04|SHIFT,      // A
		0x05|SHIFT,      // B
		0x06|SHIFT,      // C
		0x07|SHIFT,      // D
		0x08|SHIFT,      // E
		0x09|SHIFT,      // F
		0x0a|SHIFT,      // G
		0x0b|SHIFT,      // H
		0x0c|SHIFT,      // I
		0x0d|SHIFT,      // J
		0x0e|SHIFT,      // K
		0x0f|SHIFT,      // L
		0x10|SHIFT,      // M
		0x11|SHIFT,      // N
		0x12|SHIFT,      // O
		0x13|SHIFT,      // P
		0x14|SHIFT,      // Q
		0x15|SHIFT,      // R
		0x16|SHIFT,      // S
		0x17|SHIFT,      // T
		0x18|SHIFT,      // U
		0x19|SHIFT,      // V
		0x1a|SHIFT,      // W
		0x1b|SHIFT,      // X
		0x1c|SHIFT,      // Y
		0x1d|SHIFT,      // Z
		0x2f,          // [
		0x31,          // bslash
		0x30,          // ]
		0x23|SHIFT,    // ^
		0x2d|SHIFT,    // _
		0x35,          // `
		0x04,          // a
		0x05,          // b
		0x06,          // c
		0x07,          // d
		0x08,          // e
		0x09,          // f
		0x0a,          // g
		0x0b,          // h
		0x0c,          // i
		0x0d,          // j
		0x0e,          // k
		0x0f,          // l
		0x10,          // m
		0x11,          // n
		0x12,          // o
		0x13,          // p
		0x14,          // q
		0x15,          // r
		0x16,          // s
		0x17,          // t
		0x18,          // u
		0x19,          // v
		0x1a,          // w
		0x1b,          // x
		0x1c,          // y
		0x1d,          // z
		0x2f|SHIFT,    // {
		0x31|SHIFT,    // |
		0x30|SHIFT,    // }
		0x35|SHIFT,    // ~
		0				// DEL
	};

	//程序员专用，上方一行数字键默认为符号
	/*
	uint8_t Matrix[matrixRow][matrixCol] = {
		{'#',       '$',       '%', '!', '*',           '(', ')',        '='},
		{'@',       'd',       'h', 'f', 'o',           'l', 'p',        '-'},
		{KEY_ESC,   'b',       'e', 'u', 'n',           'i', ',',        '~'},
		{KEY_TAB,   '^',       's', 'a', 'w',           'r', '.',        '\\'},
		{KEY_FUN,   'y',       'x',  0 , KEY_BACKSPACE, 'g', ';',        '\''},
		{KEY_SHIFT, 'z',       'c',  0 , '}',           'k', KEY_UARROW, '/'},
		{KEY_CTRL,  KEY_ALT,   'v',  0 , 't',           'j', KEY_LARROW, KEY_RARROW},
		{KEY_WIN,   KEY_SPACE, '{', '&', 'm',           'q', KEY_ENTER,  KEY_DARROW}
	};

	uint8_t Matrix_Shift[matrixRow][matrixCol] = {
		{'2',       '3',       '4', '5', '7',           '8', '9',        '+'},
		{'1',       'D',       'H', 'F', 'O',           'L', 'P',        '_'},
		{KEY_ESC,   'B',       'E', 'U', 'N',           'I', '<',        '`'},
		{KEY_TAB,   '0',       'S', 'A', 'W',           'R', '>',        '|'},
		{KEY_FUN,   'Y',       'X',  0 , KEY_DEL,       'G', ':',        '\"'},
		{KEY_SHIFT, 'Z',       'C',  0 , ']',           'K', KEY_UARROW, '?'},
		{KEY_CTRL,  KEY_ALT,   'V',  0 , 'T',           'J', KEY_LARROW, KEY_RARROW},
		{KEY_WIN,   KEY_SPACE, '[', '6', 'M',           'Q', KEY_ENTER,  KEY_DARROW}
	};

	uint8_t Matrix_Fun[matrixRow][matrixCol] = {
		{KEY_F2,    KEY_F3,    KEY_F4, KEY_F5, KEY_F7,  KEY_F8, KEY_F9,     KEY_F10},
		{KEY_F1,    'D',       'H',    'F',    '7',     '8',    '9',        KEY_F11},
		{KEY_ESC,   'B',       'E',    'U',    '4',     '5',    '<',        KEY_F12},
		{KEY_TAB,   '0',       'S',    'A',    '1',     '6',    '>',        '|'},
		{KEY_FUN,   'Y',       'X',     0 ,    KEY_DEL, 'G',    ':',        '\"'},
		{KEY_SHIFT, 'Z',       'C',     0 ,    '0',     'K',    KEY_PAGEUP, '?'},
		{KEY_CTRL,  KEY_ALT,   'V',     0 ,    'T',     '3',    KEY_HOME,   KEY_END},
		{KEY_WIN,   KEY_SPACE, '[',    KEY_F6, 'M',     '2',    KEY_ENTER,  KEY_PAGEDOWN}
	};
	
	uint8_t Matrix_DbFun[matrixRow][matrixCol] = {
		{KEY_F2,    KEY_F3,    KEY_F4, KEY_F5, KEY_F7,  KEY_F8, KEY_F9,     KEY_F10},
		{KEY_F1,    'D',       'H',    'F',    '7',     '8',    '9',        KEY_F11},
		{KEY_ESC,   'B',       'E',    'U',    '4',     '5',    '<',        KEY_F12},
		{KEY_TAB,   '0',       'S',    'A',    '1',     '6',    '>',        '|'},
		{KEY_FUN,   'Y',       'X',     0 ,    KEY_DEL, 'G',    ':',        '\"'},
		{KEY_SHIFT, 'Z',       'C',     0 ,    '0',     'K',    KEY_PAGEUP, '?'},
		{KEY_CTRL,  KEY_ALT,   'V',     0 ,    'T',     '3',    KEY_HOME,   KEY_END},
		{KEY_WIN,   KEY_SPACE, '[',    KEY_F6, 'M',     '2',    KEY_ENTER,  KEY_PAGEDOWN}
	};
	*/
}
#endif