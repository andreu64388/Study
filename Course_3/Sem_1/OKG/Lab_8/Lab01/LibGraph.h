#pragma once
const double pi = 3.14159;

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
	CSizeD SizeD();
};

struct CMyPen
{
	int PenStyle;				// Стиль пера
	int PenWidth;				// Толщина пера 
	COLORREF PenColor;	// Цвет пера 
	CMyPen() { PenStyle = PS_SOLID; PenWidth = 1; PenColor = RGB(0, 0, 0); };
	void Set(int PS, int PW, COLORREF PC) { PenStyle = PS; PenWidth = PW; PenColor = PC; };
};

class CPlot2D
{
	CMatrix X;				// Аргумент
	CMatrix Y;				// Функция
	CMatrix K;				// Матрица пересчета коорднат
	CRect RW;					// Прямоугольник в окне
	CRectD RS;				// Прямоугольник области в МСК
	CMyPen PenLine;   // Перо для линий
	CMyPen PenAxis;   // Перо для осей
public:

	CPlot2D() { K.RedimMatrix(3, 3); };
	void SetParams(CMatrix& XX, CMatrix& YY, CRect& RWX);
	void GetWindowCoords(double xs, double ys, int &xw, int &yw);
	void SetPenLine(CMyPen& PLine);	// Перо для рисования графика
	void SetPenAxis(CMyPen& PAxis);	// Перо для осей координат
	void Draw(CDC& dc, int Ind1, int Int2);		// Рисование с самостоятельным пересчетом координат
	void DrawBezier(CDC& dc, int NT);
	void DrawLagr(CDC& dc);
};