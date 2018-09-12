#ifndef LISTALIGADA_HPP_INCLUDED
#define LISTALIGADA_HPP_INCLUDED

#include "ELEMENTO.hpp"
#include <iostream>
using namespace std;


template<typename T>
class ListaLigada{
public:
    T operator[](int);
    ListaLigada();
    ~ListaLigada();
    void inserir(T);
    void inserirInicio(T);
    void remover(int = 0);
    void esvaziar();
    void mostrarLista() const;
    T posicao(int) const; //retorna elemento da posicao
    int getTamanho() const;
    int* retornaInteiros(); //para grafos
private:
    ELEMENTO<T>* inicio;
    int tamanho;
};

template<typename T>
ListaLigada<T>::ListaLigada(){
    inicio = nullptr;
    tamanho = -1;
}

template<typename T>
ListaLigada<T>::~ListaLigada(){
    esvaziar();
}

template<typename T>
void ListaLigada<T>::inserir(T dado){
    if(inicio == nullptr){
        inicio = new ELEMENTO<T>;
        inicio->dados = dado;
        inicio->prox = nullptr;
        tamanho++;
        return;
    }
    ELEMENTO<T>* e = inicio;
    while(e->prox != nullptr)
        e = e->prox;
    e->prox = new ELEMENTO<T>;
    e = e->prox;
    e->dados = dado;
    e->prox = nullptr;
    tamanho++;
}

template<typename T>
void ListaLigada<T>::inserirInicio(T dado){
    if(inicio == nullptr){
        inicio = new ELEMENTO<T>;
        inicio->dados = dado;
        inicio->prox = nullptr;
        tamanho++;
        return;
    }
    ELEMENTO<T>* e = new ELEMENTO<T>;
    e->dados = dado;
    e->prox = inicio;
    inicio = e;
    tamanho++;
}

template<typename T>
void ListaLigada<T>::remover(int indice){
    if(inicio == nullptr)
        return;
    if(inicio->prox == nullptr){
        delete inicio;
        inicio = nullptr;
        tamanho--;
        return;
    }
    if(indice > tamanho)
        return;
    if(indice > 0){
        ELEMENTO<T>* excluir = inicio,* antecessor;
        for(int i = 0; i < indice; i++){
            antecessor = excluir;
            excluir = excluir->prox;
        }
        antecessor->prox = excluir->prox;
        delete excluir;
        tamanho--;
        return;
    }
    ELEMENTO<T>* e = inicio->prox;
    delete inicio;
    inicio = e;
}

template<typename T>
void ListaLigada<T>::esvaziar(){
    ELEMENTO<T>*e = inicio, * excluir;
    while(e != nullptr){
        excluir = e;
        e = e->prox;
        delete excluir;
    }
    inicio = nullptr;
    tamanho = -1;
}

template<typename T>
void ListaLigada<T>::mostrarLista() const{
    int i = 0;
    ELEMENTO<T>* e = inicio;
    while(e != nullptr){
        cout << "Elemento " << i << " : \t" << e->dados << endl;
        e = e->prox;
        i++;
    }
}

template<typename T>
int ListaLigada<T>::getTamanho() const{
    return tamanho;
}

template<typename T>
T ListaLigada<T>::posicao(int i) const{
    ELEMENTO<T>* e = inicio;
    for(int j = 0; j < i; j++)
        e = e->prox;

    return e->dados;
}

template<typename T>
T ListaLigada<T>::operator[](int i){
    return posicao(i);
}

//para grafos
template<typename T>
int* ListaLigada<T>::retornaInteiros(){
    int* retorno = new int[tamanho+2];
    retorno[0] = tamanho+2; // primeira posicao vai indicar quantas posicoes o vetor possui
    ELEMENTO<T>* e = inicio;
    int i = 1;
    while(e != nullptr){
        retorno[i] = e->dados;
        i++;
        e = e->prox;
    }
    return retorno;
}

#endif // LISTALIGADA_HPP_INCLUDED
