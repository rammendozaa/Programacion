#include <iostream>
using namespace std;
int main(void)
{
    int cases, auxI, caso = 0;
    bool si;
    cin >> cases;
    while(cases--)
    {
        si = true;
        for(int i = 0 ; i < 3 ; i++)
        {
            cin >> auxI;
            if(auxI > 20)
                si = false;
        }
        if(si)
            cout << "Case " << ++caso << ": good\n";
        else
            cout << "Case " << ++caso << ": bad\n";
    }
    return 0;
}
