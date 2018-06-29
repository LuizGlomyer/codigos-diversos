#include <locale.h>
#include <iostream>
#define MAX 5
using namespace std;


typedef struct{
    int cod_aluno;
    char* nome;
    int idade;
}ALUNO;

typedef struct{
    ALUNO alun;
    int proximo;
}ELEMENTO;

typedef struct{
    ELEMENTO turma[MAX];
    int inicio;
    int disponivel;
}LISTA_MATRICULA;

void inicializaLista_M(LISTA_MATRICULA* m){
    for(int i = 0; i < MAX-1; i++){
        m->turma[i].proximo = i+1;
        m->turma[MAX-1].proximo = -1;
        m->inicio = -1;
        m->disponivel = 0;
    }
}

int tamanho(LISTA_MATRICULA* m){
    int tam = 0;
    int i = m->inicio;
    while(i != -1){
        tam++;
        i = m->turma[i].proximo;
    }
    return tam;
}

void mostrarLista_M(LISTA_MATRICULA* m){
    cout << "------------------------" << endl;
    int i = m->inicio;
    while(i != -1){
        cout << "Aluno" << i << endl;
        cout << "Codigo: " << m->turma[i].alun.cod_aluno << endl;
        cout << "Nome: " << m->turma[i].alun.nome << endl;
        cout << "Idade: " << m->turma[i].alun.idade << endl;
        cout << endl;
        i = m->turma[i].proximo;
    }
}

int buscaMatricula (LISTA_MATRICULA* m, int cod_al){
    int i = m->inicio;
    while(i != -1 && m->turma[i].alun.cod_aluno < cod_al)
        i = m->turma[i].proximo;
    if(i != -1 && m->turma[i].alun.cod_aluno == cod_al)
        return i;
    return -1;
}

int obterNo(LISTA_MATRICULA* m){
    int disp = m->disponivel;
    if(m->disponivel != -1)
        m->disponivel = m->turma[disp].proximo;
    return disp;
}

bool inserirAluno(LISTA_MATRICULA* m, ALUNO novo_aluno){
    if(m->disponivel == -1)
        return false;
    int i = m->inicio;
    int pos_inserir = -1;
    while((i != -1) && (novo_aluno.cod_aluno > m->turma[i].alun.cod_aluno)){
        pos_inserir = i;
        i = m->turma[i].proximo;
    }
    if((i != -1) && (novo_aluno.cod_aluno == m->turma[pos_inserir].alun.cod_aluno)) //estava apenas = ao inves de  ==
        return false;

    i = obterNo(m); //estava *m no exemplo
    m->turma[i].alun = novo_aluno;
    if(pos_inserir == -1){
        m->turma[i].proximo = m->inicio;
        m->inicio = i;
    }else{
    m->turma[i].proximo = m->turma[pos_inserir].proximo;
    m->turma[pos_inserir].proximo = i;
    }
}

void alocarNo(LISTA_MATRICULA* m, int i){
    m->turma[i].proximo = m->disponivel;
    m->disponivel = i;
}

bool excluirAluno(LISTA_MATRICULA* m, int codA){
    int i = m->inicio;
    int anterior = -1;

    while(i != -1 && m->turma[i].alun.cod_aluno < codA){
        anterior = i;
        i = m->turma[i].proximo;
    }
    if(i != -1 && m->turma[i].alun.cod_aluno != codA)
        return false;

    if(anterior == -1)
        m->inicio = m->turma[i].proximo;
    else
        m->turma[anterior].proximo = m->turma[i].proximo;
    alocarNo(m,i);
    return true;
}





int main(void){

    LISTA_MATRICULA m;
    inicializaLista_M(&m);
    cout << tamanho(&m) << endl;
    ALUNO a;
    a.cod_aluno = 22;
    a.nome = "Karla";
    a.idade = 23;
    inserirAluno(&m,a);

    a.cod_aluno = 20;
    a.nome = "Luis";
    a.idade = 23;
    inserirAluno(&m,a);

    a.cod_aluno = 18;
    a.nome = "Pedro";
    a.idade = 23;
    inserirAluno(&m,a);

    a.cod_aluno = 33;
    a.nome = "Israel";
    a.idade = 23;
    inserirAluno(&m,a);

    a.cod_aluno = 30;
    a.nome = "Diana";
    a.idade = 23;
    inserirAluno(&m,a);

    a.cod_aluno = 12;
    a.nome = "Esteban";
    a.idade = 23;
    inserirAluno(&m,a);

    mostrarLista_M(&m);
    excluirAluno(&m,33);
    mostrarLista_M(&m);
    a.cod_aluno = 50;
    a.nome = "Carlos";
    a.idade = 19;
    inserirAluno(&m,a);
    mostrarLista_M(&m);

    return 000;
}
