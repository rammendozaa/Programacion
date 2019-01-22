/* Accepted */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int entrada;
    unordered_map <long long int, long long int> numeros;
    unordered_map <long long int, bool> ya;
    vector <long long int> input;
    while(cin >> entrada)
    {
        input.push_back(entrada);
        ya[entrada] = false;
        numeros[entrada]++;
    }
    for(auto a : input)
    {
        if(!(ya[a]))
        {
            cout << a << " " << numeros[a] << "\n";
            ya[a] = true;
        }
    }
}
