
// PDP_TEST2_2View.cpp : CPDP_TEST2_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "PDP_TEST2_2.h"
#endif

#include "PDP_TEST2_2Doc.h"
#include "PDP_TEST2_2View.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPDP_TEST2_2View

IMPLEMENT_DYNCREATE(CPDP_TEST2_2View, CFormView)

BEGIN_MESSAGE_MAP(CPDP_TEST2_2View, CFormView)
	ON_BN_CLICKED(IDC_CREATE, &CPDP_TEST2_2View::OnBnClickedCreate)
	ON_BN_CLICKED(IDC_SUBMIT, &CPDP_TEST2_2View::OnBnClickedSubmit)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CPDP_TEST2_2View::OnTvnSelchangedTree1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_LAST, &CPDP_TEST2_2View::OnBnClickedLast)
	ON_BN_CLICKED(IDC_NEXT, &CPDP_TEST2_2View::OnBnClickedNext)
	ON_BN_CLICKED(IDC_SCORE, &CPDP_TEST2_2View::OnBnClickedScore)
END_MESSAGE_MAP()

// CPDP_TEST2_2View 构造/析构

CPDP_TEST2_2View::CPDP_TEST2_2View()
	: CFormView(CPDP_TEST2_2View::IDD)
	, m_num(0)
	, m_index(0)
{
	// TODO: 在此处添加构造代码

}

CPDP_TEST2_2View::~CPDP_TEST2_2View()
{
}

void CPDP_TEST2_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CREATE, m_CreateBut);
	DDX_Control(pDX, IDC_TREE1, m_TreeCtrl);
	DDX_Control(pDX, IDC_LIST3, m_ListCtrl);
	DDX_Control(pDX, IDC_STATEXT1, m_TextCtrl);
	DDX_Control(pDX, IDC_LAST, m_lastBut);
	DDX_Control(pDX, IDC_NEXT, m_nextBut);
	DDX_Control(pDX, IDC_EDIT2, m_edit);
	DDX_Control(pDX, IDC_STATEXT2, m_textord);
}

BOOL CPDP_TEST2_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CPDP_TEST2_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	// 初始化list
	InitList();

	// 初始化tree
	InitTree();

	SetTimer(1,1000,NULL); 
	m_font.CreatePointFont(550,_T("宋体"));
	GetDlgItem(IDC_STATEXT)->SetFont(&m_font);
	GetDlgItem(IDC_STATEXT2)->SetFont(&m_font);
	GetDlgItem(IDC_EDIT2)->SetFont(&m_font);

	Ready();
}


// CPDP_TEST2_2View 诊断

#ifdef _DEBUG
void CPDP_TEST2_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CPDP_TEST2_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CPDP_TEST2_2Doc* CPDP_TEST2_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPDP_TEST2_2Doc)));
	return (CPDP_TEST2_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CPDP_TEST2_2View 消息处理程序




void CPDP_TEST2_2View::OnBnClickedCreate()
{
	// TODO: 在此添加控件通知处理程序代码
	m_CreateDlg.DoModal();
}


void CPDP_TEST2_2View::InitTree(void)
{
	m_TreeCtrl.ModifyStyle(0,TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT);
	Root = m_TreeCtrl.InsertItem( _T("我的作业"), TVI_ROOT);
	// 读取文件
	CCreateTree();
	m_TreeCtrl.Expand(Root,TVE_EXPAND);

}


void CPDP_TEST2_2View::InitList(void)
{
	CRect rect;   
  
    // 获取编程语言列表视图控件的位置和大小   
    m_ListCtrl.GetClientRect(&rect);   
  
    // 为列表视图控件添加全行选中和栅格风格   
    m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//// 为列表视图控件添加属性
	m_ListCtrl.InsertColumn(0, _T("序号"), LVCFMT_LEFT, rect.Width()/8, -1);
	m_ListCtrl.InsertColumn(1, _T("题目"), LVCFMT_CENTER, rect.Width()*3/8, -1);
	m_ListCtrl.InsertColumn(2, _T("结果"), LVCFMT_CENTER, rect.Width()/4, -1);
	m_ListCtrl.InsertColumn(3, _T("正确否"), LVCFMT_CENTER, rect.Width()/4-20, -1);
	
}


void CPDP_TEST2_2View::CCreateTree()
{
	CString path(_T("./homework/"));
	CFileFind finder;
	HTREEITEM hSonItem;
	hSonItem = m_TreeCtrl.GetChildItem(Root);
	bool bFind = false;

	CString dirName;
	BOOL exit = finder.FindFile(path + _T("\\*.txt"));
	while (exit)
	{
		exit = finder.FindNextFile();  // 保存下一个文件

		if (!finder.IsDirectory() && !finder.IsDots())
		{
			dirName = finder.GetFileName();
			hSonItem = m_TreeCtrl.InsertItem(dirName,NULL,NULL,Root,hSonItem);
		}
	}

}


void CPDP_TEST2_2View::OnBnClickedSubmit()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	GetDlgItem(IDC_SUBMIT)->GetWindowText(str);
	if(str == "开始练习")
	{
		if(m_num==0)
		{
			MessageBox(_T("请在左侧选择题目"), _T("提醒"));
		}
		else
		{
			m_starttime = GetTickCount();
			GetDlgItem(IDC_SUBMIT)->SetWindowText(_T("提交"));
			show();
			// 解锁button
			m_lastBut.EnableWindow(TRUE);
			m_nextBut.EnableWindow(TRUE);
		}
	}
	else if (str == "提交")
	{
		TimeSpend();
		SaveToFile();
	}
}



