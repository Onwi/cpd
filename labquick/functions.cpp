#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;

#include "functions.h"

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int mediana(int i, int f, int m) {
	if ((i <= f) && (f <= m)) return f;
	if ((i <= m) && (m <= f)) return m;
	if ((f <= i) && (i <= m)) return i;
	if ((f <= m) && (m <= i)) return m;
	if ((m <= i) && (i <= f)) return i;
	return f;
}

int med_lomuto(int c[], int i, int f, int *swaps){
	int m = (i+f)/2;
	int med = mediana(i, f, m);
	swap(&c[f], &c[med]);
	swaps++;
	return lomuto(c, i, f, swaps);
}

int med_hoare(int c[], int i, int f, int *swaps){
	int m = (i+f)/2;
	int med = mediana(i, f, m);
	swap(&c[i], &c[med]);
	swaps++;
	return hoare(c, i, f, swaps);
}

int random(int i, int f){
	srand(time(NULL));
	return rand() % f + i;
}

int rand_lomuto(int c[], int i, int f, int *swaps){
	int r = random(i+1, f);
	swap(&c[f], &c[r]);
	swaps++;
	return lomuto(c, i, f, swaps);
}

int rand_hoare(int c[], int i, int f, int *swaps){
	int r = random(i+1, f);
	swap(&c[i], &c[r]);
	swaps++;
	return hoare(c, i, f, swaps);
}

int lomuto(int c[], int i, int f, int *swaps){
	int pivo = c[f];
	int k = (i -1);

	for(int j = i; j <= f-1; j++){
		if(c[j] <= pivo){
			k++;
			swap(&c[k], &c[j]);
			swaps++;
		}
	}
	swap(&c[k+1], &c[f]);
	swaps++;
	return k+1;
}

int hoare(int c[], int i, int f, int *swaps){
    int pivo = c[i];
    int k = i - 1, j = f + 1;

    while(true){
        do{
           	k++;
        }while (c[k] < pivo);

        do{
            j--;
        }while (c[j] > pivo);

        if(k >= j)
            return j;

        swap(&c[k], &c[j]);
				swaps++;
    }
}

void print_array(int C[], int tam) {
  printf ("[");
  for (int i=0; i<tam-1; i++) {
    printf("%d, ", C[i]);
  }
  printf ("%d]\n", C[tam-1]);
}

void check_correctness (int C[], int tam) {
  for (int i=0; i<tam-1; i++) {
      if (C[i]>C[i+1]) {
          printf ("\n***** INCORRECT ORDERING *****");
          return;
      }
  }
}

void print_saida(int tam, int swaps, int rec, double temp, std::ofstream &saida){
    if(saida){
			saida << "TAMANHO ENTRADA " << tam << endl;
      saida << "SWAPS " << swaps << endl;
			saida << "RECURSOES " << rec << endl;
			saida << "TEMPO " << temp << endl;
    }
}
