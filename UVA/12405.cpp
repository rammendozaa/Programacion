/* Scarecrow */
/* Not Accepted */
#include <iostream>
using namespace std;

int main(void)
{
    int cases, casosCont = 0;
    cin >> cases;
    while(cases--)
    {
        int tamanoC, puntosConsec = 0, hashConsec = 0, puntosTotal = 0, espantaPaj = 0;
        char posicion;
        cin >> tamanoC;
        for(int i = 0 ; i < tamanoC ; i++)
        {
            cin >> posicion;
            if(posicion == '.')
            {
                puntosConsec++;
                if(puntosConsec == 3)
                {
                    puntosConsec = 0;
                    espantaPaj++;
                }
                puntosTotal++;
                hashConsec = 0;
            }
            if(posicion == '#')
            {
                hashConsec++;
                puntosConsec = 0;
            }
            if(puntosConsec == 3 && hashConsec == 0)
            {
                espantaPaj++;
                puntosConsec = 0;
            }
        }
        cout << "Case " << ++casosCont << ": " << res << "\n";
    }
}
