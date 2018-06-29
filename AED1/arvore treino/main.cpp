#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

typedef struct{
    int cod_pac;
    string nome;
    string cpf;
    int idade;
}PACIENTE;

typedef struct aux{
    PACIENTE pac;
    aux* esquerda;
    aux* direita;
}NO;

typedef struct{
    NO* raiz;
}ARVORE;

void inicializaArvore(ARVORE *a){
    a->raiz = NULL;
}

NO* criarNo(PACIENTE p){
    NO* no = new NO;
    no->pac = p;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

NO* inserir(NO* raiz, NO* no){
    if(raiz == NULL)
        return no;
    if(raiz->pac.cod_pac > no->pac.cod_pac)
        raiz->esquerda = inserir(raiz->esquerda, no);
    else
        raiz->direita = inserir(raiz->direita, no);
    return raiz;
}

bool adiciona(ARVORE* a, NO* novo){
    a->raiz = inserir(a->raiz, novo);
    return true;
}

bool adiciona2(ARVORE *a, PACIENTE p){
    NO* no = new NO;
    no->pac = p;
    no->esquerda = NULL;
    no->direita = NULL;
    adiciona(a, no);
    return true;
}

int somatorioNos(NO* no){
    if(no == NULL)
        return 0;
    int soma = no->pac.cod_pac, a = 0, b = 0;
    if(no->esquerda != NULL)
        a = somatorioNos(no->esquerda);
    if(no->direita != NULL)
        b = somatorioNos(no->direita);

    soma = soma + a + b;
    return soma;
}

int soma(ARVORE* a){
    return somatorioNos(a->raiz);
}


int profundidade(NO* no, int valor, int a){
    if(no == NULL)
        return 0;
    if(no->pac.cod_pac == valor)
        return a;
    if(valor > no->pac.cod_pac){
        a = profundidade(no->direita, valor, a+1);
        return a;
    }
    if(valor < no->pac.cod_pac){
        a = profundidade (no->esquerda, valor, a+1);
        return a;
    }
}

int profundidadeArvore(ARVORE* a, int valor){
    return profundidade(a->raiz, valor, 0);
}

void listarNos(NO* raiz){

    if(raiz != NULL){
        cout << "----------------------------" << endl;
        cout << "Endereco: " << raiz << endl;
        cout << "No esquerdo: " << raiz->esquerda << endl;
        cout << "No direito: " << raiz->direita << endl;
        cout << "Codigo: " << raiz->pac.cod_pac << endl;
        cout << "Nome: " << raiz->pac.nome << endl;
        cout << "----------------------------" << endl;
        listarNos(raiz->esquerda);
        listarNos(raiz->direita);
    }
}

void listarArvore(ARVORE* a){
    listarNos(a->raiz);
}

int altura(NO* no, int cont){
    if(no == NULL)
        return 0;
    int esq = cont, dir = cont;
    if(no->esquerda != NULL)
        esq = altura(no->esquerda, cont + 1);
    if(no->direita != NULL)
        dir = altura(no->direita, cont + 1);
    return esq > dir ? esq : dir;
}

int alturaArvore(ARVORE* a){
    return altura(a->raiz, 0);
}

int main(){

    ARVORE a;
    inicializaArvore(&a);
    PACIENTE np;
    np.cod_pac = 25;
    np.nome = "prova";
    adiciona2(&a, np);
    np.cod_pac = 13;
    adiciona2(&a,np);
    np.cod_pac = 24;
    adiciona2(&a, np);
    np.cod_pac = 61;
    adiciona2(&a, np);
    np.cod_pac = 11;
    adiciona2(&a, np);
    np.cod_pac = 9;
    adiciona2(&a, np);


    listarArvore(&a);

    cout << "\nSoma: " << soma(&a) << endl;
    int valor = 61;
    cout << "Profundidade de " << valor <<": " << profundidadeArvore(&a, valor) << endl;
    cout << "Altura da arvore: " << alturaArvore(&a) << endl;



    return 0;
}
