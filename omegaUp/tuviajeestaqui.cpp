/* Accepted */
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string cometa, grupo;
    cin >> cometa >> grupo;
    long long int pC = 1, pG = 1;
    for(auto a : grupo)
        pC *= a - 64;
    for(auto a : cometa)
        pG *= a - 64;
    (pC % 47 == pG % 47)? cout << "GO\n" : cout << "STAY\n";
    return 0;
}
