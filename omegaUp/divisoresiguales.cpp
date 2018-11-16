/* Accepted */
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;


int main(void)
{
    long long int n, factPrimN, auxIzq = 0, auxDer = 0;
    cin >> n;
    factPrimN = divisores[n];
    int abajo = n - 1, arriba = n + 1, res;
    while(true)
    {
        if(arriba <= 1100000 && divisores[arriba] == divisores[n])
        {
            res = arriba;
            break;
        }
        if(abajo > 0 && divisores[abajo] == divisores[n])
        {
            res = abajo;
            break;
        }
        ++arriba;
        --abajo;
    }
    cout << res << "\n";
    return 0;
}