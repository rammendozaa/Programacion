# Accepted
def expBin(a, b, mod):
    resultado = 1
    while(b):
        if(b & 1):
            resultado = (resultado * a) % mod
        a = (a * a) % mod
        b >>= 1
    print (resultado)
    return


casos = int(input())
k = 0
while k < casos:
    equis, ye, ene = map(int,raw_input().split())
    expBin(a = equis, b = ye, mod = ene)
    k += 1
