#include <iostream>

using namespace std;

int main(void)
{
    int cases, auxI, walls, caso = 0;
    cin >> cases;
    while(cases--)
    {
        cin >> walls;
        int high = 0, low = 0, last;
        cin >> last;
        for(int i = 0 ; i < walls - 1 ; i++)
        {
            cin >> auxI;
            if(auxI > last)
                high++;
            else if(auxI < last)
                low++;
            last = auxI;
        }
        cout << "Case " << ++caso << ": " << high << " " << low << "\n";
    }
    return 0;
}
