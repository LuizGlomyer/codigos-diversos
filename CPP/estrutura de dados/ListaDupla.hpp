#ifndef LISTADUPLA_HPP_INCLUDED
#define LISTADUPLA_HPP_INCLUDED

#include "ELEMENTO.hpp"

template<typename T>
class ListaDupla{
public:
    ListaDupla();
    ~ListaDupla();
    void adicionar(T);
    void remover(int = 0);
    void esvaziar();
    void mostrarLista() const;
    int getTamanho() const;
private:
    ELEMENTO<T>* inicio,* fim;
    int tamanho;
};

template<typename T>
ListaDupla<T>::ListaDupla(){
    inicio = fim = nullptr;
    tamanho = -1;
}

template<typename T>
ListaDupla<T>::~ListaDupla(){
    esvaziar();
}

template<typename T>
void ListaDupla<T>::adicionar(T dado){
    if(inicio == nullptr){
        inicio = new ELEMENTO<T>;
        inicio->dados = dado;
        inicio->prox = inicio->antc = nullptr;
        fim = inicio;
        tamanho++;
        return;
    }
    ELEMENTO<T>* e = fim;
    e->prox = new ELEMENTO<T>;
    e->prox->antc = e;
    e = e->prox;
    e->dados = dado;
    e->prox = nullptr;
    fim = e;
    tamanho++;
}

template<typename T>
void ListaDupla<T>::remover(int indice){
    if(inicio == nullptr)
        return;
    if(inicio == fim){
        delete inicio;
        inicio = fim = nullptr;
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
    if(indice == tamanho){
        ELEMENTO<T>* e = fim->antc;
        delete e->prox;
        e->prox = nullptr;
    }
    ELEMENTO<T>* e = inicio->prox;
    delete inicio;
    inicio = e;
}

template<typename T>
void ListaDupla<T>::esvaziar(){
    ELEMENTO<T>* e = inicio, *excluir;
    while(e != nullptr){
        excluir = e;
        e = e->prox;
        delete excluir;
    }
}

template<typename T>
void ListaDupla<T>::mostrarLista() const{
    int i = 0;
    ELEMENTO<T>* e = inicio;
    while(e != nullptr){
        cout << "Elemento " << i << " : \t" << e->dados << endl;
        e = e->prox;
        i++;
    }
}

template<typename T>
int ListaDupla<T>::getTamanho() const{
    return tamanho;
}

#endif // LISTADUPLA_HPP_INCLUDED
