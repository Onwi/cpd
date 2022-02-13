#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "aux-functions.h"

#define SHELL 1
#define KNUTH 2
#define CIURA 3

int main(int argc, char *argv[])
{
	string _shell = "SHELL";
	string _knuth = "KNUTH";
	string _ciura = "CIURA";
	string str;
	int count, num, arrsize;
	int *arr1, *arr2, *arr3;
	double temp;

	// FIRST ASSIGNMENT
	ofstream saida("saida1.txt");
	ifstream entrada("entrada1.txt");
	if (!saida.is_open())
		return -1;
	if (!entrada.is_open())
		return -1;

	while (getline(entrada, str))
	{
		count = 0;
		istringstream ss(str);
		ss >> arrsize; // first number of the line which will be the array size
		arr1 = new int[arrsize];
		arr2 = new int[arrsize];
		arr3 = new int[arrsize];
		// fill array with rest of the line
		while (ss >> num)
		{
			arr1[count] = num;
			arr2[count] = num;
			arr3[count] = num;
			count++;
		}
		// calls shellsort for each sequence
		print_saida(arr1, arrsize, 0, _shell, saida);
		temp = shell_sort(arr1, arrsize, SHELL, saida);

		print_saida(arr2, arrsize, 0, _knuth, saida);
		temp = shell_sort(arr2, arrsize, KNUTH, saida);

		print_saida(arr3, arrsize, 0, _ciura, saida);
		temp = shell_sort(arr3, arrsize, CIURA, saida);

		check_correctness(arr1, arrsize);
		check_correctness(arr2, arrsize);
		check_correctness(arr3, arrsize);
	}
	
	// free memory
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	arr1 = NULL;
	arr2 = NULL;
	arr3 = NULL;

	saida.close();
	entrada.close();

	/*********** SECOND ASSIGNMENT ************/
	ofstream saida2("saida2.txt");
	ofstream saida3("saida3.txt"); // store sorted array for this assignment
	ifstream entrada2("entrada2.txt");
	if (!saida2.is_open())
		return -1;
	if (!saida3.is_open())
		return -1;
	if (!entrada2.is_open())
		return -1;

	// too lazy to make a function for this tbh
	while (getline(entrada2, str))
	{
		count = 0;
		istringstream ss(str);
		ss >> arrsize; // first number of the line which will be the array size
		arr1 = new int[arrsize];
		arr2 = new int[arrsize];
		arr3 = new int[arrsize];
		// fill array with rest of the line
		while (ss >> num)
		{
			arr1[count] = num;
			arr2[count] = num;
			arr3[count] = num;
			count++;
		}
		// calls shellsort for each sequence
		temp = shell_sort(arr1, arrsize, SHELL, saida3);
		saida2 << _shell << "," << arrsize << "," << temp << endl;

		temp = shell_sort(arr2, arrsize, KNUTH, saida3);
		saida2 << _knuth << "," << arrsize << "," << temp << endl;

		temp = shell_sort(arr3, arrsize, CIURA, saida3);
		saida2 << _ciura << "," << arrsize << "," << temp << endl;
		
		check_correctness(arr1, arrsize);
		check_correctness(arr2, arrsize);
		check_correctness(arr3, arrsize);
	}
	
	// free memory
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	arr1 = NULL;
	arr2 = NULL;
	arr3 = NULL;

	saida2.close();
	saida3.close();
	entrada2.close();

	return 0;
}
