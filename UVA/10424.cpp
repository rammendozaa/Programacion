#include <iostream>
#include <string>
#include <locale>
#include <iomanip>
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
    string n1, n2;
    while(getline(cin, n1))
    {
        getline(cin, n2);
        locale loc;
        int suma1 = 0, suma2 = 0;
        double ratio;
        string low1 = "", low2 = "";
        for(auto a : n1)
            low1 += tolower(a, loc);
        for(auto a : n2)
            low2 += tolower(a, loc);
        for(auto a : low1)
            if((int)a <= 122 && (int)a >= 97)
                suma1 += (int)a - 96;
        for(auto a : low2)
            if((int)a <= 122 && (int)a >= 97)
                suma2 += (int)a - 96;
        string s1, s2;
        int uno, dos;
        s1 = calcularSuma(to_string(suma1));
        s2 = calcularSuma(to_string(suma2));
        while(s1.length() > 1)
            s1 = calcularSuma(s1);
        while(s2.length() > 1)
            s2 = calcularSuma(s2);
        uno = s1[0] - '0';
        dos = s2[0] - '0';
        ratio = (uno < dos) ? (double)uno / (double)dos : (double)dos / (double)uno;
        cout << fixed << setprecision(2) << ratio * 100 << " %\n";
    }
    return 0;
}
