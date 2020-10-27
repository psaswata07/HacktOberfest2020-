#include <iostream>
#include "BTree/BTree.h"
#include "DisjointSet/DisjointSet.h"
#include "Graph/Graph.h"
#include "HashTable/HashTable.h"

int main()
{
	/*Graph G(4, 1);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 2);
	G.addEdge(2, 0);
	G.addEdge(2, 3);
	G.addEdge(3, 3);
	G.BFSearch(2);
	return 0;*/
	/*BTree B(2);
	B.Insert(10);
	B.Insert(20);
	B.Insert(30);
	B.Insert(40);
	B.Insert(5);
	B.Insert(15);
	B.Insert(25);
	B.Insert(35);
	B.Traverse();
	std::pair<BTreeNode*, int> result;
	B.Search(20, result);
	std::cout << result.first->getKey(result.second) << std::endl;
	return 0;*/
	/*DisjointSet dj(4);
	dj.Union(0, 3);
	dj.Union(1, 2);
	if (dj.Find(0) == dj.Find(1))
	std::cout << "yes" << std::endl;
	else
	std::cout << "no" << std::endl;

	if (dj.Find(0) == dj.Find(3))
	std::cout << "yes" << std::endl;
	else
	std::cout << "no" << std::endl;

	if (dj.Find(2) == dj.Find(1))
	std::cout << "yes" << std::endl;
	else
	std::cout << "no" << std::endl;
	return 0;*/
	HashTable hs;
	hs.insertKey(15);
	hs.insertKey(5);
	hs.insertKey(1025);
	hs.insertKey(157);
	std::cout << hs.searchKey(15) << std::endl;
	std::cout << hs.searchKey(5) << std::endl;
	std::cout << hs.searchKey(1025) << std::endl;
	std::cout << hs.searchKey(157) << std::endl;
	hs.deleteKey(15);
	std::cout << hs.searchKey(15) << std::endl;
	return 0;
}