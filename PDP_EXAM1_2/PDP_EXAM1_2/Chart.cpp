#include "stdafx.h"
#include "Chart.h"


CChart::CChart(void)
{
}


CChart::~CChart(void)
{
}


void CChart::init(void)
{
	num_rect = 5;
	max_money = 2400;
	num_line = 6;
	width = 800;
	height = 500;
	pad_left = 100;
	padding = 30;
	pad_top = 200;
	
	diet.Init();
	amus.Init();
	cloth.Init();
	edu.Init();
	loan.Init();
}


void CChart::OnDraw(CDC* pDC)
{
	int t_x1,t_y1,t_x2,t_y2;
	for(int i=0;i<=num_line;i++)
	{
		t_x1 = pad_left-5, t_y1 = t_y2 = 500-i*50, t_x2 = pad_left+500;
		drawLine(t_x1,t_y1,t_x2,t_y2,pDC);
	}
	t_x1 = t_x2 = pad_left, t_y2 = pad_top + 300, t_y1 = pad_top;
	drawLine(t_x1,t_y1,t_x2,t_y2,pDC);

	for(int i=0;i<=num_rect;i++)
	{
		t_x1 = t_x2 = pad_left + i*100;
		t_y1 = pad_top + 300,t_y2 = t_y1 + 5;
		drawLine(t_x1,t_y1,t_x2,t_y2,pDC);
	}
	OnFont(pDC);
	OnTitle(pDC);

	diet.OnDraw(pDC);
	amus.OnDraw(pDC);
	cloth.OnDraw(pDC);
	edu.OnDraw(pDC);
	loan.OnDraw(pDC);
}


void CChart::drawLine(int x1, int y1, int x2, int y2, CDC* pDC)
{
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen* oldPen = pDC->SelectObject(&pen);  // 替换掉原来的pen放在oldPen里

	pDC->MoveTo(x1, y1);
	pDC->LineTo(x2, y2);

}


void CChart::OnFont(CDC* pDC)
{
	CFont font;
	font.CreatePointFont(110, TEXT("楷体"));
	pDC->SelectObject(&font);

	CString number;
	int x1 = 82,y1 = pad_top + 300 - 7;
	for(int i=0;i<=6;i++)
	{
		if(i==1)	x1 -= 15;
		if(i==3)	x1 -= 7;
		number.Format(_T("%d"), i*400);
		pDC->TextOutW(x1, y1 - i*50, number);
	}

}


void CChart::OnTitle(CDC* pDC)
{
	CFont font;
	font.CreatePointFont(250, TEXT("黑体"));
	pDC->SelectObject(&font);
	CString title;
	title = "2018年三月用户消费图";
	//title.Format(_T("2018年三月用户消费图"));
	pDC->TextOutW(180, 100, title);
}
