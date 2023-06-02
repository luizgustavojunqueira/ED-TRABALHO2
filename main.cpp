#include "abb.h"
#include "avl.h"
#include <random>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{

    int inc = atoi(argv[2]);
    int step = atoi(argv[3]);
    int max = atoi(argv[4]);
    int rept = atoi(argv[5]);
    int max_num = atoi(argv[6]);

    for (int i = inc; i <= max; i += step)
    {

        double mediaTempoABB = 0;
        double mediaTempoAVL = 0;


        for (int j = 0; j < rept; j++)
        {

            int v[i];
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

            abb.~ABB();

            clock_t inicioAVL = clock();

            AVL avl;

            for (int k = 0; k < i; k++)
            {
                avl.insere(v[k]);
            }

            mediaTempoAVL += (double)(clock() - inicioAVL) / CLOCKS_PER_SEC;

            avl.~AVL();
        }

        mediaTempoABB = mediaTempoABB / rept;
        mediaTempoAVL = mediaTempoAVL / rept;

        cout << i <<" numeros. ABB demorou: " << fixed << mediaTempoABB << setprecision(20) << " AVL demorou: " << fixed << mediaTempoAVL << setprecision(20) <<endl;
    }

}
