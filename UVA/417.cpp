/* Accepted */
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
    map <string, int> palabras;
    string auxS = "";
    char auxC;
    int i = 0;
    for(char a = 'a' ; a <= 'z' ; a++)
    {
        i++;
        auxS = a;
        palabras[auxS] = i;
    }
    for(char a = 'a' ; a <= 'y' ; a++)
    {
        for(char b = a + 1 ; b <= 'z' ; b++)
        {
            i++;
            //cout << a << " " << b << "\n";
            auxS = string() + a + b;
            palabras[auxS] = i;
        }
    }
    for(char a = 'a' ; a <= 'x' ; a++)
    {
        for(char b = a + 1 ; b <= 'y' ; b++)
        {
            for(char c = b + 1 ; c <= 'z' ; c++)
            {
                i++;
                auxS = string() + a + b + c;
                palabras[auxS] = i;
            }
        }
    }
    for(char a = 'a' ; a <= 'w' ; a++)
    {
        for(char b = a + 1 ; b <= 'x' ; b++)
        {
            for(char c = b + 1 ; c <= 'y' ; c++)
            {
                for(char d = c + 1 ; d <= 'z' ; d++)
                {
                    i++;
                    auxS = string() + a + b + c + d;
                    palabras[auxS] = i;
                }
            }
        }
    }

    for(char a = 'a' ; a <= 'v' ; a++)
    {
        for(char b = a + 1 ; b <= 'w' ; b++)
        {
            for(char c = b + 1 ; c <= 'x' ; c++)
            {
                for(char d = c + 1 ; d <= 'y' ; d++)
                {
                    for(char e = d + 1 ; e <= 'z' ; e++)
                    {
                        i++;
                        auxS = string() + a + b + c + d + e;
                        palabras[auxS] = i;
                    }
                }
            }
        }
    }
    string entrada;
    while(cin >> entrada)
        cout << palabras[entrada] << "\n";

}
