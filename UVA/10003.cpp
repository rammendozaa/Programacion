/* Not Accepted */
#include <iostream>
#include <vector>
using namespace std;

int longitud, cortes;

int minPrecio(vector <int> bloques, vector <vector<int> > DP, int ini, int fin)
{
    if(ini >= fin)
        return 0;
    if(DP[ini][fin] != -1)
        return DP[ini][fin];
    else
    {
        DP[ini][fin] = 1e9;
        for(int i = 0 ; i < cortes ; i++)
        {
            DP[ini][fin] = min(DP[ini][fin], (fin - ini + min(minPrecio(bloques, DP, ini, bloques[i]), minPrecio(bloques, DP, bloques[i], fin))));
        }
    }
    return DP[ini][fin];
}

int main(void)
{
    ios::sync_with_stdio(false);
    int auxI;
    while(cin >> longitud && longitud != 0)
    {
        vector <int> pedazos;
        cin >> cortes;
        vector <vector <int> > DP(longitud + 1, vector <int>(longitud + 1, -1));
        for(int i = 0 ; i < cortes ; i++)
        {
            cin >> auxI;
            pedazos.push_back(auxI);
        }
        int res = minPrecio(pedazos, DP, 0, longitud);
        cout << "The minimum cutting is " << res << ".\n";

    }

}
