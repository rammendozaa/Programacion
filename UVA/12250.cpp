/*
HELLO
HOLA
HALLO
BONJOUR
CIAO
ZDRAVSTVUJTE

Case 1: ENGLISH
Case 2: SPANISH
Case 3: GERMAN
Case 4: FRENCH
Case 5: ITALIAN
Case 6: RUSSIAN

*/
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string aux;
    int caso = 0;
    while(cin >> aux && aux != "#")
    {
        if(aux == "HELLO")
            cout << "Case " << ++caso <<": ENGLISH\n";
        else if(aux == "HOLA")
            cout << "Case " << ++caso <<": SPANISH\n";
        else if(aux == "BONJOUR")
            cout << "Case " << ++caso <<": FRENCH\n";
        else if(aux == "CIAO")
            cout << "Case " << ++caso <<": ITALIAN\n";
        else if(aux == "HALLO")
            cout << "Case " << ++caso <<": GERMAN\n";
        else if(aux == "ZDRAVSTVUJTE")
            cout << "Case " << ++caso <<": RUSSIAN\n";
        else
            cout << "Case " << ++caso <<": UNKNOWN\n";
    }
    return 0;
}
