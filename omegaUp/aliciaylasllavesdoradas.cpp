/* Alicia y las llaves doradas */
/* Accepted */
#include <iostream>
#include <vector>
using namespace std;
vector <int> llaves, puertas, resultados;

int binaria(int ini, int fin, int buscado)
{
    int mid;
    while(ini <= fin)
    {
        mid = (ini + fin) / 2;
        if(puertas[mid] == buscado)
            return mid + 1;
        else if(puertas[mid] < buscado)
            ini = mid + 1;
        else
            fin = mid - 1;
    }
    return 0;
}


int main(void)
{
    int cPuertas, cLlaves;
    int auxI;
    cin >> cPuertas;
    for(int i = 0 ; i < cPuertas ; i++)
    {
        cin >> auxI;
        puertas.push_back(auxI);
    }
    cin >> cLlaves;
    for(int i = 0 ; i < cLlaves ; i++)
    {
        cin >> auxI;
        llaves.push_back(auxI);
    }
    for(int i = 0 ; i < llaves.size() ; i++)
        resultados.push_back(binaria(0, puertas.size(), llaves[i]));
    for(auto a : resultados)
        cout << a << " ";
    cout << "\n";

}
