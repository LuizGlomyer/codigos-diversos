#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#define N 26
#define QTD_NOMES 500

using namespace std;

typedef struct{
    string nome;
    string telefone;
}PESSOA;

typedef struct aux{
    PESSOA pessoa;
    aux* proximo;
    aux* anterior;
}ELEMENTO;

typedef struct{
    ELEMENTO* inicio;
    ELEMENTO* fim;
}LISTA;


void inicializaLista(LISTA* l){
    l->inicio = NULL;
    l->fim = NULL;
}

void addLista(LISTA *l, PESSOA p){
    if(l->inicio == NULL){
        l->inicio = new ELEMENTO;
        l->fim = l->inicio;
        l->inicio->pessoa = p;
        l->inicio->anterior = NULL;
        l->inicio->proximo = NULL;
        return;
    }
    ELEMENTO* e = new ELEMENTO;
    e->pessoa = p;
    e->proximo = NULL;
    e->anterior = l->fim;
    l->fim->proximo = e;
    l->fim = e;
}


typedef LISTA* Hash[N];

void inicializaTabela(Hash tabela){
    for(int i = 0; i<N; i++)
        tabela[i] = NULL;
}

int fhash(string chave){
    return chave[0] - 65;
}

void adicionaTabela(Hash tabela, PESSOA p){
    int h = fhash(p.nome);
    if(tabela[h] == NULL){
        tabela[h] = new LISTA;
        inicializaLista(tabela[h]);
        addLista(tabela[h], p);
    }
    else
        addLista(tabela[h], p);
}

void mostrarLista(LISTA *l){
    if(l->inicio == NULL){
        cout << "Deque vazio!" << endl;
        return;
    }

    ELEMENTO* e = l->inicio;
    cout << "-----------------------------" << endl;
    while(e != NULL){
        cout << "Nome: " << e->pessoa.nome << endl;
        cout << "Telefone: " << e->pessoa.telefone << endl;
        cout << "-----------------------------" << endl;
        e = e->proximo;
    }
}


void mostrarTabela(Hash tabela){
    for(int i = 0; i < N; i++){
        if(tabela[i] != NULL){
            cout << "Letra " << tabela[i]->inicio->pessoa.nome[0] << ":" << endl;
            mostrarLista(tabela[i]);
            cout << endl;
        }
    }
}

int main(){

    Hash tabela;
    inicializaTabela(tabela);
    string nome, telefone;
    ifstream arq ("nomes.txt");
    PESSOA p;
    int g = 0;
    if(arq.is_open()){
        while(/*!arq.eof() dá erro, provavelmente executa N+1 linhas, ou seja, getline vazio*/ g < QTD_NOMES){
            getline(arq, nome);
            getline(arq, telefone);
            p.nome = nome;
            p.telefone = telefone;
            adicionaTabela(tabela, p);
            g++;
        }
    }

    mostrarTabela(tabela);
    system("pause");

    return 0;
}
