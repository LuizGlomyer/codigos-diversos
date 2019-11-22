#include <iostream>
#include <string>
#include <cstdlib>
#define N 127

using namespace std;


typedef struct{
    int codigo;
    string nome;
}PACIENTE;

typedef PACIENTE* Hash[N];

void inicializaTabela(Hash tabela){ //passagem por referencia?
    for(int i = 0; i<N; i++)
        tabela[i] = NULL;
}

int fhash(int chave){
    return chave%N;
}

void insereTabela(Hash tabela, PACIENTE p){
    int h = fhash(p.codigo);
    if(tabela[h] == NULL){
        tabela[h] = new PACIENTE;
        *tabela[h] = p;
    }
    else{
        while (tabela[h] != NULL)
            h++;
        tabela[h] = new PACIENTE;
        *tabela[h] = p;
    }
}

int main(void){

    Hash tabela;
    inicializaTabela(tabela); //como a estrutura é um vetor implicito, estamos enviando o endereco de memoria
    PACIENTE p;
    p.codigo = 123;
    p.nome = "jack";
    insereTabela(tabela, p);
    p.codigo = 24;
    p.nome = "ana";
    insereTabela(tabela, p);
    p.codigo = 45;
    p.nome = "paula";
    insereTabela(tabela, p);
    p.nome = "ronaldo";
    p.codigo = 97;
    insereTabela(tabela, p);
    p.codigo = 123;
    p.nome = "diana";
    insereTabela(tabela, p);
    p.codigo = 24;
    p.nome = "marcio";
    insereTabela(tabela, p);
    p.codigo = 24;
    p.nome = "cleber";
    insereTabela(tabela, p);

    for(int i = 0; i < N; i++)
        if(tabela[i] != NULL)  {
            cout << "Posicao " << i << ": " << tabela[i]->nome << " " << tabela[i]->codigo << endl;
        }




    return 0;
}
