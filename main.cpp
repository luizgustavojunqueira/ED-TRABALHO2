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

            time_t inicio, fim;
            
            time(&inicio);

            ABB abb;
            for(int i = 0; i < inc; i++){
                abb.insere(v[i]);
            }

            abb.printar();

            time(&fim);

            cout << "Demorou: " << fixed << double(fim - inicio) << setprecision(20) << endl;
            
            abb.~ABB();
        }
        
        mediaTempo = mediaTempo / rept;
    }
}