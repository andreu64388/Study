#pragma once
#include "resource.h"
#include "CMatrix.h"
#include "LibGraph.h"
#include "LibPyramid.h"


class CMainWnd : public CFrameWnd
{
private:
	CPyramid PIR;  // Пирамида
	CRect WinRect; // Область в окне
	CMatrix PView; // Точка наблюдения в сферической СК
	CMatrix PView2;
	int Index;
	CMenu menu;
	DECLARE_MESSAGE_MAP()
	int OnCreate(LPCREATESTRUCT);

public:
	CMainWnd::CMainWnd() 
	{
		Create(NULL, L"Lab5", WS_OVERLAPPEDWINDOW, CRect(10, 10, 700, 800), NULL, NULL);
		Index = 0;
		PView.RedimMatrix(3);
		PView2.RedimMatrix(3);
		PView(0) = 10; PView(1) = 0; PView(2) = 90;
		PView2(0) = 15; PView2(1) = 35; PView2(2) = 65;
	}

	void OnPaint();
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnSize(UINT nType, int cx, int cy);
	void OnPyramid1();
	void OnPyramid2();
	void OnPuramid3();
	void OnPuramid4();
	void Exit();
};

BEGIN_MESSAGE_MAP(CMainWnd, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
	ON_COMMAND(ID_30002, OnPyramid1)
	ON_COMMAND(ID_30003, OnPyramid2)
	ON_COMMAND(ID_30004, OnPuramid3)
	ON_COMMAND(ID_30005, OnPuramid4)
	ON_COMMAND(ID_EXIT, Exit)
END_MESSAGE_MAP()

int CMainWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	menu.LoadMenu(IDR_MENU1); // Загрузить меню из файла ресурса
	SetMenu(&menu); // Установить меню
	return 0;
}


void CMainWnd::OnPaint()
{
	CPaintDC dc(this);
	if (Index == 3)
		PIR.ColorDraw(dc, PView, WinRect, RGB(128, 236, 158)); // цвет пирамиды
	if (Index == 4)
		PIR.DrawLightSphere(dc, 10, PView, PView2, WinRect, COLORREF(RGB(128, 236, 158)), 1);
}

void CMainWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if ((Index == 1) || (Index == 2) || (Index == 3)||(Index==4))
	{
		switch (nChar)
		{
		case VK_UP:
		{
			double d = PView(2) - 3;
			if (d >= 0)PView(2) = d;
			break;
		}
		case VK_DOWN:
		{
			double d = PView(2) + 3;
			if (d <= 180)
				PView(2) = d;
			break;
		}
		case VK_LEFT:
		{
			double d = PView(1) - 3;  
			if (d >= -180)
				PView(1) = d;
			else
				PView(1) = d + 360;
			break;
		}
		case VK_RIGHT:
		{	
			double d = PView(1) + 3;
			if (d <= 180)
				PView(1) = d;
			else
				PView(1) = d - 360;
			break;
		}
		}
		Invalidate();
	}
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
void CMainWnd::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	WinRect.SetRect(100, 100, cx - 100, cy - 100);
}
void CMainWnd::OnPyramid1()
{
	Index = 1;
	Invalidate();
}
void CMainWnd::OnPyramid2()
{
	Index = 2;
	Invalidate();
}
void CMainWnd::OnPuramid3()
{
	Index = 3;
	Invalidate();
}
void CMainWnd::OnPuramid4()
{
	Index = 4;
	Invalidate();
}
void CMainWnd::Exit()
{
	DestroyWindow();
}