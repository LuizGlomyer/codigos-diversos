#ifndef ARVORE_HPP_INCLUDED
#define ARVORE_HPP_INCLUDED

#include "No.hpp"

template<typename T>
class Arvore{
public:
    Arvore();
    ~Arvore();
    void inserir(T);
    void remover(T);
    void buscar(T);
    void percorreEmOrdem(int); // -1 para pre, 0 para central, 1 para pos
private:
    No<T>* inserir(No<T>* novoNo, No<T>* raiz);
    int remover(T, No<T>*);
    No<T>* removeAux(No<T>*);
    void buscar(T, No<T>*);
    void percorreEmOrdem(No<T>*, int);
    No<T>* raiz;
};

template<typename T>
Arvore<T>::Arvore(){
    raiz = nullptr;
}

template<typename T>
Arvore<T>::~Arvore(){
}

template<typename T>
void Arvore<T>::buscar(T item){
    busca(item, raiz);
}

template<typename T>
No<T>* Arvore<T>::removeAux(No<T>* atual){
    No<T>* no1,* no2;
    if(atual->esq == nullptr){
        no2 = atual->dir;
        delete atual;
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != nullptr){
        printf("no2 dir %d", no2->dir->dados);
        no1 = no2;
        no2 = no2->dir;
    }

    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    delete atual;
    return no2;


    /*if(r->dir != nullptr)
        removeAux(q, r->dir);
    else
        q->dados = r->dados;
        q = r;
        r = r->esq;
        delete q;
        */
}

template<typename T>
int Arvore<T>::remover(T dado, No<T>* no){
    if(no == nullptr)
        return 0;
    No<T>* ant = nullptr,* atual = no;
    while(atual != nullptr){
        if(dado == atual->dados){
            if(atual == no)
                no = removeAux(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = removeAux(atual);
                else
                    ant->esq = removeAux(atual);
            }
            return 1;
        }
        ant = atual;
        if(dado > atual->dados)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    /*if(no == nullptr)
        cout << "Erro, item nao esta na arvore" << endl;
    else
        if(dado < no->dados)
            remover(dado, no->esq);
        else
            if(dado > no->dados)
                remover(dado, no->dir);
            else
                if (no->dir == nullptr){
                    No<T>* aux = no;
                    no = no->esq;
                    delete aux;
                }
                else
                    if(no->esq == nullptr){
                        No<T>* aux = no;
                        no = no->dir;
                        delete aux;
                    }
                    else
                        removeAux(no, no->esq);
                        */
}

template<typename T>
void Arvore<T>::remover(T dado){
    if(raiz == nullptr){
        cout << "Erro na remocao, arvore esta vazia" << endl;
        return;
    }
    remover(dado,raiz);
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
void Arvore<T>::percorreEmOrdem(int modo){
    if(modo < -1 || modo > 1){
        cout << "Erro, parametro invalido" << endl;
        return;
    }
    percorreEmOrdem(raiz, modo);
}

template<typename T>
void Arvore<T>::percorreEmOrdem(No<T>* no, int modo){
    if(no == nullptr)
        return;
    switch(modo){
        case -1 :
            cout << no->dados << endl;
            percorreEmOrdem(no->esq, modo);
            percorreEmOrdem(no->dir, modo);
            break;
        case 0 :
            percorreEmOrdem(no->esq, modo);
            cout << no->dados << endl;
            percorreEmOrdem(no->dir, modo);
            break;
        case 1 :
            percorreEmOrdem(no->esq, modo);
            percorreEmOrdem(no->dir, modo);
            cout << no->dados << endl;
            break;
        }
}

template<typename T>
No<T>* Arvore<T>::inserir(No<T>* novoNo, No<T>* raiz){
        if(raiz == nullptr){
            raiz = novoNo;
            return raiz;
        }
        if(novoNo->dados < raiz->dados)
            raiz->esq = inserir(novoNo, raiz->esq);
        if(novoNo->dados > raiz->dados)
            raiz->dir = inserir(novoNo, raiz->dir);
        if(novoNo->dados == raiz->dados)
            cout << "Erro, item ja existente na arvore" << endl;
        return raiz;

    }

template<typename T>
void Arvore<T>::inserir(T dado){
        No<T>* no = new No<T>;
        no->dados = dado;
        raiz = inserir(no, raiz);
    }



#endif // ARVORE_HPP_INCLUDED
