cases = int(input())
i = 0
while i < cases:
    instru = int(input())
    j = 0
    pos = 0
    mov = []
    auxS = []
    while j < instru:
        auxS = input().split()
        if auxS[0] == "LEFT":
            mov.append(-1)
            pos -= 1
        elif auxS[0] == "RIGHT":
            mov.append(1)
            pos += 1
        else:
            ins = int(auxS[2])
            mov.append(mov[ins - 1])
            pos += mov[ins - 1]
        j += 1
    print(f'{pos}')
    i += 1
