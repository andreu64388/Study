#include "stdafx.h"

CRectD::CRectD(double l, double t, double r, double b)
{
	left = l;
	top = t;
	right = r;
	bottom = b;
}

void CPlot2D::SetPenLine(CMyPen& PLine)
// Установка параметров пера для линии графика
{
	PenLine.PenStyle = PLine.PenStyle;
	PenLine.PenWidth = PLine.PenWidth;
	PenLine.PenColor = PLine.PenColor;
}

void CPlot2D::DrawBezier(CDC& dc, int NT)
// Рисует кривую Безье по набору опорных точек
// dc - ссылка на класс CDC MFC
// NT - число отрезков по параметру t
{
	double xs, ys;  // мировые  координаты точки
	int xw, yw;     // оконные координаты точки
	CPen MyPen(PenLine.PenStyle, PenLine.PenWidth, PenLine.PenColor);
	CPen* pOldPen = dc.SelectObject(&MyPen);
	double dt = 1.0 / NT;
	int N = X.rows();
	CMatrix RX(N), RY(N);
	xs = X(0);   ys = Y(0);
	GetWindowCoords(xs, ys, xw, yw);
	dc.MoveTo(xw, yw);
	for (int k = 1; k <= NT; k++)
	{
		double t = k * dt;
		for (int i = 0; i < N; i++)
		{
			RX(i) = X(i);
			RY(i) = Y(i);
		}
		for (int j = N - 1; j > 0; j--)
		{
			for (int i = 0; i < j; i++)
			{
				RX(i) = RX(i) + t * (RX(i + 1) - RX(i));
				RY(i) = RY(i) + t * (RY(i + 1) - RY(i));
			}
		}
		xs = RX(0);   ys = RY(0);
		GetWindowCoords(xs, ys, xw, yw);
		dc.LineTo(xw, yw);
	}
	dc.SelectObject(pOldPen);
}




double Lagr(CMatrix& X, CMatrix& Y, double x, int size)
{
	double lagrange_pol = 0;
	double basics_pol;

	for (int i = 0; i < size; i++)
	{
		basics_pol = 1;
		for (int j = 0; j < size; j++)
		{
			if (j == i)
				continue;
			basics_pol *= (x - X(j)) / (X(i) - X(j));
		}
		lagrange_pol += basics_pol * Y(i);
	}
	return lagrange_pol;
}




void CPlot2D::DrawLagr(CDC& dc)
{
	double dx = pi / 4;
	double xL = 0;
	double xH = pi;
	int N = (xH - xL) / dx;
	dx = 0.2;
	int NL = (xH - xL) / dx;
	CMatrix XL(NL + 1);
	CMatrix YL(NL + 1);

	for (int i = 0; i <= NL; i++)
	{
		XL(i) = xL + i * dx;
		YL(i) = Lagr(X, Y, XL(i), N + 1);
	}

	double xs, ys;
	int xw, yw;
	xs = XL(0); ys = YL(0);
	GetWindowCoords(xs, ys, xw, yw);			// координаты начальной точки графика в ОСК
	CPen MyPen(PenLine.PenStyle, PenLine.PenWidth, PenLine.PenColor);
	CPen* pOldPen = dc.SelectObject(&MyPen);
	dc.MoveTo(xw, yw);							// Перо в начальную точка для рисования графика
	for (int i = 1; i < XL.rows(); i++)
	{
		xs = XL(i); ys = YL(i);
		GetWindowCoords(xs, ys, xw, yw);		// координаты начальной точки графика с номером i в ОСК
		dc.LineTo(xw, yw);
	}
	dc.SelectObject(pOldPen);
}

void CPlot2D::GetWindowCoords(double xs, double ys, int &xw, int &yw)
// Пересчитывает координаты точки из МСК в оконную
// xs - x- кордината точки в МСК
// ys - y- кордината точки в МСК
// xw - x- кордината точки в оконной СК
// yw - y- кордината точки в оконной СК

{
	CMatrix V(3), W(3);
	V(2) = 1;
	V(0) = xs;
	V(1) = ys;
	W = K * V;
	xw = (int)W(0);
	yw = (int)W(1);
}

void CPlot2D::SetPenAxis(CMyPen& PAxis)
// Установка параметров пера для линий осей 
{
	PenAxis.PenStyle = PAxis.PenStyle;
	PenAxis.PenWidth = PAxis.PenWidth;
	PenAxis.PenColor = PAxis.PenColor;
}

