/*as ordenações só funcionam com template de char* se na declaração a varíavel for declarada como []. Ex
char nome[] = "teste";
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


#include "bubblesort.hpp"
#include "selectionsort.hpp"
#include "insertionsort.hpp"
#include "quicksort.hpp"
#include "mergesort.hpp"
#include "heapsort.hpp"
#include "shellsort.hpp"
#include "countingsort.hpp"
#include "combsort.hpp"
#include "bogosort.hpp"




template<typename T>
bool estaOrdenado(T& vetor, int tam){
    for(int i = 0; i < tam-1; i++)
        if(vetor[i] > vetor[i+1])
            return false;
    return true;
}
void geraVetor(int* v, int tam){
    srand(time(NULL));
    for(int i = 0; i < tam; i++)
        v[i] = rand()%100 + 1;
}
template<typename T>
void mostraVetor(T& v, int tam){
    for(int i = 0; i < tam; i++)
        cout << "Indice: " << i << " - \t" << v[i] << endl;
    cout << endl;
}
int maiorElemento(int* v, int tam){
    int c = 0;
    for(int i = 0; i < tam; i++)
        if(v[i] > c)
        c = v[i];
    return c;
}

int main(){
    //consertar e mergesort! adc heapsort bucketsort
    string nomes[] = {"kek","hue","lol","ss", "zanza", "lwa","debiru"};
    heapsort(nomes,7);
    //quicksort(nomes,0,5);
    mostraVetor(nomes,7);

    int hea[] = {16,5,90,6,-1,13};
    heapsort(hea, 6);
    mostraVetor(hea, 6);


    int tam;
    cout << "insira o tamanho: ";
    cin >> tam;
    int* v = new int[tam];
    int* t = new int[tam];
    geraVetor(v, tam);
    clock_t inicio, fim;

    mostraVetor(v, tam);
    inicio = clock();
    countingsort(v, t, tam, maiorElemento(v,tam));
    fim = clock();
    mostraVetor(t,tam);
    double tempo = (double)(fim-inicio)/CLOCKS_PER_SEC;
    cout << "tempo: " << tempo << endl;

    //mostraVetor(v, tam);
    /*char n[7] = "adenor";
    string k[2] {"abacate", "abacaxi"};
    cout << estaOrdenado(v, 5) << endl;
    cout << estaOrdenado(b, 5) << endl;
    cout << estaOrdenado(n, 6) << endl;
    cout << estaOrdenado(k, 2) << endl;
    cout << estaOrdenado(b, 5) << endl;*/

    return 0;
}
