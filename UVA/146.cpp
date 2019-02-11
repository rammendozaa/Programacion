/* Accepted */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string entrada, next;
    while(cin >> entrada && entrada != "#")
    {
        char input[entrada.length()], perm[entrada.length()];
        int i = 0;
        for(auto a : entrada)
        {
            input[i] = a;
            perm[i] = a;
            i++;
        }
        next_permutation(perm, perm + entrada.length());
        if(lexicographical_compare(input, input + entrada.length(), perm, perm + entrada.length()))
        {
            for(auto a : perm)
                cout << a;
            cout << "\n";
        }
        else
            cout << "No Successor\n";
    }
}
