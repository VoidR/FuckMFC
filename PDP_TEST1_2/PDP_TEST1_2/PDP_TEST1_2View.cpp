
// PDP_TEST1_2View.cpp : CPDP_TEST1_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_COMMAND(ID_32771, &CPDP_TEST1_2View::OnMyStart)
	ON_COMMAND(ID_32772, &CPDP_TEST1_2View::OnMyStep)
	ON_COMMAND(ID_32773, &CPDP_TEST1_2View::OnMyStop)
	ON_COMMAND(ID_32774, &CPDP_TEST1_2View::OnMyEnd)
END_MESSAGE_MAP()

// CPDP_TEST1_2View ����/����

CPDP_TEST1_2View::CPDP_TEST1_2View()
{
	// TODO: �ڴ˴���ӹ������

}

CPDP_TEST1_2View::~CPDP_TEST1_2View()
{
}

BOOL CPDP_TEST1_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPDP_TEST1_2View ����

void CPDP_TEST1_2View::OnDraw(CDC* /*pDC*/)
{
	CPDP_TEST1_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	// ��ʼ��
	init();
}


// CPDP_TEST1_2View ��ӡ

BOOL CPDP_TEST1_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CPDP_TEST1_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CPDP_TEST1_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CPDP_TEST1_2View ���

#ifdef _DEBUG
void CPDP_TEST1_2View::AssertValid() const
{
	CView::AssertValid();
}

void CPDP_TEST1_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPDP_TEST1_2Doc* CPDP_TEST1_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPDP_TEST1_2Doc)));
	return (CPDP_TEST1_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CPDP_TEST1_2View ��Ϣ�������


void CPDP_TEST1_2View::init()
{
	// ����������--������
	drawTowers();

	// ��A���з��ó�ʼ���ĸ�����
	hanoi.init();
	// ·��������routeֵΪroutes�Ŀ�ʼ
	route = hanoi.routes.begin();

	// ���ƾ���
	drawRects();

	currentStep = 0;
}



void CPDP_TEST1_2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	step();
	CView::OnTimer(nIDEvent);
}


void CPDP_TEST1_2View::step(void)
{
	/*�����̵�һ���ƶ���Ϊ����
	1. ��Ҫ�ƶ��Ľ����ƶ���������Ķ���
	2. ��Ҫ�ƶ��Ľ����ƶ���Ŀ�����Ķ���
	3. ��Ҫ�ƶ��Ľ����ƶ���Ŀ��λ��(����)*/

	// currentStepģ3�õ���ǰ�ǵڼ������Ӷ����ж�Ӧ�Ĳ���
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
	
	// ˢ�½��沢���»��ƽ���
	refresh();
	drawRects();
}


void CPDP_TEST1_2View::drawTowers()
{
	// ����������--������
	for(int i = 0; i<3; i++)
	{
		// ����
		int x1 = 300 + 300*i, y1 = 200;
		int x2 = 300 + 300*i, y2 = 400;
		drawLine(x1 ,y1, x2, y2);

		// ������
		x1 = 200 + 300*i, y1 = 400;
		x2 = 400 + 300*i, y2 = 400;
		drawLine(x1 ,y1, x2, y2);
	}
}


void CPDP_TEST1_2View::drawRects()
{
	CDC *pDC = GetDC();
	CBrush brush(RGB(236, 43, 36));// ��ʼ����ˢ
	CBrush *oldBrush = pDC->SelectObject(&brush);
	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* oldPen = pDC->SelectObject(&pen);  // �滻��ԭ����pen����oldPen��

	// ����ÿ�����ϵľ���
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

	// ������Ϣ
	drawFont();
}


void CPDP_TEST1_2View::refresh(void)
{
	CDC *pDC = GetDC();
	CBrush brush(RGB(255, 255, 255));// ��ʼ����ˢ
	CBrush *oldBrush = pDC->SelectObject(&brush);
	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	CPen* oldPen = pDC->SelectObject(&pen);  // �滻��ԭ����pen����oldPen��

	// �ð�ɫ����ˢ�½���
	pDC->Rectangle(0,0,1000,1000);
	// ���»���Hanoi������
	drawTowers();
	
	ReleaseDC(pDC);
}


void CPDP_TEST1_2View::stepOne(void)
{
	// �ӵ�ǰ�����ȡ�������յ�
	origin = route->first;
	terminal = route->second;
	// �л�����һ��
	route++;

	// �ܴ���+1
	hanoi.countAll++;

	// ��Ҫ�ƶ��ľ���(��ߵ�һ��)�ĸ߶������Ϊ9���ڻ���ʱ�ͻ�������
	// ���ε��ƶ�������һ
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
	
	// ����һ����ʱtemp���洢Ҫ�ƶ��ľ���
	CRectangle temp(0);

	// ȡ��Ҫ�ƶ��ľ��Σ������ľ�������һ����drawRects()��Ͳ���������������
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
	// �߶����Ϊ9��֮�������Ŀ������
	temp.setOrd(9);

	// Ŀ�����Ͼ�������һ��֮�����ʱ�Ϳ��԰��ƶ��ľ��λ��Ƴ���
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
	// ��Ҫ�ƶ��ľ��εĸ߶������Ϊ��ǰ���ϵľ���������Ϊ���϶�(��������)
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

	// ���ִ����������һ��֮����C�ϵľ����������ܵľ������������
	if(hanoi.totalC == hanoi.totalN)
	{
		OnMyEnd();
	}
}


void CPDP_TEST1_2View::OnMyStart()
{
	// TODO: �ڴ���������������
	SetTimer(1, 300, NULL);

	// ���C�����������³�ʼ��
	if(hanoi.totalC == hanoi.totalN)
	{
		refresh();
		init();
	}
}


void CPDP_TEST1_2View::OnMyStep()
{
	// TODO: �ڴ���������������
	step();
}


void CPDP_TEST1_2View::OnMyStop()
{
	// TODO: �ڴ���������������
	KillTimer(1);
}


void CPDP_TEST1_2View::OnMyEnd()
{
	// TODO: �ڴ���������������
	KillTimer(1);
}


void CPDP_TEST1_2View::drawFont(void)
{
	CDC *pDC = GetDC();

	CFont font;
	font.CreatePointFont(160, TEXT("����"));
	pDC->SelectObject(&font);

	// ���ƴ���
	CString string_one, string_two, string_three, string_totalAll;
	string_one.Format(_T("A���Ϸ������ƶ�����: %d"), hanoi.countA);
	pDC->TextOutW(200, 420, string_one);
	string_two.Format(_T("B���Ϸ������ƶ�����: %d"), hanoi.countB);
	pDC->TextOutW(500, 420, string_two);
	string_three.Format(_T("C���Ϸ������ƶ�����: %d"), hanoi.countC);
	pDC->TextOutW(800, 420, string_three);
	string_totalAll.Format(_T("�ܵ��ƶ�����: %d"), hanoi.countAll);
	pDC->TextOutW(500, 120, string_totalAll);

	ReleaseDC(pDC);
}


void CPDP_TEST1_2View::drawLine(int x1, int y1, int x2, int y2)
{
	CDC *pDC = GetDC();
	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* oldPen = pDC->SelectObject(&pen);  // �滻��ԭ����pen����oldPen��

	pDC->MoveTo(x1, y1);
	pDC->LineTo(x2, y2);

	ReleaseDC(pDC);
}
