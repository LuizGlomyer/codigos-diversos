vetor.splice(0, 2) // remove 2 elementos a partir da posição 0

<input name="entrada", id="entrada" class="entrada">
document.getElementByTagName(nome) : retorna o objeto que possui o nome informado, que nem acima
document.getElementByClassName(nomeClasse) - retona um vetor de objetos, estes objetos sendo da classe informada

document.querySelector(query) - faz uma pesquisa no DOM e retorna os elementos correspondentes. Ex: ('body div#app input') diz para procurar no body uma div que possui a id 'app' e depois captar o primeiro input que aparecer. Já ('input[name=nome]') retorna o input tal que o seu name é 'nome'. Notar que as [] são uma lista de atributos. "button.botao" pega todos os buttons que têm a classe botao.
documento.querySelectorAll(query) - mesma coisa, só que retorna todos os elementos ao invés de apenas o primeiro

JS consegue referenciar atributos do DOM, ex:
var inputElement = document.querySelector('input[name=nome]')
var btnElement = document.querySelector("button.botao"); // seleciona o button tal que ele seja da classe 'botao'
btnElement.onclick = function(){ // como já estamos referenciando o button podemos alterar seus atributos
    var text = inputElement.value;
    alert(text);
}; 

Manipulando elementos:

var linkElement = document.createElement('a'); // cria um elemento do tipo informado, no caso, uma tag <a></a>
linkElement.setAttribute('href', 'http://google.com'); // seta o atributo <a href=''>
var textElement = document.createTextNode("Acessar site do google"); // texto que fica dentro da tag <>texto</>
linkElement.appendChild(textElement); // põe no elemento criado
// criamos o elemento mas ainda não o colocamos no body
var containerElement = document.querySelector("div#app");  // seleciona a div onde queremos colocar
containerElement.appendChild(linkElement); // colocamos o elemento

var inputElement = document.querySelector('#nome'); // referência do elemento
containerElement.removeChild(inputElement); // removemos o elemento


Mudando css
<div class="box"></div>
var boxElement = document.querySelector('.box')
boxElement.style.width = 100;
boxElement.style.height = 100;
boxElement.style.backgroundColor = '#0F0';




//ES6+
var minhaPromise = function(){
    return new Promise(function(resolve, reject){
        var xhr = new XMLHttpRequest();
        xhr.open('GET', 'https://api.github.com/users/luizglomyer');
        xhr.send(null);
        xhr.onreadystatechange = function(){
            if(xhr.readyState === 4){
                if(xhr.status === 200){
                    resolve(JSON.parse(xhr.responseText));
                } else {
                    reject("Erro na requisição");
                }
            }
        }
    })
}

podemos reduzir a promisse usando este script
<script src="https://unpkg.com/axios/dist/axios.min.js"></script>
e, então:


axios.get('https://api.github.com/users/luizglomyer')
 .then(function(response) { // then executa após o método resolve
     console.log(response.data.avatar_url);
 })
  .catch(function(error){
      console.warn(error);
  }); // captura o reject



class List {
    constructor() {
        this.data = [];
    }

    add(data) {
        this.data.push(data);
        console.log(this.data);
    }
}

class TodoList extends List{
    constructor() {
        super();

        this.usuario = 'Luiz';
    }

    mostraUsuario() {
        console.log(this.usuario);
    }
}

var MinhaLista = new TodoList();
document.getElementById('novoTodo').onclick = function(){
    MinhaLista.add("Novo todo");
}
MinhaLista.mostraUsuario();


//MÉTODOS DE ARRAY
const arr = [1, 3, 4, 5, 8, 9];

const newArr = arr.map(function(item, index){
    return item + index; // aplica uma função a cada item do array
});
console.log(newArr);

const sum = arr.reduce(function(total, next){
    return total + next; // método para reduzir o vetor inteiro a um único valor
});
console.log(sum);

const filter = arr.filter(function(item){
    return item%2 === 0; // retorna todos os divisíveis por 2
});
console.log(filter);

const find = arr.find(function(item){
    return item === 4; // retorna o item que é 4
});
console.log(find);


//ARROW FUNCTIONS
const arr = [1, 2, 3, 4, 5]
const new Arr = arr.map(function(item) {return item * 2;});
// modo reduzido, usando arrow functions
const newArr = arr.map(item => item *2) // multiplica todos os itens do array por 2 e os retorna
const teste = () => 3; // retorna o valor. Objetos json não podem ser retornados diretamente dessa forma, porque a {} deles se confunde com a chave do corpo de função, devemos então colocar {return {objeto}} ou simplesmente colocamos parênteses por volta das chaves, como ({objeto})


///DESESTRUTURAÇÃO
const usuario = {
    nome: "luiz",
    idade: 20,
    endereco: {
        cidade: "Manaus",
        estado: "AM"
    },
};

const {nome, idade, endereco: {cidade} } = usuario;
console.log(nome);
console.log(idade);
console.log(cidade);

function mostraNome({nome, idade}){ // diz para pegar apenas as chaves nome e idade do objeto
    console.log(usuario.nome);
}
mostraNome(usuario);


///REST/SPREAD OPERATOR
const usuario = {
    nome: "Luiz",
    idade: 20,
    instituicao: "UEA"
};

const {nome, ...resto} = usuario;
console.log(nome);
console.log(resto);

const arr = [1,2,3,4];
const [a, b, ...c] = arr;
console.log(a);
console.log(b);
console.log(c);

function soma(...params){ // numero n de params, entra como um array dentro da função
    return params.reduce((total, atual) => total + atual);
}
console.log(soma(1,2,3,4,5));


const arr1 = [1,2,3];
const arr2 = [4,5,6];
const arr3 = [...arr1, ...arr2]; // juntar o conteúdo de arrays
console.log(arr3);

const usuario2 = {...usuario, nome: "Teste"}; // pegamos todos os campos de usuário, mas sobreescrevemos o campo nome
console.log(usuario2);

///TEMPLATE LITERALS
const nome = "Luiz";
const idade = 20;
console.log(`nome: ${nome} idade: ${idade}`);

///OBJECT SHORT SYNTAX
const nome = 'Luiz'; const idade = 20;
const usuario = { nome, idade, empresa:'UEA' } // não precisamos colocar nome:nome, idade:idade, podemos colocar direto o nome da variável que temos declarada
