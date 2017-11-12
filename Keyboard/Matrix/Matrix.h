
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
#define KEY_HOME         0
#define KEY_END          0
#define KEY_INSERT       0
#define KEY_PRTSC        0
#define KEY_BREAK        0

#define KEY_VOLUP        0
#define KEY_VOLDOWN      0
#define KEY_ESC          0
#define KEY_BACKSPACE          0

#define KEY_FUN   0xFF
#define KEY_TAB   0
#define KEY_F1   0
#define KEY_F2   0
#define KEY_F3   0
#define KEY_F4   0
#define KEY_F5   0
#define KEY_F6   0
#define KEY_F7   0
#define KEY_F8   0
#define KEY_F9   0
#define KEY_F10   0
#define KEY_F11   0
#define KEY_F12   0

#define KEY_SPACE ' '
#define KEY_ENTER '\n'


//为了节省IO口，当初设计矩阵键盘的时候，采用的是8*8的布线方式(左右两部分分别是4行8列)
//为了方便调整键序，需要将8*8的矩阵转换为更直观的10*7。
namespace EKEY{
	uint8_t Row[matrixRow] = {1,2,3,4,5,6,7,8}; 
	uint8_t Col[matrixCol] = {9,10,11,12,13,A0,A1,A2};

	//程序员专用，上方一行数字键默认为符号
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
}
#endif