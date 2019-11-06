#pragma once
class CConsume
{
public:
	CConsume(void);
	~CConsume(void);
	// 金额
	int money;
	// 名字
	CString name;
	// 颜色
	int R,G,B;
	// 序号
	int ord;
	// 图标id
	int id;

	// 初始化
	virtual void Init(void) = 0;
	void OnDraw(CDC* pDC);
	void OnFont(CDC* pDC);
	void OnIcon(int x,int y,CDC* pDC);
};

