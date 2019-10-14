$('#janela').offsetParent().css("background-color", "#ff0" - retorna o elemento pai do elemento com id janela
$( function(e) { 	//padrão do jquery, fica entre tags script
	$('nav li:nth-child(2)').click(function(e) { // devemos passar uma função para o .click
		$('html,body').animate({scrollTop:$('#segunda').offset().top}, 1000);
	})
});		//scrolla o conteúdo até a altura do elemento segunda

$(window).resize(function); // função que é disparada toda vez que a janela é redimensionada, útil para redimensionar elementos

$(function() {/*......*/}) função que é carregada ao carregar a página, executa só uma vez, após o DOM ser todo carregado

$('#cursohtml').click(function() { //define um evento de clique para o elemento cursohtml
    alert("clicou no botão html");
});

$('#cursocss').on("mouseover", function() {
     alert("clicou no botão css"); // informamos o evento e depois atribuimos uma função a ele
});

function mostrarMsgCss() {
   alert("clicou no botão css");
   $('#cursocss').off("mouseover", mostrarMsgCss); // desabilita o evento, ou seja, neste caso ele só vai ser executado uma vez
}
$('#cursocss').on("mouseover", mostrarMsgCss);

$('#cursocss').off(); // mata todo e qualquer evento atribuido ao elemento
$('#janela').hide(); // esconde o elemento
$('#janela').show(); // mostra o elemento



function aplicarCor(e){
   $cor = e.data.cor;
   $("#janela").css('background-color', $cor);
}

$(function(){
   $('#botaoazul').on('click', {cor:'blue'}, aplicarCor); // passando valores em um evento
   $('#botaovermelho').on('click', {cor:'red'}, aplicarCor);
   $('#botaoverde').on('click', {cor:'green'}, aplicarCor);
})


ANIMAÇÕES
$('#janela').toggle(300); // alterna entre show e hide, com uma animação de 300 ms, podemos colocar uma função como parâmetro logo após, que será executada quando a animação terminar
.fadeIn(tempo) .fadeOut() .fadeToggle() // animações de fade
.slideUp(tempo) .slideDown .slideToggle // animação de movimentar o objeto para cima ou para baixo
.animate({left:300, top: 200}, 1000, 'swing'); // animações custom, o último parâmetro define a forma que o objeto se locomove, se é constante, tem aceleração etc
