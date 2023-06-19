#include <iostream>
#include "avl.h"

using namespace std;

NoAVL::NoAVL(const int chave) : chave(chave),
                          altura(0),
                          pai(NULL),
                          esq(NULL),
                          dir(NULL)
{}

bool NoAVL::eh_raiz()
{
    return pai == NULL;
}

bool NoAVL::eh_direito() {
  return !eh_raiz() and pai->dir == this;
}

bool NoAVL::eh_esquerdo() {
  return !eh_raiz() and pai->esq == this;
}

int NoAVL::bal()
{
    int alt_esq = esq ? esq->altura : -1;
    int alt_dir = dir ? dir->altura : -1;
    return alt_esq - alt_dir;
}

void NoAVL::atualiza_altura()
{
    int alt_esq = esq ? esq->altura : -1;
    int alt_dir = dir ? dir->altura : -1;
    altura = 1 + (alt_esq > alt_dir ? alt_esq : alt_dir);
}

AVL::AVL(){
    raiz = NULL;
}

NoAVL* AVL::get_raiz(){
    return raiz;
}

NoAVL* AVL::ajusta_balanceamento(NoAVL* p) {
  
  p->atualiza_altura();
  
  if (p->bal() == 2) {       // Caso 1
    if (p->esq->bal() >= 0)  // Caso 1.1
      rotacao_dir(p);
    else                     // Caso 1.2
      rotacao_dupla_dir(p);
    p = p->pai;              // após a rotação p desceu 1 nível, precisamos subir de volta
  }
  else if (p->bal() == -2) { // Caso 2
    if (p->dir->bal() <= 0)  // Caso 2.1
      rotacao_esq(p);
    else                     // Caso 2.2
      rotacao_dupla_esq(p);
    p = p->pai;              // após a rotação p desceu 1 nível, precisamos subir de volta
  }
  
  return p;
}

void AVL::insere(int chave) {
  NoAVL *z = new NoAVL(chave);
  insere(z);
}

void AVL::insere(NoAVL* z){
    NoAVL* y = NULL;
    NoAVL* x = raiz;

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

    if(z->eh_raiz()){
        return;
    }

    do{
        z = z->pai;
        z = ajusta_balanceamento(z);
    }while(!z->eh_raiz() and z->bal() != 0);
}

void AVL::transplante(NoAVL* u, NoAVL* v) {
  if (u->eh_raiz())
    raiz = v;
  else
    if (u->eh_esquerdo())
      u->pai->esq = v;
    else
      u->pai->dir = v;

  if (v != NULL)
    v->pai = u->pai;
}


void AVL::rotacao_dir(NoAVL* p) {
  NoAVL *u = p->esq;
  // arruma u e seu pai (o pai de p)
  transplante(p, u);
  // move p para a direita de u, e o filho direito de u para a esquerda de p
  p->pai = u;
  p->esq = u->dir;
  u->dir = p;
  if (p->esq) p->esq->pai = p;
  // atualiza alturas
  p->atualiza_altura();
  u->atualiza_altura();
}

void AVL::rotacao_esq(NoAVL* p) {
  NoAVL *u = p->dir;
  // arruma u e seu pai (o pai de p)
  transplante(p, u);
  // move p para a esquerda de u, e o filho esquerdo de u para a direita de p
  p->pai = u;
  p->dir = u->esq;
  u->esq = p;
  if (p->dir) p->dir->pai = p;
  // atualiza alturas
  p->atualiza_altura();
  u->atualiza_altura();
}

void AVL::rotacao_dupla_dir(NoAVL* p) {
  rotacao_esq(p->esq);
  rotacao_dir(p);
}

void AVL::rotacao_dupla_esq(NoAVL *p) {
  rotacao_dir(p->dir);
  rotacao_esq(p);
}

void AVL::limpa() {
  limpa(raiz);
  raiz = NULL;
}

void AVL::limpa(NoAVL* x) {
  if (x == NULL)
    return;

  limpa(x->esq);
  limpa(x->dir);
  delete x;
}

AVL::~AVL() {
  limpa();
}

void AVL::printar(){
    printar(raiz);
}

void AVL::printar(NoAVL* p){
    if(p != NULL){
        printar(p->esq);
        //cout << p->chave << " ";
        printar(p->dir);
    }
}
