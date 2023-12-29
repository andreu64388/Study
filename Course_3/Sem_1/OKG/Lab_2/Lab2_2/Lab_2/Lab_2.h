
// Lab_2.h: основной файл заголовка для приложения Lab_2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CLab2App:
// Сведения о реализации этого класса: Lab_2.cpp
//

class CLab2App : public CWinApp
{
public:
	CLab2App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab2App theApp;
