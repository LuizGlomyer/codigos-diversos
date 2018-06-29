#include <iostream>
#include <iomanip>
#include <cstring>
#include "classeSTRING.hpp"
using namespace std;

STRING::STRING(){
    str = new char[1];
    str[0] = '\0';
    tamanho = 0;
}

STRING::STRING(const char* src = ""){
    str = NULL;
    setString(src);
}

STRING::STRING(const STRING& obj){ //construtor de copia
    str = NULL;
    setString(obj.str);
}

STRING::~STRING(){
    delete [] str;
}
STRING STRING::operator=(const STRING& temp){
    setString(temp.str);
    return temp;
}

STRING STRING::operator+(const STRING& temp){
    STRING a(str);
    strcat(a.str, temp.str);
    return a;

}

STRING STRING::operator+(const char* src){
    char* temp = new char[strlen(str) + strlen(src)];
    strcat(temp, str);
    strcat(temp, src);
    return temp;
}

STRING STRING::operator+=(const char* src){
    *this = *this + src;
    return *this;
}

STRING STRING::operator+=(const STRING& temp){
    *this = *this + temp;
    return *this;
}

bool STRING::operator!(){
    return !tamanho;
}

bool STRING::operator==(const STRING& temp){
    return !strcmp(str, temp.str);
}

bool STRING::operator!=(const STRING& temp){
    return strcmp(str, temp.str);
}

bool STRING ::operator<(const STRING& temp){
    return strcmp(str, temp.str) < 0;
}

bool STRING ::operator<=(const STRING& temp){
    return strcmp(str, temp.str) <= 0;
}

bool STRING ::operator>(const STRING& temp){
    return strcmp(str, temp.str) > 0;
}

bool STRING ::operator>=(const STRING& temp){
    return strcmp(str, temp.str) >= 0;
}

char STRING::operator[](int indice) const{
    if(indice < 0 || indice > tamanho)
        cerr << "Indice invalido" << endl;
    return str[indice];
}

char& STRING::operator[](int indice){
    if(indice < 0 || indice > tamanho)
        cerr << "Indice invalido" << endl;
    return str[indice];
}

ostream& operator<<(ostream& saida, const STRING& src){
    saida << src.str;
    return saida;
}

istream& operator>>(istream& entrada, STRING& src){
    char temp[100];
    entrada >> setw(100) >> temp;
    src = temp;
    return entrada;
}

void STRING::setString(const char* temp){
    tamanho = strlen(temp);
    delete [] str;
    str = new char[tamanho];
    strcpy(str, temp);
}

int STRING::getTamanho(){
    return tamanho;
}
