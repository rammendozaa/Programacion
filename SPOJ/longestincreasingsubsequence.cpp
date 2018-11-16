/* Easy Longest Increasing Subsequence */
/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int maximoN(vector <int> DP, int tam)
{
    int maximo = -1e9;
    for(int i = 0 ; i < tam ; i++)
        maximo = max(DP[i], maximo);
    return maximo;
}

int lis(vector <int> numeros, int tam)
{
    vector <int> DP(tam + 1);
    DP[0] = 1;
    for(int i = 1 ; i <= tam ; i++)
    {
        DP[i] = 1;
        for(int j = 0 ; j < i ; j++)
            if(numeros[i] > numeros[j] && DP[i] < DP[j] + 1)
                DP[i] = DP[j] + 1;
    }
    return maximoN(DP, tam);
}

int main(void)
{
    ios::sync_with_stdio(false);
    int num, auxI;
    cin >> num;
    vector <int> numeros;
    for(int i = 0 ; i < num ; i++)
    {
        cin >> auxI;
        numeros.push_back(auxI);
    }
    cout << lis(numeros, num) << "\n";
}
