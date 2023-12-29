#pragma once
class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance() // Стандартная инициализация
	{
		m_pMainWnd = new CMainWnd(); // Создать класс окна
		ASSERT(m_pMainWnd); // Проверка его правильности
		m_pMainWnd->ShowWindow(m_nCmdShow); // Показать окно
		m_pMainWnd->UpdateWindow(); // Обновить окно
		return TRUE;
	}
};