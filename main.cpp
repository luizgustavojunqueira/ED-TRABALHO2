#include "abb.h"
#include <random>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int inc = 100;
    int step = 100;
    int max = 1000;

    for(inc; inc <= max; inc += step){
        int rept = 10;
        double mediaTempo = 0;
        for(rept; rept > 0; rept--){
            int v[inc];
            for(int i = 0; i < inc; i++){
                v[i] = rand() % 10000;
            }

            clock_t inicio = clock();

            ABB abb;
            for(int i = 0; i < inc; i++){
                abb.insere(v[i]);
            }

            abb.printar();

            mediaTempo += (double)(clock() - inicio)/CLOCKS_PER_SEC;

            
            abb.~ABB();
        }
        
        cout << inc <<" numeros, demorou: " << fixed << mediaTempo << setprecision(20) << endl;
        
        mediaTempo = mediaTempo / rept;
    }
}