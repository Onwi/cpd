#include "functions.h"
#include <stdlib.h>

#define NRO 1000

int main(){
	int arr1[NRO];
	int arr2[NRO];
	int arr3[NRO];
	int arr4[NRO];

	for (int i=0; i<NRO; i++) arr1[i] = rand() % NRO+1;
	for (int i=0; i<NRO; i++) arr2[i] = rand() % NRO+1;
	for (int i=0; i<NRO; i++) arr3[i] = rand() % NRO+1;
	for (int i=0; i<NRO; i++) arr4[i] = rand() % NRO+1;

	//qsort_rand_lomuto(arr1, 0, NR0-1);
	//qsort_med_lomuto(arr2, 0, NRO-1);

	//check_correctness(arr1, NRO);
	//check_correctness(arr2, NRO);

	//qsort_rand_hoare(arr3, 0, NRO-1);
	qsort_med_hoare(arr2, 0, NRO-1);

	//check_correctness(arr3, NRO);
	check_correctness(arr2, NRO);

	return 0;
}
