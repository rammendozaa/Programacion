/* Accepted */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cases;
    cin >> cases;
    while(cases--)
    {
        int add, get, auxAdd, auxGet, ini = 0, iter = 1;
        cin >> add >> get;
        vector <int> entradas(add), instru(get);
        multiset <int> valores;
        multiset<int>::iterator it;
        for(int i = 0 ; i < add ; i++)
            cin >> entradas[i];
        valores.insert(entradas[0]);
        it = valores.begin();
        for(int i = 0 ; i < get ; i++)
        {
            cin >> instru[i];
            for( ; iter < instru[i] ; iter++)
            {
                valores.insert(entradas[iter]);
                if(entradas[iter] < *it)
                    it--;
            }
            if(i > 0)
                it++;
            cout << *it << "\n";
        }
        if(cases > 0)
            cout << "\n";
    }
}
