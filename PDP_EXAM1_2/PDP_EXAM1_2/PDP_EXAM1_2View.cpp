
// PDP_EXAM1_2View.cpp : CPDP_EXAM1_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "PDP_EXAM1_2.h"
#endif

#include "PDP_EXAM1_2Doc.h"
#include "PDP_EXAM1_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPDP_EXAM1_2View

IMPLEMENT_DYNCREATE(CPDP_EXAM1_2View, CView)

BEGIN_MESSAGE_MAP(CPDP_EXAM1_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPDP_EXAM1_2View ����/����

CPDP_EXAM1_2View::CPDP_EXAM1_2View()
{
	// TODO: �ڴ˴���ӹ������

}

CPDP_EXAM1_2View::~CPDP_EXAM1_2View()
{
}

BOOL CPDP_EXAM1_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPDP_EXAM1_2View ����

void CPDP_EXAM1_2View::OnDraw(CDC* /*pDC*/)
{
	CPDP_EXAM1_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CDC *pDC = GetDC();
	barchart.init();
	barchart.OnDraw(pDC);
}


// CPDP_EXAM1_2View ��ӡ

BOOL CPDP_EXAM1_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CPDP_EXAM1_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CPDP_EXAM1_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CPDP_EXAM1_2View ���

#ifdef _DEBUG
void CPDP_EXAM1_2View::AssertValid() const
{
	CView::AssertValid();
}

void CPDP_EXAM1_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPDP_EXAM1_2Doc* CPDP_EXAM1_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPDP_EXAM1_2Doc)));
	return (CPDP_EXAM1_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CPDP_EXAM1_2View ��Ϣ�������
