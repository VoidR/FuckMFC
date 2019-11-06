#include "stdafx.h"
#include "Consume.h"


CConsume::CConsume(void)
{
}


CConsume::~CConsume(void)
{
}

void CConsume::OnDraw(CDC* pDC)
{
	int x1,y1,x2,y2;
	CBrush brush(RGB(R, G, B));// 初始化画刷
	CBrush *oldBrush = pDC->SelectObject(&brush);
	x1 = 25 + 100*ord, x2 = 75 + 100*ord;
	// 8 = 300 /2400
	y1 = 200 + (2400 - money)/8;
	y2 = 500;
	pDC->Rectangle(x1,y1,x2,y2);

	OnFont(pDC);
	OnIcon(x1+10,(y1+y2)/2-15,pDC);
}


void CConsume::OnFont(CDC* pDC)
{
	int x1 = 25 + 100*ord + 10, y1 = 500 +7;
	CFont font;
	font.CreatePointFont(120, TEXT("楷体"));
	pDC->SelectObject(&font);
	pDC->TextOutW(x1, y1, name);
}


void CConsume::OnIcon(int x,int y,CDC* pDC)
{
	CBitmap bitmap3;//这里先建立一个位图对象
	bitmap3.LoadBitmap(id);
	BITMAP bmp3;
	bitmap3.GetBitmap(&bmp3);//这里就是将位图对象中的图像资料放进这个结构体中
	CDC dcCom3;//建立标准DC用于绘制位图
	dcCom3.CreateCompatibleDC(pDC);
	dcCom3.SelectObject(&bitmap3);
	//CRect rect;
	//GetClientRect(&rect);
	pDC->StretchBlt(x,y,30,30,&dcCom3,0,0, bmp3.bmWidth,bmp3.bmHeight,SRCCOPY);
}
