/* Accepted */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Wavelet{
    int low, high;
    vector <int> mapLeft;
    Wavelet *left, *right;
    Wavelet(vector<int>::iterator from, vector<int>::iterator to, int low, int high)
    {
        this -> low = low;
        this -> high = high;
        if(from >= to)
            return;
        int mid = (low + high) >> 1;
        auto checar = [mid](int entrada){
            return mid >= entrada;
        };
        mapLeft.reserve(to - from + 1);
        mapLeft.push_back(0);
        for(auto it = from ; it != to ; ++it)
            mapLeft.push_back(mapLeft.back() + checar(*it));
        if(high != low)
        {
            auto partir = stable_partition(from, to, checar);
            left = new Wavelet(from, partir, low, mid);
            right = new Wavelet(partir, to, mid + 1, high);
        }
    }

    int kthN(int izq, int der, int k)
    {
        if(izq > der)
            return -1;
        if(low == high)
            return low;
        int alaIzq, alaDer, seVanIzq;
        alaIzq = mapLeft[izq - 1];
        alaDer = mapLeft[der];
        seVanIzq = alaDer - alaIzq;
        if(k > seVanIzq)
            right -> kthN(izq - alaIzq, der - alaDer , k - seVanIzq);
        else
            left -> kthN(alaIzq + 1, alaDer, k);
    }

    int cuantosMenorIgual(int izq, int der, int valor)
    {
        if(valor < low || izq > der)
            return 0;
        if(valor >= high)
            return (der - izq + 1);
        int alaIzq, alaDer, seVanIzq;
        alaIzq = mapLeft[izq - 1];
        alaDer = mapLeft[der];
        seVanIzq = alaDer - alaIzq;
        return (left -> cuantosMenorIgual(alaIzq + 1, alaDer, valor) +
            right -> cuantosMenorIgual(izq - alaIzq, der - alaDer, valor));
    }

    int cuantosMayorIgual(int izq, int der, int valor){
        if(valor < low || izq > der)
            return (der - izq + 1);
        if(valor >= high)
            return 0;
        int alaIzq, alaDer, seVanIzq;
        alaIzq = mapLeft[izq - 1];
        alaDer = mapLeft[der];
        seVanIzq = alaDer - alaIzq;
        return (left -> cuantosMayorIgual(alaIzq + 1, alaDer, valor) +
            right -> cuantosMayorIgual(izq - alaIzq, der - alaDer, valor));
    }

};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numeros, casos;
    cin >> numeros >> casos;
    int minimo = 1e9, maximo = -1e9;
    vector <int> valores(numeros), auxV(numeros);
    for(int i = 0 ; i < numeros ; ++i)
    {
        cin >> valores[i];
        auxV[i] = valores[i];
        minimo = min(minimo, auxV[i]);
        maximo = max(maximo, auxV[i]);
    }
    Wavelet arbol(valores.begin(), valores.end(), minimo, maximo);
    for(int i = 0 ; i < casos ; i++)
    {
        int izquierda, derecha, ka;
        cin >> izquierda >> derecha >> ka;
        cout << arbol.kthN(izquierda, derecha, ka) << "\n";
    }
}
