
// MFCApplication1.h: основной файл заголовка для приложения MFCApplication1
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMFCApplication1App:
// Сведения о реализации этого класса: MFCApplication1.cpp
//

class CMFCApplication1App : public CWinAppEx
{
public:
	CMFCApplication1App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication1App theApp;
