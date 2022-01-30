#ifndef aux_functions_h
#define aux_functions_h

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

// aux functions
void print_array(int C[], int tam);
void check_correctness(int C[], int tam);
int binary_search(int C[], int low, int high, int key);
void print_saida(int C[], int tam, int seq, std::string tipo, std::ofstream &saida);

// sorting algorithms

// @tam = array length
// @seq = sequence to be used, which can be one of the following
// 		1 = shell, 2^p-1
// 		2 = knuth
// 		3 = ciura
double shell_sort(int C[], int tam, int seq, std::ofstream &saida);

#endif /* aux_functions_h */
