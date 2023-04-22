#pragma once
#include "Graph.h"
#include <queue>
struct BFS   // breadth-first search поиск в ширину (связный граф)
{
	const static int INF = 0x7fffffff;
	const static int NIL = -1;
	enum Color { WHITE, GRAY, BLACK };       //
	const graph::AList* al;                // исходный граф
	Color* c;                              // цвет вершины
	int* d;                              // расстояние до вершины
	int* p;                              // предшествующая вершина
	std::queue<int> q;                     // очередь
	BFS(const graph::AList& al, int s);
	BFS(const graph::AMatrix& am, int s);
	void init(const graph::AList& al, int s);
	int get();                             // получить следующую вершину
};
