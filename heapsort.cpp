#include "heapsort.h"
#include <climits>
#include <stdlib.h>
#include <iostream>

using namespace std;

Heap::Heap(){}

Heap::~Heap(){
    free(S);
}

int Heap::pai(int i){
    return (i-1) / 2;
}

int Heap::direito(int i){
    return 2 * (i+1);
}

int Heap::esquerdo(int i){
    return 2 * (i + 1) - 1;
}

void Heap::troca(int i, int j){
    int aux = S[i];
    S[i] = S[j];
    S[j] = aux;
}

void Heap::desce(int i){
    int e, d, maior;

    e = esquerdo(i);
    d = direito(i);

    if(e < tam && S[e] > S[i]){
        maior = e;
    }else{
        maior = i;
    }

    if(d < tam && S[d] > S[maior]){
        maior = d;
    }

    if(maior != i){
        troca(i, maior);
        desce(maior);
    }
}

void Heap::sobe(int i){
    while(S[pai(i)] < S[i]){
        troca(i, pai(i));
        i = pai(i);
    }
}

int Heap::extrai_maximo(){
    int maior;
    if(tam > 0){
        maior = S[0];
        S[0] = S[tam-1];
        tam = tam - 1;
        desce(0);
        return maior;
    }
    else{
        return INT_MAX;
    }
}

//Contabiliza o tempo gasto para extrair 
//os itens de forma ordenada (decrescente) do heap e o retorna
double Heap::medirTempo(int n, int* vetor){
    clock_t inicio = clock();

    tam = n;
    S = vetor;

    int i;
    for(i = tam/2 - 1; i>=0; i--){
        desce(i);
    }

    for (int l = 0; l < tam; l++)
    {
        extrai_maximo();
    }

    return (double)(clock() - inicio) / CLOCKS_PER_SEC;
}