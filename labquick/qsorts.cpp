#include "functions.h"

void qsort_rand_lomuto(int c[], int i, int f){
  if(f > i){
    int k = rand_lomuto(c, i, f);
    quicksort(c, i, k-1);
    quicksort(c, k+1, f);
  }
}

void qsort_rand_hoare(int c[], int i, int f){
  if(f > i){
    int k = rand_hoare(c, i, f);
    quicksort(c, i, k-1);
    quicksort(c, k+1, f);
  }
}

void qsort_med_lomuto(int c[], int i, int f){
  if(f > i){
    int k = med_lomuto(c, i, f);
    quicksort(c, i, k-1);
    quicksort(c, k+1, f);
  }
}

void qsort_med_hoare(int c[], int i, int f){
  if(f > i){
    int k = med_hoare(c, i, f);
    quicksort(c, i, k-1);
    quicksort(c, k+1, f);
  }
}
