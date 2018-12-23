/* Accepted */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cases, casos = 0;
    cin >> cases;
    while(cases--)
    {
        int n, auxI, maxMax = -1e9, maxAhora = 0;
        int ini = 1, fin = 1, s = 1, longitud = 0, longAct = 0, maximNo = -1e9, indice, finFin = 0, finBeg = 0;
        cin >> n;
        for(int i = 1 ; i < n ; i++)
        {
            cin >> auxI;
            if(maxAhora >= 0)
                maxAhora += auxI;
            else
            {
                maxAhora = auxI;
                ini = i;
            }
            if(maxAhora > maxMax || (maxAhora == maxMax && (i + 1) - ini > finFin - finBeg))
            {
                maxMax = maxAhora;
                finFin = i + 1;
                finBeg = ini;
            }

        }
        if(maxMax > 0)
            cout << "The nicest part of route " << ++casos << " is between stops " << finBeg << " and " << finFin << "\n";
        else
            cout << "Route " << ++casos << " has no nice parts\n";
    }
    return 0;
}
