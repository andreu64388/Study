#pragma once
#include <wingdi.h>
#include <wingdi.h>
double cosv1v2(CMatrix& one, CMatrix& two);
class CPyramid
{
private:
	CMatrix Vertices; // Координаты вершин
	void GetRect(CMatrix& Vert, CRectD&  RectView);

public:
	CPyramid();
	void Draw(CDC& dc, CMatrix& P, CRect& RW);
	void Draw1(CDC& dc, CMatrix& P, CRect& RW);
	void ColorDraw(CDC &dc, CMatrix& PView, CRect& RW, COLORREF color);
	void DrawLightSphere(CDC& dc, double Radius, CMatrix& PView, CMatrix& PSourceLight, CRect RW, COLORREF Color, int Index);
};

CPyramid::CPyramid()
{
	Vertices.RedimMatrix(4, 6);	// ABC    — нижнее основание
								// A'B'C' — верхнее основание
	/*       A                   B                    C                   A'                  B'                  C'      */
	Vertices(0, 0) = 0;	Vertices(0, 1) = 0;  Vertices(0, 2) = 3; Vertices(0, 3) = 0; Vertices(0, 4) = 0; Vertices(0, 5) = 1; 
	Vertices(1, 0) = 3; Vertices(1, 1) = 0;  Vertices(1, 2) = 0; Vertices(1, 3) = 1; Vertices(1, 4) = 0; Vertices(1, 5) = 0;  
	Vertices(2, 0) = 0; Vertices(2, 1) = 0;  Vertices(2, 2) = 0; Vertices(2, 3) = 3; Vertices(2, 4) = 3; Vertices(2, 5) = 3;  
	Vertices(3, 0) = 1; Vertices(3, 1) = 1;  Vertices(3, 2) = 1; Vertices(3, 3) = 1; Vertices(3, 4) = 1; Vertices(3, 5) = 1;  
}

void CPyramid::GetRect(CMatrix& Vert, CRectD& RectView) //коорд прям-ка, охват проекцию пирамиды на XY ВСК
{
	CMatrix V = Vert.GetRow(0);               // x - координаты
	double xMin = V.MinElement();
	double xMax = V.MaxElement();
	V = Vert.GetRow(1);                       // y - координаты
	double yMin = V.MinElement();
	double yMax = V.MaxElement();
	RectView.SetRectD(xMin, yMax, xMax, yMin);
}

#pragma region Лаба 6

