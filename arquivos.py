#gerar todas as silabas possiveis em um arquivo

silabas = open("silabas.txt", "w")

for consoante in 'bcdfghjklmnpqrstwxyz':
    for vogal in 'aeiou':
        sil = consoante+vogal
        silabas.write(sil)
        silabas.write(" ")


d = ["ch", "lh", "rr", "ss", "sc", "gu", "qu", "nh","sh"]
for digrafo in d:
    for vogal in "aeiou":
        a = digrafo+vogal
        silabas.write(a)
        silabas.write(" ")

letras = "lrsxmnaeiou"  # letras que podem ficar soltas
for letra in letras:
     silabas.write(letra)
     silabas.write(" ")

silabas.close()



#mudar as vogais para *
l = open("texto.txt", "r")
k = open("crypto.txt", "w")

for linha in l.readlines():
    for letra in linha:
        if letra in "aeiou":
            k.write("*")
        else:
            k.write(letra)
l.close()
k.close()


arquivo = open("números.txt", "w")
for linha in range(1,101):
    arquivo.write("%s\n" %linha)
arquivo.close()

arquivo = open("números.txt", "r")
for linha in arquivo.readlines():
    print(linha.rstrip(), end=" ")
arquivo.close()




