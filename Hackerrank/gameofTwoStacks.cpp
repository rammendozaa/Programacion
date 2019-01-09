/* Accepted */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include "stack.h"
using namespace std;

long long int twoStacks(long long int x, vector <long long int> one, vector <long long int> two)
{
    Stack<long long int> *uno = new Stack<long long int> ();
    Stack<long long int> *dos = new Stack<long long int> ();
    long long int total = 0, sumRemoved = 0, posT = 0, posU = 0, maximo = 0;

    for(auto a : one)
    {
        if(total + a > x)
            break;
        total += a;
        posU++;
        uno -> push(a);
    }
    sumRemoved = posU;
    for(auto a : two)
    {
        if(posU < 0)
            break;
        total += a;
        posT++;
        while(posU > 0 && total > x)
        {
            posU--;
            total -= uno -> top();
            uno -> pop();
        }
        if(total <= x && (posT + posU) > sumRemoved)
            sumRemoved = posT + posU;
    }

    return sumRemoved;
}

int main(void)
{
    long long int cases;
    cin >> cases;
    while(cases--)
    {
        long long int tam1, tam2, equis, auxI;
        cin >> tam1 >> tam2 >> equis;
        vector <long long int> uno, dos;
        for(long long int i = 0 ; i < tam1 ; i++)
        {
            cin >> auxI;
            uno.push_back(auxI);
        }
        for(long long int i = 0 ; i < tam2 ; i++)
        {
            cin >> auxI;
            dos.push_back(auxI);
        }
        long long int result = twoStacks(equis, uno, dos);
        cout << result << "\n";
    }
}
