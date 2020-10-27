#include "HashTable.h"

/***************************************************/

HashTable::HashTable()
{
	sizeOfTable = DEFAULT_TABLE_SIZE;
	table = new int(sizeOfTable);
	noOfKeys = 0;
}

HashTable::~HashTable()
{
	delete[]table;
}

bool HashTable::searchKey(int key)
{
	int index = hash(key);
	if (table[index] != INFINITY && table[index] == key)
	{
		return true;
	}
	return false;
}

bool HashTable::insertKey(int key)
{
	int index = hash(key);
	if (table[index] != INFINITY)
	{
		table[index] = key;
		return true;
	}
	return false;
}

bool HashTable::deleteKey(int key)
{
	if (searchKey(key))
	{
		int index = hash(key);
		table[index] = INFINITY;
		return true;
	}
	return false;
}

int HashTable::hash(int key)
{
	return (key%sizeOfTable);
}

