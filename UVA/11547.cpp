#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void)
{
    double cases, numero;
    cin >> cases;
    while(cases--)
    {
        cin >> numero;
        int res = abs((int)floor(((floor((numero * 567) / 9) + 7492) * 235) / 47) - 498) / 10;
        cout << res % 10 << "\n";
    }
    return 0;
}
