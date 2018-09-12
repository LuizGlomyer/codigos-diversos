#ifndef GRAFO_HPP_INCLUDED
#define GRAFO_HPP_INCLUDED

#include "ListaLigada.hpp"

typedef int Vertice;

//Grafo por lista de adjacências
class Grafo_LA{
public:
    Grafo_LA(int);
    ~Grafo_LA();
    void inserirAresta(Vertice, Vertice);
    void inserirArestaDirecionada(Vertice, Vertice);
    void removerAresta(Vertice, Vertice);
    void mostrar();
    void reinicializar(int);
    ListaLigada<Vertice>* getAdj();
    int getTamanho();

    friend void DFS(Grafo_LA G);
    friend void DSF_VISITA(Grafo_LA G);
private:
    void inicializar(int);
    void destruir();
    ListaLigada<Vertice>* adj;
    int n, m; // n° de vertices e arestas
};

//Grafo por matriz de adjacências
class Grafo_MA{
public:
    Grafo_MA(int);
    ~Grafo_MA();
    void inserirAresta(Vertice, Vertice);
    void removerAresta(Vertice, Vertice);
    void mostrar();
    void reinicializar(int);
    int getTamanho();
    int** getMatriz();
private:
    void inicializar(int);
    void destruir();
    int n, m;
    int** mat;

};

//para grafo LA
class BuscaEmProfundidade{
public:
    BuscaEmProfundidade();
    ~BuscaEmProfundidade();
    void DFS(Grafo_LA&);
    void DFS_VISITA(Grafo_LA&, int);
    ListaLigada<Vertice> ordemTopologica; //apenas para grafos direcionados acicliclos
private:
    enum Cor {Branco, Cinza, Preto};
    Cor* cor;
    int* predecessorVertice;
    int* tempoEntrada;
    int* tempoSaida;
    int tempo;
};

class BuscaEmProfundidade_MA{
public:
    BuscaEmProfundidade_MA();
    ~BuscaEmProfundidade_MA();
    void DFS(Grafo_MA&);
    void DFS_VISITA(Grafo_MA&, int);
    ListaLigada<Vertice> ordemTopologica; //apenas para grafos direcionados acicliclos
private:
    enum Cor {Branco, Cinza, Preto};
    Cor* cor;
    int* predecessorVertice;
    int* tempoEntrada;
    int* tempoSaida;
    int tempo;
};


#endif // GRAFO_HPP_INCLUDED
