#include <iostream>

using namespace std;
int main(void)
{
    int casos, farmers, auxI, area, animals, degree, res;
    cin >> casos;
    while(casos--)
    {
        cin >> farmers;
        res = 0;
        while(farmers--)
        {
            cin >> area >> animals >> degree;
            res += area * degree;
        }
        cout << res << "\n";
    }
    return 0;
}
