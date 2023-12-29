#pragma once
#ifndef LIBSURFACE
#define LIBSURFACE 1
using namespace std;

////////////// === ����������� ����� === /////////////////////////////////

typedef vector<CMatrix> CVecMatrix;
typedef vector<CVecMatrix> CMasMatrix;

typedef vector<CPoint> CVecPoint;
typedef vector<CVecPoint> CMatrPoint;

//----------------- �������� ������� -----------------------------------

double Function1(double x, double y);
double Function2(double x, double y);
double Function3(double x, double y);

//-------------------- class CPlot3D ----------------------------------

class CPoint3D
{
public:
	double x, y, z;

	CPoint3D() : x(0.0), y(0.0), z(0.0) {}
	CPoint3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

	bool operator<(const CPoint3D& other) const
	{
		return z < other.z;
	}
};

class CPlot3D
{
	pfunc2 pFunc;		    // ��������� �� ������� f(x,y), ����������� �����������
	CRectD SpaceRect;	    // ������������� �������, �� ������� ��������� ����������� � ������� ��
	CMasMatrix MatrF;		// ������� ��� �������� ��������� ����� (x,y,z,1) ����������� � ������� ��
	CMasMatrix MatrView;	// ������� ��� �������� ��������� ����� (x,y,1) �������� ����������� �� ��������� XY ������� ��
	CRectD ViewRect;		// ������������� �������, ������������ �������� ����������� �� ��������� XY ������� ��
	CRect WinRect;		    // ������������� ������� � ������� ������� ��������� ��� ���������		
	CMatrix ViewPoint;		// ������ (3x1) - ���������� ����� ���������� � ������� 										 
	// ����������� ������� ��������� (r,fi(����.), q(����.))
	CMatrPoint MatrWindow;  // ������� ��� �������� ������� ��������� P(xi,yi) ����� ����������� 

public:
	CPlot3D();
	~CPlot3D() { pFunc = NULL; };
	void SetFunction(pfunc2 pF, CRectD RS, double dx, double dy);	// ������������� ������� f(x,y)
	void SetViewPoint(double r, double fi, double q);		// ������������� ��������� ����� ���������� � ������� ��
	CMatrix GetViewPoint();				// ���������� ������ ViewPoin
	void SetWinRect(CRect Rect);		// ������������� ������� � ���� ��� ���������
	void CreateMatrF(double dx, double dy); // ��������� ������� MatrF ������������ ����� �����������
	void CreateMatrView();		// ��������� ������� MatrView ������������ ����� �������� ����������� �� ��������� XY ������� ��
	void CreateMatrWindow();	// ��������� ������� MatrWindow 
	void Draw(CDC& dc);
};


#endif


