#!/bin/sh
*  # conteúdo do diretório
MY_MESSAGE="Hello World" # atribuição
echo $MY_MESSAGE # acessar valor da var

read MY_NAME # entrada de dados
echo "Hello $MY_NAME - hope you're well."

alias a=comando # variável pode chamar o comando

. ./script # sourcing, executa o script dentro da própria shell que estamos executando, ao invés de chamar uma nova instância de sh
touch ${nome}_arquivo # pega o conteúdo da variável nome, só então concatena com _arquivo

for i in 1 2 3 4 5 # itera por cada número
do
  echo "Looping ... number $i"
done

for i in hello 1 * 2 goodbye # itera por cada parâmentro, hello e goodbye são tratados como string e cada elemento de * é capturado
do # ou seja, * pega todos os elementos do diretório atual;  ../* pega do subdiretório
  echo "Looping ... i is set to $i"
done

INPUT_STRING=hello
while [ "$INPUT_STRING" != "bye" ]
do
  echo "Please type something in (bye to quit)"
  read INPUT_STRING
  echo "You typed: $INPUT_STRING"
done


if [ ... ]; then
 ...
elif [ ... ]; then
 ...
else
 ...
fi


# && expressa qual rotina seguir se o resultado por verdadeiro
# || é o else do &&
X=5
if [ "$X" -lt "0" ] # -lt é o operador <
then
  echo "X is less than zero"
fi
if [ "$X" -gt "0" ]; then # operador >
  echo "X is more than zero"
fi
[ "$X" -le "0" ] && \ # operador <=
      echo "X is less than or equal to  zero" 
[ "$X" -ge "0" ] && \ # operador >=
      echo "X is more than or equal to zero"
[ "$X" = "0" ] && \
      echo "X is the string or number \"0\"" 
[ "$X" = "hello" ] && \
      echo "X matches the string \"hello\""
[ "$X" != "hello" ] && \
      echo "X is not the string \"hello\""
[ -n "$X" ] && \
      echo "X is of nonzero length"
[ -f "$X" ] && \
      echo "X is the path of a real file" || \
      echo "No such file: $X"
[ -x "$X" ] && \
      echo "X is the path of an executable file"
[ "$X" -nt "/etc/passwd" ] && \
      echo "X is a file which is newer than /etc/passwd"








#!/bin/sh
echo -en "Please guess the magic number: "
read X
echo $X | grep "[^0-9]" > /dev/null 2>&1 # >/dev/null 2>&1 directs any output or errors to the special "null" device, instead of going to the user's screen.
if [ "$?" -eq "0" ]; then
  # If the grep found something other than 0-9
  # then it's not an integer.
  echo "Sorry, wanted a number"
else
  # The grep found only 0-9, so it's an integer. 
  # We can safely do a test on it.
  if [ "$X" -eq "7" ]; then
    echo "You entered the magic number!"
  fi
fi


#!/bin/sh

echo "Please talk to me ..."
while :
do
  read INPUT_STRING
  case $INPUT_STRING in
	hello)
		echo "Hello yourself!"
		;;
	bye)
		echo "See you again!"
		break
		;;
	*)
		echo "Sorry, I don't understand"
		;;
  esac
done


#!/bin/sh
which xdg-open
a=$(date +%m_%d_%y-%H.%M.%S)
echo $a



#!/bin/sh
echo "I was called with $# parameters" # num total de params
echo "My name is $0" # nome do script, `basename $0` mostra apenas o nome, sem incluir ./
echo "My first parameter is $1" # primeiro param
echo "My second parameter is $2" # segundo
echo "All parameters are $@" # todos os params delimitados por espaço

# $$ é a variável que contém o PID



