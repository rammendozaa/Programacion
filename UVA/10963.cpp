#include <iostream>
#include <set>
using namespace std;
int main(void)
{
    int cases, auxI1, auxI2, lines;
    cin >> cases;
    while(cases--)
    {
        cin >> lines;
        set <int> gaps;
        while(lines--)
        {
            cin >> auxI1 >> auxI2;
            gaps.insert(auxI1 - auxI2);
        }
        if(gaps.size() == 1)
            cout << "yes\n";
        else
            cout << "no\n";
        if(cases >= 1)
            cout << "\n";
    }
    return 0;
}
