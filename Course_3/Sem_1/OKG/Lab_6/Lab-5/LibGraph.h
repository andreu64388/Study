#include <math.h>
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
	CRectD(){ left = top = right = bottom = 0; };
	CRectD(double l, double t, double r, double b);
	void SetRectD(double l, double t, double r, double b);
	CSizeD SizeD();	// ���������� �������(������, ������) �������������� 
};

CRectD::CRectD(double l, double t, double r, double b)
{
	left = l;
	top = t;
	right = r;
	bottom = b;
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
	cz.cx = fabs(right - left);	// ������ ������������� �������
	cz.cy = fabs(top - bottom);	// ������ ������������� �������
	return cz;
}


CMatrix SphereToCart(CMatrix& PView)
{// ����������� ����������� ���������� PView  ����� � ���������
// PView(0) - r
// PView(1) - fi - ������(������ �� ��� X), ����.
// PView(2) - q - ����(�������� ��� Z), ����.
// ���������: R(0)- x, R(1)- y, R(2)- z	
	CMatrix R(3);

	double r = PView(0);
	double fi = PView(1);				// �������
	double q = PView(2);				// �������
	double fi_rad = (fi / 180.0)*pi;	// ������� fi � �������
	double q_rad = (q / 180.0)*pi;		// ������� q � �������

	R(0) = r*sin(q_rad)*cos(fi_rad);	// x- ���������� ����� ����������
	R(1) = r*sin(q_rad)*sin(fi_rad);	// y- ���������� ����� ����������
	R(2) = r*cos(q_rad);				// z- ���������� ����� ����������

	return R;
}
CMatrix CreateViewCoord(double r, double fi, double q)
// ������� ������� ��������� ����� �� ������� ������� ��������� � �������
// (r,fi,q)- ���������� ����� ���������� (������ ������� ������� ���������)
// � ������� ����������� ������� ��������� ( ���� fi � q � ��������)
{
	double fg = fmod(fi, 360.0);
	double ff = (fg / 180.0)*pi; // ������� � �������
	fg = fmod(q, 360.0);
	double qq = (fg / 180.0)*pi; // ������� � �������

	CMatrix VM(4, 4);
	VM(0, 0) = -sin(ff);		    VM(0, 1) = cos(ff);				VM(0, 2) = 0;			VM(0, 3) = 0;
	VM(1, 0) = -cos(qq)*cos(ff);	VM(1, 1) = -cos(qq)*sin(ff);	VM(1, 2) = sin(qq);		VM(1, 3) = 0;
	VM(2, 0) = -sin(qq)*cos(ff);	VM(2, 1) = -sin(qq)*sin(ff);	VM(2, 2) = -cos(qq);	VM(2, 3) = r;
	VM(3, 0) = 0;					VM(3, 1) = 0;					VM(3, 2) = 0;			VM(3, 3) = 1;
	return VM;
}
CMatrix SpaceToWindow(CRectD& RS, CRect& RW)
// ���������� ������� ��������� ��������� �� ������� � �������
// rs - ������� � ������� ����������� - double
// rw - ������� � ������� ����������� - int
{
	CMatrix M(3, 3);
	CSize sz = RW.Size();          // ������ ������� � ����
	int dwx = sz.cx;               // ������
	int dwy = sz.cy;               // ������
	CSizeD szd = RS.SizeD();       // ������ ������� � ������� �����������

	double dsx = szd.cx;           // ������ � ������� �����������
	double dsy = szd.cy;           // ������ � ������� �����������

	double kx = (double)dwx / dsx; // ������� �� x
	double ky = (double)dwy / dsy; // ������� �� y

	M(0, 0) = kx; M(0, 1) = 0;   M(0, 2) = (double)RW.left - kx*RS.left;
	M(1, 0) = 0;  M(1, 1) = -ky; M(1, 2) = (double)RW.bottom + ky*RS.bottom;
	M(2, 0) = 0;  M(2, 1) = 0;   M(2, 2) = 1;

	return M;
}
CMatrix VectorMult(CMatrix& V1, CMatrix& V2)
// ��������� ��������� ������������ �������� V1 � V2
{
	CMatrix temp(V1.rows());
	temp(0) = (V1(1)*V2(2)) - (V1(2)*V2(1));
	temp(1) = (V1(2)*V2(0)) - (V1(0)*V2(2));
	temp(2) = (V1(0)*V2(1)) - (V1(1)*V2(0));
	return temp;
}
double ScalarMult(CMatrix& V1, CMatrix& V2)
// ��������� ��������� ������������ �������� V1 � V2
{
	return V1(0)*V2(0) + V1(1)*V2(1) + V1(2)*V2(2);
}



double ModVec(CMatrix& V)
// ��������� ������ ������� V
{
	int b = (V.cols() == 1) && (V.rows() == 3);
	if (!b)
	{
		char* error = "ModVec: ����������fz ����������� �������! ";
		MessageBox(NULL, (LPWSTR)error, (LPWSTR)"������", MB_ICONSTOP);
		exit(1);
	}
	double q = sqrt(V(0) * V(0) + V(1) * V(1) + V(2) * V(2));
	return q;
}
double CosV1V2(CMatrix& V1, CMatrix& V2)
// ��������� ������� ���� ����� ��������� V1 � V2
{
	double modV1 = ModVec(V1);
	double modV2 = ModVec(V2);
	int b = (modV1 < 1e-7) || (modV2 < 1e-7);
	if (b)
	{
		char* error = "CosV1V2: ������ ������ ��� ����� �������� < 1e-7!";
		MessageBox(NULL, (LPWSTR)error, (LPWSTR)"������", MB_ICONSTOP);
		exit(1);
	}
	int b1 = (V1.cols() == 1) && (V1.rows() == 3);
	int b2 = (V2.cols() == 1) && (V2.rows() == 3);
	b = b1 && b2;
	if (!b)
	{
		char* error = "CosV1V2: ������������ ����������� ��������! ";
		MessageBox(NULL, (LPWSTR)error, (LPWSTR)"������", MB_ICONSTOP);
		exit(1);
	}
	double cos_f = ScalarMult(V1, V2) / (modV1 * modV2);
	return cos_f;
}
double Ugol(CMatrix& v1, CMatrix& v2)
{
	double ugol = ScalarMult(v1, v2) / (ModVec(v1) * ModVec(v2));
	ugol = acos(ugol);
	return ugol;
}