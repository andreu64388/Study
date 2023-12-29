
// ChildView.h: интерфейс класса CChildView
//


#pragma once


// Окно CChildView

class CChildView : public CWnd
{
// Создание
public:
	CChildView();

// Атрибуты
public:
	int Index;
	CMatrix X, Y;			// Векторы координат
	CRect RW;				// Прямоугольник в окне
	CRectD RS;				// Прямоугольник области в МСК
	CPlot2D Graph;			// График функции
	CMyPen PenLine,			// Перо для линий
		PenAxis;			// Перо для осей
// Операции
public:
	double MyF1(double x);	// задаем функции
	double MyF2(double x);
	double MyF12(double x);
// Переопределение
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Реализация
public:
	virtual ~CChildView();

	// Созданные функции схемы сообщений
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	// действия при выборе пункта меню
	afx_msg void OnTestsF1();
	afx_msg void OnTestsF2();
	afx_msg void OnTestsF12();
};

