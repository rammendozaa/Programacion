#AC
import sys

def isLeap(year):
    if(int(year) % 4 == 0):
        if(int(year) % 100 == 0):
            if(int(year) % 400 == 0):
                return True
            else:
                return False    
        else:
            return True
    else:
        return False 

imp = 0
for line in sys.stdin:
    if imp != 0:
        print('')
    imp = 1    
    leap = isLeap(line)
    hul = (int(line) % 15 == 0)
    bul = (leap & (int(line) % 55 == 0))
    if leap:
        print ('This is leap year.')
    if hul:
        print ('This is huluculu festival year.')
    if bul:
        print ('This is bulukulu festival year.')
    if not leap and not bul and not hul:
        print ('This is an ordinary year.')
