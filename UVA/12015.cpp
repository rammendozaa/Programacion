#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
int main(void)
{
    int cases, auxI, casos = 0;
    string entrada;
    cin >> cases;
    while(cases--)
    {
        int maxI = -1;
        queue <pair<int, string> > paginas;
        for(int i = 0 ; i < 10 ; i++)
        {
            cin >> entrada >> auxI;
            maxI = max(auxI, maxI);
            paginas.push(make_pair(auxI, entrada));
        }
        cout << "Case #" << ++casos << ":\n";// << arriba << "\n";
        while(!paginas.empty())
        {
            if((paginas.front()).first == maxI)
                cout << (paginas.front()).second << "\n";
            paginas.pop();
        }
    }

    return 0;
}
