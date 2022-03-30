#include <iostream>
#include <fstream>
#include <sstream>

#include "hash.h"

#define CONSULTAS_SIZE 50

using namespace std;

int main(int agrc, char *argv[]){
	int colisoes;  
	int max503 = 0, max2503 = 0, max5003 = 0, max7507 =0;
	int total503 = 0, total2503 = 0, total5003 = 0, total7507 = 0;	
	ifstream entrada("nomes_10000.txt");
	ifstream consulta("consultas.txt");
	ofstream exp503("experimento503.txt");
	ofstream exp2503("experimento2503.txt");
	ofstream exp5003("experimento5003.txt");
	ofstream exp7507("experimento7507.txt");
	
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
		// table size = 503	
		colisoes = hash503.search(line);		
		total503 += colisoes;
		if(colisoes > max503) max503 = colisoes;	
		exp503 << line << " " << colisoes << endl;
	
		// table size = 2503
		colisoes = hash2503.search(line);
		total2503 += colisoes;
		if(colisoes > max2503) max2503 = colisoes;
		exp2503 << line << " " << colisoes << endl;
	
		// table size = 5003
		colisoes = hash5003.search(line);
		total5003 += colisoes;
		if(colisoes > max5003) max5003 = colisoes;
		exp5003 << line << " " << colisoes << endl;
	
		// table size = 7507
		colisoes = hash7507.search(line);
		total7507 += colisoes;
		if(colisoes > max7507) max7507 = colisoes;
		exp7507 << line << " " << colisoes << endl;
	}
	
	// write avg and max collisions
	exp503 << "MEDIA " << total503/CONSULTAS_SIZE << endl;
	exp503 << "MAXIMO " << max503 << endl;
	
	exp2503 << "MEDIA " << total2503/CONSULTAS_SIZE << endl;
	exp2503 << "MAXIMO " << max2503 << endl;

	exp5003 << "MEDIA " << total5003/CONSULTAS_SIZE << endl;
	exp5003 << "MAXIMO " << max5003 << endl;

	exp7507 << "MEDIA " << total7507/CONSULTAS_SIZE << endl;
	exp7507 << "MAXIMO " << max7507 << endl;

	// close files
	entrada.close();
	consulta.close();	
	exp503.close();
	exp2503.close();
	exp5003.close();
	exp7507.close();
		
	return 0;
}
