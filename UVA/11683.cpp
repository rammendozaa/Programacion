#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
    int height, length;
    while(cin >> height >> length && (height != 0 || length != 0))
    {
        vector <int> alturas(length);
        int auxI, alIni, ult;
        cin >> alIni;
        int cont = height - alIni;
        ult = alIni;
        for(int i = 0 ; i < length - 1; i++)
        {
            cin >> auxI;
            if(auxI < ult)
                cont += ult - auxI;
            ult = auxI;
        }
        cout << cont << "\n";
    }
    return 0;
}
