#pragma once
#include <vector>

#include "Rectangle.h"

class CHanoi
{
public:
	CHanoi(void);
	CHanoi(int n);
	~CHanoi(void);
	// ���Ľ���
	int totalN;
	// ͳ�����ϸ����θ���
	int totalA, totalB, totalC;
	// ���ϵľ���
	//std::stack<int> A,B,C;
	CRectangle A[10], B[10], C[10];
	// �������ĵײ�����
	CPoint ABottom, BBottom, CBottom;
	// �������Ϸ������ƶ����������ƶ�����
	int countA, countB, countC, countAll;

	// �ƶ��Ĳ���
	std::vector<std::pair<char, char>>routes;
	// ���溺ŵ���Ĳ���
	void save(char A, char C);
	// ���ɺ�ŵ��
	void createHanoi(int n, char A, char B, char C);
	// ��ʼ����ŵ��
	void init(void);
};

