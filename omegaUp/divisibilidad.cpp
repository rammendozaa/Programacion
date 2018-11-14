/* Accepted */
#include <iostream>
using namespace std;
int n,p;
int main()
{
	cin >> n >> p;
	int i=1;
	int valores[n];
	valores[0]=1;
	long long mult=10;
	while (i<n)
	{
		valores[i]=mult%p;
		mult=10*mult;
		i++;
	}
	i=n-1;
	while(i>=0)
	{
		cout<<valores[i]<<" ";
		i--;
	}
	cout<<"\n";


	return 0;
}
