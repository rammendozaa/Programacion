/* Accepted */
#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int num, S, modulo, res, aux = 0, ans;
	cin >> num >> S;
	if(num == 1)
		cout << S << "\n";
	else
	{
		res = S % num;
		if(res != 0)
            aux++;
		S -= res;
		ans = (S / num) + aux;
		cout << ans << "\n";
	}
}
