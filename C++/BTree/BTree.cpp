#include "BTree.h"

/*
default constructor
*/
BTreeNode::BTreeNode(int minDegree, bool isLeaf = true)
{
	t = minDegree;					// min degree
	bIsLeaf = isLeaf;				// is this node a leaf? default consider it's a leaf
	noOfKeys = 0;					// current number of keys is zero, insertion will increase the number and deletion will decrease.
	key = new int[2 * t - 1];		// (2t - 1) maximum keys it can hold
	child = new BTreeNode*[2 * t];	// 2t maximum child it can link
}
/*
default destructor
*/
BTreeNode::~BTreeNode()
{
	delete child;
	delete key;
}
/*
Returns the key at given index
*/
int BTreeNode::getKey(int index)
{
	if (index < noOfKeys)
		return key[index];
	return NULL;
}
/*
Similer to the inorder traversal of tree
Traverses the this node
*/
void BTreeNode::TraverseNode()
{
	// before traversing the i'th key, we should traverse i'th child
	int i;
	for (i = 0; i < noOfKeys; i++)
	{
		if (!bIsLeaf)
			child[i]->TraverseNode();
		std::cout << key[i] << " ";
	}
	// now we chould traverse the last child
	if (!bIsLeaf)
		child[i]->TraverseNode();
}
/*
Search for k and return pair<node*, index> such that node->key[index] = k
*/
bool BTreeNode::SearchNode(int k, std::pair<BTreeNode*, int> &result)
{
	int i = 0;
	// go to the right index of keys in this node
	while (i < noOfKeys && k > key[i])
		i++;
	// Bingo! We have found you. Really? Need to check i first.
	if (i < noOfKeys && key[i] == k)
	{
		result = std::make_pair(this, i);
		return true;
	}
	// It's really bad, sorry we can't find your stuff :(
	if (bIsLeaf)
	{
		result = std::make_pair(nullptr, NULL);
		return false;
	}
	// try to find in the child
	return child[i]->SearchNode(k, result);
}
/*
Split the node, tree grows
*/
void BTreeNode::SplitNodeChild(int x)
{
	BTreeNode *y = child[x];
	BTreeNode *z = new BTreeNode(t, y->bIsLeaf);
	z->noOfKeys = t - 1;
	for (auto i = 0; i < t; i++)
	{
		z->key[i] = y->key[t + i];
	}
	if (!y->bIsLeaf)
	{
		for (auto i = 0; i < t; i++)
		{
			z->child[i] = y->child[t + i];
		}
	}
	y->noOfKeys = t - 1;
	// shift the childs one up, make room for the new child
	int j;
	for (j = noOfKeys; j != x; j--)	// 0 based indexing
	{
		child[j + 1] = child[j];
	}
	child[j + 1] = z;
	for (j = noOfKeys - 1; j != x - 1; j--)
	{
		key[j + 1] = key[j];
	}
	key[x] = y->key[t - 1];
	noOfKeys++;
}
/*
Insert into this Node, it's full
*/
bool BTreeNode::InsertNodeNonFull(int k)
{
	int i = noOfKeys - 1;	// 0 based indexing
							// if it is a leaf then insert here
	if (bIsLeaf)
	{
		// get to the right spot
		while (i >= 0 && k < key[i])
		{
			key[i + 1] = key[i];	// shift the keys, make space
			i--;
		}
		key[i + 1] = k;
		noOfKeys += 1;
		return true;
	}
	// it's not a leaf, find the right child where we can add k
	else
	{
		// get the right child
		while (i >= 0 && k < key[i])
		{
			i--;
		}
		i++;	// k should be in the right child of this node
		if (child[i]->noOfKeys == 2 * t - 1)
		{
			SplitNodeChild(i);
			if (k > key[i])
			{
				i++;
			}
		}
		child[i]->InsertNodeNonFull(k);
	}
	return false;
}

/*************************************************************************/
//
/*************************************************************************/

/*
Default constructor
*/
BTree::BTree(int d)
{
	t = d;
	root = nullptr;
}
/*
Default destructor
*/
BTree::~BTree()
{
	delete root;
}
/*

*/
void BTree::Traverse()
{
	if (root)
		root->TraverseNode();
}
/*
search for a value k, result will hold the node and the index where value is present
*/
bool BTree::Search(int k, std::pair<BTreeNode*, int> &result)
{
	return root ? root->SearchNode(k, result) : false;	// if there is no root, nothing to search in emptyness
}
/*
insert a value to the B Tree
*/
bool BTree::Insert(int k)
{
	// If the root is nullptr, tree is empty, first insert
	if (root == nullptr)
	{
		BTreeNode *tempNode = new BTreeNode(t, true);	// create a new node
		tempNode->key[0] = k;							// add the key
		tempNode->noOfKeys = 1;							// increase the number of keys
		root = tempNode;								// new root
		return true;
	}
	else
	{
		// if this root is full. Allocate a new node and make it the root 
		if (root->noOfKeys == 2 * t - 1)
		{
			BTreeNode *tempNode = new BTreeNode(t, false);	// a new node
			tempNode->child[0] = root;						//make the root a child of this node
			tempNode->noOfKeys = 0;							// currently there are no keys in the new root.
			root = tempNode;								// make new node the root
			tempNode->SplitNodeChild(0);					// it will increase the number of keys in the new root and shift one key up
			tempNode->InsertNodeNonFull(k);					// now we can add the key, as it's not full
		}
		// we can insert the value
		else
		{
			root->InsertNodeNonFull(k);	// root is not full add the key
		}
	}
	return false;
}