
// PDP_TEST2_2View.h : CPDP_TEST2_2View 类的接口
//

#pragma once

#include "resource.h"
#include "afxwin.h"
#include "Create.h"
#include "afxcmn.h"
#include <locale.h>


class CPDP_TEST2_2View : public CFormView
{
protected: // 仅从序列化创建
	CPDP_TEST2_2View();
	DECLARE_DYNCREATE(CPDP_TEST2_2View)

public:
	enum{ IDD = IDD_PDP_TEST2_2_FORM };

// 特性
public:
	CPDP_TEST2_2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CPDP_TEST2_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	// 题目总数
	int m_num;
	// 题目
	CString m_num1[107],m_num2[107],m_ans[107],m_symbol[107],m_myans[107];
	// 题目序号
	int m_index;
	// 用时 分、秒
	int m_sec,m_min;
	// 文件名
	CString fn;
	// 答案判断
	void JudgeAns(int index);
	// 保存到文件
	void SaveToFile(void);
	// 从Edit获取输入的答案
	void GetMyAns(void);
	// 开始
	void Begin(void);
	// 显示题目
	void show(void);
	// 准备工作
	void Ready(void);
	// 从文件中获取data
	void getData(CString fn);
	
	// 正确题数，错误题数，未完成题数
	int m_correct,m_incorrect,m_incomplete;
	// 开始时间戳，结束时间戳
	long m_starttime,m_endtime;
	// 用时计算
	void TimeSpend(void);
	// 统计正确题数、错误题数、未完成题数
	void Stats(void);

	// 对话框
	CCreate m_CreateDlg;
	// 字体
	CFont m_font;
	// 控件
	CTreeCtrl m_TreeCtrl;
	CListCtrl m_ListCtrl;
	CStatic m_TextCtrl;
	CButton m_lastBut;
	CButton m_nextBut;
	CButton m_CreateBut;
	CEdit m_edit;
	CStatic m_textord;

	// List控件
	// List控件插入
	void insertlist(void);
	// List控件初始化
	void InitList(void);

	// Tree控件
	// Tree控件 根节点
	HTREEITEM Root;
	// Tree控件初始化
	void InitTree(void);
	// Tree控件生成
	void CCreateTree();
	// Tree控件 添加节点
	void CAddTree(void);
	// Tree控件 点击
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCreate();
	afx_msg void OnBnClickedScore();
	afx_msg void OnBnClickedLast();
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedSubmit();
	// 定时器
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // PDP_TEST2_2View.cpp 中的调试版本
inline CPDP_TEST2_2Doc* CPDP_TEST2_2View::GetDocument() const
   { return reinterpret_cast<CPDP_TEST2_2Doc*>(m_pDocument); }
#endif

