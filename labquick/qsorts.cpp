#include "functions.h"

void quicksort_lomuto(int c[], int i, int f, int swaps, int rec, double temp){
  if(f > i){
    int k = lomuto(c, i, f);
    quicksort_lomuto(c, i, k-1);
    quicksort_lomuto(c, k+1, f);
  }
}

void quicksort_hoare(int c[], int i, int f, int swaps, int rec, double temp){
  if(f > i){
    int k = hoare(c, i, f);
    quicksort_hoare(c, i, k);
    quicksort_hoare(c, k+1, f);
  }
}

void qsort_rand_lomuto(int c[], int i, int f, int swaps, int rec, double temp){
  if(f > i){
    int k = rand_lomuto(c, i, f);
    quicksort_lomuto(c, i, k-1);
    quicksort_lomuto(c, k+1, f);
  }
}

void qsort_rand_hoare(int c[], int i, int f, int swaps, int rec, double temp){
  if(f > i){
    int k = rand_hoare(c, i, f);
    quicksort_hoare(c, i, k);
    quicksort_hoare(c, k+1, f);
  }
}

void qsort_med_lomuto(int c[], int i, int f, int swaps, int rec, double temp){
  if(f > i){
    int k = med_lomuto(c, i, f);
    quicksort_lomuto(c, i, k-1);
    quicksort_lomuto(c, k+1, f);
  }
}

void qsort_med_hoare(int c[], int i, int f, int swaps, int rec, double temp){
  if(f > i){
    int k = med_hoare(c, i, f);
    quicksort_hoare(c, i, k);
    quicksort_hoare(c, k+1, f);
  }
}
