#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void)
{

    int cases;
    double n1, n2, res;
    cin >> cases;
    while(cases--)
    {
        cin >> n1 >> n2;
        n1 -= 2;
        n2 -= 2;
        res = ceil(n1 / 3) * ceil(n2 / 3);
        cout << fixed << setprecision(0) << res << "\n";
    }
    return 0;
}
