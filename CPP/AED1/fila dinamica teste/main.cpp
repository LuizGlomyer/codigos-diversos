#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef struct{
    string nome;
    int cpf;
}PESSOA;

typedef struct aux{
    PESSOA pessoa;
    struct aux* proximo;
    struct aux* predecessor;
}ELEMENTO;

typedef struct{
    ELEMENTO* inicio;
    ELEMENTO* fim;
}FILA;

void inicializaFila(FILA *m){
    m->inicio = NULL;
    m->fim = NULL;
}

void inserirNaFila(FILA *m, PESSOA p){
    if(m->inicio == NULL){
        m->inicio = new ELEMENTO;
        m->inicio->predecessor = NULL;
        m->inicio->proximo = NULL;
        m->inicio->pessoa = p;
        m->fim = m->inicio;
        return;
    }
    ELEMENTO* e = new ELEMENTO;
    e->pessoa = p;
    e->proximo = NULL;
    e->predecessor = m->fim; //antigo fim
    m->fim->proximo = e;
    m->fim = e;
}

void removerPessoa(FILA *m){
    if(m->inicio == NULL){
        cout << "A fila esta vazia!" << endl;
        return;
    }
    if(m->inicio == m->fim){
        delete m->inicio;
        m->inicio = NULL;
        m->fim = NULL;
        return;
    }
    cout << "Removendo " << m->inicio->pessoa.nome << " CPF: " << m->inicio->pessoa.cpf << endl;
    ELEMENTO* e = m->inicio;
    delete e;
    m->inicio = m->inicio->proximo;
    m->inicio->predecessor = NULL;

}

void mostrarFila(FILA *m){
    if(m->inicio == NULL){
        cout << "A fila esta vazia!" << endl;
        return;
    }
    ELEMENTO* e = m->inicio;
    cout << "-----------------------------------" << endl;
    while(e != NULL){
        cout << "Nome: " << e->pessoa.nome << endl;
        cout << "CPF: " << e->pessoa.cpf << endl;
        cout << "-----------------------------------" << endl;
        e = e->proximo;
    }
}

void limpaFila(FILA *m){
    if(m->inicio == NULL){
        cout << "A fila esta vazia!" << endl;
        return;
    }
    ELEMENTO* e = m->inicio;
    while(e != NULL){
        delete e;
        e = e->proximo;
    }
    m->inicio = NULL;
    m->fim = NULL;
}




int main(void){

    FILA f;
    inicializaFila(&f);
    PESSOA p;
    int input;

    menu:
    cout << "1 - adicionar pessoa na fila" << endl;
    cout << "2 - remover pessoa da fila" << endl;
    cout << "3 - mostrar fila" << endl;
    cout << "4 - limpar fila" << endl;
    cout << "\n9 - sair" << endl;
    cin >> input;

    if(input == 1){
        system("cls");
        cout << "Insira o nome da pessoa" << endl;
        cin.ignore();
        getline(cin, p.nome);
        cout << "Insira o CPF da pessoa" << endl;
        cin >> p.cpf;
        inserirNaFila(&f, p);
        system("cls");
        goto menu;
    }

    if(input == 2){
        system("cls");
        removerPessoa(&f);
        system("pause");
        system("cls");
        goto menu;
    }

    if(input == 3){
        system("cls");
        mostrarFila(&f);
        system("pause");
        system("cls");
        goto menu;
    }

    if(input == 4){
        system("cls");
        limpaFila(&f);
        system("pause");
        system("cls");
        goto menu;
    }
    if(input == 9)
        goto fim;



    fim:

    return 0;
}
