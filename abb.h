#ifndef ABB_H
#define ABB_H

class No {
    friend class ABB;

public:
    No(const int chave);

private:
    int chave;
    No* pai;
    No* esq;
    No* dir;
};

class ABB {
public:
    ABB();
    ~ABB();

    void insere(int chave);
    void limpa();
    void printar();

private:
    No* raiz;
    void insere(No* z);
    void limpa(No* x);
    void printar(No* x);
};

#endif  // ABB_H