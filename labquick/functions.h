#ifndef functions_h
#define functions_h

#include <fstream>

// aux fuctions
void swap(int *a, int *b);
int mediana(int i, int f, int m);
int random(int i, int f);
void print_array(int C[], int tam);
void check_correctness (int C[], int tam);
void print_saida(int tam, int swaps, int rec, double temp, std::ofstream &saida);

// random partitions
int rand_lomuto(int c[], int i, int f, int *swaps);
int rand_hoare(int c[], int i, int f, int *swaps);

// median partitions
int med_lomuto(int c[], int i, int f, int *swaps);
int med_hoare(int c[], int i, int f, int *swaps);

// partitions for quicksort
int lomuto(int c[], int i, int f, int *swaps);
int hoare(int c[], int i, int f, int *swaps);

// qsorts
void quicksort_lomuto(int c[], int i, int f, int *swaps, int *rec);
void quicksort_hoare(int c[], int i, int f, int *swaps, int *rec);

// four quicksort functions with pivot x partition combinations
// random x Lomuto
void qsort_rand_lomuto(int c[], int i, int f, int *swaps, int *rec);

// random x Hoare
void qsort_rand_hoare(int c[], int i, int f, int *swaps, int *rec);

// median x lomuto
void qsort_med_lomuto(int c[], int i, int f, int *swaps, int *rec);

// median x Hoare
void qsort_med_hoare(int c[], int i, int f, int *swaps, int *rec);

#endif /* functions_h */
