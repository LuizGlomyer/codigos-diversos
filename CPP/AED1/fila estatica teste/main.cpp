#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#define MAX 5
using namespace std;


typedef struct{
    string nome;
    int cpf;
}PESSOA;

typedef struct{
    PESSOA pessoa[MAX];
    int no_elementos;
}FILA;

void inicializaFila(FILA *m){
    m->no_elementos = 0;
}

void addPessoa(FILA *m, PESSOA p){

    m->pessoa[m->no_elementos] = p;
    m->no_elementos++;
}

void removerPessoa(FILA *m){
    if(m->no_elementos == 0){
        cout << "A fila esta vazia!" << endl;
        return;
    }
    cout << "---------------------------------" << endl;
    cout << "Removendo " << m->pessoa[0].nome << " CPF: " << m->pessoa[0].cpf << endl;
    cout << "---------------------------------" << endl;
    for(int i = 0; i < m->no_elementos-1; i++){
        m->pessoa[i] = m->pessoa[i+1];
    }
    m->no_elementos--;
}

void mostarFila(FILA *m){
    if(m->no_elementos == 0){
        cout << "A fila esta vazia!" << endl;
        return;
    }
    cout << "---------------------------------" << endl;
    for(int i = 0; i < m->no_elementos; i++){
        cout << "Nome: " << m->pessoa[i].nome << endl;
        cout << "CPF: " << m->pessoa[i].cpf << endl;
        cout << "---------------------------------" << endl;
    }
    cout << "Total de pessoas na fila: " << m->no_elementos << endl;
    cout << endl;
}

void limpaFila(FILA *m){
    if(m->no_elementos == 0){
        cout << "A fila esta vazia!" << endl;
        return;
    }
    cout << "---------------------------------" << endl;
    int a = m->no_elementos;
    for(int i = 0; i < m->no_elementos; i++){
        cout << "Removendo " << m->pessoa[i].nome << " CPF: " << m->pessoa[i].cpf << endl;
        cout << "---------------------------------" << endl;
        system("pause");
        m->pessoa[i] = m->pessoa[i+1];
        a--;
    }
    m->no_elementos = a;
}

 void reset(){
    system("pause");
    system("cls");
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

    if(input == 1 && f.no_elementos != MAX){
        system("cls");
        cout << "Insira o nome da pessoa" << endl;
        cin.ignore();
        getline(cin, p.nome);
        cout << "Insira o CPF da pessoa" << endl;
        cin >> p.cpf;
        addPessoa(&f, p);
        reset();
        goto menu;
    }
    if(input == 1 && f.no_elementos == MAX){
        cout << "A fila esta cheia!" << endl;
        reset();
        goto menu;
    }

    if(input == 2){
        system("cls");
        removerPessoa(&f);
        reset();
        goto menu;
    }

    if(input == 3){
        system("cls");
        mostarFila(&f);
        reset();
        goto menu;
    }

    if(input == 4){
        system("cls");
        limpaFila(&f);
        reset();
        goto menu;
    }
    if(input == 9)
        goto fim;



    fim:

    return 007;
}
