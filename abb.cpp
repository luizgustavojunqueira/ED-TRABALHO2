#include <iostream>
#include "abb.h"

using namespace std;

// Construtor da classe No
No::No(const int chave) : chave(chave), pai(NULL), esq(NULL), dir(NULL){}

//Implementações da classe ABB
ABB::ABB(){
    raiz = NULL;
}

ABB::~ABB(){
    limpa();
}

void ABB::insere(int chave){
    No* z = new No(chave);
    insere(z);
}

void ABB::insere(No* z){
    No* y = NULL;
    No* x = raiz;

    while(x != NULL){
        y = x;
        x = z->chave < x->chave ? x->esq : x->dir;
    }

    z->pai = y;

    if(y == NULL){
        raiz = z;
    }else{
        if(z->chave < y->chave){
            y->esq = z;
        }else{
            y->dir = z;
        }
    }
}

void ABB::limpa(){
    limpa(raiz);
    raiz = NULL;
}

void ABB::limpa(No* z){
    if(z == NULL){
        return;
    }

    limpa(z->esq);
    limpa(z->dir);
    delete z;
}

void ABB::printar(){
    printar(raiz);
}

void ABB::printar(No* x){
    if(x != NULL){
        printar(x->esq);
        //cout << x->chave << " ";
        printar(x->dir);
    }
}

//Recebe um vetor v e seu tamanho i
//insere cada item do vetor na estrutura da arvore
//e a percorre de forma ordenada.
//Retorna o tempo gasto para fazer esse processo
double ABB::medirTempo(int *v, int i){
    clock_t inicio = clock();

    for (int k = 0; k < i; k++)
    {
        insere(v[k]);
    }

    printar();

    return (double)(clock() - inicio) / CLOCKS_PER_SEC;
}