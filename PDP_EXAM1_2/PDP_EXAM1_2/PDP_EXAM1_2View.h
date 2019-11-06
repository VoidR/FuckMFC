
// PDP_EXAM1_2View.h : CPDP_EXAM1_2View 类的接口
//

#pragma once
#include "Chart.h"

class CPDP_EXAM1_2View : public CView
{
protected: // 仅从序列化创建
	CPDP_EXAM1_2View();
	DECLARE_DYNCREATE(CPDP_EXAM1_2View)

// 特性
public:
	CPDP_EXAM1_2Doc* GetDocument() const;

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
	virtual ~CPDP_EXAM1_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

public:
	CChart barchart;
};

#ifndef _DEBUG  // PDP_EXAM1_2View.cpp 中的调试版本
inline CPDP_EXAM1_2Doc* CPDP_EXAM1_2View::GetDocument() const
   { return reinterpret_cast<CPDP_EXAM1_2Doc*>(m_pDocument); }
#endif

