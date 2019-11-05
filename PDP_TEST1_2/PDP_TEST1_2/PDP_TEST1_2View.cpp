
// PDP_TEST1_2View.cpp : CPDP_TEST1_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "PDP_TEST1_2.h"
#endif

#include "PDP_TEST1_2Doc.h"
#include "PDP_TEST1_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPDP_TEST1_2View

IMPLEMENT_DYNCREATE(CPDP_TEST1_2View, CView)

BEGIN_MESSAGE_MAP(CPDP_TEST1_2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_COMMAND(ID_32771, &CPDP_TEST1_2View::OnMyStart)
	ON_COMMAND(ID_32772, &CPDP_TEST1_2View::OnMyStep)
	ON_COMMAND(ID_32773, &CPDP_TEST1_2View::OnMyStop)
	ON_COMMAND(ID_32774, &CPDP_TEST1_2View::OnMyEnd)
END_MESSAGE_MAP()

// CPDP_TEST1_2View 构造/析构

CPDP_TEST1_2View::CPDP_TEST1_2View()
{
	// TODO: 在此处添加构造代码

}

CPDP_TEST1_2View::~CPDP_TEST1_2View()
{
}

BOOL CPDP_TEST1_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPDP_TEST1_2View 绘制

void CPDP_TEST1_2View::OnDraw(CDC* /*pDC*/)
{
	CPDP_TEST1_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	// 初始化
	init();
}


// CPDP_TEST1_2View 打印

BOOL CPDP_TEST1_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPDP_TEST1_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CPDP_TEST1_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CPDP_TEST1_2View 诊断

#ifdef _DEBUG
void CPDP_TEST1_2View::AssertValid() const
{
	CView::AssertValid();
}

void CPDP_TEST1_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPDP_TEST1_2Doc* CPDP_TEST1_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPDP_TEST1_2Doc)));
	return (CPDP_TEST1_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CPDP_TEST1_2View 消息处理程序


void CPDP_TEST1_2View::init()
{
	// 画基本界面--三个塔
	drawTowers();

	// 在A塔中放置初始的四个矩形
	hanoi.init();
	// 路径迭代器route值为routes的开始
	route = hanoi.routes.begin();

	// 绘制矩形
	drawRects();

	currentStep = 0;
}



void CPDP_TEST1_2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	step();
	CView::OnTimer(nIDEvent);
}


void CPDP_TEST1_2View::step(void)
{
	/*将金盘的一次移动分为三步
	1. 将要移动的金盘移动到起点塔的顶端
	2. 将要移动的金盘移动到目标塔的顶端
	3. 将要移动的金盘移动到目的位置(塔上)*/

	// currentStep模3得到当前是第几步，从而进行对应的操作
	if(currentStep % 3 == 0)
	{
		stepOne();
	}
	else if(currentStep % 3 == 1)
	{
		stepTwo();
	}
	else if(currentStep % 3 == 2)
	{
		stepThree();
	}
	currentStep++;
	
	// 刷新界面并重新绘制金盘
	refresh();
	drawRects();
}


void CPDP_TEST1_2View::drawTowers()
{
	// 画基本界面--三个塔
	for(int i = 0; i<3; i++)
	{
		// 竖线
		int x1 = 300 + 300*i, y1 = 200;
		int x2 = 300 + 300*i, y2 = 400;
		drawLine(x1 ,y1, x2, y2);

		// 塔底座
		x1 = 200 + 300*i, y1 = 400;
		x2 = 400 + 300*i, y2 = 400;
		drawLine(x1 ,y1, x2, y2);
	}
}


void CPDP_TEST1_2View::drawRects()
{
	CDC *pDC = GetDC();
	CBrush brush(RGB(236, 43, 36));// 初始化画刷
	CBrush *oldBrush = pDC->SelectObject(&brush);
	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* oldPen = pDC->SelectObject(&pen);  // 替换掉原来的pen放在oldPen里

	// 绘制每个塔上的矩形
	for(int i=1; i<=hanoi.totalA; i++)
	{
		hanoi.A[i].prePointToDraw(hanoi.ABottom, pDC);
	}
	for(int i=1; i<=hanoi.totalB; i++)
	{
		hanoi.B[i].prePointToDraw(hanoi.BBottom, pDC);
	}
	for(int i=1; i<=hanoi.totalC; i++)
	{
		hanoi.C[i].prePointToDraw(hanoi.CBottom, pDC);
	}

	// 绘制信息
	drawFont();
}


void CPDP_TEST1_2View::refresh(void)
{
	CDC *pDC = GetDC();
	CBrush brush(RGB(255, 255, 255));// 初始化画刷
	CBrush *oldBrush = pDC->SelectObject(&brush);
	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	CPen* oldPen = pDC->SelectObject(&pen);  // 替换掉原来的pen放在oldPen里

	// 用白色矩形刷新界面
	pDC->Rectangle(0,0,1000,1000);
	// 重新绘制Hanoi塔背景
	drawTowers();
	
	ReleaseDC(pDC);
}


