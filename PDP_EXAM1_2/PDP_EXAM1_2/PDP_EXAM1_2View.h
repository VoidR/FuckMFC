
// PDP_EXAM1_2View.h : CPDP_EXAM1_2View ��Ľӿ�
//

#pragma once
#include "Chart.h"

class CPDP_EXAM1_2View : public CView
{
protected: // �������л�����
	CPDP_EXAM1_2View();
	DECLARE_DYNCREATE(CPDP_EXAM1_2View)

// ����
public:
	CPDP_EXAM1_2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CPDP_EXAM1_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

public:
	CChart barchart;
};

#ifndef _DEBUG  // PDP_EXAM1_2View.cpp �еĵ��԰汾
inline CPDP_EXAM1_2Doc* CPDP_EXAM1_2View::GetDocument() const
   { return reinterpret_cast<CPDP_EXAM1_2Doc*>(m_pDocument); }
#endif

