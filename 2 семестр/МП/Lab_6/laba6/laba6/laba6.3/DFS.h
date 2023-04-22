#pragma once
#include "Graph.h"
#include <vector>

struct DFS   // depth-first search поиск в глубину
{
	const static int NIL = -1;
	enum Color { WHITE, GRAY, BLACK };       //
	const graph::AList* al;                // исходный граф
	Color* c;                              // цвет вершины
	int* d;                              // время обнаружения
	int* f;                              // время завершения обработки
	int* p;                              // предшествующая вершина
	int   t;                               // текущее время
	DFS(const graph::AList& al);
	DFS(const graph::AMatrix& am);
	std::vector <int> topological_sort; //результат топологической сортировки
	void visit(int v);
	void init(const graph::AList& al);
	int get(int i);                        // получить вершину
};
