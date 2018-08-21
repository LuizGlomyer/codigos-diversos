#ifndef TABELAHASH_HPP_INCLUDED
#define TABELAHASH_HPP_INCLUDED

#include "ELEMENTO.hpp"
#include "ListaLigada.hpp"
//tipos numéricos
template<typename T>
class TabelaHash{
public:
    TabelaHash(int);
    TabelaHash();
    ~TabelaHash();
    void adicionar(T);
    void remover(int = 0, int = -1);
    int getTamanho() const;
    void mostrarTabela() const;
private:
    int fhash(T);
    const int tamanho;
    ListaLigada<T>** table;
};

template<typename T>
TabelaHash<T>::TabelaHash(int tam) : tamanho(tam){
    table = new ListaLigada<T>*[tamanho];
    for(int i = 0; i < tamanho; i++)
        table[i] = nullptr;
}

template<typename T>
TabelaHash<T>::~TabelaHash(){
    for(int i = 0; i < tamanho; i++)
        delete table[i];
    delete [] table;
}

template<typename T>
void TabelaHash<T>::adicionar(T dado){
    int i = fhash(dado);
    if(table[i] == nullptr)
        table[i] = new ListaLigada<T>;
    table[i]->adicionar(dado);
}

template<typename T>
void TabelaHash<T>::remover(int indiceTabela, int indiceLista){
    if(indiceLista == -1){
        delete table[indiceTabela];
        table[indiceTabela] = nullptr;
        return;
    }
    table[indiceTabela]->remover(indiceLista);
}

template<typename T>
int TabelaHash<T>::getTamanho() const{
    return tamanho;
}

template<typename T>
void TabelaHash<T>::mostrarTabela() const{
    for(int i = 0; i < tamanho; i++){
        cout << "Posicao " << i << ": " << endl;
        if(table[i] == nullptr){
            cout << "Nulo" << endl << endl;
            continue;
        }
        table[i]->mostrarLista();
        cout << endl;
    }
}

template<typename T>
int TabelaHash<T>::fhash(T valor){
    return std::hash<T>{}(valor) % tamanho;
}



// especialização string

template<>
int TabelaHash<string>::fhash(string valor){
    return std::hash<char>{}(valor[0] - 97) % tamanho; //-97 normaliza o caso das letras minusculas
}

template<>
TabelaHash<string>::TabelaHash() : tamanho(26){
    table = new ListaLigada<string>*[26];
    for(int i = 0; i < tamanho; i++)
        table[i] = nullptr;
}

template<>
void TabelaHash<string>::mostrarTabela() const{
    for(int i = 0; i < tamanho; i++){
        cout << "Letra " << static_cast<char> (i + 65) << ": " << endl;
        if(table[i] == nullptr){
            cout << "Nulo" << endl << endl;
            continue;
        }
        table[i]->mostrarLista();
        cout << endl;
    }
}

#endif // TABELAHASH_HPP_INCLUDED
