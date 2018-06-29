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
    int h;
}NO;

typedef struct{
    NO* raiz;
}ARVORE;

void inicializaArvore(ARVORE *a){
    a->raiz = NULL;
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
    no->h = 0;
    a->raiz = insere(a->raiz, no);
    return true;
}

int profundidade(NO* raiz, NO* no, int cont){
    if(raiz->elemento.valor == no->elemento.valor)
        return cont;
    if(raiz->elemento.valor > no->elemento.valor)
        return profundidade(raiz->esq, no, cont+1);
    else
        return profundidade(raiz->dir, no, cont+1);
}

int altura(NO* raiz){
    if(!raiz)
        return -1;
    else
        return raiz->h;
}

int maximo(int a, int b){
    return a > b ? a : b;
}

NO* rotacao_direita(NO* desbalanceado){
    NO* aux;
    aux = desbalanceado->esq;
    desbalanceado->esq = aux->dir;
    aux->dir = desbalanceado;

    desbalanceado->h = maximo(altura(desbalanceado->dir), altura(desbalanceado->esq)) +1;
    aux->h = maximo(altura(aux->esq), altura(desbalanceado)) +1;
    return aux;
}

NO* rotacao_esquerda(NO* desbalanceado){
    NO* aux;
    aux = desbalanceado->dir;
    desbalanceado->dir = aux->esq;
    aux->esq = desbalanceado;

    desbalanceado->h = maximo(altura(desbalanceado->dir), altura(desbalanceado->esq)) +1;
    aux->h = maximo(altura(aux->dir), altura(desbalanceado)) +1;
    return aux;
}

NO* rotacao_esq_dir(NO* desbalanceado){
    desbalanceado->esq = rotacao_esquerda(desbalanceado->esq);
    return rotacao_direita(desbalanceado);
}

NO* rotacao_dir_esq(NO* desbalanceado){
    desbalanceado->dir = rotacao_direita(desbalanceado->dir);
    return rotacao_esquerda(desbalanceado);
}

NO* inserirAVL(NO* raiz, NO* no){
    if(raiz == NULL) return no;
    if(raiz->elemento.valor > no->elemento.valor){
        raiz->esq = inserirAVL(raiz->esq, no);
        if( (altura(raiz->dir) - altura(raiz->esq)) >= 2 /*|| (altura(raiz->dir) - altura(raiz->esq)) <= -2*/){
            if(no->elemento.valor < raiz->esq->elemento.valor)
                raiz = rotacao_direita(raiz);
            else
                raiz = rotacao_esq_dir(raiz);
        }
    }
    else
        if(raiz->elemento.valor < no->elemento.valor){
            raiz->dir = inserirAVL(raiz->dir,no);
            if( (altura(raiz->dir) - altura(raiz->esq)) >= 2 /*|| (altura(raiz->dir) - altura(raiz->esq)) <= -2*/){
                if(no->elemento.valor > raiz->dir->elemento.valor)
                    raiz = rotacao_esquerda(raiz);
                else
                    raiz = rotacao_dir_esq(raiz);
            }
        }
    raiz->h = maximo(altura(raiz->esq), altura(raiz->dir)) + 1;
    return raiz;
}

bool adicionaAVL(ARVORE* a, ELEMENTO e){
    NO* novoNo = new NO;
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    novoNo->h = 0;
    novoNo->elemento = e;
    a->raiz = inserirAVL(a->raiz, novoNo);
}


int main(){
    //aasd
    ARVORE a;
    inicializaArvore(&a);
    ELEMENTO e;
    e.nome = "aa";
    e.valor= 123;
    adicionaAVL(&a, e);
    e.nome = "tt";
    e.valor = 456;
    adicionaAVL(&a, e);
    listarArvore(&a,0);
    e.nome = "rr";
    e.valor = 142;
    cout << endl;
    adicionaAVL(&a, e);
    listarArvore(&a,0);
    e.valor = 44;
    adicionaAVL(&a, e);
    e.valor = 90;
    adicionaAVL(&a, e);
    e.valor = 60;
    adicionaAVL(&a, e);
    cout << endl;
    listarArvore(&a,0);
    e.valor = 900;
    adicionaAVL(&a, e);
    cout << '\n' << endl;
    listarArvore(&a,0);


    return 0;
}
