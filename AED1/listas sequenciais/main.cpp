#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include "declaracao.h"
#define MAX 5

using namespace std;


int main(){
    setlocale(LC_ALL, "ptb");
    int input;
    char c;
    MATRICULA m;
    inicializaVetor(&m);

    menu:
    menu();

    cin >> c;
    if(c == 'a'){
        system("cls");

        inserirMatricula(&m);
        system("cls");
        goto menu;
    }

    if(c == 'b'){
        system("cls");
        cout << "Insira a posicao a ser excluida" << endl;
        cin >> input;
        if(input >= MAX){
            cout << "erro, valor excede tamanho da lista\n" << endl;
            goto menu;
        }
        excluirElemento(&m, input);
        system("cls");
        goto menu;
    }

    if(c == 'c'){
        system("cls");
        mostrarMatricula(&m);
        system("pause");
        system("cls");
        goto menu;
    }

    if(c == 'd'){
        system("cls");
        maiorMatricula(&m);
        system("pause");
        system("cls");
        goto menu;
    }

    if(c == 'e'){
        system("cls");
        menorMatricula(&m);
        system("pause");
        system("cls");
        goto menu;
    }

    if(c == 'f'){
        system("cls");
        alteraValor(&m);
        system("pause");
        system("cls");
        goto menu;
    }


    if(c == 'j'){
        system("cls");
        mostrarTudo(&m);
        system("pause");
        system("cls");
        goto menu;
    }

    if(c == 'h'){
        system("cls");
        listarMatDuplicada(&m);
        system("pause");
        system("cls");
        goto menu;
    }

    if(c == 'i'){
        system("cls");
        deletarMatDuplicada(&m);
        system("pause");
        system("cls");
        goto menu;
    }

    if(c == 'k'){
        system("cls");
        adicionaValorPelaChave(&m);
        system("pause");
        system("cls");
        goto menu;
    }

    if(c == 'l'){
        system("cls");
        excluirValorPelaChave(&m);
        system("pause");
        system("cls");
        goto menu;
    }

    if(c == 'z')
        exit(1);





    cout << m.num_elementos;
    system("cls");
    goto menu;

    return 0;
}
