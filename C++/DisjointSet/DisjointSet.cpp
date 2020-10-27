#include "DisjointSet.h"

/*
Default constructor, constructs singelton set of n elements
*/
DisjointSet::DisjointSet(int n)
{
	noOfElements = n;				// total number of elements
	rank = new int[noOfElements];	// rank of each element, representative of a set
	parent = new int[noOfElements];	// parent of each element
	MakeSet();
}
/*
Default destructor
*/
DisjointSet::~DisjointSet()
{
	delete[]rank;
	delete[]parent;
}
/*
Finds the representative of it's set
*/
int DisjointSet::Find(int x)
{
	if (parent[x] == x)
		return parent[x];	// if parent of x is x itself, own representative
	else
		parent[x] = Find(parent[x]);	// using path compression heuristic
	return parent[x];
}
/*
Union of two sets 1. representative of x and 2. representative of y
*/
int DisjointSet::Union(int x, int y)
{
	int xRep = Find(x);	// get the representative of this element x in it's set
	int yRep = Find(y);	// get the representative of this element x in it's set
	if (xRep == yRep)	// if both belongs to same set, no need to union
		return xRep;
	if (rank[xRep] > rank[yRep])	// union by rank heuristic
	{
		parent[yRep] = xRep;
		return true;
	}
	else
	{
		parent[xRep] = yRep;
		if (rank[xRep] == rank[yRep])	// if ranks are same, increase the rank of new representative of the set
		{
			rank[xRep]++;
		}
		return true;
	}
	return false;
}
/*
makes a set of n element where each element is a representative of it's ows set and rank of each set is 0
*/
void DisjointSet::MakeSet(void)
{
	for (auto i = 0; i < noOfElements; i++)
	{
		rank[i] = 0;
		parent[i] = i;
	}
}