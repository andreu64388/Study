#include "stdafx.h"
#include "CMatrix.h"
#include "LibGraph.h"
#include "CPyramid.h"

CPyramid::CPyramid()//�������� �� ���������
{
	_vertices.resize(4, 8);

	_vertices(0, 0) = 6;
	_vertices(0, 3) = 2;
	_vertices(2, 3) = 6;

	_vertices(1, 1) = -6;
	_vertices(1, 4) = -2;
	_vertices(2, 4) = 6;

	_vertices(0, 2) = -6;
	_vertices(0, 5) = -2;
	_vertices(2, 5) = 6;
}

void CPyramid::draw(CDC& dc, CMatrix& viewport, CRect& rectWindow)//���������� �������� ��� ��������� ������
{
	CMatrix viewportCoords = sphericalToCartesian(viewport);
	CMatrix converterWorldToView = getConverterWorldToView(viewport(0), viewport(1), viewport(2));
	CMatrix verticesView = converterWorldToView * _vertices;
	CRectD rectView;
	getRect(verticesView, rectView);
	CMatrix converterWorldToWindow = getConverterWorldToWindow(rectView, rectWindow);

	CPoint vertices[6];
	CMatrix verticesCoords(3);
	verticesCoords(2) = 1;

	for (int i = 0; i < 6; i++)//������� �����
	{
		verticesCoords(0) = verticesView(0, i);
		verticesCoords(1) = verticesView(1, i);

		verticesCoords = converterWorldToWindow * verticesCoords;
		vertices[i].x = (int)verticesCoords(0);
		vertices[i].y = (int)verticesCoords(1);
	}

	CPen brushEdge(PS_SOLID, 2, RGB(0, 0, 255)); 
	CPen* pOldPen = dc.SelectObject(&brushEdge);
	CBrush brushBottom(RGB(255, 255, 0)); // ������ �����
	CBrush* pOldBrush = dc.SelectObject(&brushBottom); 
	CMatrix R1(3), R2(3), normalOuter(3);
	double sm;
	for (int i = 0; i < 3; i++) // ������������ ������
	{
		CMatrix VE = _vertices.getCol(i + 3, 0, 2);
		int k = i == 2 ? 0 : i + 1;
		R1 = _vertices.getCol(i, 0, 2);
		R2 = _vertices.getCol(k, 0, 2);
		CMatrix edgeBase = R2 - R1;
		CMatrix edgeVertex = VE - R1;
		normalOuter = vectorProduct(edgeVertex, edgeBase);
		sm = scalarProduct(normalOuter, viewportCoords);
														
		if (sm >= 0)
		{
			dc.MoveTo(vertices[i]);
			dc.LineTo(vertices[k]);
			dc.LineTo(vertices[k + 3]);
			dc.LineTo(vertices[i + 3]);
			dc.LineTo(vertices[i]);
		}
	}
	if (viewportCoords(2) < 0) 
	{
		dc.Polygon(vertices, 3);
	}
	else
	{
		CBrush brushTop(RGB(100, 255, 255));//������ � ���� �������� ����� ��� ���������
		dc.SelectObject(brushTop);
		dc.Polygon(vertices + 3, 3);
	}
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);
}

void CPyramid::drawXray(CDC& dc, CMatrix& viewport, CRect& rectWindow)
{
	CMatrix converterWorldToView = getConverterWorldToView(viewport(0), viewport(1), viewport(2));
	CMatrix verticesView = converterWorldToView * _vertices;
	CRectD rectView;
	getRect(verticesView, rectView);
	CMatrix converterWorldToWindow = getConverterWorldToWindow(rectView, rectWindow);

	CPoint vertices[6];
	CMatrix verticesCoords(3); // ������� ��������� ������
	verticesCoords(2) = 1;

	for (int i = 0; i < 6; i++)//������� �����
	{
		verticesCoords(0) = verticesView(0, i);
		verticesCoords(1) = verticesView(1, i);
		verticesCoords = converterWorldToWindow * verticesCoords;
		vertices[i].x = (int)verticesCoords(0);
		vertices[i].y = (int)verticesCoords(1);
	}

	CPen brushEdge(PS_SOLID, 2, RGB(0, 0, 255)); //������ � ���� ������ ����� ��� �����(�����)
	CPen* pOldPen = dc.SelectObject(&brushEdge);

	dc.MoveTo(vertices[2]); //������ �����
	for (int i = 0; i < 3; i++)
	{
		dc.LineTo(vertices[i]);
	}
	dc.MoveTo(vertices[5]);
	for (int i = 3; i < 6; i++)
	{
		dc.LineTo(vertices[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		dc.MoveTo(vertices[i]);
		dc.LineTo(vertices[i + 3]);
	}

	dc.SelectObject(pOldPen);
}

void CPyramid::getRect(CMatrix& Vert, CRectD& RectView)//�������������
{
	CMatrix V = Vert.getRow(0);

	double xMin = V.getMin();
	double xMax = V.getMax();

	V = Vert.getRow(1);

	double yMin = V.getMin();
	double yMax = V.getMax();

	RectView.setRectD(xMin, yMax, xMax, yMin);
}
// ��������� ���������� ��������������, ������������� �������� 
// �������� �� ��������� XY � ������� ������� ���������
// Vert - ���������� ������ (� ��������)
// RectView - �������� - ������������ �������������