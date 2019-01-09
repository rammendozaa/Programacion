/* Accepted */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long int boardCutting(vector<long long int> cost_y, vector<long long int> cost_x) {
    long long int horSeg = 1, verSeg = 1;
    priority_queue <long long int> equis, ye;
    long long int suma = 0;
    for(auto a : cost_x)
        equis.push(a);
    for(auto a : cost_y)
        ye.push(a);
    while(!equis.empty() && !ye.empty())
    {
        if(equis.top() > ye.top())
        {
            suma += (equis.top() * verSeg) % ((long long int)1e9 + 7);
            suma %= ((long long int)1e9 + 7);
            horSeg++;
            equis.pop();
        }
        else
        {
            suma += (ye.top() * horSeg) % ((long long int)1e9 + 7);
            suma %= ((long long int)1e9 + 7);
            verSeg++;
            ye.pop();
        }
    }
    if(!equis.empty())
    {
        while(!equis.empty())
        {
            suma += (verSeg * equis.top()) % ((long long int)1e9 + 7);
            suma %= ((long long int)1e9 + 7);
            equis.pop();
        }
    }
    else if(!ye.empty())
    {
        while(!ye.empty())
        {
            suma += (horSeg * ye.top()) % ((long long int)1e9 + 7);
            suma %= ((long long int)1e9 + 7);
            ye.pop();
        }
    }

    return suma % ((long long int)1e9 + 7);
}


int main(void)
{
    int casos;
    cin >> casos;
    while(casos--)
    {
        int tamX, tamY;
        cin >> tamY >> tamX;
        vector <long long int> ex(tamX - 1), why(tamY - 1);
        for(int i = 0 ; i < tamY - 1 ; i++)
            cin >> why[i];
        for(int i = 0 ; i < tamX - 1 ; i++)
            cin >> ex[i];
        long long int res = boardCutting(why, ex);
        cout << res << "\n";
    }
}
