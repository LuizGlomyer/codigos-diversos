#include "Grafo.hpp"
#include <iostream>
using namespace std;

Grafo_LA::Grafo_LA(int numVertices){
    n = 0;
    inicializar(numVertices);
}

Grafo_LA::~Grafo_LA(){
    destruir();
}

void Grafo_LA::inicializar(int numVertices){
    if(n != 0)
        destruir();
    adj = new ListaLigada<Vertice>[numVertices+1];
    n = numVertices;
    m = 0;
}

void Grafo_LA::inserirAresta(Vertice u, Vertice v){
    adj[u].inserir(v);
    adj[v].inserir(u);
    m++;
}

void Grafo_LA::removerAresta(Vertice u, Vertice v){

}

void Grafo_LA::mostrar(){
    for(int i = 1; i <= n; i++){
        cout << "Vertice " << i << ": " << endl;
        adj[i].mostrarLista();
    }
}

void Grafo_LA::destruir(){
    for(int i = 0; i <= n; i++)
        adj[i].esvaziar();
    delete [] adj;
    n = m = 0;
}

void Grafo_LA::reinicializar(int numVertices){
    destruir();
    inicializar(numVertices);
}




/*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*******************************************************************************************************************
*******************************************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                                                                                 */


Grafo_MA::Grafo_MA(int numVertices){
    inicializar(numVertices);
}

Grafo_MA::~Grafo_MA(){
    destruir();
}

void Grafo_MA::inicializar(int numVertices){
    n = numVertices;
    mat = new int*[n+1];
    mat[0] = nullptr;
    for(int i = 1; i <= n; i++){
        mat[i] = new int[n+1];
        for(int j = 1; j <= n; j++)
            mat[i][j] = 0;
    }
}

void Grafo_MA::destruir(){
    for(int i = 1; i <= n; i++)
        delete [] mat[i];
    delete [] mat;
}

void Grafo_MA::reinicializar(int numVertices){
    destruir();
    inicializar(numVertices);
}

void Grafo_MA::inserirAresta(Vertice u, Vertice v){
    mat[u][v]++;
    mat[v][u]++;
    m++;
}

void Grafo_MA::removerAresta(Vertice u, Vertice v){
    mat[u][v]--;
    mat[v][u]--;
    m--;
}

void Grafo_MA::mostrar(){
//    for(int i = 0; i <= n; i++)
    cout << '\t';
    for(int i = 1; i<= n; i++)
        cout << '[' << i << ']' << '\t';
    cout << '\n';

    for(int i = 1; i <= n; i++){
        cout << '[' << i << ']' << '\t';
        for(int j = 1; j <= n; j++)
            cout << mat[i][j] << '\t';
        cout << '\n';
    }
}
