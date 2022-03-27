#include <iostream>
#include <fstream>
#include <sstream>

#include "hash.h"

using namespace std;

int main(int agrc, char *argv[]){
	ifstream entrada("nomes_10000.txt");
	ifstream consulta("consultas.txt");
	
	if(!entrada.is_open() || !consulta.is_open()) return -1;

	HashTable hash503(503);
	HashTable hash2503(2503);
	HashTable hash5003(5003);
	HashTable hash7507(7507);
	string line;
	
	// insert names from input on the table
	while(getline(entrada, line)){
		hash503.insert(line);
		hash2503.insert(line);
		hash5003.insert(line);
		hash7507.insert(line);
	}
	
	//search names on the table
	while(getline(consulta, line)){
		int i = hash503.search(line);		
	
		//write files
	}

	return 0;
}
