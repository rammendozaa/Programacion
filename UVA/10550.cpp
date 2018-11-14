#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
    int ini, first, second, third;
    while(cin >> ini >> first >> second >> third && (ini != 0 || first != 0 || second != 0 | third != 0))
    {
        ini = (ini == 0) ? 40 : ini;
        first = (first == 0) ? 40 : first;
        second = (second == 0) ? 40 : second;
        third = (third == 0) ? 40 : third;
        int suma = 360 * 3;
        if(ini < first)
            suma += (ini + (40 - first)) * 9;
        else
            suma += (ini - first) * 9;
        if(second < first)
            suma += (second + (40 - first)) * 9;
        else
            suma += (second - first) * 9;
        if(third > second)
            suma += (second + (40 - third)) * 9;
        else
            suma += (second - third) * 9;
        cout << suma << "\n";
    }
    return 0;
}
