#ifndef LIBGRAPH
#include "CMatrix.h"
#include "stdafx.h"
#include "resource.h"
#define LIBGRAPH 1
const double pi = 3.14159;

struct CSizeD	// ���������� ������ (������, ������) ������������� �������
{
	double cx;	
	double cy;
};
//-------------------------------------------------------------------------------
struct CRectD		// ���������� ������� ����� � ������ ������ ����� ������������� �������
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

// ����� ��� �������� � CMatrix
class ControllerCMatrix
{
public:
	ControllerCMatrix() = default;
	~ControllerCMatrix() = default;

#pragma region Methods
	// ����� �������
	void PrintMatrix(CDC& dc, int x, int y, CMatrix& M);
	// ������������� ������� ���������� �������
	void InitMatrix(CMatrix& M);
	//��������� ������������ ��������
	double ScalarMult(CMatrix& V1, CMatrix& V2);
	// �������������� double � CString (��� ������ � ����)
	CString DoubleToString(double x);
	// ������ �������
	double ModVec(CMatrix& V);
	// ��������� ������������
	CMatrix VectorMult(CMatrix& V1, CMatrix& V2);
	// ������� ���� ����� ���������
	double CosV1V2(CMatrix& V1, CMatrix& V2);
	// ����������� ����������� ���������� PView  ����� � ���������
	CMatrix SphereToCart(CMatrix& PView);
	// PView(0) � r � ���������� �� �����.
	// PView(1) - fi - ������(������ �� ��� X), ����.
	// PView(2) - q - ����(�������� ��� Z), ����.
	// ���������: R(0)- x, R(1)- y, R(2)- z	

#pragma endregion
private:

};

#endif

