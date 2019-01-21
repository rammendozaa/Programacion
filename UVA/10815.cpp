/* Accepted */
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string auxS, another;
    char auxC;
    set <string> cadenas;
    while(cin >> auxS)
    {
        another = "";
        for(auto a : auxS)
        {
            auxC = tolower(a);
            if(auxC < 97 || auxC > 122)
            {
                cadenas.insert(another);
                another = "";
            }
            else
                another += tolower(a);
        }
        cadenas.insert(another);
    }
    set<string>::iterator it = cadenas.begin();
    it++;
    while(it != cadenas.end())
    {
        cout << *it << "\n";
        it++;
    }
}
