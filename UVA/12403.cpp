#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    int lineas, auxI, moneyC = 0;
    string auxS;
    cin >> lineas;
    while(lineas--)
    {
            cin >> auxS;
            if(auxS == "donate")
            {
                cin >> auxI;
                moneyC += auxI;
            }
            else
                cout << moneyC << "\n";
    }


    return 0;
}
