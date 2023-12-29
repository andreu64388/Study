#include "stdafx.h"
#include <algorithm>

double Function1(double x, double y)/////////
{
	return x * x + y * y;
};

double Function2(double x, double y)///////
{
	return x * x - y * y;
};

double Function3(double x, double y)///////
{
	if (y != 0 && x != 0)
		if ((1 - x * x - y * y) >= 0)
			return sqrt(1 - x * x - y * y);

};

CPlot3D::CPlot3D()///////////////
{
	pFunc = NULL;
	ViewPoint.RedimMatrix(3);
	WinRect.SetRect(0, 0, 200, 200);
	ViewPoint(0) = 10, ViewPoint(1) = 30;
	ViewPoint(2) = 45;
};

void CPlot3D::SetFunction(pfunc2 pF, CRectD RS, double dx, double dy)//////////
// Устанавливает функцию f(x,y)
// pFunc - указатель на функцию f(x,y) - поверхность для построения
// RS - область в МСК (xmin,ymax,xmax,ymin) для расчета значений f(x) 
// dx, dy - шаги для расчет значений f(x) по x и y 
// VP - координаты точки наблюдения (r,fi,q) в сферической МСК  
// RW - область в окне для рисования 
{
	pFunc = pF;
	SpaceRect.SetRectD(RS.left, RS.top, RS.right, RS.bottom);
	MatrF.clear();		// очищаем матрицу для хранения координат точек поверхности в МСК
	MatrView.clear();	// очищаем матрицу для хранения к-т точек проекции поверхности на плоскость XY ВСК
	MatrWindow.clear();	// очищаем матрицу для хранения оконных координат точек изображения 

	CreateMatrF(dx, dy);// заполняем матрицу к-ми точек поверхности
	CreateMatrView();	// заполняем матрицу к-ми точек проекции поверхности на плоскость XY ВСК
	CreateMatrWindow(); // заполняем матрицу 
}

void CPlot3D::SetViewPoint(double r, double fi, double q)////////////
// Устанавливает положение точки наблюдения в МИРОВОЙ СК - 
// -заполняет матрицу ViewPoint
// r - модуль радиус-вектора
// fi - азимут (от оси OX против часовой стрелки, 0-360), град.
// q  - угол (от оси Z по часовой стрелке, 0-180), град.
{
	ViewPoint(0) = r, ViewPoint(1) = fi;
	ViewPoint(2) = q;
	MatrView.clear();
	CreateMatrView();
	MatrWindow.clear();
	CreateMatrWindow();
}

CMatrix CPlot3D::GetViewPoint()
{
	CMatrix P = ViewPoint;
	return P;
}

void CPlot3D::SetWinRect(CRect Rect)
// Устанавливает область в окне для рисования
// Rect - новая область
{
	WinRect = Rect;    // Присваиваем прямоугольник WinRect из параметра Rect
	MatrWindow.clear();    // Очищаем матрицу MatrWindow
	CreateMatrWindow();    // Создаем новую матрицу MatrWindow
}

void CPlot3D::CreateMatrF(double dx, double dy)//////////////
// Заполняет матрицу MatrF координатами точек поверхности
// dx - шаг для расчета значений функции f(x,y) оси x
// dy - шаг для расчета значений функции f(x,y) оси y
{
	double xL = SpaceRect.left;
	double xH = SpaceRect.right;
	double yL = SpaceRect.bottom;
	double yH = SpaceRect.top;
	CVecMatrix VecMatrix;
	CMatrix V(4);
	V(3) = 1;
	for (double x = xL; x <= xH; x += dx)
	{
		VecMatrix.clear();
		for (double y = yL; y <= yH; y += dy)
		{
			V(0) = x;
			V(1) = y;
			V(2) = pFunc(x, y);
			VecMatrix.push_back(V);
		}
		MatrF.push_back(VecMatrix);
	}
}

double Y1(CRectD rect, double x)
{
	//rect.top = yL
	//rect.buttom = yH
	//rect.left = xL
	//rect.right = xH
	return rect.top + (((rect.bottom - rect.top) / (rect.right - rect.left)) * (x - rect.left));
}

