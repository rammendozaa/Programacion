#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool iguales(string s, int ini, int fin)
{
    char aux = s[ini];
    for(int i = ini + 1 ; i <= fin ; i++)
        if(s[i] != aux)
            return false;
    return true;
}

int main(void)
{
    string entrada;
    int casos = 0;
    while(cin >> entrada && entrada != "\n")
    {
        int cases, pr, fi, in, out;
        cin >> cases;
        cout << "Case " << ++casos << ":\n";
        for(int i = 0 ; i < cases ; i++)
        {
            cin >> pr >> fi;
            in = (pr < fi) ? pr : fi;
            out = (pr < fi) ? fi : pr;
            if(iguales(entrada, in, out))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}
