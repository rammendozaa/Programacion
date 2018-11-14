#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    int cases, aux, stores;
    cin >> cases;
    while(cases--)
    {
        cin >> stores;
        vector <int> visit;
        for(int i = 0 ; i < stores ; i++)
        {
            cin >> aux;
            visit.push_back(aux);
        }
        int nMin = 10000000, nMax = -10000000;
        for(auto a : visit)
        {
            nMin = min(nMin, a);
            nMax = max(nMax, a);
        }
        cout << (2 * (nMax - nMin)) << "\n";
    }


    return 0;
}
