#pragma once
class CConsume
{
public:
	CConsume(void);
	~CConsume(void);
	// ���
	int money;
	// ����
	CString name;
	// ��ɫ
	int R,G,B;
	// ���
	int ord;
	// ͼ��id
	int id;

	// ��ʼ��
	virtual void Init(void) = 0;
	void OnDraw(CDC* pDC);
	void OnFont(CDC* pDC);
	void OnIcon(int x,int y,CDC* pDC);
};

