#include "troca.hpp"

template<typename T>
void insertionsort(T* vetor, int tam){
    for (int i = 1; i < tam; i++) {
		T escolhido = vetor[i];
		int j = i - 1;

		while ((j >= 0) && (vetor[j] > escolhido)) {
			vetor[j + 1] = vetor[j];
			j--;
		}

		vetor[j + 1] = escolhido;
	}
}
