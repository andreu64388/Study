#include "BFS.h"
void BFS::init(const graph::AList& al, int s)
{
	this->al = &al;
	this->c = new Color[this->al->n_vertex];
	this->d = new int[this->al->n_vertex];
	this->p = new int[this->al->n_vertex];
	for (int i = 0; i < this->al->n_vertex; i++)
	{
		this->c[i] = WHITE;
		this->d[i] = INF;
		this->p[i] = NIL;
	};
	this->c[s] = GRAY;
	this->q.push(s);
};
BFS::BFS(const graph::AList& al, int s) { this->init(al, s); };
BFS::BFS(const graph::AMatrix& am, int s)
{
	this->init(*(new graph::AList(am)), s);
};

int BFS::get()
{
	int rc = NIL, v = NIL;
	if (!this->q.empty())
	{
		rc = this->q.front();
		for (int j = 0; j < this->al->size(rc); j++)
			if (this->c[v = this->al->get(rc, j)] == WHITE)
			{
				this->c[v] = GRAY;
				this->d[v] = this->d[rc] + 1;
				this->p[v] = rc;
				this->q.push(v);
			};
		this->q.pop();
		this->c[rc] = BLACK;
	};
	return rc;
}