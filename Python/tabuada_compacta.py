n = int(input("Insira até onde gerar a tabuada\n"))
for i in range(1,n+1):
    print("Tabuada de %d:" %i,[j*i for j in range(1,11)])