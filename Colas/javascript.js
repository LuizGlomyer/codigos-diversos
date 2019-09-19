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

function soma(...params){ // numero n de params
    return params.reduce((total, atual) => total + atual);
}
console.log(soma(1,2,3,4,5));


const arr1 = [1,2,3];
const arr2 = [4,5,6];
const arr3 = [...arr1, ...arr2];
console.log(arr3);

const usuario2 = {...usuario, nome: "Teste"};
console.log(usuario2);

///TEMPLATE LITERALS
const nome = "Luiz";
const idade = 20;
console.log(`nome: ${nome} idade: ${idade}`);