void CPDP_TEST2_2View::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: 在此添加控件通知处理程序代码
	CPoint pos;
	GetCursorPos(&pos);
	m_TreeCtrl.ScreenToClient(&pos);
	UINT uFlags=0;
	HTREEITEM hItem = m_TreeCtrl.HitTest(pos, &uFlags);
	if ((hItem != NULL) && (TVHT_ONITEM & uFlags))//如果点击的位置是在节点位置上面
	{
		// 计算点击节点对应的文件名
		fn = m_TreeCtrl.GetItemText(hItem);
		fn = _T("./homework/") + fn;
		// 开始
		Begin();
	}
}


void CPDP_TEST2_2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CFormView::OnTimer(nIDEvent);
	// 判断是否有新生成的题目文件
	if(m_CreateDlg.m_iscreate == TRUE)
	{
		fn=m_CreateDlg.fn;
		// 添加Tree节点
		CAddTree();
		// 开始练习
		Begin();
		// 标记该新题目文件已被使用
		m_CreateDlg.Used();
	}
}


void CPDP_TEST2_2View::CAddTree(void)
{
	HTREEITEM hSonItem;
	hSonItem = m_TreeCtrl.GetChildItem(Root);
	int index = fn.Find(_T(" "));
	CString str=fn.Right(fn.GetLength()-index);
	while(hSonItem != NULL)
	{
		HTREEITEM t = m_TreeCtrl.GetNextSiblingItem(hSonItem);
		hSonItem = t;
	}
	hSonItem = m_TreeCtrl.InsertItem(str,NULL,NULL,Root,hSonItem);
	
}


void CPDP_TEST2_2View::getData(CString fn)
{
	for (int i = 0; i < 107; i++)
	{
		m_myans[i].Empty();
	}
	CStdioFile file;
	BOOL flag = file.Open(fn,CFile::modeRead);
	if(flag == FALSE)
	{
		MessageBox(_T("文件打开失败！"), _T("提醒"));
	}
	// 设置系统区域，使得可以中文读取
	char* pOldLocale=_strdup(setlocale(LC_CTYPE,NULL));
	setlocale(LC_CTYPE,"chs");
	CString strline;
	if(file.ReadString(strline) != FALSE)
	{
		// 获取题目总数
		CString str;
		int n =-1;
		n=strline.Find(_T(":"));
		str = strline.Mid(n+1);
		m_num = _ttoi(str);
	}
	for (int i = 0; i < m_num; i++)
	{
		// 获取第一个数
		file.ReadString(strline);
		int index = strline.Find(_T(" "));
		m_num1[i] = strline.Left(index);

		// 获取符号
		strline = strline.Right(strline.GetLength()-index-1);
		index = strline.Find(_T(" "));
		m_symbol[i] = strline.Left(index);

		// 获取第二个数
		strline = strline.Right(strline.GetLength()-index-1);
		index = strline.Find(_T(" "));
		m_num2[i] = strline.Left(index);
		
		// 获取答案
		strline = strline.Right(strline.GetLength()-index-1);
		index = strline.Find(_T(" "));
		if(index == -1)
		{
			m_ans[i] = strline;
		}
		else
		{
			m_ans[i] = strline.Left(index);
			strline = strline.Right(strline.GetLength()-index-1);
			m_myans[i]=strline;
		}
	}
	setlocale(LC_CTYPE,pOldLocale);
	free(pOldLocale);
}


void CPDP_TEST2_2View::insertlist(void)
{
	m_ListCtrl.DeleteAllItems();
	for (int i = 0; i < m_num; ++i)
	{
		CString ord;
		ord.Format(_T("%d"),i+1);
		m_ListCtrl.InsertItem(i, ord);//插入行
		m_ListCtrl.SetItemText(i, 1, m_num1[i]+m_symbol[i]+m_num2[i]+"=");
		m_ListCtrl.SetItemText(i, 2, m_myans[i]);
		JudgeAns(i);
	}
}


void CPDP_TEST2_2View::Ready(void)
{
	m_lastBut.EnableWindow(FALSE);
	m_nextBut.EnableWindow(FALSE);
	m_textord.SetWindowText(_T(""));
	m_TextCtrl.SetWindowText(_T(""));
	GetDlgItem(IDC_SUBMIT)->SetWindowText(_T("开始练习"));
	m_index=0;
	m_correct=0;
	m_incorrect=0;
	m_starttime=0;
	m_endtime=0;
	m_min=0;
	m_sec=0;
}


