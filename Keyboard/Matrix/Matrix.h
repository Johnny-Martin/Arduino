
#ifndef _MATRIX_H_
#define _MATRIX_H_

#define matrixRow 8
#define matrixCol 8

uint8_t Row[matrixRow] = {1,2,3,4,5,6,7,8}; 
uint8_t Col[matrixCol] = {9,10,11,12,13,A0,A1,A2};
                         
#define KEY_LEFT_SHIFT   KEY_SHIFT
#define KEY_LEFT_CTRL    KEY_CTRL
#define KEY_LEFT_ALT     KEY_ALT
#define KEY_LEFT_GUI     KEY_WIN
#define KEY_DELETE       KEY_DEL
#define KEY_LEFT_ARROW   KEY_LARROW
#define KEY_RIGHT_ARROW  KEY_RARROW
#define KEY_DOWN_ARROW   KEY_DARROW
#define KEY_UP_ARROW     KEY_UARROW
#define KEY_FUN 0xFF
#define KEY_SPACE ' '
#define KEY_ENTER '\n'

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
	{Key_Fun,   'Y',       'X',  0 , KEY_DEL,       'G', ':',        '\"'},
	{KEY_SHIFT, 'Z',       'C',  0 , ']',           'K', KEY_UARROW, '?'},
	{KEY_CTRL,  KEY_ALT,   'V',  0 , 'T',           'J', KEY_LARROW, KEY_RARROW},
	{KEY_WIN,   KEY_SPACE, '[', '6', 'M',           'Q', KEY_ENTER,  KEY_DARROW}
};

#endif