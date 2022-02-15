#ifndef functions_h
#define functions_h

// aux fuctions
void swap(int *a, int *b);
int mediana(int i, int f, int m);
int random(int i, int f);
void print_array(int C[], int tam);
void check_correctness (int C[], int tam);

// random partitions
int rand_lomuto(int c[], int i, int f);
int rand_hoare(int c[], int i, int f);

// median partitions
int med_lomuto(int c[], int i, int f);
int med_hoare(int c[], int i, int f);

// partitions for quicksort
int lomuto(int c[], int i, int f);
int hoare(int c[], int i, int f);

// qsorts
void quicksort_lomuto(int c[], int i, int f);

// four quicksort functions with pivot x partition combinations
// random x Lomuto
void qsort_rand_lomuto(int c[], int i, int f);

// random x Hoare
void qsort_rand_hoare(int c[], int i, int f);

// median x lomuto
void qsort_med_lomuto(int c[], int i, int f);

// median x Hoare
void qsort_med_hoare(int c[], int i, int f);

#endif /* functions_h */
