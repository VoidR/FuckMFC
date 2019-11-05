#include "stdafx.h"
#include "Hanoi.h"


CHanoi::CHanoi(void)
{
	totalN = 4;
	totalA = 4;
	totalB = 0;
	totalC = 0;
	createHanoi(4, 'A', 'B', 'C');
	ABottom = CPoint(300, 400);
	BBottom = CPoint(600, 400);
	CBottom = CPoint(900, 400);
}


CHanoi::~CHanoi(void)
{
}


CHanoi::CHanoi(int n)
{
	/*totalA = 4;
	totalB = 0;
	totalC = 0;
	createHanoi(4, 'A', 'B', 'C');*/
}


void CHanoi::createHanoi(int n, char A, char B, char C)
{
	// 生成汉诺塔
	if(n==1) save(A, C);
	else {
		createHanoi(n-1, A, C, B);
		save(A, C);
		createHanoi(n-1, B, A, C);
	}
}


void CHanoi::save(char A, char C)
{
	// 保存路径
	routes.push_back(std::pair<char, char>(A, C));
}





void CHanoi::init(void)
{
	// 初始化Hanoi塔信息
	totalA = 4;
	totalB = 0;
	totalC = 0;
	countA = 0;
	countB = 0;
	countC = 0;
	countAll = 0;
	for(int i=1; i<=totalA; i++)
	{
		// 金盘的宽度以此位80，60，40，20
		CRectangle temp((5-i)*20);
		// 以此设置金盘的高度序号
		temp.setOrd(i);
		A[i]=temp;
	}
}
