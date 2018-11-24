/* A Crear Un Humuncuo */
/* Accepted */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> materiales;

void binaria(int buscado)
{
    int ini = 0, fin = materiales.size();
    while(ini <= fin)
    {
        int mid = (ini + fin) / 2;
        if(materiales[mid] == buscado)
        {
            cout << "SI\n";
            return;
        }
        else if(materiales[mid] < buscado)
            ini = mid + 1;
        else
            fin = mid - 1;
    }
    cout << "NO\n";
    return;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int valores, busqueda, auxI;
    cin >> valores;
    for(int i = 0 ; i < valores ; i++)
    {
        cin >> auxI;
        materiales.push_back(auxI);
    }
    sort(materiales.begin(), materiales.end());
    cin >> busqueda;
    for(int i = 0 ; i < busqueda ; i++)
    {
        cin >> auxI;
        binaria(auxI);
    }
    return 0;
}
