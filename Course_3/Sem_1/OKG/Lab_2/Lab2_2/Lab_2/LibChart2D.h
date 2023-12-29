#pragma once
#define LIBGRAPH 1
#include "pch.h"


struct CSizeD
{
	double cx;
	double cy;
};

struct CRectD
{
	double left;
	double top;
	double right;
	double bottom;
	CRectD() { left = top = right = bottom = 0; };
	CRectD(double l, double t, double r, double b);
	void SetRectD(double l, double t, double r, double b);
	CSizeD SizeD();	// Возвращает размеры(ширина, высота) прямоугольника 
};


struct CMyPen
{
	int PenStyle;		// Стиль пера
	int PenWidth;		// Толщина пера 
	COLORREF PenColor;	// Цвет пера 
	CMyPen() { PenStyle = PS_SOLID; PenWidth = 1; PenColor = RGB(0, 0, 0); };
	void Set(int PS, int PW, COLORREF PC)
	{
		PenStyle = PS; PenWidth = PW; PenColor = PC;
	};
};


CMatrix SpaceToWindow(CRectD& rs, CRect& rw);
// Возвращает матрицу пересчета координат из мировых в оконные
// rs - область в мировых координатах - double
// rw - область в оконных координатах - int


class CPlot2D
{
	CMatrix X;				// Аргумент
	CMatrix Y;				// Функция
	CMatrix K;				// Матрица пересчета координат
	CRect RW;				// Прямоугольник в окне
	CRectD RS;				// Прямоугольник области в МСК
	CMyPen PenLine;			// Перо для линий
	CMyPen PenAxis;			// Перо для осей
public:
	CPlot2D() { K.RedimMatrix(3, 3); };			//Конструктор по умолчанию
	void SetParams(CMatrix& XX, CMatrix& YY, CRect& RWX);	// Установка параметров графика
	void SetWindowRect(CRect& RWX);				//Установка области в окне для отображения графика
	void GetWindowCoords(double xs, double ys, int& xw, int& yw);	//Пересчет координаты точки из МСК в оконную СК
	void SetPenLine(CMyPen& PLine);				// Перо для рисования графика
	void SetPenAxis(CMyPen& PAxis);				// Перо для осей координат
	void Draw(CDC& dc, int Ind1, int Int2);		// Рисование с самостоятельным пересчетом координат
};



