/**************************************************
 *
 * Luiz Gustavo Sabadim Spolon Junqueira e Arthur Henrique Andrade Farias
 * Trabalho 2
 * Professor(a): Fabio Henrique Viduani Martinez
 *
 */

#include "abb.h"
#include "avl.h"
#include "heapsort.h"
#include <random>
#include <iostream>
#include <iomanip>

using namespace std;

//Realiza o teste dos algoritmos e contabiliza o tempo
int main(int argc, char *argv[])
{

    int inc, step, max, rept, max_num;

    // Leitura dos argumentos utilizados para testar os algoritmos
    cin >> inc >> step >> max >> rept >> max_num;

    for (int i = inc; i <= max; i += step)
    {

        double mediaTempoABB = 0;
        double mediaTempoAVL = 0;
        double mediaTempoHeapSort = 0;

        for (int j = 0; j < rept; j++)
        {

            //Inicialização do vetor de testes com números pseudoaleatorios
            int *v = (int *)malloc(i * sizeof(int));
            for (int k = 0; k < i; k++)
            {
                v[k] = rand() % max_num;
            }

            ABB abb;

            mediaTempoABB += abb.medirTempo(v, i);

            AVL avl;

            mediaTempoAVL += avl.medirTempo(v, i);

            Heap h = Heap();

            mediaTempoHeapSort += h.medirTempo(i, v);
            
        }

        mediaTempoABB = mediaTempoABB / rept;
        mediaTempoAVL = mediaTempoAVL / rept;
        mediaTempoHeapSort = mediaTempoHeapSort / rept;

        cout << i << " numeros. ABB demorou: " << fixed << mediaTempoABB << setprecision(10) << " AVL demorou: " << fixed << mediaTempoAVL << setprecision(10) << " HEAPSORT demorou: " << fixed << mediaTempoHeapSort << setprecision(10) << endl;
    }
}
