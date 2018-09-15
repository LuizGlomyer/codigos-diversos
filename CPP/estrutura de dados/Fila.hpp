#ifndef FILA_HPP_INCLUDED
#define FILA_HPP_INCLUDED

#include "ELEMENTO.hpp"

template<typename T>
class Fila{
    public:
        Fila();
        ~Fila();
        void adicionar(T);
        void remover();
        T pop();
        bool estaVazia() const;
        void esvaziar();
        void mostrarFila() const;
    private:
        ELEMENTO<T>* primeiro,* ultimo;
};

template<typename T>
Fila<T>::Fila(){
    primeiro = nullptr;
    ultimo = nullptr;
}

template<typename T>
Fila<T>::~Fila(){
    esvaziar();
}

template<typename T>
void Fila<T>::adicionar(T dado){
    if(primeiro == nullptr){
        primeiro = new ELEMENTO<T>;
        primeiro->dados = dado;
        primeiro->prox = nullptr;
        ultimo = primeiro;
        return;
    }
    ELEMENTO<T>* e = ultimo;
    e->prox = new ELEMENTO<T>;
    e->prox->dados = dado;
    e->prox->prox = nullptr;
    ultimo = e->prox;
}

template<typename T>
void Fila<T>::remover(){
    if(primeiro == nullptr){
        return;
    }
    if(primeiro == ultimo){
        delete primeiro;
        primeiro = ultimo = nullptr;
        return;
    }
    ELEMENTO<T>* e = primeiro->prox;
    delete primeiro;
    primeiro = e;
}

template<typename T>
T Fila<T>::pop(){
    if(primeiro == nullptr){
        throw bad_alloc();
        //return * new T;
    }
    if(primeiro == ultimo){
        T dado = primeiro->dados;
        delete primeiro;
        primeiro = ultimo = nullptr;
        return dado;
    }
    T dado = primeiro->dados;
    ELEMENTO<T>* e = primeiro->prox;
    delete primeiro;
    primeiro = e;
    return dado;
}

template<typename T>
bool Fila<T>::estaVazia() const{
    return primeiro == nullptr ? true : false;
}

template<typename T>
void Fila<T>::esvaziar(){
    ELEMENTO<T>* e = primeiro,* excluir;
    while(e != nullptr){
       excluir = e;
       e = e->prox;
       delete excluir;
    }
}

template<typename T>
void Fila<T>::mostrarFila() const{
    int i = 0;
    ELEMENTO<T>* e = primeiro;
    while(e != nullptr){
        cout << "Elemento " << i << " : \t" << e->dados << endl;
        e = e->prox;
        i++;
    }
}


#endif // FILA_HPP_INCLUDED
