#pragma once
#include <utility>
#include <cassert>
#include <vector>
#include <iostream>

#ifndef __INCLUDE_BTREE_H__
#define __INCLUDE_BTREE_H__

// class BTreeNode : represents a node in a B Tree. Has a list of keys and a list of childs
// It may be a leaf or an internal node
class BTreeNode
{
private:
	BTreeNode * *child;				// list of child nodes in the node
	int *key;						// list of keys in the node
	int noOfKeys;					// total number of keys in this node, count current number of keys
	int t;							// minimum degree. (t-1) minimum keys and t minimum childs, (2t-1) maximum keys and 2t maximum childs
	bool bIsLeaf;					// is leaf node?
	friend class BTree;				// Btree is a friend class, it can access the private attributes of this class
public:
	/*
	default constructor
	*/
	BTreeNode(int, bool isLeaf);
	/*
	default destructor
	*/
	~BTreeNode();
	/*
	Returns the key at given index
	*/
	int getKey(int);
	/*
	Similer to the inorder traversal of tree
	Traverses the this node
	*/
	void TraverseNode();
	/*
	Search for k and return pair<node*, index> such that node->key[index] = k
	*/
	bool SearchNode(int, std::pair<BTreeNode*, int>&);
	/*
	Split the node, tree grows
	*/
	void SplitNodeChild(int);
	/*
	Insert into this Node, it's full
	*/
	bool InsertNodeNonFull(int);
};

class BTree
{
private:
	BTreeNode * root;	// root of the B Tree
	int t;	// branching factor or minimum degree. (t-1) minimum keys, t minimum childs and (2t-1) maximum keys, 2t maximum childs
public:
	/*
	Default constructor
	*/
	BTree(int);
	/*
	Default destructor
	*/
	~BTree();
	/*

	*/
	void Traverse();
	/*
	search for a value k, result will hold the node and the index where value is present
	*/
	bool Search(int, std::pair<BTreeNode*, int> &);
	/*
	insert a value to the B Tree
	*/
	bool Insert(int);
};

#endif // !__INCLUDE_BTREE_H__