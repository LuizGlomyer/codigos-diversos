#include <iostream>
#include <string>
#include <cstdlib>
#define MAX 5
using namespace std;

typedef struct{
    string nome;
    int cpf;
}PESSOA;

typedef struct{
    PESSOA pessoa[MAX];
    int no_elementos;
}PILHA;


void inicializaPilha(PILHA *m){
    m->no_elementos = 0;
}

void inserirPilha(PILHA *m, PESSOA p){
    if(m->no_elementos == MAX){
        cout << "Pilha cheia!" << endl;
        return;
    }
    m->pessoa[m->no_elementos] = p;
    m->no_elementos++;
}

void removerPilha(PILHA *m){
    if(m->no_elementos == 0){
        cout << "Pilha vazia!" << endl;
        return;
    }
    cout << "----------------------------------" << endl;
    cout << "Removendo " << m->pessoa[m->no_elementos-1].nome << " CPF: " << m->pessoa[m->no_elementos-1].cpf << endl;
    cout << "----------------------------------" << endl;
    m->no_elementos--;
}

void mostrarPilha(PILHA *m){
    if(m->no_elementos == 0){
        cout << "Pilha vazia!" << endl;
        return;
    }
    cout << "----------------------------------" << endl;
    for(int i = m->no_elementos-1; i >= 0; i--){
        cout << "Nome: " << m->pessoa[i].nome << endl;
        cout << "CPF: " << m->pessoa[i].cpf << endl;
        cout << "----------------------------------" << endl;
    }
}

void limparPilha(PILHA *m){
    if(m->no_elementos == 0){
        cout << "Pilha vazia!" << endl;
        return;
    }
    cout << "----------------------------------" << endl;
    for(int i = m->no_elementos-1; i >=0; i--){
        cout << "Removendo " << m->pessoa[i].nome << " CPF: " << m->pessoa[i].cpf << endl;
        cout << "----------------------------------" << endl;
        m->no_elementos--;
    }
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

    if(input == 1 && p.no_elementos != MAX){
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

    if(input == 1 && p.no_elementos == MAX){
        system("cls");
        cout << "Pilha cheia" << endl;
        system("pause");
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


    return 44;
}
