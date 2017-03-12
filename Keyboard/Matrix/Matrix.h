
#ifndef _MATRIX_H_
#define _MATRIX_H_

#define matrixRow 8
#define matrixCol 8

uint8_t Row[matrixRow] = {1,2,3,4,5,6,7,8}; 
uint8_t Col[matrixCol] = {9,10,11,12,13,A0,A1,A2};

//程序员专用，上方一行数字键默认为符号
uint8_t Matrix[matrixRow][matrixCol] = {
	{'#','$','%','!','*','(',')','='},
	{'@','d','h','f','o','l','p','-'},
	{ESC,'b','e','u','n','i',',','~'},
	{Tab,'^','s','a','w','r','.','\\'},
	{Fun,'y','x',0  ,bak,'g',';','\''},
	{shift,'z','c',0,'}','k',upA,'/'},
	{ctrl,alt,'v',0 ,'t','j',lfA,rtA},
	{win,spc,'{','&','m','q',etr,btA}
};

uint8_t Matrix_Shift[matrixRow][matrixCol] = {
	{'2','3','4','5','7','8','9','+'},
	{'1','D','H','F','O','L','P','_'},
	{ESC,'B','E','U','N','I','<','`'},
	{Tab,'0','S','A','W','R','>','|'},
	{Fun,'Y','X',0  ,Del,'G',':','\"'},
	{shift,'Z','C',0,']','K',upA,'?'},
	{ctrl,alt,'V',0 ,'T','J',lfA,rtA},
	{win,spc,'[','6','M','Q',etr,btA}
};

#endif