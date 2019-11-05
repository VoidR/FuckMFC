
// PDP_TEST1_2View.h : CPDP_TEST1_2View 类的接口
//

#pragma once
#include <vector>
#include <stack>

#include "Rectangle.h"
#include "Hanoi.h"

class CPDP_TEST1_2View : public CView
{
protected: // 仅从序列化创建
	CPDP_TEST1_2View();
	DECLARE_DYNCREATE(CPDP_TEST1_2View)

// 特性
public:
	CPDP_TEST1_2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CPDP_TEST1_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	// 初始化界面
	void init();
	CHanoi hanoi;
	// 当前移动的起点和终点
	char origin,terminal;
	// 当前步骤--迭代器
	std::vector<std::pair<char, char>>::iterator route;
	// 模三得到当前第几步
	int currentStep;

	// 一步执行的函数
	void step(void);
	// 绘制初始三个塔
	void drawTowers();
	// 绘制矩形
	void drawRects();
	// 绘制文字(移动次数)
	void drawFont(void);
	// 刷新屏幕
	void refresh(void);
	// 将一次矩形移动分为三步
	void stepOne(void);
	void stepTwo(void);
	void stepThree(void);
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMyStart();
	afx_msg void OnMyStep();
	afx_msg void OnMyStop();
	afx_msg void OnMyEnd();

	// 画线
	void drawLine(int x1, int y1, int x2, int y2);
};

#ifndef _DEBUG  // PDP_TEST1_2View.cpp 中的调试版本
inline CPDP_TEST1_2Doc* CPDP_TEST1_2View::GetDocument() const
   { return reinterpret_cast<CPDP_TEST1_2Doc*>(m_pDocument); }
#endif

