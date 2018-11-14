import math
members = int(input())
gente = []
i = 0
cancion = []
nombre = "Rujia"
cancion.append("Happy")
cancion.append("birthday")
cancion.append("to")
cancion.append("you")
while i < members:
    auxS = input()
    gente.append(auxS)
    i += 1
veces = math.ceil(members / 16.0)
i = 0
personas = 0
while i < veces:
    j = 0
    while j < 16:
        if personas == members:
            personas = 0
        if j == 11:
            print (f'{gente[personas]}: {nombre}')
        else:
            print (f'{gente[personas]}: {cancion[j % 4]}')
        j += 1
        personas += 1
    i += 1
