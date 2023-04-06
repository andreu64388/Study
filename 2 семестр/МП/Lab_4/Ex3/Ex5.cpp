#include <cmath>
#include <memory.h>
#include <iostream>
#include "MultyMatrix.h"   // ��������� ������ 

#define N 6
int main()
{
	clock_t tstart, tend,
		timeR, timeD;

	int Mc[N + 1] = { 9 ,12,  20,  23,  30,  40, 51 }, Ms[N][N], r = 0, rd = 0;

	memset(Ms, 0, sizeof(int) * N * N);

	tstart = clock();
	r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
	tend = clock();

	timeR = tend - tstart;

	setlocale(LC_ALL, "rus");
	std::cout << std::endl;
	std::cout << std::endl << "-- ����������� ������ (����������� �������) "
		<< std::endl;
	std::cout << std::endl << "����������� ������: ";
	for (int i = 1; i <= N; i++) std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "����������� ���������� �������� ���������: " << r;
	std::cout << std::endl << std::endl << "������� S" << std::endl;

	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}
	std::cout << std::endl;

	memset(Ms, 0, sizeof(int) * N * N);

	tstart = clock();
	rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
	tend = clock();

	timeD = tend - tstart;

	std::cout << std::endl
		<< "-- ����������� ������ (������������ ����������������) " << std::endl;
	std::cout << std::endl << "����������� ������: ";
	for (int i = 1; i <= N; i++)
		std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "����������� ���������� �������� ���������: "
		<< rd;
	std::cout << std::endl << std::endl << "������� S" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "����� ����������� �� ��������: " << timeR << std::endl
			  << "����� ����������� ���. �����������������: " << timeD << "\n\n";

	system("pause");

	return 0;
}
