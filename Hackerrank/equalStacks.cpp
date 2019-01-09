/* Accepted */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


long long int equalStacks(vector<long long int> h1, vector<long long int> h2, vector<long long int> h3) {
    map <long long int, long long int> total;
    long long int sumaUno = 0, sumaDos = 0, sumaTres = 0;
    total[0] = 3;
    for(vector <long long int>::reverse_iterator a = h1.rbegin() ; a != h1.rend() ; ++a)
    {
        sumaUno += *a;
        total[sumaUno]++;
    }
    for(vector <long long int>::reverse_iterator a = h2.rbegin() ; a != h2.rend() ; ++a)
    {
        sumaDos += *a;
        total[sumaDos]++;
    }
    for(vector <long long int>::reverse_iterator a = h3.rbegin() ; a != h3.rend() ; ++a)
    {
        sumaTres += *a;
        total[sumaTres]++;
    }
    for(map<long long int, long long int>::reverse_iterator it = total.rbegin() ; it != total.rend() ; ++it)
    {
        if(it -> second >= 3)
            return it -> first;
    }
    return 0;
}

int main(void)
{
    long long int tam1, tam2, tam3, auxI;
    cin >> tam1 >> tam2 >> tam3;
    vector <long long int> U, D, T;
    for(long long int i = 0 ; i < tam1 ; i++)
    {
        cin >> auxI;
        U.push_back(auxI);
    }
    for(long long int i = 0 ; i < tam2 ; i++)
    {
        cin >> auxI;
        D.push_back(auxI);
    }
    for(long long int i = 0 ; i < tam3 ; i++)
    {
        cin >> auxI;
        T.push_back(auxI);
    }
    long long int res = equalStacks(U, D, T);
    cout << res << "\n";
}
