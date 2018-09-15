#ifndef GRAFO_HPP_INCLUDED
#define GRAFO_HPP_INCLUDED

#include "ListaLigada.hpp"
#include "Fila.hpp"

typedef int Vertice;
enum Cor {Branco, Cinza, Preto};

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

    friend void DFS(Grafo_LA&);
    friend void DSF_VISITA(Grafo_LA&);
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
    Cor* cor;
    int* predecessorVertice;
    int* tempoEntrada;
    int* tempoSaida;
    int tempo;
};

class BuscaEmLargura{
public:
    BuscaEmLargura();
    ~BuscaEmLargura();
    void BFS(Grafo_LA&, Vertice);
    int* getDistancia() const;
private:
    Cor* cor;
    int* predecessorVertice;
    int* distancia;
    int distAtual;
    Fila<Vertice> fila;
};

class BuscaEmLargura_MA{
public:
    BuscaEmLargura_MA();
    ~BuscaEmLargura_MA();
    void BFS(Grafo_MA&, Vertice);
    int* getDistancia() const;
private:
    Cor* cor;
    int* predecessorVertice;
    int* distancia;
    int distAtual;
    Fila<Vertice> fila;

};

#endif // GRAFO_HPP_INCLUDED
