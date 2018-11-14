#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int minDis(vector <int> drugs, vector <int> rest)
{
    int minD = 10000000;
    for(auto a : drugs)
    {
        for(auto b : rest)
        {
            if(abs(a - b) == 1)
                return 1;
            else
                minD = min(abs(a - b), minD);
        }
    }
    return minD;
}

int main(void)
{
    int length;
    while(cin >> length && length != 0)
    {
        string auxS;
        cin >> auxS;
        bool zeta = false;
        vector <int> res, drug;
        for(int i = 0 ; i < auxS.length() ; i++)
        {
            if(auxS[i] == 'Z')
            {
                cout << "0" << "\n";
                zeta = true;
                break;
            }
            else if(auxS[i] == 'D')
                drug.push_back(i);
            else if(auxS[i] == 'R')
                res.push_back(i);
        }
        if(!zeta)
            cout << minDis(drug, res) << "\n";
    }
    return 0;
}
