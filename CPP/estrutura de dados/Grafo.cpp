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

    adj = new ListaLigada<Vertice>[numVertices+1];
    n = numVertices;
    m = 0;
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


void Grafo_LA::inserirAresta(Vertice u, Vertice v){
    adj[u].inserir(v);
    adj[v].inserir(u);
    m++;
}

void Grafo_LA::inserirArestaDirecionada(Vertice u, Vertice v){
    adj[u].inserir(v);
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

int Grafo_LA::getTamanho(){
    return n;
}

ListaLigada<Vertice>* Grafo_LA::getAdj(){
    return adj;
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

int Grafo_MA::getTamanho(){
    return n;
}

int** Grafo_MA::getMatriz(){
    return mat;
}








BuscaEmProfundidade::BuscaEmProfundidade(){
    cor = nullptr;
    predecessorVertice = tempoEntrada = tempoSaida = nullptr;
}

BuscaEmProfundidade::~BuscaEmProfundidade(){
    if(cor != nullptr)
        delete [] cor;
    if(predecessorVertice != nullptr)
        delete [] predecessorVertice;
    if(tempoEntrada != nullptr)
        delete [] tempoEntrada;
    if(tempoSaida != nullptr)
        delete [] tempoSaida;
}


void BuscaEmProfundidade::DFS(Grafo_LA& G){
    tempo = 0;
    cor = new Cor[G.getTamanho()+1];
    predecessorVertice = new int [G.getTamanho()+1];
    tempoEntrada = new int [G.getTamanho()+1];
    tempoSaida = new int [G.getTamanho()+1];

    for(Vertice u = 1; u <= G.getTamanho(); u++){
        cor[u] = Branco;
        predecessorVertice[u] = -1;
    }
    for(Vertice u = 1; u <= G.getTamanho(); u++)
        if(cor[u] == Branco)
            DFS_VISITA(G, u);
}

void BuscaEmProfundidade::DFS_VISITA(Grafo_LA& G, int u){
    cout << "Vertice: " << u << '\n';
    tempo++;
    tempoEntrada[u] = tempo;
    cor[u] = Cinza;
    int* adjacenciaVertice = G.getAdj()[u].retornaInteiros(); //retorna inteiros nos dá uma vetor com os inteiros referentes aos vertices adjacentes a u

    /*for(int i = 1; i < adjacenciaVertice[0]; i++)
        cout << adjacenciaVertice[i] << '\n';
    cout << '\n';
    printa as adjacencias */

    for(Vertice v = 1; v < adjacenciaVertice[0]; v++){ //a posicao 0 apenas indica quantos elementos existem no vetor. Que engenhoso
        if(cor[adjacenciaVertice[v]] == Branco){
            predecessorVertice[adjacenciaVertice[v]] = u;
            DFS_VISITA(G, adjacenciaVertice[v]);
        }
    }

    cor[u] = Preto;
    tempo++;
    tempoSaida[u] = tempo;
    ordemTopologica.inserirInicio(u);
}









BuscaEmProfundidade_MA::BuscaEmProfundidade_MA(){
    cor = nullptr;
    predecessorVertice = tempoEntrada = tempoSaida = nullptr;
}

BuscaEmProfundidade_MA::~BuscaEmProfundidade_MA(){
    if(cor != nullptr)
        delete [] cor;
    if(predecessorVertice != nullptr)
        delete [] predecessorVertice;
    if(tempoEntrada != nullptr)
        delete [] tempoEntrada;
    if(tempoSaida != nullptr)
        delete [] tempoSaida;
}

void BuscaEmProfundidade_MA::DFS(Grafo_MA& G){
    tempo = 0;
    cor = new Cor[G.getTamanho()+1];
    predecessorVertice = new int [G.getTamanho()+1];
    tempoEntrada = new int [G.getTamanho()+1];
    tempoSaida = new int [G.getTamanho()+1];

    for(Vertice u = 1; u <= G.getTamanho(); u++){
        cor[u] = Branco;
        predecessorVertice[u] = -1;
    }
    for(Vertice u = 1; u <= G.getTamanho(); u++)
        if(cor[u] == Branco)
            DFS_VISITA(G, u);
}


void BuscaEmProfundidade_MA::DFS_VISITA(Grafo_MA& G, int u){
    cout << "Vertice: " << u << '\n';
    tempo++;
    tempoEntrada[u] = tempo;
    cor[u] = Cinza;


    for(int v = 1; v <= G.getTamanho(); v++){
        int a = G.getMatriz()[u][v];
        if(a != 0) //!= 0 pois a quando uma posicao é 0 é porque não existem arestas
            if(cor[v] == Branco){
            predecessorVertice[v] = u;
            DFS_VISITA(G, v);
        }
    }

    cor[u] = Preto;
    tempo++;
    tempoSaida[u] = tempo;
    ordemTopologica.inserirInicio(u);
}
