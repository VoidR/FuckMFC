#pragma once
class CRectangle
{
public:
	CRectangle(void);
	~CRectangle(void);
	CRectangle(int w);
	CRectangle(int w, int n);

	// ���ε����ϽǺ����½�
	CPoint letfTop, rightBottom;  
	// ���εĿ��һ��
	int width;  
	// ���εĸ�
	int height;  
	// �þ���ĸ߶����
	int ord;  
	// �þ��ε��ƶ�����
	int count;

	// ���ƾ���
	void onDraw(CDC* pDC); 
	// ���øþ��εĸ߶����
	void setOrd(int t);  
	// ���þ��ε����ϽǺ����½Ǻ���ƾ���
	void prePointToDraw(CPoint now, CDC* pDC);  
};

