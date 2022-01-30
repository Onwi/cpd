#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

//--------------------------------------------------------------
void print_array(int C[], int tam)
{
    //--------------------------------------------------------------
    printf("[");
    for (int i = 0; i < tam - 1; i++)
    {
        printf("%d, ", C[i]);
    }
    printf("%d]\n", C[tam - 1]);
}

//--------------------------------------------------------------
void check_correctness(int C[], int tam)
{
    //--------------------------------------------------------------
    for (int i = 0; i < tam - 1; i++)
    {
        if (C[i] > C[i + 1])
        {
            printf("\n***** INCORRECT ORDERING *****");
            return;
        }
    }
}

//--------------------------------------------------------------
int binary_search(int C[], int low, int high, int key)
{
    //--------------------------------------------------------------
    int mid;

    if (low == high)
        return low;

    mid = low + ((high - low) / 2);

    if (key > C[mid])
        return binary_search(C, mid + 1, high, key);
    else if (key < C[mid])
        return binary_search(C, low, mid, key);

    return mid;
}

/*
 * @seq -> current sequence increment
 * or if its 0 prints the sequence name
 * */
void print_saida(int C[], int tam, int seq, std::string tipo, std::ofstream &saida)
{
    if (saida)
    {
        for (int i = 0; i < tam - 1; i++)
        {
            saida << C[i] << " ";
        }
        if (seq == 0)
        {
            saida << C[tam - 1] << " SEQ=" + tipo << std::endl;
        }
        else if (seq > 0)
        {
            saida << C[tam - 1] << " INCR=" << seq << std::endl;
        }
    }
}
