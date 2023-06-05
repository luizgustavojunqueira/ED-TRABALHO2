#ifndef HEAPSORT_H
#define HEAPSORT_H

class Heap{
    public:
        Heap(int n, int vetor[]);
        ~Heap();

        int extrai_maximo();
    
    private:
        int *S;
        int tam;

        int pai(int i);
        int esquerdo(int i);
        int direito(int i);
        void troca(int i, int j);
        void desce(int i);
        void sobe(int i);

};

#endif  // HEAPSORT_H