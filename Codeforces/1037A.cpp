/* Accepted */
#include <iostream>
using namespace std;

int main(void)
{
	long long int entrada, veces = 0;
	cin >> entrada;
	while(entrada > 0)
	{
		entrada >>= 1;
		veces++;
	}
	cout << veces << "\n";
}
