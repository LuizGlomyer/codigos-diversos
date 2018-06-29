#include <iostream>
using namespace std;
#define N 25
#include <locale.h>



int buscaBinaria(int x, int tam, int *v){
    int centro, inicio = 0, fim = tam-1;
    while(inicio <= fim){
        centro = (inicio+fim)/2;
        if(x == v[centro]) return 1;
        if(v[centro] < x) inicio = centro + 1;
        else fim = centro - 1;
    }
    return 0;
}




/*
int buscaBinaria (int x, int n, int v[]) {
   int e, m, d;                              // 1
   e = 0; d = n-1;                           // 2
   while (e <= d) {                          // 3
      m = (e + d)/2;                         // 4
      if (v[m] == x) return m;               // 5
      if (v[m] < x) e = m + 1;               // 6
      else d = m - 1;                        // 7
   }                                         // 8
   return 0;                                // 9
}
*/


int main(void){
    setlocale(LC_ALL, "ptb");
    int vetor[N], c = 0;
    int aa = 5/2;
    for(int i = 0; i<N; i++){
        vetor[i] = c;
        c+=10;
    }
    cout << "Vetor: ";
    for(int i = 0; i<N; i++)
        cout << vetor[i] << " ";
    cout << endl;

    cout << "Insira o valor a ser pesquisado bináriamente: ";
    int input;
    cin >> input;

    if(buscaBinaria(input, N, vetor))
        cout << "Valor encontrado!";
    else
        cout << "Valor não encontrado";




    return 99;
}
