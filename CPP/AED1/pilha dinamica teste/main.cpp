#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef struct{
    string nome;
    int cpf;
}PESSOA;

typedef struct aux{
    PESSOA pessoa;
    aux* proximo;
    aux* anterior;
}ELEMENTO;

typedef struct{
    ELEMENTO* topo;
}PILHA;


void inicializaPilha(PILHA *m){
    m->topo = NULL;
}

void inserirPilha(PILHA *m, PESSOA pe){
    ELEMENTO* e = new ELEMENTO;
    e->pessoa = pe;
    e->proximo = m->topo;
    m->topo = e;
}

void removerPilha(PILHA *m){
    ELEMENTO* e = m->topo;
    if(e == NULL){
        cout << "Pilha vazia!" << endl;
        return;
    }
    cout << "--------------------------" << endl;
    cout << "Removendo " << e->pessoa.nome<< " CPF: " << e->pessoa.cpf << endl;
    cout << "--------------------------" << endl;
    m->topo = m->topo->proximo;
    delete e;
}

void mostrarPilha(PILHA *m){
    ELEMENTO* e = m->topo;
    if(e == NULL){
        cout << "Pilha vazia!" << endl;
        return;
    }

    cout << "--------------------------" << endl;
    while(e != NULL){
        cout << "Nome: " << e->pessoa.nome << endl;
        cout << "CPF: " << e->pessoa.cpf << endl;
        cout << "-------------------------" << endl;
        e = e->proximo;
    }
}

void limparPilha(PILHA *m){
    ELEMENTO* e = m->topo;
    ELEMENTO* i;
    if(e == NULL){
        cout << "Pilha vazia!" << endl;
        return;
    }

    cout << "-------------------------" << endl;
    while(e != NULL){
        cout << " Removendo " << e->pessoa.nome << " CPF: " << e->pessoa.cpf << endl;
        cout << "-------------------------" << endl;
        i = e;
        e = e->proximo;
        delete i;
    }
    m->topo = NULL;
}

int main(){

    PILHA p;
    inicializaPilha(&p);
    PESSOA pe;
    int input;

    menu:
    cout << "1 - adicionar pessoa na pilha" << endl;
    cout << "2 - remover pessoa da pilha" << endl;
    cout << "3 - mostrar pilha" << endl;
    cout << "4 - limpar pilha" << endl;
    cout << "\n9 - sair" << endl;
    cin >> input;

    if(input == 1){
        system("cls");
        cout << "Insira o nome" << endl;
        cin.ignore();
        getline(cin, pe.nome);
        cout << "Insira o CPF" << endl;
        cin >> pe.cpf;
        inserirPilha(&p, pe);
        system("cls");
        goto menu;
    }


    if(input == 2){
        system("cls");
        removerPilha(&p);
        system("pause");
        system("cls");
        goto menu;
    }

    if(input == 3){
        system("cls");
        mostrarPilha(&p);
        system("pause");
        system("cls");
        goto menu;
    }

    if(input == 4){
        system("cls");
        limparPilha(&p);
        system("pause");
        system("cls");
        goto menu;
    }

    if(input == 9){
        exit(1);
    }

    goto menu;


    return 00;
}
