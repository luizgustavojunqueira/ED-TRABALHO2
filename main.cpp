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

int main(int argc, char *argv[])
{

    int inc, step, max, rept, max_num;

   cin >> inc >> step >> max >> rept >> max_num;

    for (int i = inc; i <= max; i += step)
    {

        double mediaTempoABB = 0;
        double mediaTempoAVL = 0;
        double mediaTempoHeapSort = 0;


        for (int j = 0; j < rept; j++)
        {

            int *v = (int*) malloc(i * sizeof(int));
            for (int k = 0; k < i; k++)
            {
                v[k] = rand() % max_num;
            }

            clock_t inicioABB = clock();

            ABB abb;

            for (int k = 0; k < i; k++)
            {
                abb.insere(v[k]);
            }

            abb.printar();

            mediaTempoABB += (double)(clock() - inicioABB) / CLOCKS_PER_SEC;

            clock_t inicioAVL = clock();

            AVL avl;

            for (int k = 0; k < i; k++)
            {
                avl.insere(v[k]);
            }

            mediaTempoAVL += (double)(clock() - inicioAVL) / CLOCKS_PER_SEC;

            clock_t inicioHeap = clock();

            Heap h = Heap(i, v);

            for(int l = 0; l < i; l++){
                int x = h.extrai_maximo();
            }
            
            mediaTempoHeapSort += (double)(clock() - inicioHeap) / CLOCKS_PER_SEC;

        }

        mediaTempoABB = mediaTempoABB / rept;
        mediaTempoAVL = mediaTempoAVL / rept;
        mediaTempoHeapSort = mediaTempoHeapSort / rept;

        cout << i <<" numeros. ABB demorou: " << fixed << mediaTempoABB << setprecision(10) << " AVL demorou: " << fixed << mediaTempoAVL << setprecision(10) << " HEAPSORT demorou: " << fixed << mediaTempoHeapSort << setprecision(10) << endl;
    }

}
