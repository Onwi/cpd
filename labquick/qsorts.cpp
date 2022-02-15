#include "functions.h"

void quicksort_lomuto(int c[], int i, int f, int *swaps, int *rec){
  if(f > i){
    (*rec)++;
    int k = lomuto(c, i, f, swaps);
    quicksort_lomuto(c, i, k-1, swaps, rec);
    quicksort_lomuto(c, k+1, f, swaps, rec);
  }
}

void quicksort_hoare(int c[], int i, int f, int *swaps, int *rec){
  if(f > i){
    (*rec)++;
    int k = hoare(c, i, f, swaps);
    quicksort_hoare(c, i, k, swaps, rec);
    quicksort_hoare(c, k+1, f, swaps, rec);
  }
}

void qsort_rand_lomuto(int c[], int i, int f, int *swaps, int *rec){
  if(f > i){
    int k = rand_lomuto(c, i, f, swaps);
    quicksort_lomuto(c, i, k-1, swaps, rec);
    quicksort_lomuto(c, k+1, f, swaps, rec);
  }
}

void qsort_rand_hoare(int c[], int i, int f, int *swaps, int *rec){
  if(f > i){
    int k = rand_hoare(c, i, f, swaps);
    quicksort_hoare(c, i, k, swaps, rec);
    quicksort_hoare(c, k+1, f, swaps, rec);
  }
}

void qsort_med_lomuto(int c[], int i, int f, int *swaps, int *rec){
  if(f > i){
    int k = med_lomuto(c, i, f, swaps);
    quicksort_lomuto(c, i, k-1, swaps, rec);
    quicksort_lomuto(c, k+1, f, swaps, rec);
  }
}

void qsort_med_hoare(int c[], int i, int f, int *swaps, int *rec){
  if(f > i){
    int k = med_hoare(c, i, f, swaps);
    quicksort_hoare(c, i, k, swaps, rec);
    quicksort_hoare(c, k+1, f, swaps, rec);
  }
}
