#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CCreate �Ի���

class CCreate : public CDialogEx
{
	DECLARE_DYNAMIC(CCreate)

public:
	CCreate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCreate();

// �Ի�������
	enum { IDD = IDD_CREATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	// ��Ŀ
	CString m_num1[107],m_num2[107],m_ans[107],m_symbol[107];
	// ��Ŀ����
	int m_quan;
	// ��Ŀ���Ⱥ���Ŀ����
	CString m_len,m_sym;

	// �����ɱ��
	BOOL m_iscreate;
	// �ļ�����
	CString fn;
	
	// �ؼ�
	CEdit m_Quantity;
	CComboBox m_Len;
	CComboBox m_Symbol;
	CListCtrl m_ListCtrl;
	// ��ʼ���ؼ�
	void InitList(void);
	void InitLenCombo(void);
	void InitSymCombo(void);

	// ��������
	void CreateQues(void);
	// List�ؼ�����
	void InsterList(void);
	// ���浽�ļ�
	void Save(void);
	// ��������ɵ��Ѿ�ʹ��
	void Used(void);

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
