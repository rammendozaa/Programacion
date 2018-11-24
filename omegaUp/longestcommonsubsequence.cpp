/*

Mendoza Ramírez Álvaro (rammendozaa)
Solución para problema Longest Common Subsequence

M. en C. Franco Martinez Edgardo Adrián
Análisis de Algoritmos
Grupo 3CM3

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string cadenaA, cadenaB;

/*
Función que recibe la primera cadena y la segunda cadena a las que se les quiere
sacar el tamaño de la subsecuencia común más larga.
Devuleve la longitud mayor de esta subsecuencia.
*/

int lcs(string A, string B, int tamA, int tamB)
{
    /*
    Se declara el arreglo con el que se va a realizar la DP en donde se va a ir
    guardando la longitud de la subsecuencia más larga hasta el momento
    */
    vector <vector<int> > DP(tamA + 1, vector <int>(tamB + 1, -1));
    long long int resultado;
    for(int i = 0 ; i <= tamA ; i++)
    {
        for(int j = 0 ; j <= tamB ; j++)
        {
            /*
            Se ejecuta el algoritmo checando los valores de la tabla de longitudes
            con un caso base donde el valor de la longitud más larga es 0
            */
            if(i == 0 || j == 0)
                DP[i][j] = 0;
            else if(A[i - 1] == B[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }
    return DP[tamA][tamB];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int res;
    cin >> cadenaA >> cadenaB;
    res = lcs(cadenaA, cadenaB, cadenaA.length(), cadenaB.length());
    cout << res << "\n";

    return 0;
}
