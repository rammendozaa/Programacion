/* Accepted */
/* Evolution from 10815 */
#include <iostream>
#include <set>
#include <string>
using namespace std;
//32 space
//45 hyphen
set <string> cadenas;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string auxS, another = "";
    bool hyphen = false;
    char auxC;
    while(getline(cin, auxS))
    {
        for(int i = 0 ; i < auxS.length() ; i++)
        {
            if(i == auxS.length() - 1 && auxS[i] == '-')
            {
                int c = cin.peek();
                if(c != EOF)
                {
                    hyphen = true;
                    break;
                }
                else
                {
                    another += auxS[i];
                    cadenas.insert(another);
                    another = "";
                }
            }
            else
            {
                hyphen = false;
                auxC = tolower(auxS[i]);
                if(auxS[i] != '-' && (auxC < 97 || auxC > 122))
                {
                    cadenas.insert(another);
                    another = "";
                }
                else
                {
                    another += tolower(auxS[i]);
                }
                //cout << another << "\n";
            }
        }
        if(!hyphen)
        {
            cadenas.insert(another);
            another = "";
        }
    }

    set<string>::iterator it = cadenas.begin();
    if((*it).length() == 0)
        it++;
    while(it != cadenas.end())
    {
        cout << *it << "\n";
        it++;
    }
}
