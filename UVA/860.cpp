/* Accepted */
#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string auxS, another;
    char auxC;
    vector <string> cadenas;
    while(cin >> auxS && auxS != "****END_OF_INPUT****")
    {
        if(auxS != "****END_OF_TEXT****")
        {
            another = "";
            for(auto a : auxS)
            {
                auxC = tolower(a);
                if((auxC >= 97 && auxC <= 122) || (a != ',' && a != '.' && a != ';' && a != ':' && a != '!' && a != '?' && a != '"' && a != '(' && a != ')'))
                    another += tolower(a);
                else
                {
                    if(another.size() > 0)
                        cadenas.push_back(another);
                    another = "";
                }
            }
            if(another.size() > 0)
                cadenas.push_back(another);
        }
        else
        {
            unordered_map <string, int> veces;
            int total, soloU;
            double entropy = 0, max = 0, logoT, porcent;
            for(auto a : cadenas)
                    veces[a]++;
            total = cadenas.size();
            max = log10(veces.size());
            logoT = log10(cadenas.size());
            for(auto a : veces)
                entropy += (a.second * (logoT - log10(a.second)));
            entropy /= cadenas.size();
            porcent = (entropy / log10(cadenas.size())) * 100;
            cout << total << " " << fixed << setprecision(1) << entropy << " " << (int)round(porcent) << "\n";
            cadenas.clear();
        }
    }
}
