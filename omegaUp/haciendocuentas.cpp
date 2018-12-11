#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int dias, p, n, m, t, auxP, auxN, auxM, cantN, cantM, totalN = 0, totalM = 0;
    cin >> dias;
    while(dias--)
    {
        cin >> p >> n >> m >> t;
        auxM = m * -1;
        auxN = auxM;
        auxP = p * auxM;
        cantN = (t + auxP) / (n + auxN);
        cantM = p - cantN;
        totalM += cantM;
        totalN += cantN;
    }
    cout << totalN << " " << totalM << "\n";
    return 0;
}
