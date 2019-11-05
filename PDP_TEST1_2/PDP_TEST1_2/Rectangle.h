#pragma once
class CRectangle
{
public:
	CRectangle(void);
	~CRectangle(void);
	CRectangle(int w);
	CRectangle(int w, int n);

	// 矩形的左上角和右下角
	CPoint letfTop, rightBottom;  
	// 矩形的宽的一半
	int width;  
	// 矩形的高
	int height;  
	// 该矩阵的高度序号
	int ord;  
	// 该矩形的移动次数
	int count;

	// 绘制矩形
	void onDraw(CDC* pDC); 
	// 设置该矩形的高度序号
	void setOrd(int t);  
	// 设置矩形的左上角和右下角后绘制矩形
	void prePointToDraw(CPoint now, CDC* pDC);  
};

