#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string numero;
    while(getline(cin, numero) && numero != "END")
    {
        int it = 1;
        while(numero[0] != '1' || numero.length() != 1)
        {
            numero = to_string(numero.length());
            it++;
        }
        cout << it << "\n";
    }
    return 0;
}
