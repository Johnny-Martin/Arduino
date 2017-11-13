
#ifndef _ADAPTER_H_
#define _ADAPTER_H_


//为了节省IO口，当初设计矩阵键盘的时候，采用的是8*8的布线方式(左右两部分分别是4行8列)
//为了方便调整键序，需要将8*8的矩阵转换为更直观的10*7。
namespace EKEY{
	//L_MatrixAdapter内的值N是按键在L_Martix数组的位置，通过将N的个位、十位拆分，得到
	//L_Martix的行、列index
	uint8_t L_MatrixAdapter[33] = {
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
	uint8_t R_MatrixAdapter[33] = {
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
}
#endif