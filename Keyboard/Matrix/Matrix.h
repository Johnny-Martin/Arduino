
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
	
	//第二层按键定义
	uint8_t L_Martix_Fun[5][7] = {
		{'~', 		'1', 		'2', 		'3', 		'4', 		'5', 		0},
		{KEY_TAB, 	'Q', 		'W', 		'E', 		'R', 		'T',		0},
		{KEY_FUN, 	'A', 		'S', 		'D', 		'F', 		'G',		0},
		{KEY_SHIFT,	'Z', 		'X', 		'C', 		'V', 		'B',		0},
		{KEY_CTRL,  KEY_WIN,	KEY_ALT, 	KEY_DELETE, KEY_BACKSPACE,KEY_RETURN,0}
	};

  	uint8_t R_Martix_Fun[5][7] = {
		{'6', 		'7', 		'8', 		'9', 		'0', 		'-', 		'+'},
		{'Y', 		'U', 		'I', 		'O', 		'P', 		'[',/*{*/	']'/*}*/},
		{'H',		'J',		'K',		'L',		';',		'"',/*'*/	'|'/*\*/},
		{'N', 		'M', 		',',/*<*/	'.',/*>*/	'/',/*?*/ 	KEY_UARROW, 0},
		{KEY_SPACE,	KEY_RETURN,	KEY_LARROW,	KEY_DARROW, KEY_RARROW, 0, 			0}
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