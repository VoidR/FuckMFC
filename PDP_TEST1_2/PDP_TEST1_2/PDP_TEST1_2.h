
// PDP_TEST1_2.h : PDP_TEST1_2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CPDP_TEST1_2App:
// �йش����ʵ�֣������ PDP_TEST1_2.cpp
//

class CPDP_TEST1_2App : public CWinApp
{
public:
	CPDP_TEST1_2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPDP_TEST1_2App theApp;
