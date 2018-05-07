from random import randint
n = int(input("insira a quantidade de nomes a serem gerados\n"))
s = open("silabas.txt", "r")
silabas = s.read()
silabas = silabas.split()
nomes = []

for nome in range(n):
    a = ""
    tamanhonome = randint (2,5)
    for silaba in range(tamanhonome):
        a = a + silabas[randint(0, len(silabas) - 1)]
    nomes.append(a)

print(nomes)

s.close()

input()
