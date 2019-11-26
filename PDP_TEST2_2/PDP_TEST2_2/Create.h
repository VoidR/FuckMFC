#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CCreate 对话框

class CCreate : public CDialogEx
{
	DECLARE_DYNAMIC(CCreate)

public:
	CCreate(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCreate();

// 对话框数据
	enum { IDD = IDD_CREATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	// 题目
	CString m_num1[107],m_num2[107],m_ans[107],m_symbol[107];
	// 题目数量
	int m_quan;
	// 题目长度和题目符号
	CString m_len,m_sym;

	// 新生成标记
	BOOL m_iscreate;
	// 文件名字
	CString fn;
	
	// 控件
	CEdit m_Quantity;
	CComboBox m_Len;
	CComboBox m_Symbol;
	CListCtrl m_ListCtrl;
	// 初始化控件
	void InitList(void);
	void InitLenCombo(void);
	void InitSymCombo(void);

	// 生成问题
	void CreateQues(void);
	// List控件插入
	void InsterList(void);
	// 保存到文件
	void Save(void);
	// 标记新生成的已经使用
	void Used(void);

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
