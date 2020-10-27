#include "Graph.h"

/*****************************************************/

Vertex::Vertex()
{
	content = NIL;
	color = WHITE;
	distance = INFINITY;
	predecessor = NIL;
	discovered = NIL;
	finished = NIL;
}

Vertex::Vertex(int c)
{
	content = c;
	Vertex();
}

Vertex::~Vertex()
{
	connection.clear();
}

/*****************************************************/

Graph::Graph(int d = 0)
{
	noOfvertices = 0;
	directed = d;
	noOfedges = 0;
}

Graph::Graph(int v, bool d = 0)
{
	noOfvertices = v;
	directed = d;
	noOfedges = 0;
	for (int i = 0; i<noOfvertices; i++)
	{
		Vertex *newVertex = new Vertex;
		AdjList.push_back(*newVertex);
	}
}

Graph::~Graph()
{
	AdjList.clear();
}

int Graph::addVertex(int c = NIL)
{
	Vertex *newVertex = new Vertex(c);
	AdjList.push_back(*newVertex);
	return AdjList.size() - 1;	// return the index of the newly inserted Vertex.
}

void Graph::deleteVertex(int v)
{
	// TODO
}

void Graph::addEdge(int u, int v)
{
	noOfedges++;
	AdjList[u].connection.push_front(v);
	if (!directed)
		AdjList[v].connection.push_front(u);
}

void Graph::deleteEdge(int u, int v)
{
	noOfedges--;
	AdjList[u].connection.remove(v);
	if (directed)
		AdjList[v].connection.remove(u);
}

void Graph::BFSearch(int s)
{
	for (int i = 0; i<noOfvertices && i != s; i++)
	{
		AdjList[i].color = WHITE;
		AdjList[i].distance = INFINITY;
		AdjList[i].predecessor = NIL;
	}
	AdjList[s].color = GREY;
	AdjList[s].distance = 0;
	AdjList[s].predecessor = NIL;
	std::list<int> q;
	q.push_back(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop_front();
		for (auto v = std::begin(AdjList[u].connection); v != std::end(AdjList[u].connection); v++)
		{
			if (AdjList[*v].color == WHITE)
			{
				AdjList[*v].color = GREY;
				AdjList[*v].distance = AdjList[u].distance + 1;
				AdjList[*v].predecessor = u;
				q.push_back(*v);
			}
		}
		AdjList[u].color = BLACK;
		std::cout << u << " ";
	}
	std::cout << std::endl;
}

void Graph::DFSearch(int s)
{
}

/*****************************************************/