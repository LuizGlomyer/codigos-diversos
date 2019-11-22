#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#define MAX 5
using namespace std;




typedef struct{
    int num_matricula[MAX];
    int num_elementos;
}MATRICULA;
//maximo de 20 alunos


void menu(){
    cout << "O que deseja fazer?\n" << endl;
    cout <<"a) adicionar uma matricula" << endl;
    cout <<"b) excluir um elemento, dado o valor do elemento" << endl;
    cout <<"c) exibir o valor de uma matricula por sua posição" << endl;
    cout <<"d) maior matricula da turma" << endl;
    cout <<"e) menor matricula da turma" << endl;
    cout <<"f) alterar o valor de uma matricula de acordo sua posição" << endl;
    cout <<"g) alterar o valor de uma matricula de acordo ao valor" << endl;
    cout <<"h) listar matriculas duplicadas" << endl;
    cout <<"i) excluir matriculas duplicadas" << endl;
    cout <<"j) printar todos os elementos da lista" << endl;
    cout <<"k) adicionar um elemento a partir de uma chave" << endl;
    cout <<"l) deletar um elemento a partir de uma chave" << endl;
    cout <<"\nz) sair\n" << endl;
}

void inicializaVetor(MATRICULA *m){
    m->num_elementos = 0;
}

void inserirMatricula(MATRICULA *m){
    if(m->num_elementos == MAX){
        cout << "Lista cheia, nao é possivel inserir novo aluno" << endl;
        system("pause");
        return;
    }
    int valor;
    cout << "insira o valor a ser colocado na lista" <<endl;
    cin >> valor;
    m->num_matricula[m->num_elementos] = valor;
    m->num_elementos++;
}

void mostrarTudo(MATRICULA *m){
    cout << "-------------------------" << endl;
    for(int i = 0; i < m->num_elementos; i++){
        cout << "Matricula " << i << " = " <<m->num_matricula[i]<<endl;
    }
}

void excluirElemento(MATRICULA *m, int posicao){
    if(posicao == MAX-1){
        m->num_elementos--;
        return;
    }
    for(int i = posicao; i < m->num_elementos; i++)
        m->num_matricula[i] = m->num_matricula[i+1];
    m->num_elementos--;
}

void mostrarMatricula(MATRICULA* m){

    if(m->num_elementos == 0){
        cout << "Estrutura vazia!" << endl;
        return;
    }

    int posicao;
    cout << "Insira a posicao do elemento desejado" << endl;
    cin >> posicao;

    if(posicao > m->num_elementos -1 || posicao < 0){
        cout << "Valor inválido" << endl;
        return;
    }

    cout << "A matricula eh: " << m->num_matricula[posicao] << endl;
}

void maiorMatricula(MATRICULA* m){
    int maior = m->num_matricula[0];
    for(int i = 0; i < m->num_elementos; i++){
        if(maior < m->num_matricula[i])
            maior = m->num_matricula[i];
    }
    cout << "A maior matricula é " << maior << endl;
}

void menorMatricula(MATRICULA* m){
    int menor = m->num_matricula[0];
    for(int i = 0; i < m->num_elementos; i++){
        if(menor > m->num_matricula[i])
            menor = m->num_matricula[i];
    }
    cout << "A menor matricula eh " << menor << endl;
}

void alteraValor(MATRICULA * m){

    int posicao, novovalor;
    cout << "Insira a posição do elemento a ter o valor alterado" << endl;
    cin >> posicao;
    if(posicao < 0 || posicao > m->num_elementos -1){
        cout << "Posição inválida" << endl;
        return;
    }

    cout << "Insira o novo valor" << endl;
    cin >> novovalor;
    m->num_matricula[posicao] = novovalor;
}

void listarMatDuplicada(MATRICULA* m){
    for(int i = 0; i < m->num_elementos; i++){
        for(int j = i+1; j < m->num_elementos; j++){
            if(m->num_matricula[i] == m->num_matricula[j])
                cout << "Matrícula duplicada: Valor: " << m->num_matricula[i] << " posição " << i <<
                " ==  Valor: " << m->num_matricula[j] << " posição " << j << endl;
        }
    }
}

void deletarMatDuplicada(MATRICULA* m){
    int igual = 0;

    for(int i = 0; i < m->num_elementos; i++){
        for(int j = i+1; j < m->num_elementos; j++){
            if(m->num_matricula[i] == m->num_matricula[j]){
                igual = 1;
                for(int k = j; k < m->num_elementos-1; k++){
                    m->num_matricula[k] = m->num_matricula[k+1];
                }
                m->num_elementos--;
            }
        }
    }
    if(igual)
        deletarMatDuplicada(m); //recursao, porque se tiver 3 elementos iguais, por exemplo, só uma passada da função não basta,
                                //se tiver mais de 2 iguais, depois de uma passada ficarão 2 valores iguais no vetor,
                                //para resolver isso é só passar outra vez a função
}


void adicionaValorPelaChave(MATRICULA* m){

    if(m->num_elementos == MAX){
        cout << "Lista cheia, nao é possivel inserir novo aluno" << endl;
        return;
    }
    int chave, valor;
    cout << "Insira em que posição será colocado o novo valor" << endl;
    cin >> chave;
    if(chave < 0 || chave > m->num_elementos-1){
        cout << "Valor inválido" << endl;
        return;
    }
    cout << "Insira o valor" << endl;
    cin >> valor;

    for(int i = m->num_elementos; i > chave; i--){
        m->num_matricula[i] = m->num_matricula[i-1];
    }
    m->num_matricula[chave] = valor;
    m->num_elementos++;
}


void excluirValorPelaChave(MATRICULA* m){
    if(m->num_elementos == 0){
        cout << "Lista vazia, não há o que excluir" << endl;
        return;
    }
    int chave;
    cout << "Insira a posição a ser excluída" << endl;
    cin >> chave;
    if(chave < 0 || chave >= m->num_elementos){
        cout << "Posição inválida" << endl;
        return;
    }

    for(int i = chave; i < m->num_elementos-1; i++){
        m->num_matricula[i] = m->num_matricula[i+1];
    }
    m->num_elementos--;

}
