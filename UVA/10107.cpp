/* Accepted */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector <int> entrada;
    int auxI;
    cin >> auxI;
    entrada.push_back(auxI);
    cout << auxI << "\n";
    while(cin >> auxI)
    {
        entrada.push_back(auxI);
        sort(entrada.begin(), entrada.end());
        if(entrada.size() % 2 != 0)
            cout << entrada[entrada.size() / 2] << "\n";
        else
            cout << (entrada[entrada.size() / 2] + entrada[(entrada.size() / 2) - 1]) / 2 << "\n";
    }
}
