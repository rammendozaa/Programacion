#include <iostream>
#include <string>
using namespace std;

int sumaDigitos(int digito)
{
    int suma = 0;
    while(digito > 0)
    {
        suma += digito % 10;
        digito /= 10;
    }
    return suma;
}

int main(void)
{
    int A, N, B, minSuma = 1e9;
    cin >> N;
    for(int i = 0 ; i <= N / 2 ; i++)
    {
        A = sumaDigitos(i);
        B = sumaDigitos(N - i);
        minSuma = min(minSuma, A + B);
    }
    cout << minSuma << "\n";
}
