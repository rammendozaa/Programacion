/* Accepted */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    vector <vector <long long int> > cuadro(6, vector<long long int> (6, 0));
    long long int maximo = -1e9, res = 0;
    for(long long int i = 0 ; i < 6 ; i++)
        for(long long int j = 0 ; j < 6 ; j++)
            cin >> cuadro[i][j];
    for(int i = 0 ; i < 4 ; i++)
        for(int j = 0 ; j < 4 ; j++)
        {
            res = cuadro[i][j] + cuadro[i][j + 1] + cuadro[i][j + 2] + cuadro[i + 1][j + 1] + cuadro[i + 2][j] + cuadro[i + 2][j + 1] + cuadro[i + 2][j + 2];
            maximo = max(maximo, res);
        }
    cout << maximo << "\n";
}
