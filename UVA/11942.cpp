#include <iostream>
#include <vector>
using namespace std;

bool ascending(vector <int> entrada)
{
    int primer = entrada[0];
    if(primer > entrada[1])
        return false;
    for(int i = 2 ; i < entrada.size() ; i++)
        if(entrada[i - 1] > entrada[i])
            return false;
    return true;
}

bool descending(vector <int> entrada)
{
    int primer = entrada[0];
    if(primer < entrada[1])
        return false;
    for(int i = 2 ; i < entrada.size() ; i++)
        if(entrada[i - 1] < entrada[i])
            return false;
    return true;
}

int main(void)
{
    int cases, aux;
    cin >> cases;
    cout << "Lumberjacks:\n";
    while(cases--)
    {
        vector <int> lumber(10);
        bool asc, des;
        for(int i = 0 ; i < 10 ; i++)
        {
            cin >> aux;
            lumber[i] = aux;
        }
        asc = ascending(lumber);
        des = descending(lumber);
        if(asc || des)
            cout << "Ordered\n";
        else
            cout << "Unordered\n";
    }
    return 0;
}
