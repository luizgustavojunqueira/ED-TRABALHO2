#include "abb.h"

int main(){
    ABB abb;
    for(int i = 0; i < 11; i++){
        abb.insere(i);
    }

    abb.printar();
}