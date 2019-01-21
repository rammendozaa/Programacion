/* Accepted */
#include <iostream>
#include <set>

using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int cuantos;
    while(cin >> cuantos && cuantos != 0)
    {
        multiset <long long int> tickets;
        multiset <long long int> :: iterator mayor, menor;
        long long int auxI, auxEn, suma = 0;
        for(long long int i = 0 ; i < cuantos ; i++)
        {
            cin >> auxI;
            for(long long int j = 0 ; j < auxI ; j++)
            {
                cin >> auxEn;
                tickets.insert(auxEn);
            }
            menor = tickets.begin();
            mayor = tickets.end();
            mayor--;
            suma += (*mayor) - (*menor);
            tickets.erase(menor);
            tickets.erase(mayor);
        }
        cout << suma << "\n";
    }

}
