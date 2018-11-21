/* Knapsack Problem */
/* Accepted */
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int maxValor(vector <pair<int, int> > objetos, int capacidad)
{
    vector <vector<int> > DP(objetos.size() + 1, vector <int> (capacidad + 1,-1));
    for(int i = 0 ; i <= objetos.size() ; i++)
    {
        for(int j = 0 ; j <= capacidad ; j++)
        {
            if(j == 0 || i == 0)
                DP[i][j] = 0;
            else if(objetos[i - 1].first <= j)
            /*
            Maximo entre:
                Valor del objeto anterior mas DP para el peso actual y el valor
                de la DP en el objeto anterior
            */
                DP[i][j] = max(objetos[i - 1].second + DP[i - 1][j - objetos[i - 1].first],
                    DP[i - 1][j]);
            else
                DP[i][j] = DP[i - 1][j];
        }
    }
    return DP[objetos.size()][capacidad];
}

int main(void)
{
    int capacidad, objetos, auxValor, auxPeso;
    cin >> capacidad >> objetos;
    //.first -> auxPeso
    //.second -> auxValor
    vector <pair<int, int> > cosas;
    for(int i = 0 ; i < objetos ; i++)
    {
        cin >> auxPeso >> auxValor;
        cosas.push_back(make_pair(auxPeso, auxValor));
    }
    sort(cosas.begin(), cosas.end());
    cout << maxValor(cosas, capacidad) << "\n";
}
