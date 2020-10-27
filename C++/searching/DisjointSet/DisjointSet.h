#pragma once

#ifndef __INCLUDE_DISJOINT_SET__
#define __INCLUDE_DISJOINT_SET__

class DisjointSet
{
private:
	int noOfElements;	// number of elements in the set
	int *rank;			// holds the rank of sets
	int *parent;		// holds the parent of each element
public:
	/*
	Default constructor, constructs singelton set of n elements
	*/
	DisjointSet(int n);
	/*
	Default destructor
	*/
	~DisjointSet();
	/*
	Finds the representative of it's set
	*/
	int Find(int x);
	/*
	Union of two sets 1. representative of x and 2. representative of y
	*/
	int Union(int x, int y);
private:
	/*
	makes a set of n element where each element is a representative of it's ows set and rank of each set is 0
	*/
	void MakeSet(void);
};

#endif // !__INCLUDE_DISJOINT_SET__