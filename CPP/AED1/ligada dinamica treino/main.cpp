#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct{
    string nome;
    string genero;
}JOGO;

typedef struct aux{
    JOGO jogo;
    struct aux *proximo;
    struct aux *predecessor;
}ELEMENTO;

typedef struct{
    ELEMENTO* inicio;
}LISTA;

void inicializaLista(LISTA *m){
    m->inicio = NULL;
}

int tamanhoLista(LISTA *m){
    int tam = 0;
    ELEMENTO *e = m->inicio;
    while(e != NULL){
        e = e->proximo;
        tam++;
    }
    return tam;
}

void mostrarLista(LISTA *m){
    ELEMENTO *e = m->inicio;
    if (e == NULL){
        cout << "Lista vazia" << endl;
        return;
    }
    cout << "=========================================" << endl;
    while(e != NULL){
        cout << "Jogo: " + e->jogo.nome << endl;
        cout << "Genero: " + e->jogo.genero << endl;
        cout << "=========================================" << endl;
        e = e->proximo;
    }
    cout << endl;
}

ELEMENTO* buscaJogo(LISTA *m, string nome){
    ELEMENTO* i = m->inicio;
    while(i != NULL){
        if(i->jogo.nome == nome)
            return i;
        i = i->proximo;
    }
    return NULL;
}

ELEMENTO* buscaUltimoElemento(LISTA *m){
    ELEMENTO* predecessor = NULL;
    ELEMENTO *atual = m->inicio;
    while( atual != NULL ){
        predecessor = atual;
        atual = atual->proximo;
    }
    return predecessor;
}

bool inserirJogo(LISTA *m, JOGO j){

    if(m->inicio == NULL){
        m->inicio = new ELEMENTO;
        ELEMENTO *e = m->inicio;
        e->jogo = j;
        e->predecessor = NULL;
        e->proximo = NULL;
        return true;
    }

    ELEMENTO* e = m->inicio, *predecessor;
    while( e != NULL){
        predecessor = e;
        e = e->proximo;
    }
    e = new ELEMENTO;
    predecessor->proximo = e;
    e->predecessor = predecessor;
    e->proximo = NULL;
    e->jogo = j;
}

void excluirElemento(LISTA *m, string nome){
    ELEMENTO *e = m->inicio;
    while( e != NULL ){
        if( e->jogo.nome == nome){
            e->predecessor->proximo = e->proximo;
            e->proximo->predecessor = e->predecessor;
            delete e;
            return;
        }
        e = e->proximo;
    }
    cout << "Elemento nao encontrado" << endl;
}

void reinicializarLista(LISTA *m){
    ELEMENTO* e = m->inicio, *auxiliar;
    while( e != NULL ){
        auxiliar = e;
        e = e->proximo;
        delete auxiliar;
    }
    m->inicio = NULL;
}

void inserirOrdenado(LISTA *m, string nome){

    ELEMENTO *e = m->inicio, *auxiliar;
    while( e != NULL){
        if(e->jogo.nome == nome){ //inserção
            auxiliar = e->proximo;
            e->proximo = new ELEMENTO;
            cout << "insira o nome do jogo" << endl;
            getline(cin, e->proximo->jogo.nome);
            cout << "insira o genero do jogo" << endl;
            getline(cin, e->proximo->jogo.genero);
            e->proximo->proximo = auxiliar;
            e->proximo->predecessor = e->proximo;
            return;
        }
        e = e->proximo;
    }
    cout << "Jogo nao encontrado" << endl;

}


int main(void){

    LISTA l;
    inicializaLista(&l);
    int a;
    /* testes
    mostrarLista(&l);
    l.inicio = new ELEMENTO;
    l.inicio->jogo.nome = "hue";
    l.inicio->jogo.genero = "hue";
    l.inicio->proximo = new ELEMENTO;
    l.inicio->proximo->jogo.nome = "teste";
    l.inicio->proximo->jogo.genero = "teste";
    l.inicio->proximo->proximo = NULL;
    mostrarLista(&l);
    cout << l.inicio->jogo.nome << endl;

    ELEMENTO *i = buscaJogo(&l, "teste");
    cout << i->jogo.nome ;
    */

    menu:
    int input;
    string nome;

    cout << "Insira o comando" << endl;
    cout << "1 - adicionar jogo" << endl;
    cout << "2 - inserir um jogo logo após algum elemento na lista" << endl;
    cout << "3 - excluir um jogo, dado o seu nome" << endl;
    cout << "4 - listar os jogos" << endl;
    cout << "5 - reinicializar lista de jogos" << endl;
    cout << "\n9 - sair" << endl;

    cin >> input;

    if(input == 1){
        cout << "Insira a quantidade de jogos" << endl;
        cin >> a;
        cin.ignore();
        JOGO aux;
        for(int i = 0; i < a; i++){
            cout << "insira o nome do jogo " << (i+1) << endl;
            getline(cin, aux.nome);
            cout << "insira o genero do jogo " << (i+1) << endl;
            getline(cin, aux.genero);
            inserirJogo(&l, aux);
        }
        system("pause");
        system("cls");
        goto menu;
    }

    if(input == 2){
        cout << "Insira o nome da chave" << endl;
        cin.ignore();
        getline(cin, nome);
        inserirOrdenado(&l, nome);
        system("pause");
        system("cls");
        goto menu;
    }

    if(input == 3){
        getline(cin, nome);
        excluirElemento(&l, nome);
        system("pause");
        system("cls");
        goto menu;
    }

    if(input == 4){
        mostrarLista(&l);
        system("pause");
        system("cls");
        goto menu;
    }

    if(input == 5){
        cout << "Excluindo elementos..." << endl;
        reinicializarLista(&l);
        system("pause");
        system("cls");
        goto menu;
    }

    if(input == 9)
        exit(1);

    return 007;
}
