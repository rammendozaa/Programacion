#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    int cases;
    string auxS;
    cin >> cases;
    while(cases--)
    {
        cin >> auxS;
        if(auxS == "1" || auxS == "4" || auxS == "78")
            cout << "+\n";
        else if(auxS[auxS.length() - 1] == '5' && auxS[auxS.length() - 2] == '3')
            cout << "-\n";
        else if(auxS[0] == '9' && auxS[auxS.length() - 1] == '4')
            cout << "*\n";
        else
            cout << "?\n";
    }
    return 0;
}
