#include <iostream>
#include <cstring>
#include <string>

#include "ListaLigada.hpp"

using namespace std;

bool comparar(char* a, char* b){
    int tam = strlen(a);
    for(int i = 0; i < tam; i++)
        if(a[i] != b[i])
            return false;
    return true;
}

ListaLigada<int>* stringMatcherIngenuo(char* texto, char* str){
    int tamTexto = strlen(texto), tamStr = strlen(str);
    ListaLigada<int>* deslocamentos = new ListaLigada<int>;
    char* trecho = new char[tamStr+1];
    trecho[tamStr] = '\0';
    for(int i = 0; i < tamTexto; i++){
        for(int j = 0; j < tamStr; j++)
            trecho[j] = texto[i+j]; //copiar um trecho do texto para a variavel
        if(comparar(trecho, str))
            deslocamentos->inserir(i);
    }
    return deslocamentos;
}



void criaAlfabeto(char* alfabeto, char* str){
    alfabeto = new char[128];
    for(int i = 0; i < 128; i++)
        alfabeto[i] = 66;
    for(unsigned int j = 0; j < strlen(str); j++)
        alfabeto[(int)str[j]] = j;
    for(int i = 0; i < 128; i++)
        cout << alfabeto[i];
}

ListaLigada<int>* BoyerMoore(char* texto, char* str){
    char* alfabeto = nullptr;
    ListaLigada<int>* deslocamentos = new ListaLigada<int>;
    criaAlfabeto(alfabeto, str);
    int n = strlen(texto), m = strlen(str);
    int salto = 0;

    for(int i = 0; i < n-m; i += salto){
        salto = 0;
        for(int j = m-1; j >= 0; j--){
            if(str[j] != texto[i+j]){
                int a = (int) texto[i+j];
                salto = j - (int) alfabeto[a];
                if(salto < 1)
                    salto = 1;
                break;
            }
        }
        if(salto == 0)
            return deslocamentos;
    }


    delete [] alfabeto;
    return deslocamentos;
}



int main(){

    char* texto = new char[1200];
    strcpy(texto, "Eu o ja tenho minha enevoada bola de cristal por longo tempo. Suas previsoes sao invariavelmente sombrias  e  usualmente  corretas mas ja estou suficientemente acostumado com elas e nao me impedirao de dar-lhe algumas sugestoes, mesmo se isso for meramente um exercicio de  futilidade  cujo  unico  efeito  e  fazer  voce se sentir  culpado.        Nos poderiamos, por exemplo, comecar limpando nossa linguagem nao mais chamando \"bug\" de bug, mas de  erro.    E  muito  mais  honesto,  pois  coloca  a culpa exatamente em quem deve, a saber, o  programador que fez o erro.  A metafora animista do inseto (\"bug\") que imiscui-se  maliciosamente  enquanto  o  programador  nao  esta  olhando e intelectualmente desonesta porque ela  tenta  esconder  o  fato de  que  o erro e criacao do programador.  O aspecto agradavel  dessa simples mudanca de  vocabulario  e  que  ela  tem  um  efeito  profundo:  Enquanto,  anteriormente,  um programa com apenas um bug  era considerado \"quase correto\", agora um programa com um erro e simplesmente \"incorreto\" (porque esta errado).\0");
    char input[100];
    cout << "insira uma string: ";
    gets(input);

    char* str = new char[strlen(input)+1]; //strlen não inclui o espaço para o \0
    strcpy(str, input);
    cout << str << " " << strlen(str) << '\n';

    ListaLigada<int>* deslocamentos = BoyerMoore(texto, str);





    /*
    ListaLigada<int>* deslocamentos = stringMatcherIngenuo(texto, str);

    deslocamentos->mostrarLista();
    char* teste = new char[strlen(input)+1]; //strlen não inclui o espaço para o \0
    teste[strlen(input)] = '\0'; //ultima posicao
    for(int i = 0; i < deslocamentos->getTamanho()+1; i++){
        for(int j = 0; j < strlen(str); j++)
            teste[j] = texto[deslocamentos[1][i] + j];
        cout << "\n" << teste;
        //cout << deslocamentos[1][i] << "\n"; //colocar [1] já que alocamos apenas uma unidade, senão o compilador pensa que estamos na posição i de um vetor de listaligada, já que a variável é um ponteiro
    }
    delete deslocamentos;
    */


    return 0;
}
