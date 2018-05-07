#contagem de letras no livro alice no pais das maravilhas
import string
arquivo = open("alice.txt", "r")


d = {}

for linha in arquivo.readlines(): #lê cada linha do arquivo como uma string
    #print(linha, end="") #imprime todo o texto normalmente
    a = linha.split() #transforma a string em uma lista de palavras
    for palavra in a: #para cada palavra da lista...
        palavra = palavra.lower() #transformar em minúscula
        for caractere in string.punctuation: #string.punctuation retorna uma string com caracteres de pontuação, esse for percorre essa string
            palavra = palavra.replace(caractere, ' ') #se a palavra tiver um caractere de pontuação, ele vai ser substituído por " "

        if palavra not in d: #como agora nós temos a palavra, basta perguntar se ela está ou não no dicionário
            d[palavra] = 1; #se não estiver, cria a chave e conta 1
        else:
            d[palavra] += 1 # se já estiver, adiciona 1 ao valor

for chave in d:
    print(chave, ": ", d[chave])