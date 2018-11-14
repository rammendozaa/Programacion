import math
casos = int(input())
k = 0
cases = 1
while k < casos:
    llamadas = int(input())
    llamadas = map(int,input().strip().split(" "))
    juice = int(0)
    mile = int(0)
    for a in llamadas:
        juice += ((((a / 60) + 1) * 15) if (a % 60 == 0) else ((math.ceil(a / 60.0)) * 15))
        mile += ((((a / 30) + 1) * 10) if (a % 30 == 0) else ((math.ceil(a / 30.0)) * 10))
    if juice < mile:
        print(f'Case {cases}: Juice {int(juice)}')
    elif mile < juice:
        print(f'Case {cases}: Mile {int(mile)}')
    else:
        print(f'Case {cases}: Mile Juice {int(juice)}')
    cases = cases + 1
    k = k + 1
#p3
