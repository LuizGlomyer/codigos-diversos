#ifndef LISTALIGADA_HPP_INCLUDED
#define LISTALIGADA_HPP_INCLUDED

#include "ELEMENTO.hpp"

template<typename T>
class ListaLigada{
public:
    ListaLigada();
    ~ListaLigada();
    void adicionar(T);
    void remover(int = 0);
    void esvaziar();
    void mostrarLista() const;
    int getTamanho() const;
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
void ListaLigada<T>::adicionar(T dado){
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

#endif // LISTALIGADA_HPP_INCLUDED
