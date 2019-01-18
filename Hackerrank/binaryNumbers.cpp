/* Accepted */
#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    long long int res = 0, entrada, mult = 1, i = 0;
    cin >> entrada;
    while(entrada)
    {
        res += ((entrada % 2) * pow(10, i));
        entrada >>= 1;
        i++;
    }
    int maxActual = 0, maxTotal = -1e9;
    while(res)
    {
        if(res % 2 == 0)
            maxActual = 0;
        else
            maxActual++;
        if(maxActual > maxTotal)
            maxTotal = maxActual;
        res /= 10;
    }
    cout << maxTotal << "\n";
}
