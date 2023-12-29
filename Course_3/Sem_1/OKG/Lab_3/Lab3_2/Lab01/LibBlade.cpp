#include "stdafx.h"

CRectD::CRectD(double l, double t, double r, double b)
{
	left = l;
	top = t;
	right = r;
	bottom = b;
}
//------------------------------------------------------------------------------
void CRectD::SetRectD(double l, double t, double r, double b)
{
	left = l;
	top = t;
	right = r;
	bottom = b;
}

//------------------------------------------------------------------------------
CSizeD CRectD::SizeD()
{
	CSizeD cz;
	cz.cx = fabs(right - left);	// Ширина прямоугольной области
	cz.cy = fabs(top - bottom);	// Высота прямоугольной области
	return cz;
}

//----------------------------------------------------------------------------

CMatrix CreateTranslate2D(double dx, double dy)
// Формирует матрицу для преобразования координат объекта при его смещении 
// на dx по оси X и на dy по оси Y в фиксированной системе координат
// --- ИЛИ ---
// Формирует матрицу для преобразования координат объекта при смещении начала
// системы координат на -dx оси X и на -dy по оси Y при фиксированном положении объекта 
{
	CMatrix TM(3, 3);
	TM(0, 0) = 1; TM(0, 2) = dx;
	TM(1, 1) = 1;  TM(1, 2) = dy;
	TM(2, 2) = 1;
	return TM;
}

//------------------------------------------------------------------------------------
CMatrix CreateRotate2D(double fi)
// Формирует матрицу для преобразования координат объекта при его повороте
// на угол fi (при fi>0 против часовой стрелки)в фиксированной системе координат
// --- ИЛИ ---
// Формирует матрицу для преобразования координат объекта при повороте начала
// системы координат на угол -fi при фиксированном положении объекта 
// fi - угол в градусах
{
	double fg = fmod(fi, 360.0);
	double ff = (fg / 180.0) * pi; // Перевод в радианы
	CMatrix RM(3, 3);
	RM(0, 0) = cos(ff); RM(0, 1) = -sin(ff);
	RM(1, 0) = sin(ff);  RM(1, 1) = cos(ff);
	RM(2, 2) = 1;
	return RM;
}


//------------------------------------------------------------------------------

CMatrix SpaceToWindow(CRectD& RS, CRect& RW)
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

	M(0, 0) = kx;  M(0, 1) = 0;    M(0, 2) = (double)RW.left - kx * RS.left;
	M(1, 0) = 0;   M(1, 1) = -ky;  M(1, 2) = (double)RW.bottom + ky * RS.bottom;
	M(2, 0) = 0;   M(2, 1) = 0;    M(2, 2) = 1;
	return M;
}

//------------------------------------------------------------------------------

void SetMyMode(CDC& dc, CRectD& RS, CRect& RW)
// Устанавливает режим отображения MM_ANISOTROPIC и его параметры
// dc - ссылка на класс CDC MFC
// RS -  область в мировых координатах - int
// RW -	 Область в оконных координатах - int  
{
	double dsx = RS.right - RS.left;
	double dsy = RS.top - RS.bottom;
	double xsL = RS.left;
	double ysL = RS.bottom;

	int dwx = RW.right - RW.left;
	int dwy = RW.bottom - RW.top;
	int xwL = RW.left;
	int ywH = RW.bottom;
	//CreateTranslate2D();
	dc.SetMapMode(MM_ANISOTROPIC);
	dc.SetWindowExt((int)dsx, (int)dsy);
	dc.SetViewportExt(dwx, -dwy);
	dc.SetWindowOrg((int)xsL, (int)ysL);
	dc.SetViewportOrg(xwL, ywH);
}

CBlade::CBlade()            
{
	double rS = 30;//radius of sun
	double RoE = 10 * rS;//radius of ellipses
	RS.SetRectD(-RoE, RoE, RoE, -RoE);					// Область системы в мировых координатах
	RW.SetRect(0, 0, 600, 600);					// Область в окне
	MainPoint.SetRect(-rS, rS, rS, -rS);
	FirstTop.SetRect(-5, 5, 5, -5);
	SecondTop.SetRect(-5, 5, 5, -5);
	FirstBootom.SetRect(-5, 5, 5, -5);
	SecondBootom.SetRect(-5, 5, 5, -5);
	EarthOrbit.SetRect(-RoE, RoE, RoE, -RoE);	
	fiSB = 215;
	fiFB = 205;			
	fiST = 25;			
	fiFT = 35;//угл положение для FT
	wPoint = 100;
	dt = 1;
	FTCoords.RedimMatrix(3);
	STCoords.RedimMatrix(3);
	FBCoords.RedimMatrix(3);
	SBCoords.RedimMatrix(3);
}

