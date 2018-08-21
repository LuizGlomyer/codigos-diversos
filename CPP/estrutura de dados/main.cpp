#include <iostream>
using namespace std;

#include "Fila.hpp"
#include "Pilha.hpp"
#include "ListaLigada.hpp"
#include "ListaDupla.hpp"
#include "TabelaHash.hpp"
#include "Arvore.hpp"

#include "aleatorio.hpp"

int main(){
    sementeAleatoria();
    //cout << "Teste de filas: " << endl;
    /*Fila<int> f1;
    f1.adicionar(2);
    f1.adicionar(98);
    f1.adicionar(234);
    f1.adicionar(5);
    f1.mostrarFila();

    f1.remover();
    f1.remover();
    f1.remover();
    f1.remover();

    Fila<string> f2;
    f2.adicionar("ohh");
    f2.adicionar("magolor");
    f2.adicionar("gg");
    f2.mostrarFila();
    f2.remover();
    f2.remover();
    f2.remover();
    f2.remover();

    cout << "\nTeste de pilhas: " << endl;
    Pilha<int> p1;
    p1.adicionar(1);
    p1.adicionar(2);
    p1.adicionar(3);
    p1.mostrarPilha();
    p1.remover();
    p1.mostrarPilha();
    Pilha<char*> p2;
    p2.adicionar("oi");
    p2.adicionar("teste");
    p2.adicionar("charponteiro");
    p2.mostrarPilha();

    //cout << "Teste de listas ligadas: " << endl;
    ListaLigada<string> l1;
    l1.adicionar("lula");
    l1.adicionar("ursal");
    l1.adicionar("acer");
    l1.adicionar("cereja");
    l1.mostrarLista();
    cout << endl;
    l1.remover(1);
    l1.mostrarLista();
    cout << endl;
    l1.remover();
    l1.mostrarLista();
    l1.remover();
    l1.remover();
    l1.remover();

    cout << "Teste de lista ligadas duplas: " << endl;
    ListaDupla<string> d1;
    d1.adicionar("merge");
    d1.adicionar("quick");
    d1.adicionar("tree");
    d1.adicionar("avl");
    d1.mostrarLista();
    cout << endl;
    d1.remover(2);
    d1.mostrarLista();
    cout << endl;
    d1.remover();
    d1.mostrarLista();
    cout << endl;
    d1.remover();
    d1.remover();
    d1.remover();
    */

    Fila<int> f1;
    size_t s = std::hash<string>{}("oi");
    s = std::hash<int>{}(44);
    cout << s << endl;

    /*TabelaHash<int> t1(10);
    t1.adicionar(5);
    t1.adicionar(3);
    t1.adicionar(33);
    t1.adicionar(25);
    t1.adicionar(20);
    t1.adicionar(0);
    t1.adicionar(90);
    t1.mostrarTabela();

    TabelaHash<char> t2(26);
    for(int i = 0; i < 50; i++)
        t2.adicionar(charAleatorioSimb());
    t2.mostrarTabela();


    TabelaHash<string> t3;
    for(int i = 0; i < 500; i++)
        t3.adicionar(stringAleatorio(5));
    t3.remover(25,1);
    t3.mostrarTabela();
    */

    Arvore<int> a;
    a.inserir(12);
    a.inserir(15);
    a.inserir(9);
    a.inserir(4);
    a.inserir(2);
    a.inserir(3);





    return 0;
}
