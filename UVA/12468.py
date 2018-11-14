import sys
for line in sys.stdin:
    valores = []
    for var in line.split():
        valores.append(var)
    arriba = int(valores[1]) if int(valores[1]) > int(valores[0]) else int(valores[0])
    abajo = int(valores[1]) if int(valores[1]) < int(valores[0]) else int(valores[0])
    if abajo == -1 and arriba == -1:
        break
    else:
        normal = arriba - abajo
        vuelta = (100 - arriba) + (abajo - 0)
        res = normal if normal < vuelta else vuelta
        print (f'{res}')