void CBlade::SetNewCoords()
//Вычисляет новые координаты планет в СК Солнца через интервал времени dt
{


	double RoV = (EarthOrbit.right - EarthOrbit.left) / 2;
	double ff = (fiFT / 90.0) * pi;
	double x = RoV * cos(ff);
	double y = RoV * sin(ff);
	FTCoords(0) = x;
	FTCoords(1) = y;
	FTCoords(2) = 1;

	fiFT += wPoint * dt;
	CMatrix P = CreateRotate2D(fiFT);
	FTCoords = P * FTCoords;

	RoV = (EarthOrbit.right - EarthOrbit.left) / 2;
	ff = (fiST / 90.0) * pi;
	x = RoV * cos(ff);
	y = RoV * sin(ff);
	STCoords(0) = x;
	STCoords(1) = y;
	STCoords(2) = 1;

	fiST += wPoint * dt;
	P = CreateRotate2D(fiST);
	STCoords = P * STCoords;

	RoV = (EarthOrbit.right - EarthOrbit.left) / 2;
	ff = (fiFB / 90.0) * pi;
	x = RoV * cos(ff);
	y = RoV * sin(ff);
	FBCoords(0) = x;
	FBCoords(1) = y;
	FBCoords(2) = 1;

	fiFB += wPoint * dt;
	P = CreateRotate2D(fiFB);
	FBCoords = P * FBCoords;

	RoV = (EarthOrbit.right - EarthOrbit.left) / 2;
	ff = (fiSB / 90.0) * pi;
	x = RoV * cos(ff);
	y = RoV * sin(ff);
	SBCoords(0) = x;
	SBCoords(1) = y;
	SBCoords(2) = 1;

	fiSB += wPoint * dt;
	P = CreateRotate2D(fiSB);
	SBCoords = P * SBCoords;




}


void CBlade::Draw(CDC& dc)
{
	CBrush SBrush, EBrush, MBrush, VBrush, * pOldBrush;
	CRect R;

	SBrush.CreateSolidBrush(RGB(0, 0, 155));//brush for sun
	EBrush.CreateSolidBrush(RGB(0, 0, 155));//brush for planets
	MBrush.CreateSolidBrush(RGB(0, 255, 0));
	VBrush.CreateSolidBrush(RGB(128, 64, 64));

	dc.SelectStockObject(NULL_BRUSH);		
	dc.Ellipse(EarthOrbit);					

	// Рисуем центр точку

	//
	int d = FirstTop.right;				// FT
	R.SetRect(FTCoords(0) - d, FTCoords(1) + d, FTCoords(0) + d, FTCoords(1) - d);
	dc.SelectObject(&EBrush);
	dc.Ellipse(R);
	//
	d = SecondTop.right;				// ST
	R.SetRect(STCoords(0) - d, STCoords(1) + d, STCoords(0) + d, STCoords(1) - d);
	dc.SelectObject(&EBrush);
	dc.Ellipse(R);
	//
	d = FirstBootom.right;				// FB
	R.SetRect(FBCoords(0) - d, FBCoords(1) + d, FBCoords(0) + d, FBCoords(1) - d);
	dc.SelectObject(&EBrush);
	dc.Ellipse(R);
	//
	d = SecondBootom.right;				// SB
	R.SetRect(SBCoords(0) - d, SBCoords(1) + d, SBCoords(0) + d, SBCoords(1) - d);
	dc.SelectObject(&EBrush);
	dc.Ellipse(R);


	dc.MoveTo(0, 0);
	dc.LineTo(FTCoords(0), FTCoords(1));
	DrawTriangle(FTCoords, STCoords, dc);
	DrawTriangle(FBCoords, SBCoords, dc);
	pOldBrush = dc.SelectObject(&SBrush);	// Цвет красный
	dc.Ellipse(MainPoint);  
	dc.SelectObject(pOldBrush);				//Восстанавливаем контекст по pOldBrush 
}
void CBlade::DrawTriangle(CMatrix FCoords, CMatrix SCoords, CDC& dc) {
	CPen Pen(PS_SOLID, 1, RGB(255, 0, 0));

	CBrush TBrush;
	TBrush.CreateSolidBrush(RGB(255, 0, 0));
	dc.SelectObject(&TBrush);

	POINT points[3] = { {0, 0}, {FCoords(0), FCoords(1)}, {SCoords(0), SCoords(1)} };

	dc.Polygon(points, 3);
}


void CBlade::GetRS(CRectD& RSX)
// RS - структура, куда записываются параметры области графика
{
	RSX.left = RS.left;
	RSX.top = RS.top;
	RSX.right = RS.right;
	RSX.bottom = RS.bottom;
}







