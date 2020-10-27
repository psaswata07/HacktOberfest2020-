//#pragma once
#include <list>
#include <iostream>
#include <algorithm>
#include <vector>

#ifndef __INCLUDE_GRAPH_H__
#define __INCLUDE_GRAPH_H__

#define NIL 0
//#define INFINITY 1024

enum Colors { WHITE, GREY, BLACK };

/*****************************************************/
// Class Vertex. Represents Vertex of a Graph.
//template <class T> --TODO
class Vertex
{
private:
	int content;	// Content of the vertex.
	Colors color;	// Color of the vertex, useful in many Graph algorithms.
	int distance;	// Distance of this Vertex from another Vertex.
	int predecessor;	// Predecessor of this Vertex.
	int discovered;	// Timestamp of when this Vertex is discovered.
	int finished;	// Timestamp of when this Vertex is done processing.
	std::list<int> connection;	// List of all Vertex it's connected to.
public:
	Vertex();	// Default constructor.
	Vertex(int c);	// Constructor passes content as parameter.
	~Vertex();	// Default Destructor.
	friend class Graph;	// Graph is declaired as friend, all the private and protected is accessable from Graph class.
};

/*****************************************************/
// Class Graph. Represents Graph structure.
//template <class T>
class Graph
{
private:
	int noOfvertices;	// No. of vertices.
	int noOfedges;	// No. of edges.
	bool directed;	// Directed Graph or Undirected.
	std::vector<Vertex> AdjList;	// List of all the Vertices in this Graph. We want direct access to the notes thus vector is used.
public:
	Graph(int d);
	Graph(int v, bool d);
	~Graph();
	int addVertex(int c);
	void deleteVertex(int v);
	void addEdge(int u, int v);
	void deleteEdge(int u, int v);
	void BFSearch(int s);
	void DFSearch(int s);
};
/*****************************************************/

#endif // !__INCLUDE_GRAPH_H__