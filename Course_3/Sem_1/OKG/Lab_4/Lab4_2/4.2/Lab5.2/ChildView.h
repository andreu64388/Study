#pragma once

#include "CMatrix.h"
#include "LibGraph.h"
#include "CPyramid.h"

// ���� CChildView

class CChildView : public CWnd
{
	// ��������
public:
	CChildView();

	// ��������
public:
	CPyramid Pyramid;
	CRect RectWindow;
	CMatrix Viewport;
	int Mode;

	// ��������
public:

	// ���������������
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	// ����������
public:
	virtual ~CChildView();

	// ��������� ������� ����� ���������
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPyramidDraw();
	afx_msg void OnPyramidDrawxray();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};