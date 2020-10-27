#pragma once
#include <iostream>
#ifndef __INCLUDE_HASHTABLE_H__
#define __INCLUDE_HASHTABLE_H__

#define DEFAULT_TABLE_SIZE 7

#ifndef INFINITY
#define INFINITY 10241024
#endif // !INFINITY

/*****************************************************/
// Hash Table representation
class HashTable
{
public:
	/*
	default constructor
	*/
	HashTable();
	~HashTable();
	bool searchKey(int key);
	bool insertKey(int key);
	bool deleteKey(int key);
private:
	/*
	Hash function, internal to the class
	*/
	int hash(int key);
	/*
	hash table where the actual values are stored
	*/
	int *table;
	/*
	current size of table
	*/
	int sizeOfTable;
	/*
	current number of keys in the table
	*/
	int noOfKeys;

};

#endif // !__INCLUDE_HASHTABLE_H__