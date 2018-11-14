#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(void)
{
    int cases;
    cin >> cases;
    cin.ignore();
    while(cases--)
    {
        string auxS;
        getline(cin, auxS);
        int izqM = 0, derM = 0, izqF = 0, derF = 0;
        for(int i = 1 ; i < auxS.length() ; i += 3)
        {
            if(auxS[i - 1] == 'M')
                izqM++;
            else if(auxS[i - 1] == 'F')
                izqF++;
            if(auxS[i] == 'M')
                derM++;
            else if(auxS[i] == 'F')
                derF++;
        }
        if((izqF == derM) && (izqM == derF) && auxS.length() > 3)
            cout << "LOOP\n";
        else
            cout << "NO LOOP\n";
    }
    return 0;
}
