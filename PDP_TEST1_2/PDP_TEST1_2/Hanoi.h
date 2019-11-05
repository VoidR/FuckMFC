#pragma once
#include <vector>

#include "Rectangle.h"

class CHanoi
{
public:
	CHanoi(void);
	CHanoi(int n);
	~CHanoi(void);
	// 塔的阶数
	int totalN;
	// 统计塔上个矩形个数
	int totalA, totalB, totalC;
	// 塔上的矩形
	//std::stack<int> A,B,C;
	CRectangle A[10], B[10], C[10];
	// 三个塔的底部坐标
	CPoint ABottom, BBottom, CBottom;
	// 三个塔上发生的移动次数和总移动次数
	int countA, countB, countC, countAll;

	// 移动的步骤
	std::vector<std::pair<char, char>>routes;
	// 储存汉诺塔的步骤
	void save(char A, char C);
	// 生成汉诺塔
	void createHanoi(int n, char A, char B, char C);
	// 初始化汉诺塔
	void init(void);
};

