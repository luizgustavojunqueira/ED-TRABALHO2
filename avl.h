#ifndef AVL_H
#define AVL_H

class NoAVL
{
    friend class AVL;

public:
    NoAVL(const int chave);
    bool eh_raiz();
    bool eh_direito();
    bool eh_esquerdo(); 
    int bal();
    void atualiza_altura();

private:
    int chave;
    int altura;
    NoAVL *pai;
    NoAVL *esq;
    NoAVL *dir;
};

class AVL
{
public:
    AVL();
    ~AVL();

    NoAVL *get_raiz();

    void insere(int chave);

    void limpa();

    void printar();

    double medirTempo(int *v, int i);

private:
    NoAVL *raiz;

    NoAVL *ajusta_balanceamento(NoAVL *p);

    void transplante(NoAVL *u, NoAVL *v);
    void insere(NoAVL *z);

    void limpa(NoAVL *x);

    void rotacao_dir(NoAVL *p);
    void rotacao_esq(NoAVL *p);
    void rotacao_dupla_dir(NoAVL *p);
    void rotacao_dupla_esq(NoAVL *p);

    void printar(NoAVL *p);
};

#endif // AVL_H