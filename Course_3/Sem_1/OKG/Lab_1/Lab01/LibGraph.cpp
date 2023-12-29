﻿#include "stdafx.h"
#include "LibGraph.h"

#pragma region Controller
void ControllerCMatrix::PrintMatrix(CDC & dc, int x, int y, CMatrix & M) // вывод матрицы/вектора
{
	for (size_t i = 0; i < M.cols(); i++)
	{
		for (size_t j = 0; j < M.rows(); j++)
		{
			dc.TextOutW(x + i * 40, y + j * 40, DoubleToString(M(j, i))); 
		}
	}
}
void ControllerCMatrix::InitMatrix(CMatrix & M)							// инициализация матрицы/вектора
{
	for (size_t i = 0; i < M.rows(); i++)
	{
		for (size_t j = 0; j < M.cols(); j++)
		{
			M(i, j) = 1 + rand() % 10;	// рандом от 1 до 10
		}
	}
}
double ControllerCMatrix::ScalarMult(CMatrix & V1, CMatrix & V2)		// скалярное произведение векторов
{
	if (V1.rows() == V2.rows() && V1.cols() == V2.cols())
	{
		return V1(0, 0)*V2(0, 0) + V1(1, 0)*V2(1, 0) + V1(2, 0)*V2(2, 0); // x1x2 + y1y2+ z1z2
	}
}
CString ControllerCMatrix::DoubleToString(double x)						// перевод вещественного числа в строковое представление
{
	CString s;
	s.Format(_T("%.1f"), x);
	return s;
}
double ControllerCMatrix::ModVec(CMatrix & V)							// модуль вектора
{
	return V.rows() == 3 && V.cols() == 1 ?
		sqrt((double)(V(0, 0)*V(0, 0) + V(1, 0)*V(1, 0) + V(2, 0)*V(2, 0))) // sqrt(x^2+y^2+z^2)
		: 0.0;
}
CMatrix ControllerCMatrix::VectorMult(CMatrix & V1, CMatrix & V2)		// векторное произведение векторов
{
	if (V1.cols() == 1 && V2.cols() == 1 && V1.rows() == V2.rows())
	{
		CMatrix multVector(3);
		multVector(0, 0) = V1(1, 0)*V2(2, 0) - V1(2, 0)*V2(1, 0);
		multVector(1, 0) = (-1)*(V1(0, 0)*V2(2, 0) - V1(2, 0)*V2(0, 0));
		multVector(2, 0) = V1(0, 0)*V2(1, 0) - V1(1, 0)*V2(0, 0);
		return multVector;
	}
	else
	{
		return NULL;
	}
}
double ControllerCMatrix::CosV1V2(CMatrix& V1, CMatrix& V2)				// косинус угла между векторами
{
	return V1.cols() == 1 && V2.cols() == 1 && V1.rows() == 3 && V2.rows() == 3 ? // скалярное произведение / |V1||V2|
		(ScalarMult(V1, V2) / (ModVec(V1)*ModVec(V2))) :
		0.0;
}
CMatrix ControllerCMatrix::SphereToCart(CMatrix & PView)				// преобразует сферические координаты точки в декартовы
{
	CMatrix R(3);
	R(0) = PView(0)*cos(PView(1))*sin(PView(2));
	R(1) = PView(0)*sin(PView(1))*sin(PView(2));
	R(2) = PView(0)*cos(PView(2));
	return R;
}
#pragma endregion



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




