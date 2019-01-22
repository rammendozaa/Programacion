/* Accepted */
#include <algorithm>
#include <iostream>
#include <vector>
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
        int tamU, tamD;
        cin >> tamU >> tamD;
        vector <int> uno(tamU), dos(tamD), tres;
        vector <int> :: iterator it;
        for(int i = 0 ; i < tamU ; i++)
            cin >> uno[i];
        for(int i = 0 ; i < tamD ; i++)
            cin >> dos[i];
        sort(uno.begin(), uno.end());
        sort(dos.begin(), dos.end());
        set_intersection(uno.begin(), uno.end(), dos.begin(), dos.end(), back_inserter(tres));
        cout << ((uno.size() - tres.size()) + (dos.size() - tres.size())) << "\n";
    }

}
