Terminal Linux

/ - diretório raiz
~ - diretório home do usuário atual


sudo - ao colocar antes de um comando permite usar os poderes de root
sudo su - muda o terminal para o superuser
htop - um monitor de tarefas robusto. Mostra os processos abertos, threads etc

cd diretorio - muda diretório
cd .. - volta uma pasta   ../../ - volta duas pastas
cd "palavra" (apertando tab) - completa automaticamente, se estivessemos em home, escrito Desk, ele iria completar Desktop. Caso não esteja escrito nada ou houver uma colisão entre a palavra, ele lista os diretórios disponíveis
cd "Teste 123", cd 'Teste 123', cd Teste\ 123 - equivalentes (espaço em branco)
pushd diretório - vai para o diretório informado, mas sem remover o anterior. É uma espécide de pilha de diretórios.
popd - desempilha o diretório atual e muda para o próximo da pilha

echo "string" - exporta a string para algum lugar. Sem argumentos, mostra no próprio terminal
echo "string" > arquivo.txt - exporta a string para um .txt
which comando - retorna o diretório de onde o comando está localizado. Ex: which firefox retorna onde a aplicação está armazenada
file diretório - retorna o tipo e os atributos de um arquivo
locate nome - retorna todos os diretórios do sistema que contém o nome informado

clear - limpa a tela
pwd - mostra o diretório atual
ls - lista o conteúdo do diretório atual. ls diretorio - lista diretório
ls *.mp3 - lista todos os arquivos de tipo mp3
ls foto?.png - lista todas as fotos, ex: foto1, foto2 etc
-a mostra hidden files -l mostra tamanhos e permissões

mkdir nome_da_pasta - cria uma pastaf
touch nome_arquivo - cria um arquivo
cat arquivo.txt - mostra o arquivo no terminal
cp diretorio1 diretorio2 - copia diretorio1 para o diretorio 2. Flag -r para copiar também o conteúdo presente dentro da pasta
rm nome_do_arquivo - remove o arquivo. Não serve para pastas. Para pastas usar rm -rf nome_da_pasta

chmod - altera as permissões do arquivo
chown - altera o dono do arquivo

mv diretorio1 diretorio2 - move diretorio1 para o diretorio2. Também serve para renomear. Ex:
mv pasta1 pasta2 >> move a pasta 1 para a pasta 2 caso a pasta 2 exista, caso não exista, apenas renomeia
mv texto.txt pasta >> move o arquivo para a pasta caso não exista dentro da pasta. Se existir, substitui o arquivo anterior


cal - calendário do mês   cal ano - calendário do ano informado
history - histórico dos comandos usados


hostname - printa o local host, o nome da máquina
date
time
who - quem está logado na máquina
uptime - tempo que a maquina está ligada


PERMISSÕES
ls -lh - lista os arquivos e suas permissões
drwxr-xr-x (pasta qualquer)  -rw-r--r-- (arquivo recém criado pelo terminal) 

o primeiro caractere diz se é pasta (d) ou arquivo (-). Os três próximos caracteres são as permissões do arquivo para o dono: read (r), write (w), execute (x). Scripts necessitam da permissão x para rodarem no terminal

Os três seguintes se referem às permissões do grupo do dono (adm, usuario médios etc(). Os três últimos se referem às permissões para qualquer usuário
r = 4  w = 2  x = 1, o somatório desses valores é a permissão de um usuário

chmod muda as permissões de um diretório, chown muda o dono de um arquivo

chmod 777 diretorio - cada dígito se refere a cada um dos níveis explicaos acima
chmod +r diretorio - ativa a leitura para cada usuário
chmod -x diretorio - desativa a leitura para todos os usuarios
chown usuario:seu_grupo diretorio - muda o dono do arquivo


COMANDOS SUDO

apt-get install nome
apt-get update
apt-get upgrade
shutdown -PARAM now - r para reiniciar e h para desligar
updatedb

ATALHOS
ctrl + alt + F(1-6) muda para um terminal de texto puro
ctrl + alt + F(7-12) muda para a interface gráfica
