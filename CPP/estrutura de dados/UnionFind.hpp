#ifndef UNIONFIND_HPP_INCLUDED
#define UNIONFIND_HPP_INCLUDED

#include "ListaLigada.hpp"

template<typename T>
class UnionFind{
public:
    UnionFind();
    ~UnionFind();
    void makeSet(T);
    void Union(T, T);
    ListaLigada<T> findSet(T); // retorna ponteiro para o subconjunto
private:
    ListaLigada<ListaLigada<T>*> conjuntos;
    int numConjuntos;
};

template<typename T>
UnionFind<T>::UnionFind(){
    numConjuntos = 0;
}

template<typename T>
UnionFind<T>::~UnionFind(){

}

template<typename T>
void UnionFind<T>::makeSet(T elemento){
    if(conjuntos.estaVazia()){
        ListaLigada<T>* a = new ListaLigada<T>;
        a->inserir(elemento);
        conjuntos.inserir(a);//deveria inserir uma copia? a morre no escopo
        numConjuntos++;
        return;
    }
    for(int i = 0; i < numConjuntos; i++) // o elemento já existe em algum subconjunto?
        if(conjuntos[i]->estaNaLista(elemento))
            return; // se sim, não faz nada
    ListaLigada<T>* a = new ListaLigada<T>;
    a->inserir(elemento);
    conjuntos.inserir(a);
}

template<typename T>
void UnionFind<T>::Union(T c1, T c2){ // um representante qualquer de seus conjuntos
    int indice1 = -1, indice2 = -1;
    for(int i = 0; i < numConjuntos; i++){
        if(conjuntos[i].estaNaLista(c1))
            c1 = i;
        if(conjuntos[i].estaNaLista(c2))
            c2 = i;
    }
    if(c1 == c2){
        cout << "ERRO, CONJUNTOS DISJUNTOS" << '\n';
        return;
    }
    ListaLigada<T> novoConjunto;
    for(int i = 0; i < conjuntos[c1].getTamanho(); i++) //inserção dos elementos de forma não-ordenada
        novoConjunto.inserir(conjuntos[c1][i]);
    for(int i = 0; i < conjuntos[c2].getTamanho(); i++)
        novoConjunto.inserir(conjuntos[c2][i]);
    conjuntos[c1].esvaziar();
    conjuntos[c2].esvaziar();
    conjuntos.remover(c1);
    conjuntos.remover(c2);
    numConjuntos -= 2;

    conjuntos.inserir(novoConjunto);//objservar a qtd de conjuntos criada
    numConjuntos++;
}

template<typename T>
ListaLigada<T> UnionFind<T>::findSet(T elemento){
    for(int i = 0; i < numConjuntos; i++)
        if(conjuntos[i]->estaNaLista(elemento)){
            return *conjuntos[i];
        }

    return *new ListaLigada<T>;
}

#endif // UNIONFIND_HPP_INCLUDED
