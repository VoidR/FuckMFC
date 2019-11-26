// Create.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PDP_TEST2_2.h"
#include "Create.h"
#include "afxdialogex.h"
#include <locale.h>

// CCreate �Ի���

IMPLEMENT_DYNAMIC(CCreate, CDialogEx)

CCreate::CCreate(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCreate::IDD, pParent)
{
}

CCreate::~CCreate()
{
}

void CCreate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_ListCtrl);
	DDX_Control(pDX, IDC_QUANTITY, m_Quantity);
	DDX_Control(pDX, IDC_LEN, m_Len);
	DDX_Control(pDX, IDC_SYM, m_Symbol);
}


BEGIN_MESSAGE_MAP(CCreate, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCreate::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCreate::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCreate ��Ϣ�������




BOOL CCreate::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// ��ʼ����Ա����
	m_quan = 0;
	m_iscreate=FALSE;
	// ��ʼ���б�
	InitList();
	// ��ʼ��Combo
	InitLenCombo();
	InitSymCombo();
	this->SetWindowText(_T("������Ŀ"));
	return TRUE;
}


void CCreate::InitList(void)
{
	CRect rect;   
  
    // ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
    m_ListCtrl.GetClientRect(&rect);   
  
    // Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
    m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//// Ϊ�б���ͼ�ؼ��������
	m_ListCtrl.InsertColumn(0, _T("���"), LVCFMT_LEFT, rect.Width()/8, -1);
	m_ListCtrl.InsertColumn(1, _T("��Ŀ"), LVCFMT_CENTER, rect.Width()*7/8-20, -1);
}


void CCreate::InitLenCombo(void)
{
	m_Len.AddString(_T("һλ��"));
	m_Len.AddString(_T("��λ��"));
}


void CCreate::InitSymCombo(void)
{
	m_Symbol.AddString(_T("�ӷ�"));
	m_Symbol.AddString(_T("����"));
	m_Symbol.AddString(_T("�˷�"));
	m_Symbol.AddString(_T("���"));
}


void CCreate::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// ��ȡ����
	CString str;
	m_Quantity.GetWindowText(str);
	m_quan = _ttoi(str);
	if(m_quan > 100)
	{
		MessageBox(_T("�ף�һ����̫��Ҳ����Ŷ���������100����"), _T("����"));
		return;
	}
	else
	{
		// ��ȡλ��
		m_Len.GetWindowText(m_len);
	
		// ��ȡ����
		m_Symbol.GetWindowText(m_sym);

		//������Ŀ
		CreateQues();

		//����list
		InsterList();
	}
}
	


void CCreate::CreateQues(void)
{
	// ʹ��ϵͳʱ������ʼ���������
	srand((unsigned)time(NULL)); 
	// ���flag
	int flag = 0;
	if (m_sym == "���")
	{
		flag = 1;
	}

	for (int i = 0; i < m_quan; i++)
	{
		int number1, number2,ans;
		CString sym,str;
		if(m_len == "һλ��")
		{
			number1 = rand() % 10;
			number2 = rand() % 10;
		}
		else if (m_len == "��λ��")
		{
			number1 = rand() % 100;
			number2 = rand() % 100;
		}
		if (flag)
		{
			int r = rand()%3;
			switch (r)
			{
			case 0:
				m_sym = "�ӷ�";
				break;
			case 1:
				m_sym = "����";
				break;
			case 2:
				m_sym = "�˷�";
				break;
			default:
				m_sym = "�ӷ�";
			}
		}
		if(m_sym == "�ӷ�")
		{
			ans = number1 + number2;
			sym.Format(_T("+"));
		}
		else if (m_sym == "����")
		{
			// ����ᵼ�½��Ϊ�������������ͱ�����
			if(number1<number2){number2 = (number1+number2)-(number1=number2);}
			ans = number1 - number2;
			sym.Format(_T("-"));
		}
		else if(m_sym == "�˷�")
		{
			ans = number1 * number2;
			sym.Format(_T("*"));
		}
		str.Format(_T("%d"),number1);
		m_num1[i]=str;
		str.Format(_T("%d"),number2);
		m_num2[i]=str;
		str.Format(_T("%d"),ans);
		m_ans[i]=str;
		m_symbol[i]=sym;
	}
}


void CCreate::InsterList(void)
{
	// ���list֮ǰ��������
	m_ListCtrl.DeleteAllItems();
	for (int i = 0; i < m_quan; i++)
	{
		CString strItem = _T("");
		strItem.Format(_T(" %d"), i+1);
		m_ListCtrl.InsertItem(i, strItem);

		m_ListCtrl.SetItemText(i,1,m_num1[i]+m_symbol[i]+m_num2[i]+"=");
	}
}


void CCreate::Save(void)
{
	CTime tm = CTime::GetCurrentTime();
	//CString fn;
	fn.Format(_T("%d-%d-%d-%d-%d"),tm.GetYear(),tm.GetMonth(),tm.GetDay(),tm.GetHour(),tm.GetMinute());
	fn = _T("./homework/ ") + fn +_T(".txt");
	CStdioFile  file;
	if (PathFileExists(fn))
	{
		 //����ļ��Ѿ�������д��
		file.Open(fn, CFile::modeWrite);
		}
	else
	{
		//����ļ��������򴴽�
		file.Open(fn, CFile::modeCreate | CFile::modeWrite);
	}
	 char* pOldLocale=_strdup(setlocale(LC_CTYPE,NULL));
     setlocale(LC_CTYPE,"chs");
        
	CString str;
	str.Format(_T("��Ŀ����:%d\n"),m_quan);
	file.WriteString(str);
	setlocale(LC_CTYPE,pOldLocale);
	free(pOldLocale);
	for (int i = 0; i < m_quan; i++)
	{
		str.Format(_T("%s %s %s %s\n"),m_num1[i],m_symbol[i],m_num2[i],m_ans[i]);
		file.WriteString(str);
	}
	file.Close();
}


void CCreate::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//
	if (m_quan)
	{
		m_iscreate=TRUE;
		Save();
	}
	// �رնԻ���
	CDialogEx::OnOK();
}



void CCreate::Used(void)
{
	m_iscreate=FALSE;
}
