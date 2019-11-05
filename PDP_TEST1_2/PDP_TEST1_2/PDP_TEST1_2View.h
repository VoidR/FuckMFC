
// PDP_TEST1_2View.h : CPDP_TEST1_2View ��Ľӿ�
//

#pragma once
#include <vector>
#include <stack>

#include "Rectangle.h"
#include "Hanoi.h"

class CPDP_TEST1_2View : public CView
{
protected: // �������л�����
	CPDP_TEST1_2View();
	DECLARE_DYNCREATE(CPDP_TEST1_2View)

// ����
public:
	CPDP_TEST1_2Doc* GetDocument() const;

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
	virtual ~CPDP_TEST1_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	// ��ʼ������
	void init();
	CHanoi hanoi;
	// ��ǰ�ƶ��������յ�
	char origin,terminal;
	// ��ǰ����--������
	std::vector<std::pair<char, char>>::iterator route;
	// ģ���õ���ǰ�ڼ���
	int currentStep;

	// һ��ִ�еĺ���
	void step(void);
	// ���Ƴ�ʼ������
	void drawTowers();
	// ���ƾ���
	void drawRects();
	// ��������(�ƶ�����)
	void drawFont(void);
	// ˢ����Ļ
	void refresh(void);
	// ��һ�ξ����ƶ���Ϊ����
	void stepOne(void);
	void stepTwo(void);
	void stepThree(void);
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMyStart();
	afx_msg void OnMyStep();
	afx_msg void OnMyStop();
	afx_msg void OnMyEnd();

	// ����
	void drawLine(int x1, int y1, int x2, int y2);
};

#ifndef _DEBUG  // PDP_TEST1_2View.cpp �еĵ��԰汾
inline CPDP_TEST1_2Doc* CPDP_TEST1_2View::GetDocument() const
   { return reinterpret_cast<CPDP_TEST1_2Doc*>(m_pDocument); }
#endif

