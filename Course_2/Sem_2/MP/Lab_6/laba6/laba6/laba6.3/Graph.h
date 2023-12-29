#pragma once
#include <list>
namespace graph
{
	struct AList;
	struct AMatrix  // ������� ���������
	{
		int  n_vertex;                  // ���������� ������
		int* mr;                       // �������
		AMatrix(int n);                 // ������� ������� ������� n*n
		AMatrix(int n, int mr[]);       // ������� ������� n*n �
		AMatrix(const AMatrix& am);     // ������� �������� �������
		AMatrix(const AList& al);       // ������� ������� �� ����������
		void set(int i, int j, int r);  // �������� mr[i,j] = r
		int  get(int i, int j)const;    // ������� mr[i,j]
	};

	struct AList  // ������ ���������
	{
		int  n_vertex;                 // ���������� ������
		std::list<int>* mr;            // ������ �������
		void create(int n);            // ������� ������ ������ �������
		AList(int n);                  // ������� ������ ������ �������
		AList(int n, int mr[]);        // ������� ��������� �������������
		AList(const AMatrix& am);      // ������� ��������� �������������
		AList(const AList& al);        // ������� ��������  ���������
		void add(int i, int j);        // �������� � i-�� ������
		int  size(int i) const;        // ������ i-�� ������
		int  get(int i, int j)const;   // j-��  ������� i-�� ������
	};
};
