#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

#include "functions.h"

int main(int argc, char *argv[]){
	int count, arrsize, num;
	int swaps, rec;
	int *arr1, *arr2, *arr3, *arr4; // 4 arrays for 4 quicksorts
	string str;
	double temp;
	clock_t start_clock, end_clock;

	ifstream entrada("entrada-quicksort.txt");
	if(!entrada.is_open()) return -1;

	ofstream saida_rl("stats-aleatorio-lomuto.txt");
	ofstream saida_ml("stats-mediana-lomuto.txt");
	ofstream saida_rh("stats-aleatorio-hoare.txt");
	ofstream saida_mh("stats-mediana-hoare.txt");

	if(!saida_rl.is_open() || !saida_ml.is_open()
		 || !saida_rh.is_open() || !saida_mh.is_open()) return -1;

	while(getline(entrada, str)){
		count = 0;
		istringstream ss(str);
		ss >> arrsize; // first number of line is the array size
		arr1 = new int[arrsize];
		arr2 = new int[arrsize];
		arr3 = new int[arrsize];
		arr4 = new int[arrsize];

		//fill array with rest of the getline
		while (ss >> num){
			arr1[count] = num;
			arr2[count] = num;
			arr3[count] = num;
			arr4[count] = num;
			count++;
		}

		// call quicksorts and write statistics to file
		// rand x Lomuto -> arr1
		swaps = 0;
		rec = 0;
		start_clock = clock();
		qsort_rand_lomuto(arr1, 0, arrsize-1, &swaps, &rec);
		end_clock = clock();
		temp = (end_clock - start_clock) / (double)CLOCKS_PER_SEC;
		check_correctness(arr1, arrsize);
		print_saida(arrsize, swaps, rec, temp, saida_rl);

		// median x Lomuto -> arr2
		swaps = 0;
		rec = 0;
		start_clock = clock();
		qsort_med_lomuto(arr2, 0, arrsize-1, &swaps, &rec);
		end_clock = clock();
		temp = (end_clock - start_clock) / (double)CLOCKS_PER_SEC;
		check_correctness(arr2, arrsize);
		print_saida(arrsize, swaps, rec, temp, saida_ml);

		// rand x Hoare -> arr3
		swaps = 0;
		rec = 0;
		start_clock = clock();
		qsort_rand_hoare(arr3, 0, arrsize-1, &swaps, &rec);
		end_clock = clock();
		temp = (end_clock - start_clock) / (double)CLOCKS_PER_SEC;
		check_correctness(arr3, arrsize);
		print_saida(arrsize, swaps, rec, temp, saida_rh);

		// median x Hoare -> arr4
		swaps = 0;
		rec = 0;
		start_clock = clock();
		qsort_med_hoare(arr4, 0, arrsize-1, &swaps, &rec);
		end_clock = clock();
		temp = (end_clock - start_clock) / (double)CLOCKS_PER_SEC;
		check_correctness(arr4, arrsize);
		print_saida(arrsize, swaps, rec, temp, saida_mh);

		// free memory
		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		delete[] arr4;
		arr1 = NULL;
		arr2 = NULL;
		arr3 = NULL;
		arr4 = NULL;
	}

	// close files
	entrada.close();
	saida_rl.close();
	saida_ml.close();
	saida_rh.close();
	saida_mh.close();

	return 0;
}
