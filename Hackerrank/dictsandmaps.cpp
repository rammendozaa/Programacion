/* Accepted */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "mapa.h"
using namespace std;

int main(void)
{
    mapa <string, int> *soyMapa = new mapa<string, int> ();
    int entradas, auxT;
    cin >> entradas;
    string auxN, nombres;
    for(int i = 0 ; i < entradas ; i++)
    {
        cin >> auxN >> auxT;
        soyMapa -> insertar(auxN, auxT);
    }
    while(cin >> nombres)
    {
        int res = soyMapa -> rescatar(nombres);
        if(!res)
            cout << "Not found\n";
        else
            cout << nombres << "=" << res << "\n";
    }
    return 0;
}
