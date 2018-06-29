#include <iostream>
#include <locale.h>
#define N 10
using namespace std;

int main(){

    /*Seja L uma lista composta de números inteiros cujos nós são l 1 , l 2 , l 3 , ..., l n .
Escreva um programa para percorrer L, uma única vez, construa uma outra
lista L’ formada dos seguintes elementos:
a) l 2 , l 3  ,..., l n , l 1;
b) l n , l n - - 1 ,…, l 1;
c) l 1 +l n , l 2 +l n - - 1 ,…,l n/2 +l n/2+1 ; onde n é par.*/
    setlocale(LC_ALL, "ptb");
    int lista[N] = {1,2,3,4,5,6,7,8,9,10};
    int x[N];
    //letra a
    int i, c;
    for(i = 0, c = 1; i <= N; i++, c++){
        if(i == N-1){
            x[i] = lista[0];
            break;
        }
        x[i] = lista[c];
    }

    for(i = 0; i<N; i++)
        cout << x[i] << " ";
    cout << endl;
    //letra b
    int l[N] = {1,2,3,4,5,6,7,8,9,10}, y[N];
    for(i = 0, c = N; i < N; i++, c--){
        y[i] = l[c-1];
    }
    for(i = 0; i < N; i++)
        cout << y[i] << " ";
    cout << endl;
    //letra c
    int LISTA[10] = {1,2,3,4,5,6,7,8,9,10}, z[5];
    for(i = 0, c = N; i<N/2; i++, c--){
        z[i] = LISTA[i]+LISTA[c-1];
    }

    for(i = 0; i < N/2; i++)
        cout << z[i] << " ";


/*Escreva um programa para:
a) Verificar se um número pertence lista;
e) Copiar uma lista l 1 para uma lista l 2;
f) Concatenar uma lista l 1 com uma lista l 2;
g) Intercalar l 1 e l 2; */

  //a)
    int t1[N] = {90,80,70,60,50,40,30,20,10,100}, t2[N] = {11,22,33,44,55,66,77,88,99,111}, t3[2*N],t4[2*N], input;
    cout << "\n\nInsira um número" << endl;
    cin >> input;
    for(int i = 0; i < 10; i++)
        if(input == t1[i])
            cout << "Elemento encontrado, posição " << i << endl;



    //g) Intercalar l 1 e l 2;


    for(int j = 0, i = 0; i < 2*N; i++){
        t4[j] = t1[i];
        j++;
        t4[j] = t2[i];
        j++;
    }
    cout << "\nIntercalados: "<< endl;
    for(int i = 0; i < 2*N; i++){
        cout << t4[i] << " ";
    }

    //e)
    cout << "\nCópia" << endl;
    for(int i = 0; i < N; i++){
        t1[i] = t2[i];
        cout << t1[i] << " ";
    }


     //f)
    cout << "\nConcatenação" << endl;
    for(int i = 0, j = 0; i < 2*N; i++){
        if(i < N){
            t3[j] = t1[j];
            j++;
        }
        else{
            if(i == N)
                j = 0;
            t3[i] = t2[j];
            j++;
        }
    }

    for(int i = 0; i < 2*N; i++)
        cout << t3[i] << " ";
    cout << endl;

    /*Escreva um programa que remova todos os elementos com chaves pares de
uma lista.*/

    cout << "\n Removendo pares" << endl;

    int pares[20] = {2,80,9,17,60,45,67,89,113,42,114,70,60,33,176,87,907,50,19,204},cont = 0, sempares[20];
    for(i = 0; i < 20; i++)
        if(pares[i] % 2 != 0){
            sempares[cont] = pares[i];
            cont++;
        }
    for(i = 0; i < cont; i++){
        cout << sempares[i] << " ";
    }








    return 0;
}
