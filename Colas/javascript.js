<input name="entrada", id="entrada" class="entrada">
document.getElementByTagName(nome) : retorna o objeto que possui o nome informado, que nem acima
document.getElementByClassName(nomeClasse) - retona um vetor de objetos, estes objetos sendo da classe informada

document.querySelector(query) - faz uma pesquisa no DOM e retorna os elementos correspondentes. Ex: ('body div#app input') diz para procurar no body uma div que possui a id 'app' e depois captar o primeiro input que aparecer. Já ('input[name=nome]') retorna o input tal que o seu name é 'nome'. Notar que as [] são uma lista de atributos
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









