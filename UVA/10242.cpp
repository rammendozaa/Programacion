/* Accepted */

#include <iostream>
#include <iomanip>
using namespace std;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double unoX, unoY, dosX, dosY, tresX, tresY, cuatroX, cuatroY;
    while(cin >> unoX >> unoY >> dosX >> dosY >> tresX >> tresY >> cuatroX >> cuatroY)
    {
        cout << fixed << setprecision(3);
        if(unoX == dosX && unoY == dosY)
            cout << (tresX + cuatroX) - unoX << " " << (tresY + cuatroY) - unoY << "\n";
        else if(unoX == tresX && unoY == tresY)
            cout << (dosX + cuatroX) - unoX << " " << (dosY + cuatroY) - unoY << "\n";
        else if(unoX == cuatroX && unoY == cuatroY)
            cout << (tresX + dosX) - unoX << " " << (tresY + dosY) - unoY << "\n";
        else if(dosX == tresX && dosY == tresY)
            cout << (unoX + cuatroX) - dosX << " " << (unoY + cuatroY) - dosY << "\n";
        else if(dosX == cuatroX && dosY == cuatroY)
            cout << (tresX + unoX) - dosX << " " << (tresY + unoY) - dosY << "\n";
        else if(tresX == cuatroX && tresY == cuatroY)
            cout << (unoX + dosX) - tresX << " " << (unoY + dosY) - tresY << "\n";
    }
    return 0;
}
