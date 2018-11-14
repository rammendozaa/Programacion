#include <iostream>
using namespace std;
int main(void)
{
    int auxI, casos = 0, entrada, contador;
    while(cin >> auxI && auxI != 0)
    {
        contador = 0;
        for(int i = 0 ; i < auxI ; i++)
        {
            cin >> entrada;
            if(entrada == 0)
                contador--;
            else
                contador++;
        }
        cout << "Case " << ++casos << ": "<< contador << "\n";
    }

    return 0;
}
