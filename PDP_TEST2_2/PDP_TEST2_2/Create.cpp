// Create.cpp : 实现文件
//

#include "stdafx.h"
#include "PDP_TEST2_2.h"
#include "Create.h"
#include "afxdialogex.h"
#include <locale.h>

// CCreate 对话框

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


// CCreate 消息处理程序




BOOL CCreate::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 初始化成员变量
	m_quan = 0;
	m_iscreate=FALSE;
	// 初始化列表
	InitList();
	// 初始化Combo
	InitLenCombo();
	InitSymCombo();
	this->SetWindowText(_T("生成题目"));
	return TRUE;
}


void CCreate::InitList(void)
{
	CRect rect;   
  
    // 获取编程语言列表视图控件的位置和大小   
    m_ListCtrl.GetClientRect(&rect);   
  
    // 为列表视图控件添加全行选中和栅格风格   
    m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//// 为列表视图控件添加属性
	m_ListCtrl.InsertColumn(0, _T("序号"), LVCFMT_LEFT, rect.Width()/8, -1);
	m_ListCtrl.InsertColumn(1, _T("题目"), LVCFMT_CENTER, rect.Width()*7/8-20, -1);
}


void CCreate::InitLenCombo(void)
{
	m_Len.AddString(_T("一位数"));
	m_Len.AddString(_T("两位数"));
}


void CCreate::InitSymCombo(void)
{
	m_Symbol.AddString(_T("加法"));
	m_Symbol.AddString(_T("减法"));
	m_Symbol.AddString(_T("乘法"));
	m_Symbol.AddString(_T("混合"));
}


void CCreate::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	// 读取数量
	CString str;
	m_Quantity.GetWindowText(str);
	m_quan = _ttoi(str);
	if(m_quan > 100)
	{
		MessageBox(_T("亲，一次做太多也不好哦，建议最多100道呢"), _T("建议"));
		return;
	}
	else
	{
		// 读取位数
		m_Len.GetWindowText(m_len);
	
		// 读取符号
		m_Symbol.GetWindowText(m_sym);

		//生成题目
		CreateQues();

		//更新list
		InsterList();
	}
}
	


void CCreate::CreateQues(void)
{
	// 使用系统时间来初始化随机种子
	srand((unsigned)time(NULL)); 
	// 混合flag
	int flag = 0;
	if (m_sym == "混合")
	{
		flag = 1;
	}

	for (int i = 0; i < m_quan; i++)
	{
		int number1, number2,ans;
		CString sym,str;
		if(m_len == "一位数")
		{
			number1 = rand() % 10;
			number2 = rand() % 10;
		}
		else if (m_len == "两位数")
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
				m_sym = "加法";
				break;
			case 1:
				m_sym = "减法";
				break;
			case 2:
				m_sym = "乘法";
				break;
			default:
				m_sym = "加法";
			}
		}
		if(m_sym == "加法")
		{
			ans = number1 + number2;
			sym.Format(_T("+"));
		}
		else if (m_sym == "减法")
		{
			// 如果会导致结果为负，交换减数和被减数
			if(number1<number2){number2 = (number1+number2)-(number1=number2);}
			ans = number1 - number2;
			sym.Format(_T("-"));
		}
		else if(m_sym == "乘法")
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
	// 清空list之前的所有行
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
		 //如果文件已经存在则写入
		file.Open(fn, CFile::modeWrite);
		}
	else
	{
		//如果文件不存在则创建
		file.Open(fn, CFile::modeCreate | CFile::modeWrite);
	}
	 char* pOldLocale=_strdup(setlocale(LC_CTYPE,NULL));
     setlocale(LC_CTYPE,"chs");
        
	CString str;
	str.Format(_T("题目数量:%d\n"),m_quan);
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
	// TODO: 在此添加控件通知处理程序代码
	//
	if (m_quan)
	{
		m_iscreate=TRUE;
		Save();
	}
	// 关闭对话框
	CDialogEx::OnOK();
}



void CCreate::Used(void)
{
	m_iscreate=FALSE;
}
