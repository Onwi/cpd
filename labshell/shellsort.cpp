#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

#include "aux-functions.h"

//--------------------------------------------------------------
double shell_sort(int C[], int tam, int seq, std::ofstream &saida)
{
	//--------------------------------------------------------------
	clock_t start_clock, end_clock;
	long changes = 0;
	int i, j, k = 10, chave;
	int h = 1, p = 11;								  // p-> exponent of 2^p-1 to be used in the shell sequence, arbitrarily defined by me
	int ciura[11] = {1, 4, 10, 23, 57, 132, 301, 701, 1577, 3548, 7983}; // ciura sequence

	// it doesn't really matter which string will be passed to print_saida() here, but it does need a string so.. why not
	std::string _shell = "SHELL";
	std::string _knuth = "KNUTH";
	std::string _ciura = "CIURA";

	// ITS A MESS BUT IT WORKS
	switch (seq)
	{
	case 1: // 2^p sequence
		start_clock = clock();
		while (p >= 1)
		{
			h = pow(2, p - 1);
			for (i = h; i < tam; i++)
			{
				chave = C[i];
				j = i - h;
				while (j >= 0 && chave < C[j])
				{
					C[j + h] = C[j];
					changes++;
					j -= h;
				}
				C[j + h] = chave;
			}
			print_saida(C, tam, h, _shell, saida);
			p--;
		}
		end_clock = clock();
		break;
	case 2: // knuth sequence
		start_clock = clock();
		while (h < tam)
			h = 3 * h + 1;
		while (h > 1)
		{
			h /= 3;
			for (i = h; i < tam; i++)
			{
				chave = C[i];
				j = i - h;
				while (j >= 0 && chave < C[j])
				{
					C[j + h] = C[j];
					changes++;
					j -= h;
				}
				C[j + h] = chave;
			}
			print_saida(C, tam, h, _knuth, saida);
		}
		end_clock = clock();
		break;
	case 3: // ciura sequence
		start_clock = clock();
		h = ciura[k];
		while (k >= 0)
		{
			for (i = h; i < tam; i++)
			{
				chave = C[i];
				j = i - h;
				while (j >= 0 && chave < C[j])
				{
					C[j + h] = C[j];
					changes++;
					j -= h;
				}
				C[j + h] = chave;
			}
			print_saida(C, tam, h, _ciura, saida);
			k--;
			h = ciura[k];
		}
		end_clock = clock();
		break;
	default:
		std::cout << "invalid sequence argument" << std::endl;
		return -1;
	}

	return (end_clock - start_clock) / (double)CLOCKS_PER_SEC;
}
