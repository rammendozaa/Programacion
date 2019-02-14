/* Accepted */
#include <iostream>
using namespace std;
using lol = long long int;
int main(void)
{
    lol dias, capacidad, entrada, auxI, carry = 0, bolsas = 0, resB, dayBefore, currentDay, total;
    cin >> dias >> capacidad;
    if(dias == 1)
    {
        cin >> entrada;
        if(entrada <= capacidad && entrada > 0)
            cout << "1\n";
        else if(entrada == 0)
            cout << "0\n";
        else
        {
            if(entrada % capacidad == 0)
                cout << entrada / capacidad << "\n";
            else
                cout << (entrada / capacidad) + 1 << "\n";
        }
    }
    else
    {
        for(int i = 0 ; i < dias ; i++)
        {
            cin >> entrada;
            total = entrada + resB;
            bolsas += total / capacidad;
            resB = total % capacidad;
            if(total / capacidad == 0 && dayBefore == 1)
            {
                bolsas++;
                resB = 0;
            }
            if(resB > 0)
                dayBefore = 1;
            else
                dayBefore = 0;
        }
        if(resB > 0)
            bolsas++;
        //bolsas += carry;
        cout << bolsas << "\n";
    }
}
