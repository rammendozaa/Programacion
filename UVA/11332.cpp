#include <iostream>
#include <string>
using namespace std;

string calcularSuma(string ent)
{
    string salida = "";
    int suma = 0;
    for(auto a : ent)
        suma += a - '0';
    return to_string(suma);
}

int main(void)
{
    string entrada;
    while(cin >> entrada && entrada != "0")
    {
        string sal = calcularSuma(entrada);
        while(sal.length() > 1)
            sal = calcularSuma(sal);
        cout << sal << "\n";
    }

    return 0;
}