double Y2(CRectD rect, double x)
{
	//rect.top = yL
	//rect.buttom = yH
	//rect.left = xL
	//rect.right = xH
	return rect.top - (((rect.bottom - rect.top) / (rect.right - rect.left)) * (x - rect.left));
}

bool CompareVecMatrix(const CVecMatrix& a, const CVecMatrix& b, const CRectD& viewRect,  CMatrix& viewPoint)
{ 
	CMatrix matrA = a[0];
	CMatrix matrB = b[0];
	CPoint pointA(matrA(0,0), matrA(0,1)); // первый элемент первой матрицы в векторе a
	CPoint pointB(matrB(0, 0), matrB(0, 1)); // первый элемент первой матрицы в векторе b

	double ax = pointA.x;
	double ay = pointA.y;
	double bx = pointB.x;
	double by = pointB.y;

	// Расстояние от точки A до точки наблюдения
	double distA = sqrt((ax - viewPoint(0)) * (ax - viewPoint(0)) + (ay - viewPoint(1)) * (ay - viewPoint(1)));

	// Расстояние от точки B до точки наблюдения
	double distB = sqrt((bx - viewPoint(0)) * (bx - viewPoint(0)) + (by - viewPoint(1)) * (by - viewPoint(1)));

	// Если точка A ближе к наблюдателю, то она должна идти раньше
	// Если точки находятся на одинаковом расстоянии, то сравниваем их по координате y
	if (distA < distB || (distA == distB && ay > by))
		return true;

	return false;
}

void CPlot3D::CreateMatrView()////////////////
// Заполняет матрицу MatrView координатами точек проекции поверхности f(x,y)
// на плоскость XY видовой СК 
// !!! И !!!
// Определяет прямоугольная область ViewRect, охватывающая проекцию 
// поверхности на плоскость XY видовой СК
{
	CMatrix MV = CreateViewCoord(ViewPoint(0), ViewPoint(1), ViewPoint(2));	//Матрица(4x4) пересчета  
	CMatrix RC = GetViewPoint();	//проекция камеры на XY																//в видовуюсистему координат 
	CVecMatrix VecMatrix;
	CMatrix VX(4), V(3);
	V(2) = 1;
	double xmin = DBL_MAX;	// DBL_MAX - максимальное из double
	double xmax = DBL_MIN;	// DBL_MIN - минимальное из double
	double ymin = DBL_MAX;
	double ymax = DBL_MIN;

	for (int i = 0; i < MatrF.size(); i++)
	{
		VecMatrix.clear();
		for (int j = 0; j < MatrF[i].size(); j++)
		{
			VX = MatrF[i][j];
			VX = MV * VX;
			V(0) = VX(0); // x- координата проекции
			V(1) = VX(1);	// y- координата проекции
			VecMatrix.push_back(V);

			//------- Для определения области ViewRect --------------------------
			double x = V(0);
			double y = V(1);
			if (x < xmin)xmin = x;
			if (x > xmax)xmax = x;
			if (y < ymin)ymin = y;
			if (y > ymax)ymax = y;
		}
		MatrView.push_back(VecMatrix);
	}
	ViewRect.SetRectD(xmin, ymax, xmax, ymin);// Определяем область



	if (RC(1) >= Y1(ViewRect, RC(0)) && RC(1) >= Y2(ViewRect, RC(0)))//дальней является грань AD
	{
		//сортировка
		sort(MatrView.begin(), MatrView.end(), [&](const CVecMatrix& a, const CVecMatrix& b) {
			return CompareVecMatrix(a, b, ViewRect, RC);
			});
	}
	else if (Y2(ViewRect, RC(0)) < RC(1) && RC(1) < Y1(ViewRect, RC(0)))//дальней является грань AC
	{
		//сортировка
		sort(MatrView.begin(), MatrView.end(), [&](const CVecMatrix& a, const CVecMatrix& b) {
			CMatrix matrA = a[0];
			CMatrix matrB = b[0];
			double ax = matrA(0,0);
			double bx = matrB(0, 0);
			return ax > bx;
			});
	}
	else if (RC(1) <= Y1(ViewRect, RC(0)) && RC(1) <= Y2(ViewRect, RC(0)) < RC(1))//дальней является грань CB
	{
		//сортировка
		sort(MatrView.begin(), MatrView.end(), [&](const CVecMatrix& a, const CVecMatrix& b) {
			return CompareVecMatrix(b, a, ViewRect, RC);
			});
	}
	else if (Y1(ViewRect, RC(0)) < RC(1) && RC(1) < Y2(ViewRect, RC(0)))//дальней является грань BD
	{
		//сортировка
		sort(MatrView.begin(), MatrView.end(), [&](const CVecMatrix& a, const CVecMatrix& b) {
			CMatrix matrA = a[0];
			CMatrix matrB = b[0];
			double ax = matrA(0, 0);
			double bx = matrB(0, 0);
			return bx > ax;
			});
	}
}

