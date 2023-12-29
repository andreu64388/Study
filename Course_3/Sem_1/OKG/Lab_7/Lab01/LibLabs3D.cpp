#include "stdafx.h"
#include "CMatrix.h"
#include "LibGraph.h"
#include "math.h"
#include "LibLabs3D.h"

void DrawLightSphere(CDC& dc, double Radius, CMatrix& PView, CMatrix& PSourceLight, CRect RW, COLORREF Color, int Index)
// Рисует сферу с учетом освещенности
// Radius - Радиус сферы
// PView - координаты точки наблюдения в мировой сферической системе координат
// PSourceLight - координаты источника света в мировой сферической системе координат
// RW - область в окне для отображение шара
// Color - цвет источника света
// Index=0 -  Диффузионная модель отражения света :cos(e)
// Index=1 -  Зеркальная модель отражения света :[cos(a)]^n
{
	BYTE red = GetRValue(Color);
	BYTE green = GetGValue(Color);
	BYTE blue = GetBValue(Color);

	CMatrix VSphere(3), VSphereNorm(3), PV(4);					
	COLORREF Col;												
	double df = 0.3; double dq = 0.4; double kLight;			// Шаг по азимуту	
	VSphere(0) = Radius;										// Радиус сферы
	CMatrix VR = SphereToCart(PView);							// Декартовы координаты точки наблюдения
	CMatrix VS = SphereToCart(PSourceLight);					// Декартовы координаты источника света
	CRectD  RV(-Radius, Radius, Radius, -Radius);				// Область в ВСК в плоскости XY для изображения проекции шара
	CMatrix MW = SpaceToWindow(RV, RW);							// Матрица пересчета в ОСК
	CMatrix MV = CreateViewCoord(PView(0), PView(1), PView(2)); // Матрица пересчета в ВСК  

//------ Проходим по точкам сферы  ---------------------------------------
	for (double fi = 0; fi <= 360.0; fi += df)  // Азимут
		for (double q = 0; q <= 180.0; q += dq) 
		{
			VSphere(1) = fi; VSphere(2) = q;		// Долгота (Азимут),VSphere(0)==Radius и широта
			CMatrix VCart = SphereToCart(VSphere);  // Декартовы координаты точки сферы  
			VSphereNorm = VCart;                    // Вектор НОРМАЛИ к поверхности СФЕРЫ!
			double cos_RN = CosV1V2(VR, VSphereNorm);// Косинус угла между вектором точки наблюдения R и вектором нормали N к точке сферы тета
			PV(0) = VCart(0);
			PV(1) = VCart(1);
			PV(2) = VCart(2);
			PV(3) = 1;
			PV = MV * PV;							// Координаты точки в ВСК
			VCart(0) = PV(0);
			VCart(1) = PV(1);
			VCart(2) = 1;
			VCart = MW * VCart;						// Координаты точки в ОСК
			CMatrix  VP = VS - VR;					// Направление на источник света относительно нормали к точке падения
			double cos_PN = CosV1V2(VP, VSphereNorm); // угол падения луча	фи
			if (cos_PN > 0)							// Если точка сферы освещается...
			{
				if (Index == 0)						//Диффузионная модель отражения света 
					kLight = cos_PN*cos_RN;
				if (Index == 1)						//Зеркальная модель отражения света 
				{
					double xx = 2 * ModVec(VP)*cos_PN / ModVec(VSphereNorm); // интенсивность излучения 
					CMatrix RX = (VSphereNorm*xx) - VP; // вектор отражения
					double cos_A = CosV1V2(RX, VR);		// угол между вектором отражения и вектором наблюдения
					if (cos_A > 0)
						kLight = cos_A * cos_A;
					else
						kLight = 0;
				}
				Col = RGB(kLight * red, kLight * green, kLight * blue);
				dc.SetPixel((int)VCart(0), (int)VCart(1), Col);
			}
		}
}