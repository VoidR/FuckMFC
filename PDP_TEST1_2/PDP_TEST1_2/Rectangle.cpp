#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(void)
{
	width = 0;
	height = 25;
	count = 0;
}


CRectangle::~CRectangle(void)
{
}


CRectangle::CRectangle(int w)
{
	width = w;
	height = 25;  // 所有矩形的高度都是25
	count = 0;
}


CRectangle::CRectangle(int w, int n)
{
	width = w;
	height = 25;  // 所有矩形的高度都是25
	count = n;
}


void CRectangle::onDraw(CDC* pDC)
{
	pDC->Rectangle(letfTop.x,letfTop.y,rightBottom.x,rightBottom.y);

	CFont font;
	font.CreatePointFont(120, TEXT("楷体"));
	pDC->SelectObject(&font);

	// 绘制该矩形移动的次数
	CString string_one;
	string_one.Format(_T("%d"), count);
	pDC->TextOutW(rightBottom.x + 10, letfTop.y + 3, string_one);
}


void CRectangle::setOrd(int t)
{
	ord = t;
}


void CRectangle::prePointToDraw(CPoint now, CDC* pDC)
{
	letfTop.x = now.x - width;
	letfTop.y = now.y - (ord * height);
	rightBottom.x = now.x + width;
	rightBottom.y = letfTop.y + height;
	onDraw(pDC);
}
