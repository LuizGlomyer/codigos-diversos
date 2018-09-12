#include <iostream>
using namespace std;

#include "Fila.hpp"
#include "Pilha.hpp"
#include "ListaLigada.hpp"
#include "ListaDupla.hpp"
#include "TabelaHash.hpp"
#include "Arvore.hpp"
#include "Grafo.hpp"

#include "aleatorio.hpp"


int main(){
    sementeAleatoria();
    //cout << "Teste de filas: " << endl;
    /*Fila<int> f1;
    f1.inserir(2);
    f1.inserir(98);
    f1.inserir(234);
    f1.inserir(5);
    f1.mostrarFila();

    f1.remover();
    f1.remover();
    f1.remover();
    f1.remover();

    Fila<string> f2;
    f2.inserir("ohh");
    f2.inserir("magolor");
    f2.inserir("gg");
    f2.mostrarFila();
    f2.remover();
    f2.remover();
    f2.remover();
    f2.remover();

    cout << "\nTeste de pilhas: " << endl;
    Pilha<int> p1;
    p1.inserir(1);
    p1.inserir(2);
    p1.inserir(3);
    p1.mostrarPilha();
    p1.remover();
    p1.mostrarPilha();
    Pilha<char*> p2;
    p2.inserir("oi");
    p2.inserir("teste");
    p2.inserir("charponteiro");
    p2.mostrarPilha();


    //cout << "Teste de listas ligadas: " << endl;
    ListaLigada<string> l1;
    l1.inserir("lula");
    l1.inserir("ursal");
    l1.inserir("acer");
    l1.inserir("cereja");
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
    d1.inserir("merge");
    d1.inserir("quick");
    d1.inserir("tree");
    d1.inserir("avl");
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
    /*
    Fila<int> f1;
    size_t s = std::hash<string>{}("oi");
    s = std::hash<int>{}(44);
    cout << s << endl;
    */
    /*TabelaHash<int> t1(10);
    t1.inserir(5);
    t1.inserir(3);
    t1.inserir(33);
    t1.inserir(25);
    t1.inserir(20);
    t1.inserir(0);
    t1.inserir(90);
    t1.mostrarTabela();

    TabelaHash<char> t2(26);
    for(int i = 0; i < 50; i++)
        t2.inserir(charAleatorioSimb());
    t2.mostrarTabela();


    TabelaHash<string> t3;
    for(int i = 0; i < 500; i++)
        t3.inserir(stringAleatorio(5));
    t3.remover(25,1);
    t3.mostrarTabela();
    */

   /*
    Arvore<char> a2;
    a2.inserir('k');
    a2.inserir('g');
    a2.inserir('p');
    a2.inserir('i');
    a2.inserir('h');
    a2.inserir('j');
    a2.inserir('d');
    a2.inserir('s');
    a2.inserir('q');
    a2.inserir('z');
    a2.percorreEmOrdem(-1);

    Arvore<string> a3;
    a3.inserir("kabu");
    a3.inserir("geogebra");
    a3.inserir("pp");
    a3.inserir("i");
    a3.inserir("house");
    a3.inserir("jj");
    a3.inserir("dado");
    a3.inserir("ss");
    a3.inserir("qqqqqqqqqqqqqqq");
    a3.inserir("zanza");

    a3.remover("kabu");
    a3.percorreEmOrdem(0);
*/
/*
    Arvore<int> a;
    a.inserir(12);
    a.inserir(15);
    a.inserir(9);
    a.inserir(11);
    a.inserir(4);
    a.inserir(2);
    a.inserir(10);
    a.inserir(3);

    a.remover(2);
    a.remover(11);
    a.remover(12);
    a.percorreEmOrdem(-1);

*/

/*
    Grafo_LA g(5);
    g.inserirAresta(3,2);
    g.inserirAresta(5,2);
    g.inserirAresta(4,3);
    g.inserirAresta(1,1);
    g.inserirAresta(4,2);
    g.inserirAresta(5,1);
    //g.mostrar();
    cout << '\n';

    g.reinicializar(8);
    for(int i = 0; i < 20; i++)
        g.inserirAresta(uintAleatorio(1,8), uintAleatorio(1,8));
    //g.mostrar();


    BuscaEmProfundidade b;
    b.DFS(g);
    cout << '\n';

    Grafo_LA h(9);
     // 1 cinto, 2  camisa, 3 calca, 4 gravata, 5 sapato, 6 meia, 7 relogio, 8 jaqueta, 9 cueca
    h.inserirArestaDirecionada(1,8);
    h.inserirArestaDirecionada(2,4);
    h.inserirArestaDirecionada(6,5);
    h.inserirArestaDirecionada(4,8);
    h.inserirArestaDirecionada(3,5);
    h.inserirArestaDirecionada(9,3);
    h.inserirArestaDirecionada(3,1);
    h.inserirArestaDirecionada(9,5);
    h.inserirArestaDirecionada(2,1);
    BuscaEmProfundidade b2;
    b2.DFS(h);
    for(int i = 0; i < 9; i++)
        cout << b2.ordemTopologica[i] << '\n';

*/

    /*ListaLigada<int> l;
    l.inserir(5);
    l.inserir(8);
    l.inserir(90);
    l.inserir(12);
    l.inserir(45);
    l.inserir(77);
    l.inserir(99);

    int* t = l.retornaInteiros();
    for(int i = 1; i < t[0]; i++)
        cout << t[i] << '\n';
*/



    Grafo_MA h(5);
    h.inserirAresta(1,4);
    h.inserirAresta(5,2);
    h.inserirAresta(4,3);
    h.inserirAresta(3,5);
    h.mostrar();

    BuscaEmProfundidade_MA m;
    m.DFS(h);

    return 0;
}
