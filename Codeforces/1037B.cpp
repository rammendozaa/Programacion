/* Accepted */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using lol = long long int;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lol tam, S, m;
    cin >> tam >> S;
    m = tam >> 1;
    vector <lol> entrada(tam);
    for(lol i = 0 ; i < tam ; i++)
        cin >> entrada[i];
    sort(entrada.begin(), entrada.end());
    lol suma = 0;
    if(entrada[m] < S)
    {
        for(lol i = m ; entrada[i] < S && i < tam; i++)
            suma += abs(S - entrada[i]);
        cout << suma << "\n";
    }
    else if(entrada[m] > S)
    {
        for(lol i = m ; entrada[i] > S && i >= 0 ; i--)
            suma += abs(S - entrada[i]);
        cout << suma << "\n";
    }
    else if(entrada[m] == S)
        cout << "0\n";
}
