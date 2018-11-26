#include <iostream>
using namespace std;

long long int expoBin(long long int a, long long int b, long long int m)
{
	long long int res = 1;
	for(; b; b >>= 1)
	{
		if(b & 1)
			res = (res * a) % m;
		a = (a * a) % m;
	}
	return res;
}


int main(void)
{
	long long int fila, colu, K;
	cin >> fila >> colu >> K;
	if((fila % 2 != colu % 2) && K == -1)
		cout << 0 << "\n";
	else
	{
		long long int res = expoBin(expoBin(2, fila - 1,1000000007), colu - 1,1000000007);
		cout << res << "\n";

	}
	return 0;
}
