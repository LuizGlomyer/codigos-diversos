#include "troca.hpp"

template <typename T>
void bubblesort(T& vetor, int tam){
    for(int i = 0; i < tam-1; i++){
        bool mudou = false;
        for(int j = 0; j < tam-1-i; j++)
            if(vetor[j] > vetor[j+1]){
                troca(vetor[j], vetor[j+1]);
                mudou = true;
            }
        if(!mudou)
            return;
    }
}