void CPlot3D::CreateMatrWindow()/////////////
// Заполняет матрицу MatrWindow оконными координатами точек изображения
{
	CMatrix MW = SpaceToWindow(ViewRect, WinRect);		// Матрица (3 на 3)пересчета 
														//в оконную систему координат
	CVecPoint VecPoint;
	CMatrix  V(3);
	for (int i = 0; i < MatrView.size(); i++)
	{
		VecPoint.clear();
		for (int j = 0; j < MatrView[i].size(); j++)
		{
			V = MatrView[i][j];
			V = MW * V;
			CPoint P((int)V(0), (int)V(1));
			VecPoint.push_back(P);
		}
		MatrWindow.push_back(VecPoint);
	}


}

void CPlot3D::Draw(CDC& dc)//////
{
	if (MatrWindow.empty())
	{
		TCHAR* error = _T("Массив данных для рисования в окне пуст! ");
		MessageBox(NULL, error, _T("Ошибка"), MB_ICONSTOP);
		return;
	}
	CPoint pt[4];
	int nRows = MatrWindow.size();
	int nCols = MatrWindow[0].size();




	for (int i = 0; i < nRows - 1; i++)
		for (int j = 0; j < nCols - 1; j++)
		{
			pt[0] = MatrWindow[i][j];
			pt[1] = MatrWindow[i][j + 1];
			pt[2] = MatrWindow[i + 1][j + 1];
			pt[3] = MatrWindow[i + 1][j];
			dc.Polygon(pt, 4);
		}
}
//
// 
// 
//void CPlot3D::Draw(CDC& dc)
//{
//	if (MatrWindow.empty())
//	{
//		TCHAR* error = _T("Массив данных для рисования в окне пуст! ");
//		MessageBox(NULL, error, _T("Ошибка"), MB_ICONSTOP);
//		return;
//	}
//	CPoint pt[4];
//	int nRows = MatrWindow.size();
//	int nCols = MatrWindow[0].size();
//	for (int i = 0; i < nRows - 1; i++)
//	{
//		for (int j = 0; j < nCols - 1; j++)
//		{
//			// Определяем точки полигона
//			pt[0] = MatrWindow[i][j];
//			pt[1] = MatrWindow[i][j + 1];
//			pt[2] = MatrWindow[i + 1][j + 1];
//			pt[3] = MatrWindow[i + 1][j];
//
//			// Находим центр полигона
//			int cx = (pt[0].x + pt[1].x + pt[2].x + pt[3].x) / 4;
//			int cy = (pt[0].y + pt[1].y + pt[2].y + pt[3].y) / 4;
//
//			// Определяем размер полигона
//			int polyWidth = abs(pt[0].x - pt[2].x);
//			int polyHeight = abs(pt[0].y - pt[2].y);
//
//			// Определяем количество точек, которые будут использоваться
//			// для закрашивания полигона
//			int numPoints = polyWidth * polyHeight / 100;
//
//			// Создаем регион, соответствующий полигону
//			CRgn polyRgn;
//			CPoint polyPts[4] = { pt[0], pt[1], pt[2], pt[3] };
//			polyRgn.CreatePolygonRgn(polyPts, 4, WINDING);
//
//			// Закрашиваем полигон цветом, выбранным случайным образом
//			// из палитры
//			COLORREF fillColour = RGB(rand() % 255, rand() % 255, rand() % 255);
//			CBrush fillBrush(fillColour);
//			dc.SelectObject(&fillBrush);
//			dc.Polygon(pt, 4);
//
//			// используем алгоритм художника для заполнения полигона точками
//			for (int k = 0; k < numPoints; k++)
//			{
//				int x = pt[0].x + rand() % polyWidth;
//				int y = pt[0].y + rand() % polyHeight;
//				CPoint p(x, y);
//				if (polyRgn.PtInRegion(p))
//				{
//					// Если да, то закрашиваем ее
//					dc.SetPixel(p, fillColour);
//				}
//			}
//		}
//	}
//}





