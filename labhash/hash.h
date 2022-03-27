#ifndef HASH_
#define HASH_
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>

using namespace std;

unsigned long hashing(const string& str, int size);

class HashTable{
	int size;
	list <string> * table;

public:
	HashTable(int t_size); // constructor
	
	// search for a name on Table	
	void insert(string str);
	// insert a name on Table
	int search(string str);
};

#endif //HASH_
