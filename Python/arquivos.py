#gerar todas as silabas possiveis em um arquivo

silabas = open("silabas.txt", "w")

for consoante in 'bcdfghjklmnpqrstvwxyz': # silabas normais
    for vogal in 'aeiou':
        sil = consoante+vogal
        silabas.write(sil)
        silabas.write(" ")


d = ["ch", "lh", "rr", "ss", "sc", "gu", "qu", "nh","sh"]
for digrafo in d: #digrafos como cha, lha, gua
    for vogal in "aeiou":
        a = digrafo+vogal
        silabas.write(a)
        silabas.write(" ")

for letra in "bdfgjkptv": #bra bre dra e similares
    for vogal in "aeiou":
        a = letra + 'r' + vogal
        silabas.write(a)
        silabas.write(" ")

for letra in "dklmnrstxz": #silabas com al, el, ak, at, ax
    for vogal in "aeiou":
        a = vogal + letra
        silabas.write(a)
        silabas.write(" ")

letras = "lrsxmnaeiouy"  # letras que podem ficar soltas
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




