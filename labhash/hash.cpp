#include "hash.h"

using namespace std;

// djb2 hashing algorithm by Dan Bernstein
unsigned long hashing(const string& str, int size){
    unsigned long hash = 5381;

    for(string::const_iterator it=str.begin();it!=str.end();it++)
        hash = ((hash << 5) + hash) + *it; /* hash * 33 + character */

	return hash % size;
}

HashTable::HashTable(int t_size){
	this->size = t_size;
	table = new list<string>[size];
}

void HashTable::insert(string str){
	int index = hashing(str, this->size);
	table[index].push_back(str);
}

// search for @str on the table,
// return @count >0, the number of hits to find the name on the table, or
// @count+1, if not found
int HashTable::search(string str){
	int index = hashing(str, this->size);
	list<string>::iterator i;
	int cont =1;

	for(i = table[index].begin(); i!= table[index].end(); i++, cont++){
		if(str.compare(*i) == 0){
			return cont;
		}
	}
	return cont+1;
}

