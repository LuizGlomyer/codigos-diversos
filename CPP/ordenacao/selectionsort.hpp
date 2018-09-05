#include "troca.hpp"

template<typename T>
void selectionsort(T* vetor, int tam){
    for(int i = 0; i < tam-1; i++){
        int indicemenor = i;
        for(int j = i+1; j < tam; j++)
            if(vetor[indicemenor] > vetor[j])
                indicemenor = j;
        if(vetor[i] != vetor[indicemenor])
            troca(vetor[i], vetor[indicemenor]);
    }
}
