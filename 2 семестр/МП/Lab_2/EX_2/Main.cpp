// Main      
#include <iostream>
#include <tchar.h>
#include "Combi2.h"

using std::cout;
using std::endl;



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	char  AA[][2] = { "A", "B", "C", "D" };
	cout << endl << " --- ��������� ��������� ---";
	cout << endl << "�������� ���������: ";
	cout << "{ ";

	for (int i = 0; i < sizeof(AA) / 2; i++)
		cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	cout << "}";

	cout << endl << "��������� ��������� ";


	combi2::xcombination xc(sizeof(AA) / 2, 3);
	cout << "�� " << xc.n << " �� " << xc.m;
	int  n = xc.getfirst();
	while (n >= 0)
	{
		cout << endl << xc.nc << ": { ";
		for (int i = 0; i < n; i++)
			cout << AA[xc.ntx(i)] << ((i < n - 1) ? ", " : " ");
		cout << "}";
		n = xc.getnext();
	};


	cout << endl << "�����: " << xc.count() << endl;
	system("pause");
	return 0;
}