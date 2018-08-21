#ifndef ARVORE_HPP_INCLUDED
#define ARVORE_HPP_INCLUDED

#include "No.hpp"

template<typename T>
class Arvore{
public:
    Arvore();
    ~Arvore();
    void inserir(T dado){
        inserir(dado, raiz);
    }
    void remover(T);
    void buscar(T);
    void percorrePreOrdem();
    void percorrreCenOrdem();
    void percorrePosOrdem();
private:
    void inserir(T dado, No<T>* no){
        if(no == nullptr){
            no = new No<T>;
            no->dados = dado;
            return;
        }
        if(dado <= no->dados)
            inserir(dado, no->esq);
        if(dado > no->dados)
            inserir(dado, no->dir);
    }
    void remover(T, No<T>*);
    void buscar(T, No<T>*);
    No<T>* raiz;
};

template<typename T>
Arvore<T>::Arvore(){
    raiz = nullptr;
}

template<typename T>
Arvore<T>::~Arvore(){
}

/*template<typename T>
void Arvore<T>::inserir(T dado){

}*/

template<typename T>
void Arvore<T>::remover(T dado){
    remover(dado, raiz);
}

template<typename T>
void Arvore<T>::buscar(T item){
    busca(item, raiz);
}

/*template<typename T>
void inserir(T dado, No<T>* no){
    if(no == nullptr){
        no = new No<T>;
        no->dados = dado;
        return;
    }
    if(dado < no->dados)
        inserir(dado, no->esq);
    if(dado > no->dados)
        inserir(dado, no->dir);
}*/

template<typename T>
void remover(T dado, No<T>* no){
    if(dado == no->dados);
}

template<typename T>
void buscar(T dado, No<T>* no){
    if(dado == no->dados)
        cout << "Dado encontrado: " << no->dados << endl;
    if(dado < no->dados)
        buscar(dado, no->esq);
    if(dado > no->dados)
        buscar(dado, no->dir);
}


template<typename T>
void Arvore<T>::percorrePreOrdem(){

}





#endif // ARVORE_HPP_INCLUDED