#pragma region Часть 1
void CPyramid::ColorDraw(CDC &dc, CMatrix& PView, CRect& RW, COLORREF color)
{
	BYTE Red = GetRValue(color);
	BYTE Green = GetGValue(color);
	BYTE Blue = GetBValue(color);

	CMatrix ViewCart = SphereToCart(PView);	// точка наблюдения в декартовых
	CMatrix MV = CreateViewCoord(PView(0), PView(1), PView(2));	//м-ца МСК->ВСК
	CMatrix ViewVert = MV * Vertices;
	CRectD RectView;
	GetRect(ViewVert, RectView); //прям-к, охват проекцию пирамиды на XY ВСК
	
	CMatrix MW = SpaceToWindow(RectView, RW); // м-ца МСК->ОСК
	CPoint MasVert[6];
	CMatrix V(3);
	V(2) = 1;
	for (int i = 0; i < 6; i++)	///верш в ОСК
	{
		V(0) = ViewVert(0, i); ///x
		V(1) = ViewVert(1, i); ///y
		V = MW * V;
		MasVert[i].x = (int)V(0);
		MasVert[i].y = (int)V(1);
	}

	CMatrix R1(3),	// текущая точка основания
		R2(3),		// следующая точка основания
		VN(3);		// вектор нормали
	double sm;		// коэффицент преломления
	
	for (int i = 0; i < 3; i++)
	{
		CMatrix VE = Vertices.GetCol(i + 3, 0, 2);	// вершина Е (точка верхнего основания)
		int k;
		if (i == 2) k = 0;
		else k = i + 1;
		R1 = Vertices.GetCol(i, 0, 2);	// текущая точка основания
		R2 = Vertices.GetCol(k, 0, 2);	// следующая точка основания
		CMatrix V1 = R2 - R1;			// Вектор ребра основания
		CMatrix V2 = VE - R1;           // Вектор – ребро к вершине (вектор между основанием и вершиной)
		VN = VectorMult(V2, V1);
		sm = cosv1v2(VN, ViewCart);	    // cos (нормаль к грани, вектор к точке наблюдения) - косинус фи
		
		if (sm >= 0) // Грань видима (отсрый угол больше нуля) – рисуем боковую грань
		{
			CPen Pen(PS_SOLID, 2, RGB(sm * Red * 0.3, sm * Green * 0.3, sm * Blue * 0.3));	//контур
			CPen* pOldPen = dc.SelectObject(&Pen);
			CBrush Brus(RGB(sm * Red * 0.5, sm * Green * 0.5, sm * Blue * 0.5));
			CBrush* pOldBrush = dc.SelectObject(&Brus);
			CPoint MasVertr[4]{ MasVert[i], MasVert[k], MasVert[k + 3],MasVert[i + 3] };	// стороны треугольника
			dc.Polygon(MasVertr, 4);	// зарисовка боковой грани
			dc.SelectObject(pOldPen);	// освобождение ресурсов контекста
			dc.SelectObject(pOldBrush);
		}
	}
	VN = VectorMult(R1, R2);
	sm = cosv1v2(VN, ViewCart);

	if (sm >= 0) // нижнее основание
	{
		CBrush *topBrush = new CBrush(RGB(sm * 0.5 * Red, sm * 0.5 * Green, sm * 0.5 * Blue));
		dc.SelectObject(topBrush);
		dc.Polygon(MasVert, 3);	
	}
	else		// верхнее основание
	{
		CBrush *topBrush = new CBrush(RGB(sm * sm * Red, sm * sm * Green, sm * sm * Blue));
		//CBrush *topBrush = new CBrush(RGB(sm * 0.7 * Red, sm * 0.7*Green, sm * 0.7*Blue));
		dc.SelectObject(topBrush);
		dc.Polygon(MasVert + 3, 3);	
	}
}
#pragma endregion

	#pragma region Часть 2
	void CPyramid::DrawLightSphere(CDC& dc, double Radius, CMatrix& PView, CMatrix& PSourceLight, CRect RW, COLORREF Color, int Index)
	{
		BYTE red = GetRValue(Color);
		BYTE green = GetGValue(Color);
		BYTE blue = GetBValue(Color);
		double kLight;
		CRectD RectView;
	
		CMatrix VR = SphereToCart(PView); //т.наблюд в декарт(VR)
		CMatrix VS = SphereToCart(PSourceLight);//т.света в декарт
		CMatrix MV = CreateViewCoord(PView(0), PView(1), PView(2));//М-ца -> ВСК
		CMatrix ViewVert = MV * Vertices;
		GetRect(ViewVert, RectView); //прям-к, охват проекцию пирамиды на XY ВСК
		CMatrix MW = SpaceToWindow(RectView, RW); // м-ца МСК->ОСК
	
		CPoint MasVert[6];
		CMatrix V(3);
		V(2) = 1;
		for (int i = 0; i < 6; i++)	///верш в ОСК
		{
			V(0) = ViewVert(0, i); ///x
			V(1) = ViewVert(1, i); ///y
			V = MW * V;
			MasVert[i].x = (int)V(0);
			MasVert[i].y = (int)V(1);
		}

		CMatrix R1(3),	///тек. точка основания
			R2(3),		///следующая т.основания
			VN(3);		///вектор нормали
		double sm;
		for (int i = 0; i < 3; i++)
		{
			CMatrix VE = Vertices.GetCol(i + 3, 0, 2);	// вершина Е
			int k;
			if (i == 2) k = 0;
			else k = i + 1;
			R1 = Vertices.GetCol(i, 0, 2);
			R2 = Vertices.GetCol(k, 0, 2);
			CMatrix V1 = R2 - R1;          // Вектор – ребро в основании
			CMatrix V2 = VE - R1;          // Вектор – ребро к вершине
			VN = VectorMult(V2, V1);
			sm = cosv1v2(VR, VN);	   // cos (N к грани, вект ТН)
			double UgolAlpha = Ugol(VS, VN);

			if (sm >= 0) // Грань видима – рисуем боковую грань
			{
				CMatrix VP = VS - VR; // Напр на источник света отн нормали к т.падения
				sm = cosv1v2(VP, VN);
				double result = 0;
				if(sm > 0)
				{
						kLight = cosv1v2(VR, VN);
						result = pow(kLight, 5);
				}
				CPen Pen(PS_SOLID, 2, RGB(0,7*result*red, 0,7*result*green, 0,7*result*blue));	//контур
					CPen* pOldPen = dc.SelectObject(&Pen);
					CBrush Brus(RGB(result * red, result * green, result * blue));
					CBrush* pOldBrush = dc.SelectObject(&Brus);
					CPoint MasVertr[4]{ MasVert[i], MasVert[k], MasVert[k + 3],MasVert[i + 3] };
					dc.Polygon(MasVertr, 4);	///зарисовка
					dc.SelectObject(pOldPen);
					dc.SelectObject(pOldBrush);
			}
		}
		VN = VectorMult(R1, R2);
		sm = cosv1v2(VN, VR);

		if (sm >= 0) // Основание
		{
			CMatrix VP = VS - VR;
			sm = cosv1v2(VP, VN);
			double result = 0;
			double UgolAlpha = Ugol(VR, VN);
			if (sm > 0)
			{
				kLight = cosv1v2(VN, VR);;
				result = pow(kLight, 5);
			}
			if (result < 0) result = 0;
			CBrush* topBrush = new CBrush(RGB(result *red, result * green, result * blue));
			dc.SelectObject(topBrush);
			dc.Polygon(MasVert, 3);	// Основание
		}
		else
		{
			CMatrix VP = VS - VR;
			sm = cosv1v2(VP, VN);
			double result = 0;
			double UgolAlpha = Ugol(VS, VN);
			if (sm > 0)
			{
				kLight = cosv1v2(VN, VR);
				result = pow(kLight, 5);
			}
			CBrush* topBrush = new CBrush(RGB(result * result*red, result * result * green, result * result * blue));
			//CBrush *topBrush = new CBrush(RGB(sm * 0.7, sm * 0.7, sm * 0.7));
			dc.SelectObject(topBrush);
			dc.Polygon(MasVert + 3, 3);	// верхнее основание
		}
	}
	#pragma endregion

#pragma endregion


double cosv1v2(CMatrix& one, CMatrix& two)
{
	double sc = ScalarMult(one, two);
	return sc / ((sqrt((pow(one(0, 0), 2) + pow(one(1, 0), 2) + pow(one(2, 0), 2))))*sqrt(pow(two(0, 0), 2) + pow(two(1, 0), 2) + pow(one(2, 0), 2)));
}
