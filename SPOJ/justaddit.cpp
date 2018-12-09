/* Accepted */
#include <iostream>
using namespace std;

long long int expBin(long long int a, long long int b, long long int mod)
{
    long long int res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int N, K;
    long long int modulo = 1e7 + 7;
    while(cin >> N >> K && (N != 0) || (K != 0))
    {
        long long int resultado = 0;
        long long int eneMen = N - 1;
        resultado = (expBin(eneMen, K, 10000007) * 2) + expBin(N, K, 10000007) + (2 * expBin(eneMen, eneMen, 10000007)) + expBin(N, N, 10000007);
        cout << resultado % 10000007 << "\n";
    }
    return 0;
}
