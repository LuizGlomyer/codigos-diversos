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
    ELEMENTO* inicio;
    ELEMENTO* fim;
}DEQUE;


void inicializaDeque(DEQUE *d){
    d->inicio = NULL;
    d->fim = NULL;
}

void addInicio(DEQUE *d, PESSOA p){
    if(d->inicio == NULL){
        d->inicio = new ELEMENTO;
        d->fim = d->inicio;
        d->inicio->pessoa = p;
        d->inicio->anterior = NULL;
        d->inicio->proximo = NULL;
        return;
    }

    ELEMENTO* e = new ELEMENTO;
    e->pessoa = p;
    e->proximo = d->inicio;
    d->inicio->anterior = e;
    e->anterior = NULL;
    d->inicio = e;
}

void addFinal(DEQUE *d, PESSOA p){
    if(d->inicio == NULL){
        d->inicio = new ELEMENTO;
        d->fim = d->inicio;
        d->inicio->pessoa = p;
        d->inicio->anterior = NULL;
        d->inicio->proximo = NULL;
        return;
    }

    ELEMENTO* e = new ELEMENTO;
    e->pessoa = p;
    e->proximo = NULL;
    e->anterior = d->fim;
    d->fim->proximo = e;
    d->fim = e;
}

void removeInicio(DEQUE *d){
    if(d->inicio == NULL){
        cout << "Deque vazio!" << endl;
        return;
    }
    if(d->inicio == d->fim){
        cout << "-----------------------------" << endl;
        cout << "Removendo " << d->inicio->pessoa.nome << " CPF: " << d->inicio->pessoa.cpf << endl;
        cout << "-----------------------------" << endl;
        delete d->inicio;
        d->inicio = NULL;
        d->fim = NULL;
        return;
    }

    ELEMENTO* e = d->inicio;
    cout << "-----------------------------" << endl;
    cout << "Removendo " << e->pessoa.nome << " CPF: " << e->pessoa.cpf << endl;
    cout << "-----------------------------" << endl;
    d->inicio = e->proximo;
    e->proximo->anterior = NULL;
    delete e;
}

void removeFinal(DEQUE *d){
    if(d->inicio == NULL){
        cout << "Deque vazio!" << endl;
        return;
    }
    if(d->inicio == d->fim){
        cout << "-----------------------------" << endl;
        cout << "Removendo " << d->inicio->pessoa.nome << " CPF: " << d->inicio->pessoa.cpf << endl;
        cout << "-----------------------------" << endl;
        delete d->fim;
        d->inicio = NULL;
        d->fim = NULL;
        return;
    }

    ELEMENTO* e = d->fim;
    cout << "-----------------------------" << endl;
    cout << "Removendo " << e->pessoa.nome << " CPF: " << e->pessoa.cpf << endl;
    cout << "-----------------------------" << endl;
    d->fim = e->anterior;
    d->fim->proximo = NULL;
    delete e;
}

void limparDeque(DEQUE *d){
    if(d->inicio == NULL){
        cout << "Deque vazio!" << endl;
        return;
    }
    if(d->inicio == d->fim){
        cout << "Limpando deque..." << endl;
        delete d->inicio;
        d->inicio = NULL;
        d->fim = NULL;
    }
    ELEMENTO* e = d->inicio;
    cout << "Limpando deque..." << endl;
    while(e != NULL){
        ELEMENTO* a;
        a = e;
        e = e->proximo;
        delete a;
    }
    d->inicio = NULL;
    d->fim = NULL;
}

void mostrarDeque(DEQUE *d){
    if(d->inicio == NULL){
        cout << "Deque vazio!" << endl;
        return;
    }

    ELEMENTO* e = d->inicio;
    cout << "-----------------------------" << endl;
    while(e != NULL){
        cout << "Nome: " << e->pessoa.nome << endl;
        cout << "CPF: " << e->pessoa.cpf << endl;
        cout << "-----------------------------" << endl;
        e = e->proximo;
    }
}

int main(void){

    DEQUE d;
    inicializaDeque(&d);
    PESSOA pe;
    int input;

    menu:
    cout << "1 - adicionar pessoa no inicio do deque" << endl;
    cout << "2 - adicionar pessoa no fim do deque" << endl;
    cout << "3 - remover pessoa do inicio do deque" << endl;
    cout << "4 - remover pessoa do fim do deque" << endl;
    cout << "5 - mostrar deque" << endl;
    cout << "6 - limpar deque" << endl;
    cout << "\n9 - sair" << endl;
    cin >> input;

    if(input == 1){
        system("cls");
        cout << "Insira o nome" << endl;
        cin.ignore();
        getline(cin, pe.nome);
        cout << "Insira o CPF" << endl;
        cin >> pe.cpf;
        addInicio(&d, pe);
        system("cls");
        goto menu;
    }

    if(input == 2){
        system("cls");
        cout << "Insira o nome" << endl;
        cin.ignore();
        getline(cin, pe.nome);
        cout << "Insira o CPF" << endl;
        cin >> pe.cpf;
        addFinal(&d, pe);
        system("cls");
        goto menu;
    }

    if(input == 3){
        system("cls");
        removeInicio(&d);
        system("pause");
        system("cls");
        goto menu;
    }

    if(input == 4){
        system("cls");
        removeFinal(&d);
        system("pause");
        system("cls");
        goto menu;
    }

    if(input == 5){
        system("cls");
        mostrarDeque(&d);
        system("pause");
        system("cls");
        goto menu;
    }

    if(input == 6){
        system("cls");
        limparDeque(&d);
        system("pause");
        system("cls");
        goto menu;
    }

    if(input == 9){
        exit(1);
    }

    goto menu;

    return 123;
}
