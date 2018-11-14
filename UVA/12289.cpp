#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    int cases;
    string numero;
    cin >> cases;
    while(cases--)
    {
        cin >> numero;
        if(numero.length() == 5)
            cout << "3\n";
        else if((numero[0] == 'o' && numero[1] == 'n') || (numero[0] == 'o' && numero[2] == 'e') || (numero[1] == 'n' && numero[2] == 'e'))
            cout << "1\n";
        else
            cout << "2\n";
    }


    return 0;
}