//void CPlot3D::Draw(CDC& dc)
//{
//	if (MatrWindow.empty())
//	{
//		TCHAR* error = _T("Массив данных для рисования в окне пуст! ");
//		MessageBox(NULL, error, _T("Ошибка"), MB_ICONSTOP);
//		return;
//	}
//	int nRows = MatrWindow.size();
//	int nCols = MatrWindow[0].size();
//	std::vector<std::pair<CVecPoint, int>> sortedPoints;
//	for (int i = 0; i < nRows; i++)
//	{
//		for (int j = 0; j < nCols; j++)
//		{
//			CVecPoint vecPoint = MatrWindow[i];
//			sortedPoints.emplace_back(std::make_pair(vecPoint, i * nCols + j));
//		}
//	}
//	std::sort(sortedPoints.begin(), sortedPoints.end(),
//		[](const std::pair<CVecPoint, int>& a, const std::pair<CVecPoint, int>& b)
//		{
//			return a.first[2].y < b.first[2].y;
//		});
//	std::vector<CPoint> pt(4);
//	for (auto& point : sortedPoints)
//	{
//		int i = point.second / nCols;
//		int j = point.second % nCols;
//		pt[0] = MatrWindow[i][j];
//		pt[1] = MatrWindow[i][(j + 1) % nCols];
//		pt[2] = MatrWindow[(i + 1) % nRows][(j + 1) % nCols];
//		pt[3] = MatrWindow[(i + 1) % nRows][j];
//		dc.Polygon(pt.data(), 4);
//	}
//}

//void CPlot3D::Draw(CDC& dc)
//{
//	if (MatrWindow.empty())
//	{
//		TCHAR* error = _T("Массив данных для рисования в окне пуст! ");
//		MessageBox(NULL, error, _T("Ошибка"), MB_ICONSTOP);
//		return;
//	}
//
//	
//		
//		// получаем количество строк и столбцов в матрице
//		int nRows = MatrWindow.size();
//	int nCols = MatrWindow[0].size();
//
//	// создаем вектор пар, где первый элемент - вектор точек, второй элемент - индекс точки в матрице
//	std::vector<std::pair<CVecPoint, int>> sortedPoints;
//
//	// заполняем вектор пар отсортированными точками
//	for (int i = 0; i < nRows; i++)
//	{
//		for (int j = 0; j < nCols; j++)
//		{
//			// добавляем пару (вектор точек i-ой строки, индекс точки i,j в матрице)
//			CPoint& point = MatrWindow[i][j];
//			sortedPoints.emplace_back(std::make_pair(CVecPoint{ point.x, point.y }, i * nCols + j));
//		}
//	}
//
//	// сортируем вектор пар по y-координате средней точки вектора точек
//	std::sort(sortedPoints.begin(), sortedPoints.end(),
//		[](const std::pair<CVecPoint, int>& a, const std::pair<CVecPoint, int>& b)
//		{
//			double ay = (a.first[0].y + a.first[a.first.size() - 1].y) / 2.0;
//			double by = (b.first[0].y + b.first[b.first.size() - 1].y) / 2.0;
//			return ay < by;
//		});
//
//	// создаем вектор из 4 точек для каждой грани куба
//	std::vector<CPoint> pt(4);
//
//	// проходим по всем парам отсортированных точек и рисуем соответствующие грани куба
//	for (auto& point : sortedPoints)
//	{
//		// получаем индекс строки и столбца точки в матрице
//		int i = point.second / nCols;
//		int j = point.second % nCols;
//
//		// задаем 4 точки для текущей грани куба
//		pt[0] = MatrWindow[i][j];
//		pt[1] = MatrWindow[i][(j + 1) % nCols];
//		pt[2] = MatrWindow[(i + 1) % nRows][(j + 1) % nCols];
//		pt[3] = MatrWindow[(i + 1) % nRows][j];
//
//		// рисуем текущую грань куба
//		dc.Polygon(pt.data(), 4);
//	}
//}