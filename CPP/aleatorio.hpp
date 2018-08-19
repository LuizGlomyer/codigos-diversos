#ifndef ALEATORIO_HPP_INCLUDED
#define ALEATORIO_HPP_INCLUDED

#include <ctime>
#include <cstdlib>
#include <cctype>
#include <cmath>


void sementeAleatoria();
char charAleatorio();
char charAleatorioSimb();
int intAleatorio(int, int);
int uintAleatorio(int, int);
float floatAleatorio(int, int);
float ufloatAleatorio(int, int);
double doubleAleatorio(int, int);
double udoubleAleatorio(int, int);
string stringAleatorio(int);
string stringAleatorioMaiMin(int);
string stringAleatorioSimb(int);



void sementeAleatoria(){
    srand(time(NULL));
}

char charAleatorio(){
    char a = rand() %(90 - 65 + 1) + 65;
    if(rand() % 2)
        a = tolower(a);
    return a;
}

char charAleatorioSimb(){
    char a = rand() % (125 - 33 + 1) + 33;
    return a;
}

//numeros primos grandes não são gerados por causa do limite de RAND_MAX
int intAleatorio(int a, int b){ //intervalo de a até b
    int c = rand() % (b - a + 1) + a;
    return rand() % 2 ? c : -c;
}
int uintAleatorio(int a, int b){
    return rand() % (b - a + 1) + a;
}
float floatAleatorio(int a, int b){
    float f = (rand()) / (static_cast <float> (RAND_MAX/a));
    f = b - f;
    return rand() % 2 ? f : -f;
}

float ufloatAleatorio(int a, int b){
    float f = (rand()) / (static_cast <float> (RAND_MAX/a));
    return b - f;
}


double doubleAleatorio(int a, int b){
   /*std::uniform_real_distribution<double> unif(a, b);
   std::default_random_engine re;
   return; unif(re); precisa de um compilador  atualizado*/
}
double udoubleAleatorio(int a, int b){

}
string stringAleatorio(int a){
    string s = "";
    for(int i = 0; i < a; i++)
        s += tolower(charAleatorio());
    return s;
}
string stringAleatorioMaiMin(int a){
    string s = "";
    for(int i = 0; i < a; i++)
        s += charAleatorio();
    return s;
}
string stringAleatorioSimb(int a){
    string s = "";
    for(int i = 0; i < a; i++)
        s += charAleatorioSimb();
    return s;
}

#endif // ALEATORIO_HPP_INCLUDED
