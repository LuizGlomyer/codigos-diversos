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
    void removerAresta(Vertice, Vertice);
    void mostrar();
    void reinicializar(int);
    ListaLigada<Vertice>* getAdj();
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
private:
    void inicializar(int);
    void destruir();
    int n, m;
    int** mat;

};



#endif // GRAFO_HPP_INCLUDED
