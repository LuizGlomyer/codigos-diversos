#include <iostream>
using namespace std;
#define N 10

typedef struct{
    int valor;
    int prox;
}MATRICULA;


void mostrarValores(MATRICULA *m){
    for(int i = 0; i < N; i++)
        cout << m[i].valor << " ";
}

int main(void){
    int c = 0;
    MATRICULA v[N];
    for(int i = 0; i<N; i++){
        v[i].valor = c;
        c+=10;
    }
    v[0].prox = 2;
    v[1].prox = 3;
    v[2].prox = 4;
    v[3].prox = 5;
    v[4].prox = 6;
    v[5].prox = 7;
    v[6].prox = 8;
    v[7].prox = -1;
    v[8].prox = 9;
    v[9].prox = 1;

    mostrarValores(v);
    cout << endl;

    for(int i = 0;;){
        cout << v[i].valor << " ";
        i = v[i].prox;
        if(v[i].prox == -1){
            cout << v[i].valor;
            break;
        }
    }


    //a
    MATRICULA m[N];
    for(int i = 0; i<N; i++){

    }




    return 0;
}
