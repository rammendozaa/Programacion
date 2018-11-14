/* Accepted */
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

long long int sacarDiv(long long int n)
{
    map <int, int> primos;
    while(n % 2 == 0)
    {
        primos[2] = primos[2] + 1;
        n = n >> 1;
    }
    for(int i = 3 ; i <= sqrt(n) ; i += 2)
    {
        while(n % i == 0)
        {
            primos[i] = primos[i] + 1;
            n /= i;
        }
    }
    if(n > 2)
        primos[n] = primos[n] + 1;

    long long int num = 1;
    for(auto a : primos)
        num *= (a.second + 1);

    return num;
}

long long int gcd(long long int a, long long int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

int main(void)
{
    long long int uno, dos, ggg, unoO, dosO;
    cin >> uno >> dos;
    unoO = max(uno, dos);
    dosO = min(uno, dos);
    ggg = gcd(unoO, dosO);
    if(ggg == 1)
        cout << 1 << "\n";
    else
        cout << sacarDiv(ggg) << "\n";
    return 0;
}
