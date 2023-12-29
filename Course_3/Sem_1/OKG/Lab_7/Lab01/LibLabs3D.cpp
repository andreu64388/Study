#include "stdafx.h"
#include "CMatrix.h"
#include "LibGraph.h"
#include "math.h"
#include "LibLabs3D.h"

void DrawLightSphere(CDC& dc, double Radius, CMatrix& PView, CMatrix& PSourceLight, CRect RW, COLORREF Color, int Index)
// ������ ����� � ������ ������������
// Radius - ������ �����
// PView - ���������� ����� ���������� � ������� ����������� ������� ���������
// PSourceLight - ���������� ��������� ����� � ������� ����������� ������� ���������
// RW - ������� � ���� ��� ����������� ����
// Color - ���� ��������� �����
// Index=0 -  ������������ ������ ��������� ����� :cos(e)
// Index=1 -  ���������� ������ ��������� ����� :[cos(a)]^n
{
	BYTE red = GetRValue(Color);
	BYTE green = GetGValue(Color);
	BYTE blue = GetBValue(Color);

	CMatrix VSphere(3), VSphereNorm(3), PV(4);					
	COLORREF Col;												
	double df = 0.3; double dq = 0.4; double kLight;			// ��� �� �������	
	VSphere(0) = Radius;										// ������ �����
	CMatrix VR = SphereToCart(PView);							// ��������� ���������� ����� ����������
	CMatrix VS = SphereToCart(PSourceLight);					// ��������� ���������� ��������� �����
	CRectD  RV(-Radius, Radius, Radius, -Radius);				// ������� � ��� � ��������� XY ��� ����������� �������� ����
	CMatrix MW = SpaceToWindow(RV, RW);							// ������� ��������� � ���
	CMatrix MV = CreateViewCoord(PView(0), PView(1), PView(2)); // ������� ��������� � ���  

//------ �������� �� ������ �����  ---------------------------------------
	for (double fi = 0; fi <= 360.0; fi += df)  // ������
		for (double q = 0; q <= 180.0; q += dq) 
		{
			VSphere(1) = fi; VSphere(2) = q;		// ������� (������),VSphere(0)==Radius � ������
			CMatrix VCart = SphereToCart(VSphere);  // ��������� ���������� ����� �����  
			VSphereNorm = VCart;                    // ������ ������� � ����������� �����!
			double cos_RN = CosV1V2(VR, VSphereNorm);// ������� ���� ����� �������� ����� ���������� R � �������� ������� N � ����� ����� ����
			PV(0) = VCart(0);
			PV(1) = VCart(1);
			PV(2) = VCart(2);
			PV(3) = 1;
			PV = MV * PV;							// ���������� ����� � ���
			VCart(0) = PV(0);
			VCart(1) = PV(1);
			VCart(2) = 1;
			VCart = MW * VCart;						// ���������� ����� � ���
			CMatrix  VP = VS - VR;					// ����������� �� �������� ����� ������������ ������� � ����� �������
			double cos_PN = CosV1V2(VP, VSphereNorm); // ���� ������� ����	��
			if (cos_PN > 0)							// ���� ����� ����� ����������...
			{
				if (Index == 0)						//������������ ������ ��������� ����� 
					kLight = cos_PN*cos_RN;
				if (Index == 1)						//���������� ������ ��������� ����� 
				{
					double xx = 2 * ModVec(VP)*cos_PN / ModVec(VSphereNorm); // ������������� ��������� 
					CMatrix RX = (VSphereNorm*xx) - VP; // ������ ���������
					double cos_A = CosV1V2(RX, VR);		// ���� ����� �������� ��������� � �������� ����������
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