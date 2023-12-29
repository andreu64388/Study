#include <iostream>
#include "Graph.h"
#include "BFS.h"
#include "DFS.h"

int main()
{
	int m[7][7] = {
				  {0, 1, 1, 0, 0, 0, 0},
				  {0, 0, 0, 1, 0, 0, 0},
				  {0, 0, 0, 0, 0, 1, 0},
				  {0, 0, 1, 0, 1, 1, 1},
				  {0, 0, 0, 0, 0, 0, 1},
				  {0, 0, 0, 0, 0, 0, 1},
				  {0, 0, 0, 0, 0, 0, 0}
	};
	setlocale(LC_ALL, "rus");
	graph::AMatrix g1(7, (int*)m);
	std::cout << std::endl;
	std::cout << std::endl << "-- матрица смежности " << std::endl;
	for (int i = 0; i < g1.n_vertex; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < g1.n_vertex; j++) std::cout << g1.get(i, j) << " ";
	};
	std::cout << std::endl;

	graph::AList g2(g1);
	std::cout << std::endl;
	std::cout << std::endl << "-- списки смежных вершин " << std::endl;
	for (int i = 0; i < g1.n_vertex; i++)
	{
		std::cout << std::endl << i << ": ";
		for (int j = 0; j < g2.size(i); j++) std::cout << g2.get(i, j) << " ";
	}
	std::cout << std::endl;

	graph::AMatrix g3(g1);
	std::cout << std::endl;
	std::cout << std::endl << "-- матрица смежности " << std::endl;
	for (int i = 0; i < g3.n_vertex; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < g3.n_vertex; j++) std::cout << g3.get(i, j) << " ";
	};
	std::cout << std::endl;

	graph::AList g4(7, (int*)m);
	std::cout << std::endl;
	std::cout << std::endl << "-- списки смежных вершин " << std::endl;
	for (int i = 0; i < g4.n_vertex; i++)
	{
		std::cout << std::endl << i << ": ";
		for (int j = 0; j < g4.size(i); j++) std::cout << g4.get(i, j) << " ";
	}
	std::cout << std::endl;

	BFS b1(g2, 0);
	std::cout << std::endl;
	std::cout << std::endl << "-- поиск в ширину " << std::endl;
	int k1;
	while ((k1 = b1.get()) != BFS::NIL) std::cout << k1 << " ";
	std::cout << std::endl;

	DFS b2(g2);
	std::cout << std::endl;
	std::cout << std::endl << "-- поиск в глубину " << std::endl;
	for (int i = 0; i < g2.n_vertex; i++) std::cout << b2.get(i) << " ";
	std::cout << std::endl;

	int m3[7][7] = { {0, 1, 1, 1, 0, 0, 0},
                     {0, 0, 0, 1, 0, 0, 0},
                     {0, 0, 0, 1, 0, 1, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 1, 0, 1, 0, 0, 0},
                     {0, 0, 0, 1, 0, 0, 1},
                     {0, 0, 0, 0, 1, 0, 0}
	};
	graph::AList g5(7, (int*)m3);
	DFS b3(g5);
	std::cout << std::endl;
	std::cout << std::endl << "-- поиск в глубину (ориентированный граф) "
		<< std::endl;
	for (int i = 0; i < g5.n_vertex; i++) std::cout << b3.get(i) << " ";
	std::cout << std::endl;

	std::cout << std::endl << "Топологическая сортировка" << std::endl;
	for (std::vector <int>::iterator i(b3.topological_sort.begin()); i != b3.topological_sort.end(); ++i) std::cout << *i << ' ';
	std::cout << std::endl;

	system("pause");
	return 0;
}