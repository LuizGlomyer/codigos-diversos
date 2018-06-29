#include <iostream>
using namespace std;

#include "classeSTRING.hpp"


int main(){
    STRING bg;
    cout << bg << endl<< "teste de STRING vazia^" << endl;

    STRING s1("aa"), s2("bb"), s3("cc"), s4("ab"), s5("cc");

    if(s1 > s2){
        cout << s1 << " eh maior que " << s2 << endl;
    }
    if(s3 == s5 && s3<= s5 && s3 >= s5)
        cout << s3 << " e " << s5 << " sao iguais" << endl;

    if(s4 < s5)
        cout << s4 << " eh menor que " << s5 << endl;
    if(s2 >= s1)
        cout << s2 << " eh maior ou igual a " << s1 << endl;
    if(s2 != s4)
        cout << s2 << " eh diferente de " << s4 << endl;

    STRING t1("abacate");
    for(int i = 0; i < t1.getTamanho(); i++){
        cout << "indice[" << i << "] de t1: " << t1[i] << endl;
    }
    t1[6] = 'o';
    cout << "teste de sobrecarga de [], atribuicao de um lvalue na STRING t1: " << t1 << endl;

    cout << "concatenacao de objeto STRING e char*: " << t1 + "cereja" << endl;
    STRING t2 = "maracuja";
    cout << "concatenacao de dois objetos STRING: " << t1 + t2 << endl;
    STRING t3 = STRING(t2); //construtor de copia
    cout << "concatenacao usando += com objeto rvalue: " << (t3 += STRING("coca-cola")) << endl;
    cout << "concatenacao usando += com objeto e char*: " << (t1 += "caramelo") << endl;
    STRING t4;
    cout << (!t4 ? "STRING vazia" : "STRING nao-vazia") << endl;

    cout << "Insira um valor para t4" << endl;
    cin >> t4;
    cout << t4 << endl;






    return 0;
}