void CPDP_TEST2_2View::show(void)
{
	m_edit.SetWindowText(m_myans[m_index]);
	CString ord;
	ord.Format(_T("%d"),m_index+1);
	m_TextCtrl.SetWindowText((ord, 1, m_num1[m_index]+m_symbol[m_index]+m_num2[m_index]+"="));
	m_textord.SetWindowText(ord+":");
}


void CPDP_TEST2_2View::OnBnClickedLast()
{
	// TODO: 在此添加控件通知处理程序代码
	GetMyAns();
	JudgeAns(m_index);
	if(m_index>0)
	{
		m_index--;
		show();
	}
	else
	{
		MessageBox(_T("已经是第一题啦！"), _T("提醒"));
	}
}


void CPDP_TEST2_2View::OnBnClickedNext()
{
	// TODO: 在此添加控件通知处理程序代码
	GetMyAns();
	JudgeAns(m_index);
	if(m_index<m_num-1)
	{
		m_index++;
		show();
	}
	else
	{
		Stats();
		if (m_correct+m_incorrect == m_num )
		{
			MessageBox(_T("恭喜你！已经完成啦！\n保存成功！"), _T("提醒"));
		}
		else
		{
			CString str;
			str.Format(_T("已经是最后一题啦！\n你还有%d题没有完成!%d\n%d\n"),m_incomplete,m_correct,m_incorrect);
			MessageBox(str, _T("提醒"));
		}
	}
}


void CPDP_TEST2_2View::JudgeAns(int index)
{
	CString str;
	m_ListCtrl.SetItemText(index, 2, m_myans[index]);
	if(!m_myans[index].IsEmpty())
	{
		if(m_myans[index]==m_ans[index])
		{
			str.Format(_T("正确"));
		}
		else
		{
			str.Format(_T("错误"));
		}
		m_ListCtrl.SetItemText(index, 3, str);
	}
}


void CPDP_TEST2_2View::SaveToFile(void)
{
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
	str.Format(_T("题目数量:%d\n"),m_num);
	file.WriteString(str);
	for (int i = 0; i < m_num; i++)
	{
		str.Format(_T("%s %s %s %s %s\n"),m_num1[i],m_symbol[i],m_num2[i],m_ans[i],m_myans[i]);
		file.WriteString(str);
	}

	int m_min =0,m_sec = (m_endtime-m_starttime)/1000;
	while(m_sec>60)
	{
		m_min++;
		m_sec-=60;
	}
	Stats();
	str.Format(_T("正确题数:%d\n错误题数:%d\n未完成题数:%d\n用时:%02dm-%02ds"),m_correct,m_incorrect,m_incomplete,m_min,m_sec);
	file.WriteString(str);
	file.Close();
	setlocale(LC_CTYPE,pOldLocale);
	free(pOldLocale);
}


void CPDP_TEST2_2View::GetMyAns(void)
{
	CString str;
	m_edit.GetWindowText(str);
	m_myans[m_index]=str;
}


void CPDP_TEST2_2View::Begin(void)
{
	Ready();
	getData(fn);
	insertlist();
}


void CPDP_TEST2_2View::TimeSpend(void)
{
	m_endtime = GetTickCount();
	int m_min =0,m_sec = (m_endtime-m_starttime)/1000;
	while(m_sec>60)
	{
		m_min++;
		m_sec-=60;
	}
	CString str;
	Stats();
	str.Format(_T("总数:%d\n正确题数:%d\n错误题数:%d\n未完成题数:%d\n用时:%02dm-%02ds"),m_num,m_correct,m_incorrect,m_incomplete,m_min,m_sec);
	int index = fn.Find(_T(" "));
	CString title=fn.Right(fn.GetLength()-index-1);
	index = title.Find(_T("."));
	title=title.Left(index);
	MessageBox(str,title);
}


void CPDP_TEST2_2View::OnBnClickedScore()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_num==0)
	{
		MessageBox(_T("请在左侧选择题目"), _T("提醒"));
	}
	else
	{
		CString str;
		Stats();
		m_endtime = GetTickCount();
		int m_min =0,m_sec = (m_endtime-m_starttime)/1000;
		while(m_sec>60)
		{
			m_min++;
			m_sec-=60;
		}
		str.Format(_T("总数:%d\n正确题数:%d\n错误题数:%d\n未完成题数:%d\n用时:%02dm-%02ds"),m_num,m_correct,m_incorrect,m_incomplete,m_min,m_sec);
		MessageBox(str,_T("成绩"));
	}
}


void CPDP_TEST2_2View::Stats(void)
{
	// 初始化
	m_incomplete=0;
	m_incorrect=0;
	m_correct=0;
	// 统计正确题数、错误题数、未完成题数
	for (int i = 0; i < m_num; i++)
	{
		if(m_myans[i].IsEmpty())
		{
			m_incomplete++;
		}
		else
		{
			if(m_myans[i]==m_ans[i])
			{
				m_correct++;
			}
		}
	}
	m_incorrect = m_num - m_correct - m_incomplete;
}
