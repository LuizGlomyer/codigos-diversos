#include <iostream>
#include <string>
using namespace std;

typedef struct{
    int valor;
    string nome;
}ELEMENTO;

typedef struct aux{
    ELEMENTO elemento;
    aux* esq;
    aux* dir;
}NO;

typedef struct{
    NO* raiz;
}ARVORE;

void inicializaArvore(ARVORE *a){
    a->raiz = NULL;
}

NO* insere(NO* raiz, NO* no){
    if(raiz == NULL)
        return no;
    if(raiz->elemento.valor > no->elemento.valor)
        raiz->esq = insere(raiz->esq, no);
    else
        raiz->dir = insere(raiz->dir, no);

    return raiz;
}

bool inserir(ARVORE* a, ELEMENTO e){
    NO* no = new NO;
    no->elemento = e;
    no->dir = NULL;
    no->esq = NULL;
    a->raiz = insere(a->raiz, no);
    return true;
}


void listarNos(NO* raiz, int num){

    if(raiz != NULL && num == 0){
        cout << "----------------------------" << endl;
        cout << "Endereco: " << raiz << endl;
        cout << "No esquerdo: " << raiz->esq << endl;
        cout << "No direito: " << raiz->dir << endl;
        cout << "Codigo: " << raiz->elemento.valor << endl;
        cout << "----------------------------" << endl;
        listarNos(raiz->esq, num);
        listarNos(raiz->dir, num);
    }

    if(raiz != NULL && num == 1){
        listarNos(raiz->esq, num);
        cout << "----------------------------" << endl;
        cout << "Endereco: " << raiz << endl;
        cout << "No esquerdo: " << raiz->esq << endl;
        cout << "No direito: " << raiz->dir << endl;
        cout << "Codigo: " << raiz->elemento.valor << endl;
        cout << "----------------------------" << endl;
        listarNos(raiz->dir, num);
    }

    if(raiz != NULL && num == 2){
        listarNos(raiz->esq, num);
        listarNos(raiz->dir, num);
        cout << "----------------------------" << endl;
        cout << "Endereco: " << raiz << endl;
        cout << "No esquerdo: " << raiz->esq << endl;
        cout << "No direito: " << raiz->dir << endl;
        cout << "Codigo: " << raiz->elemento.valor << endl;
        cout << "----------------------------" << endl;
    }
}

void listarArvore(ARVORE* a, int num){ //0 para prefixa, 1 infixa, 2 posfixa
    listarNos(a->raiz, num);
}

NO* busca(NO* raiz, int valor){
    if(raiz == NULL)
        return NULL;
    if(raiz->elemento.valor == valor)
        return raiz;
    if(raiz->elemento.valor > valor)
        return busca(raiz->esq, valor);
    else
        return busca(raiz->dir, valor);
}

NO* buscarNo(ARVORE* a, int valor){
    return busca(a->raiz, valor);
}

int somaNos(NO* no){
    if(no == NULL)
        return 0;
    return no->elemento.valor + somaNos(no->dir) + somaNos(no->esq);
}

int profundidade(NO* raiz, NO* no, int cont){
    if(raiz->elemento.valor == no->elemento.valor)
        return cont;
    if(raiz->elemento.valor > no->elemento.valor)
        return profundidade(raiz->esq, no, cont+1);
    else
        return profundidade(raiz->dir, no, cont+1);
}

int altura(NO* raiz, int cont){
    if(raiz->esq == NULL && raiz->dir == NULL)
        return cont;
    int a = 0, b = 0;
    if(raiz->esq != NULL)
        a = altura(raiz->esq, cont+1);
    if(raiz->dir != NULL)
        b = altura(raiz->dir, cont+1);

    return a > b ? a : b;
}

int alturaArvore(ARVORE* a){
    return altura(a->raiz, 0);
}

int main(){

    ARVORE a;
    inicializaArvore(&a);
    ELEMENTO e;
    e.valor = 17;
    inserir(&a, e);
    e.valor = 14;
    inserir(&a, e);
    e.valor = 21;
    inserir(&a, e);
    e.valor = 4;
    inserir(&a, e);
    e.valor = 7;
    inserir(&a, e);
    e.valor = 18;
    inserir(&a, e);
    e.valor = 19;
    inserir(&a, e);
    e.valor = 23;
    inserir(&a, e);
    e.valor = 2;
    inserir(&a, e);
    e.valor = 15;
    inserir(&a, e);
    e.valor = 1;
    inserir(&a, e);
    e.valor = 3;
    inserir(&a, e);
    e.valor = 0;
    inserir(&a, e);

    listarArvore(&a, 0);

    cout << "\n\n" << somaNos(a.raiz) << endl;
    cout << "\n" << profundidade(buscarNo(&a, 21), buscarNo(&a, 19), 0) << endl;
    cout << alturaArvore(&a) << endl;



    return 0;
}
