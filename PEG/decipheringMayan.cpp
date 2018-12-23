/* Accepted */
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    int tamC, tamL;
    string peque, grande;
    cin >> tamC >> tamL;
    cin >> peque >> grande;
    map <char, int> letras, barrido;
    vector <int> original;
    for(char a = 'a' ; a <= 'z' ; a++)
        letras[a] = barrido[a] = 0;
    for(char a = 'A' ; a <= 'Z' ; a++)
        letras[a] = barrido[a] = 0;
    int contador = 0;
    for(auto a : peque)
        letras[a] += 1;
    for(int i = 0 ; i < peque.length() ; i++)
        barrido[grande[i]] += 1;
    if(barrido == letras)
        contador++;
    for(int i = peque.length() ; i < grande.length() ; i++)
    {
        barrido[grande[i]] += 1;
        barrido[grande[i - peque.length()]] -= 1;
        if(barrido == letras)
            contador++;
    }
    cout << contador << "\n";
    }
