
// PDP_TEST2_2View.h : CPDP_TEST2_2View ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "afxwin.h"
#include "Create.h"
#include "afxcmn.h"
#include <locale.h>


class CPDP_TEST2_2View : public CFormView
{
protected: // �������л�����
	CPDP_TEST2_2View();
	DECLARE_DYNCREATE(CPDP_TEST2_2View)

public:
	enum{ IDD = IDD_PDP_TEST2_2_FORM };

// ����
public:
	CPDP_TEST2_2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CPDP_TEST2_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	// ��Ŀ����
	int m_num;
	// ��Ŀ
	CString m_num1[107],m_num2[107],m_ans[107],m_symbol[107],m_myans[107];
	// ��Ŀ���
	int m_index;
	// ��ʱ �֡���
	int m_sec,m_min;
	// �ļ���
	CString fn;
	// ���ж�
	void JudgeAns(int index);
	// ���浽�ļ�
	void SaveToFile(void);
	// ��Edit��ȡ����Ĵ�
	void GetMyAns(void);
	// ��ʼ
	void Begin(void);
	// ��ʾ��Ŀ
	void show(void);
	// ׼������
	void Ready(void);
	// ���ļ��л�ȡdata
	void getData(CString fn);
	
	// ��ȷ����������������δ�������
	int m_correct,m_incorrect,m_incomplete;
	// ��ʼʱ���������ʱ���
	long m_starttime,m_endtime;
	// ��ʱ����
	void TimeSpend(void);
	// ͳ����ȷ����������������δ�������
	void Stats(void);

	// �Ի���
	CCreate m_CreateDlg;
	// ����
	CFont m_font;
	// �ؼ�
	CTreeCtrl m_TreeCtrl;
	CListCtrl m_ListCtrl;
	CStatic m_TextCtrl;
	CButton m_lastBut;
	CButton m_nextBut;
	CButton m_CreateBut;
	CEdit m_edit;
	CStatic m_textord;

	// List�ؼ�
	// List�ؼ�����
	void insertlist(void);
	// List�ؼ���ʼ��
	void InitList(void);

	// Tree�ؼ�
	// Tree�ؼ� ���ڵ�
	HTREEITEM Root;
	// Tree�ؼ���ʼ��
	void InitTree(void);
	// Tree�ؼ�����
	void CCreateTree();
	// Tree�ؼ� ��ӽڵ�
	void CAddTree(void);
	// Tree�ؼ� ���
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCreate();
	afx_msg void OnBnClickedScore();
	afx_msg void OnBnClickedLast();
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedSubmit();
	// ��ʱ��
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // PDP_TEST2_2View.cpp �еĵ��԰汾
inline CPDP_TEST2_2Doc* CPDP_TEST2_2View::GetDocument() const
   { return reinterpret_cast<CPDP_TEST2_2Doc*>(m_pDocument); }
#endif

