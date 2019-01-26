/* Accepted */
#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <vector>
#include <utility>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cases;
    unordered_map <string, pair<string, string> > parents;
    map <string, string> hasG;
    unordered_set <string> fatherless;
    cin >> cases;
    while(cases--)
    {
        string nombre, auxS;
        cin >> nombre >> auxS;
        if(auxS != "dominant" && auxS != "recessive" && auxS != "non-existent")
        {
            if(parents[auxS].first.length() == 0)
                parents[auxS].first = nombre;
            else
                parents[auxS].second = nombre;
            fatherless.insert(auxS);
        }
        else
            hasG[nombre] = auxS;
    }
    int contador = 0, total = fatherless.size();
    unordered_set <string>::iterator it = fatherless.begin();
    while(contador < total)
    {
        if(it == fatherless.end())
            it = fatherless.begin();
        if(hasG[parents[*it].first].length() == 0 || hasG[parents[*it].second].length() == 0)
            it++;
        else
        {
            if((hasG[parents[*it].first] == "dominant" || hasG[parents[*it].second] == "dominant") ||
            (hasG[parents[*it].first] == "dominant" && hasG[parents[*it].second] == "recessive") ||
            (hasG[parents[*it].first] == "recessive" && hasG[parents[*it].second] == "dominant") ||
            (hasG[parents[*it].first] == "dominant" && hasG[parents[*it].second] == "dominant") ||
            (hasG[parents[*it].first] == "recessive" && hasG[parents[*it].second] == "recessive"))
            {
                if((hasG[parents[*it].first] == "dominant" && hasG[parents[*it].second] == "dominant") || (hasG[parents[*it].first] == "dominant" && hasG[parents[*it].second] == "recessive") ||
                (hasG[parents[*it].first] == "recessive" && hasG[parents[*it].second] == "dominant"))
                    hasG[*it] = "dominant";
                else
                    hasG[*it] = "recessive";
            }
            else
                hasG[*it] = "non-existent";
            fatherless.erase(it);
            contador++;
            it = fatherless.begin();
        }
    }
    for(auto a : hasG)
        cout << a.first << " " << a.second << "\n";
}
