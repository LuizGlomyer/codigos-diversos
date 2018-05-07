#codigo que escreve o proprio codigo

a = open("codigo.py","r")

for linha in a.readlines():
    print(linha, end="")