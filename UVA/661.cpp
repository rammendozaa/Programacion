#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
    int n, m, c, seq = 0;
    bool bandera = true;
    cin >> n >> m >> c;
    if(n != 0 && m != 0 && c != 0)
        bandera = true;
    else
        bandera = false;
    while(bandera)
    {
        bool blew = false;
        int actual = 0, maxA = -10000, auxI;
        vector <int> apar(n);
        vector <int> onoff(n, 0);
        for(int i = 0 ; i < n ; i++)
        {
            cin >> auxI;
            apar[i] = auxI;
        }
        for(int i = 0 ; i < m ; i++)
        {
            cin >> auxI;
            if(onoff[auxI - 1] == 0)
            {
                actual += apar[auxI - 1];
                onoff[auxI - 1] = 1;
                maxA = max(actual, maxA);
            }
            else
            {
                actual -= apar[auxI - 1];
                onoff[auxI - 1] = 0;
                maxA = max(actual, maxA);
            }
            if(actual > c)
            {
                blew = true;
            }
        }
        if(blew)
            cout << "Sequence " << ++seq << "\n" << "Fuse was blown.\n";
        else
            cout << "Sequence " << ++seq << "\n" << "Fuse was not blown.\nMaximal power consumption was " << maxA << " amperes.\n";
        if((cin >> n >> m >> c) && (n != 0 && m != 0 && c != 0))
            cout << "\n";
        else
        {
            cout << "\n";
            bandera = false;
        }
    }
    return 0;
}
