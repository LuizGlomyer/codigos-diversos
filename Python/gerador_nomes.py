from random import *
n = int(input("insira a quantidade de nomes a serem gerados\n"))
s = open("silabas.txt", "r")
silabas = s.read()
silabas = silabas.split()
nomes = []

for nome in range(n):
    a = ""
    tamanhonome = randint(2,5)
    for silaba in range(tamanhonome):
        sil = choice(silabas)
        while silaba == 0 and sil in "lrsxmn" or silaba == 0 and sil in ["rra", "rre", "rri", "rro", "rru", "ssa","sse", "ssi", "sso", "ssu"]: #a primeira silaba não pode começar com uma dessas consoantes
            sil = choice(silabas)
        a = a + sil
        a = a.capitalize()

    nomes.append(a)

print(nomes)

s.close()