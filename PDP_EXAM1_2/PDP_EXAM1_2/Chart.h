#pragma once
#include "Diet.h"
#include "Amusement.h"
#include "Clothing.h"
#include "Education.h"
#include "Loan.h"

class CChart
{
public:
	CChart(void);
	~CChart(void);

	// 消费类数 柱体数
	int num_rect;
	int num_line;
	// 最多消费 最大刻度
	int max_money;
	// 图表的宽
	int width;
	// 图表的高
	int height;
	int padding;
	int pad_left;
	int pad_top;
	
	CDiet diet;
	CAmusement amus;
	CClothing cloth;
	CEducation edu;
	CLoan loan;

	void init(void);

	
	void OnDraw(CDC* pDC);
	void drawLine(int x1, int y1, int x2, int y2, CDC* pDC);
	void OnFont(CDC* pDC);
	void OnTitle(CDC* pDC);
};

