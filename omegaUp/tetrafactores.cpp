/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

void todosDiv(vector <int> &divisores)
{
    divisores.resize(5115001,0);
    for(int i = 1 ; i <= 5115001 ; ++i)
        for(int j = i ; j <= 5115001 ; j += i)
            divisores[j]++;

}

int main(void)
{
    vector <int> divisores;
    int n, cuantos = 0, i = 1;
    cin >> n;
    todosDiv(divisores);
    while(cuantos < n)
    {
        if(divisores[i] == 4)
            cuantos++;
        i++;
    }
    cout << i - 1 << "\n";

}
