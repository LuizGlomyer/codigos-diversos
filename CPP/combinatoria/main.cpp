#include <iostream>
#include <string>
#include<cmath>
using namespace std;

#include "combinacao.hpp"
#include "ListaLigada.hpp"

enum Seta {Esquerda, Direita};

int fatorial(int n){
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;
    else
        return n * fatorial(n-1);
}


class JohnsonTrotter{
public:
    JohnsonTrotter();
    ~JohnsonTrotter();
    bool ehMovel(int);
    bool temNumeroMovel();
    int maiorMovel();
    ListaLigada<int*>* permutar(int);
private:
    void inverterSetas(int);
    void mostrarVet();
    void destruir();
    void inicializar(int);
    void trocaIndices(int, int);
    Seta* setas;
    int* v;
    int tam, numPermutacoes;
};

JohnsonTrotter::JohnsonTrotter(){
    setas = nullptr;
    v = nullptr;
}

JohnsonTrotter::~JohnsonTrotter(){
    destruir();
}

void JohnsonTrotter::destruir(){
    if(setas != nullptr)
        delete [] setas;
    if(v != nullptr)
        delete [] v;
}

void JohnsonTrotter::mostrarVet(){
    for(int i = 0; i < tam; i++)
        cout << v[i] << " ";
    cout << '\n';
}

bool JohnsonTrotter::ehMovel(int pos){
    if(pos == 0){
        if(setas[pos] == Esquerda)
            return false;
        if(setas[pos] == Direita && v[pos] > v[pos+1])
            return true;
        return false;
    }
    if(pos == tam-1){
        if(setas[pos] == Direita)
            return false;
        if(setas[pos] == Esquerda && v[pos] > v[pos-1])
            return true;
        return false;
    }
    if(setas[pos] == Esquerda && v[pos] > v[pos-1])
        return true;
    if(setas[pos] == Direita && v[pos] > v[pos+1])
        return true;

    return false;
}

bool JohnsonTrotter::temNumeroMovel(){
    for(int i = 0; i < tam; i++)
        if(ehMovel(i))
            return true;
    return false;
}

int JohnsonTrotter::maiorMovel(){ //retorna a posicao do maior
    int maior = -1;
    for(int i = 0; i < tam; i++) //o maior vai ser o primeiro móvel
        if(ehMovel(i)){
            maior = i;
            break;
        }

    for(int i = 0; i < tam; i++)
        if(ehMovel(i) && v[i] > v[maior])
            maior = i;
    return maior;
}

void JohnsonTrotter::inicializar(int n){
    destruir();
    v = new int[n];
    setas = new Seta[n];
    tam = n;
    numPermutacoes = 1;
}

void JohnsonTrotter::inverterSetas(int k){
    for(int i = 0; i < tam; i++) //inverter as setas dos maiores que o maior
        if(v[i] > v[k]){
            if(setas[i] == Esquerda){
                setas[i] = Direita;
                continue;
            }

            if(setas[i] == Direita){
                setas[i] = Esquerda;
                continue;
            }
        }
}

void JohnsonTrotter::trocaIndices(int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;

    Seta temp2 = setas[a];
    setas[a] = setas[b];
    setas[b] = temp2;
}



/*
 nota: armazenar todas as permutações dinamicamente é extremamente ineficiente,
 para n = 9 o programa vai ocupar aproximadamente 13 MB na memória (teoricamente,
 no meu teste o programa ocupou uns 27 MB) às vezes é mais útil fazer o processamente
 dentro do próprio método lodo após ser gerada a permutação
*/

ListaLigada<int*>* JohnsonTrotter::permutar(int n){
    inicializar(n);
    for(int i = 0; i < tam; i++){ //1, 2, ... , n
        v[i] = i+1;
        setas[i] = Esquerda;
    }

    //adicionar v na permutacao
    ListaLigada<int*>* permutacoes = new ListaLigada<int*>;
    int* a = new int[tam];
    for(int i = 0; i < tam; i++)
        a[i] = v[i];
    permutacoes->inserir(a);

    while(temNumeroMovel()){
        int maior = maiorMovel();
        if(setas[maior] == Esquerda){
            trocaIndices(maior, maior-1);
            maior = maior-1;
        }

        if(setas[maior] == Direita){
            trocaIndices(maior, maior+1);
            maior = maior+1;
        }

        //mostrarVet();
        inverterSetas(maior); // inverte quem é maior que a variavel maior
        numPermutacoes++;

        a = new int[tam]; //inserir na lista, ineficiente
        for(int i = 0; i < tam; i++)
            a[i] = v[i];
        permutacoes->inserir(a);
    }

    cout << "Total de permutacoes: " << numPermutacoes << '\n';
    return permutacoes;

}


//gera de uma forma que considero meio bagunçada
class Subconjuntos{
public:
    Subconjuntos();
    ~Subconjuntos();
    void inicializar(int);
    ListaLigada<int>* separar(int);
private:
    int* conj;
    int qtdSubconjuntos, cont, posicaoLista;
    void subconjunto(int, int, ListaLigada<int>*);
};


Subconjuntos::Subconjuntos(){
    conj = nullptr;
}

Subconjuntos::~Subconjuntos(){
    if(conj != nullptr)
        delete [] conj;
}

void Subconjuntos::inicializar(int n){
    qtdSubconjuntos = static_cast<int>(pow(2,n));
    conj = new int[qtdSubconjuntos];
    cont = posicaoLista = 0;
}

ListaLigada<int>* Subconjuntos::separar(int n){
    inicializar(n);
    ListaLigada<int>* listaSubconjuntos = new ListaLigada<int>[qtdSubconjuntos];
    subconjunto(1, n, listaSubconjuntos);

    return listaSubconjuntos;
}

void Subconjuntos::subconjunto(int i, int n, ListaLigada<int>* lista){
    if(i > n){
        //cout << "subconjunto " << ++cont << ": ";
        for(int j = 1; j <= n; j++)
            if(conj[j] == 1){
                //cout << j << " ";
                lista[posicaoLista].inserir(j);
            }
            posicaoLista++;
            //cout << "\n";
    }
    else{
        conj[i] = 1;
        subconjunto(i+1, n, lista);
        conj[i] = 0;
        subconjunto(i+1, n, lista);
    }
}




int main(){

    /*int v;
    cin >> v;
    JohnsonTrotter john;
    ListaLigada<int*>* p = john.permutar(v);

    for(int i = 0; i < fatorial(v); i++){
        for(int j = 0; j < v; j++)
            cout << (*p)[i][j] << " ";
        cout << '\n';
    }


    string str;
    cout << "Insira uma palavra a ser permutada: ";
    cin >> str;
    cout << "\nPermutacoes da palavra " << str << ": " << '\n';

    v = str.size();
    p = john.permutar(str.size());
    for(int i = 0; i < fatorial(v); i++){
        string temp = str;
        for(int j = 0; j < v; j++){
           temp[j]  = str[(*p)[i][j] - 1]; //atribuir posição a posição
            //cout << str[(*p)[i][j] - 1] << " "; //imprimir cada letra
        }
        cout << temp;
        cout << '\n';
    }*/

    int n;
    cin >> n;
    Subconjuntos sub;
    int qtd = pow(2, n);
    ListaLigada<int>* subconj = sub.separar(n);

    for(int i = 0; i < qtd; i++){
        subconj[i].mostrarLista();
        cout << '\n';
    }
    delete [] subconj;


    return 0;
}
