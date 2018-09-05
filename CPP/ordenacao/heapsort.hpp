#ifndef HEAPSORT_HPP_INCLUDED
#define HEAPSORT_HPP_INCLUDED

int pai(int i){
    int a = i/2;
    return a;
}

int esq(int i){
    int a = 2*i;
    return a;
}

int dir(int i){
    int a = 2*i+1;
    return a;
}

template<typename T>
void heapifica(T* v, int pai, int tam){
    int l = esq(pai), r = dir(pai), maior;
    if(l < tam && v[l] > v[pai])
        maior = l;
    else
        maior = pai;
    if(r < tam && v[r] > v[maior])
        maior = r;
    if(maior != pai){
        T a = v[maior];
        v[maior] = v[pai];
        v[pai] = a;
        heapifica(v, maior, tam);
    }
}

template<typename T>
void constroiHeap(T* v, int tam){
    for (int i = tam/2 -1; i >= 0; i--)
        heapifica(v,i,tam);
}

template<typename T>
void heapsort(T* v, int tam){
    int tamHeap = tam;
    constroiHeap(v,tam);
    for(int i = tam-1 ; i >= 0; i--){
        T temp = v[0];
        v[0] = v[i];
        v[i] = temp;
        tamHeap -= 1;
        heapifica(v,0,i);
    }
}

#endif // HEAPSORT_HPP_INCLUDED
