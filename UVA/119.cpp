#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main(void)
{
    int persons, people;
    bool bandera = true;
    cin >> persons;
    while(bandera)
    {
            people = persons;
            int auxI, dinero, rounding;
            string auxS, personas;
            map <string, int> moneyS;
            vector <string> llegadas;
            for(int i = 0 ; i < people ; i++)
            {
                cin >> auxS;
                llegadas.push_back(auxS);
            }
            for(int i = 0 ; i < people ; i++)
            {
                cin >> personas >> dinero >> auxI;
                rounding = (dinero == 0 || auxI == 0) ? 0 : dinero / auxI;
                moneyS[personas] -= (auxI * rounding);
                for(int j = 0 ; j < auxI ; j++)
                {
                    cin >> auxS;
                    moneyS[auxS] += rounding;
                }
            }
            for(auto a : llegadas)
                cout << a << " " << moneyS[a] << "\n";
            if(cin >> persons)
            {
                people = persons;
                cout << "\n";
            }
            else
                bandera = false;
    }
    return 0;
}