void CPDP_TEST1_2View::stepOne(void)
{
	// 从当前步骤从取出起点和终点
	origin = route->first;
	terminal = route->second;
	// 切换到下一步
	route++;

	// 总次数+1
	hanoi.countAll++;

	// 将要移动的矩形(最高的一个)的高度序号设为9，在绘制时就会在塔顶
	// 矩形的移动次数加一
	if(origin == 'A')
	{
		hanoi.A[hanoi.totalA].setOrd(9);
		hanoi.A[hanoi.totalA].count++;
		hanoi.countA++;
	}
	else if(origin == 'B')
	{
		hanoi.B[hanoi.totalB].setOrd(9);
		hanoi.B[hanoi.totalB].count++;
		hanoi.countB++;
	}
	else if(origin == 'C')
	{
		hanoi.C[hanoi.totalC].setOrd(9);
		hanoi.C[hanoi.totalC].count++;
		hanoi.countC++;
	}
}


void CPDP_TEST1_2View::stepTwo(void)
{
	
	// 定义一个临时temp来存储要移动的矩形
	CRectangle temp(0);

	// 取出要移动的矩形，该塔的矩形数减一，在drawRects()里就不会绘制这个矩形了
	if(origin == 'A')
	{
		temp = hanoi.A[hanoi.totalA];
		hanoi.totalA--;
	}
	else if(origin == 'B')
	{
		temp = hanoi.B[hanoi.totalB];
		hanoi.totalB--;
	}
	else if(origin == 'C')
	{
		temp = hanoi.C[hanoi.totalC];
		hanoi.totalC--;
	}
	// 高度序号为9，之后绘制在目标塔顶
	temp.setOrd(9);

	// 目标塔上矩形数加一，之后绘制时就可以把移动的矩形绘制出来
	if(terminal == 'A')
	{
		hanoi.totalA++;
		hanoi.A[hanoi.totalA] = temp;
	}
	else if(terminal == 'B')
	{
		hanoi.totalB++;
		hanoi.B[hanoi.totalB] = temp;
	}
	else if(terminal == 'C')
	{
		hanoi.totalC++;
		hanoi.C[hanoi.totalC] = temp;
	}
}

void CPDP_TEST1_2View::stepThree(void)
{
	// 将要移动的矩形的高度序号设为当前塔上的矩形数，即为最上端(不是塔顶)
	if(terminal == 'A')
	{
		hanoi.A[hanoi.totalA].setOrd(hanoi.totalA);
	}
	else if(terminal == 'B')
	{
		hanoi.B[hanoi.totalB].setOrd(hanoi.totalB);
	}
	else if(terminal == 'C')
	{
		hanoi.C[hanoi.totalC].setOrd(hanoi.totalC);
	}

	// 如果执行完完整的一步之后，塔C上的矩阵数等于总的矩形数，则结束
	if(hanoi.totalC == hanoi.totalN)
	{
		OnMyEnd();
	}
}


void CPDP_TEST1_2View::OnMyStart()
{
	// TODO: 在此添加命令处理程序代码
	SetTimer(1, 300, NULL);

	// 如果C塔已满就重新初始化
	if(hanoi.totalC == hanoi.totalN)
	{
		refresh();
		init();
	}
}


void CPDP_TEST1_2View::OnMyStep()
{
	// TODO: 在此添加命令处理程序代码
	step();
}


void CPDP_TEST1_2View::OnMyStop()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
}


void CPDP_TEST1_2View::OnMyEnd()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
}


void CPDP_TEST1_2View::drawFont(void)
{
	CDC *pDC = GetDC();

	CFont font;
	font.CreatePointFont(160, TEXT("楷体"));
	pDC->SelectObject(&font);

	// 绘制次数
	CString string_one, string_two, string_three, string_totalAll;
	string_one.Format(_T("A塔上发生的移动次数: %d"), hanoi.countA);
	pDC->TextOutW(200, 420, string_one);
	string_two.Format(_T("B塔上发生的移动次数: %d"), hanoi.countB);
	pDC->TextOutW(500, 420, string_two);
	string_three.Format(_T("C塔上发生的移动次数: %d"), hanoi.countC);
	pDC->TextOutW(800, 420, string_three);
	string_totalAll.Format(_T("总的移动次数: %d"), hanoi.countAll);
	pDC->TextOutW(500, 120, string_totalAll);

	ReleaseDC(pDC);
}


void CPDP_TEST1_2View::drawLine(int x1, int y1, int x2, int y2)
{
	CDC *pDC = GetDC();
	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* oldPen = pDC->SelectObject(&pen);  // 替换掉原来的pen放在oldPen里

	pDC->MoveTo(x1, y1);
	pDC->LineTo(x2, y2);

	ReleaseDC(pDC);
}
