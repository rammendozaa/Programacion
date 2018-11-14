/* Accepted */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector <long long int> sacarPrimos(long long int a)
{
    long long int raiz = sqrt(a);
    vector <long long int> primos;
    for(int i = 2 ; i <= raiz ; i++)
    {
        while(a % i == 0)
        {
            primos.push_back(i);
            a /= i;
        }
    }
    //if(a > 1)
    //    primos.push_back(a);
    return primos;
}

int main(void)
{
    vector <string> numeros;
    string auxS;
    long long int suma;
    int n;
    cin >> n;
    while(n--)
    {
        vector <long long int> primos;
        suma = 0;
        cin >> auxS;
        for(auto a : auxS)
        {
            suma += a - '0';
        }
        primos = sacarPrimos(suma);
        if(primos.size() == 0)
            cout << "UltraPrimo\n";
        else
            cout << "No UltraPrimo\n";
    }
    return 0;
}
