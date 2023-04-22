#pragma once
#include <list>
namespace graph
{
	struct AList;
	struct AMatrix  // матрица смежности
	{
		int  n_vertex;                  // количество вершин
		int* mr;                       // матрица
		AMatrix(int n);                 // создать нулевую матрицу n*n
		AMatrix(int n, int mr[]);       // создать матрицу n*n и
		AMatrix(const AMatrix& am);     // создать подобную матрицу
		AMatrix(const AList& al);       // создать матрицу из спискового
		void set(int i, int j, int r);  // записать mr[i,j] = r
		int  get(int i, int j)const;    // элемент mr[i,j]
	};

	struct AList  // списки смежности
	{
		int  n_vertex;                 // количество вершин
		std::list<int>* mr;            // массив списков
		void create(int n);            // создать массив пустых списков
		AList(int n);                  // создать массив пустых списков
		AList(int n, int mr[]);        // создать списковое представление
		AList(const AMatrix& am);      // создать списковое представление
		AList(const AList& al);        // создать подобную  структуру
		void add(int i, int j);        // добавить в i-ый список
		int  size(int i) const;        // размер i-го списка
		int  get(int i, int j)const;   // j-ый  элемент i-го списка
	};
};
