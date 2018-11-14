#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string auxS;
    int casos = 0;
    while(cin >> auxS && auxS != "*")
    {
        if(auxS == "Umrah")
            cout << "Case " << ++casos << ": Hajj-e-Asghar\n";
        else
            cout << "Case " << ++casos << ": Hajj-e-Akbar\n";
    }
    return 0;
}