void CPlot2D::Draw(CDC& dc, int Ind1, int Ind2)
// Рисует график в режиме MM_TEXT - собственный пересчет координат
// dc - ссылка на класс CDC MFC
// Ind1=1/0 - рисовать/не рисовать рамку
// Ind2=1/0 - рисовать/не рисовать оси координат
{
	double xs, ys;  // мировые  координаты точки
	int xw, yw;     // оконные координаты точки
	if (Ind1 == 1)dc.Rectangle(RW);								 // Рамка в окне
	if (Ind2 == 1)	// Если нужны оси...
	{//***
		CPen MyPen(PenAxis.PenStyle, PenAxis.PenWidth, PenAxis.PenColor);
		CPen* pOldPen = dc.SelectObject(&MyPen);
		if (RS.left*RS.right < 0)							// Нужна Ось Y
		{
			xs = 0;  ys = RS.top;           // Точка (0,y_max) в МСК
			GetWindowCoords(xs, ys, xw, yw); // (xw,yw) -точка (0,y_max) в ОСК		
			dc.MoveTo(xw, yw);		      // Перо в точку (0,y_max)

			xs = 0;  ys = RS.bottom;        // Точка (0,y_min) в МСК
			GetWindowCoords(xs, ys, xw, yw); // (xw,yw) -точка (0,y_min) в ОСК
			dc.LineTo(xw, yw);		      // Линия (0,y_max) - (0,y_min) - Ось Y
		}

		if (RS.top*RS.bottom < 0)							// Нужна Ось X
		{
			xs = RS.left;  ys = 0;           // (xs,ys) - точка (x_min,0) в МСК
			GetWindowCoords(xs, ys, xw, yw); // (xw,yw) -точка (x_min,0) в ОСК
			dc.MoveTo(xw, yw);		         // Перо в точку (x_min,0)

			xs = RS.right;  ys = 0;          // (xs,ys) - точка (x_max,0) в МСК
			GetWindowCoords(xs, ys, xw, yw); // (xw,yw) -точка (x_max,0) в ОСК
			dc.LineTo(xw, yw);		         // Линия (x_min,0) - (x_max,0) - Ось X
		}
		dc.SelectObject(pOldPen);

	}

	xs = X(0); ys = Y(0);
	GetWindowCoords(xs, ys, xw, yw); // координаты начальной точки графика в ОСК
	CPen MyPen(PenLine.PenStyle, PenLine.PenWidth, PenLine.PenColor);
	CPen* pOldPen = dc.SelectObject(&MyPen);
	dc.MoveTo(xw, yw);        // Перо в начальную точка для рисования графика
	for (int i = 1; i < X.rows(); i++)
	{
		xs = X(i); ys = Y(i);
		GetWindowCoords(xs, ys, xw, yw); // координаты начальной точки графика с номером i в ОСК
		dc.LineTo(xw, yw);
	}
	dc.SelectObject(pOldPen);
}

void CRectD::SetRectD(double l, double t, double r, double b)
{
	left = l;
	top = t;
	right = r;
	bottom = b;
}

CSizeD CRectD::SizeD()
{
	CSizeD cz;
	cz.cx = fabs(right - left);	// Ширина прямоугольной области
	cz.cy = fabs(top - bottom);	// Высота прямоугольной области
	return cz;
}

CMatrix SpaceToWindow(CRectD& RS, CRect& RW)
// Функция обнавлена
// Возвращает матрицу пересчета координат из мировых в оконные
// RS - область в мировых координатах - double
// RW - область в оконных координатах - int
{
	CMatrix M(3, 3);
	CSize sz = RW.Size();	 // Размер области в ОКНЕ
	int dwx = sz.cx;	     // Ширина
	int dwy = sz.cy;	     // Высота
	CSizeD szd = RS.SizeD(); // Размер области в МИРОВЫХ координатах

	double dsx = szd.cx;    // Ширина в мировых координатах
	double dsy = szd.cy;    // Высота в мировых координатах

	double kx = (double)dwx / dsx;   // Масштаб по x
	double ky = (double)dwy / dsy;   // Масштаб по y


	M(0, 0) = kx;  M(0, 1) = 0;    M(0, 2) = (double)RW.left - kx * RS.left;			// Обновлено
	M(1, 0) = 0;   M(1, 1) = -ky;  M(1, 2) = (double)RW.bottom + ky * RS.bottom;		// Обновлено
	M(2, 0) = 0;   M(2, 1) = 0;    M(2, 2) = 1;
	return M;
}

void CPlot2D::SetParams(CMatrix& XX, CMatrix& YY, CRect& RWX)
// XX - вектор данных по X 
// YY - вектор данных по Y 
// RWX - область в окне 
{
	int nRowsX = XX.rows();
	int nRowsY = YY.rows();
	X.RedimMatrix(nRowsX);
	Y.RedimMatrix(nRowsY);
	X = XX;
	Y = YY;
	double x_max = X.MaxElement();
	double x_min = X.MinElement();
	double y_max = Y.MaxElement();
	double y_min = Y.MinElement();
	RS.SetRectD(x_min, y_max, x_max, y_min);				// Область в мировой СК
	RW.SetRect(RWX.left, RWX.top, RWX.right, RWX.bottom);	// Область в окне
	K = SpaceToWindow(RS, RW);								// Матрица пересчета координат
}
