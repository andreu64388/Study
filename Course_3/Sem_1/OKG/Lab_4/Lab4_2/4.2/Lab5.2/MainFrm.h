
// MainFrm.h : ��������� ������ CMainFrame
//

#pragma once
#include "ChildView.h"

class CMainFrame : public CFrameWnd
{

public:
	CMainFrame();
protected:
	DECLARE_DYNAMIC(CMainFrame)

	// ��������
public:

	// ��������
public:

	// ���������������
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

	// ����������
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ���������� ����� ������ ��������� ����������
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	CChildView    m_wndView;

	// ��������� ������� ����� ���������
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()

};


