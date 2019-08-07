var a = 1; //tipo fixo
dynamic b = "c"; //tipo pode mudar, similar a python
List frutas = new List() //qualquer tipo de dados, podemos usar simplesmente []
List<int> numeros = [] //restringe o tipo de dados de uma lista
for(Usuario u in lista){} //itera na lista
Map estados = Map() //tabela hash
Map<String, String> estados = Map(); estados["SP"] = "São Paulo"; //primeiro tipo é a chave o segundo é o dado
Map<int, dynamic> estados //chave int, dado é qualquer tipo 
estados.forEach(
    (chave, valor)  => print("$chave - $valor") //outra forma de iterar
);


(){} //função anônima, instruções vão dentro das chaves
int _variavel //variavel privada

void exibirDados(String nome, {int idade, double altura}){ //tudo o que está em {} são parâmetros opcionais
    int novaIdade = idade ?? 0; //operador nulo // Fuction funcao para mandar funções como param
    double novaAltura = altura ?? 0;
    print("Olá $nome seu idade: $novaIdade sua altura: $altura");
}

void main(){
    exibirDados("Luiz", idade:20, altura:1.82);
}

abstract Class Animal{ //classe que não pode ser instanciada
    Animal();   
    Animal.jabuti(){} //named constructor, chamamos com Animal tartaruga = new Animal.jabuti()
    Animal(this.especie); //já seta o atributo
    Animal(String especie){
        this.especie = especie;    
    }

    String especie;
    void dormir(){print("dormindo")};
} // instanciação Animal cachorro = new Animal();

Class Papagaio extends Animal{ //herança
    Papagaio(String cor) : super(cor); //construtor do metodo pai

    String _cor;
    String get cor{
        return this._cor;      //gets e sets são implicitos
    }                          //arara.cor = 'vermelho' é um set
    set cor(String cor){       //print(arara.cor) é um get
        this._cor = cor;    
    }
    
    @override       //sobrescrita de metodo.
    void dormir(){} //super.dormir() para usar a implementação da classe pai

}

class Venda implements NotaFiscal{ //interfaces são classes, recomenda-se classes abstratas

}

A a() => b(); //equivale a:
A a(){
    return b();
}



stless/stfull : digitando isto fora da estrutura do app conseguimos criar novas classes Stateless/StatefulWidget. Stateless não podemos alterar o seu estado (constantes) e Stateful podemos alterar o seu estado (variáveis)




