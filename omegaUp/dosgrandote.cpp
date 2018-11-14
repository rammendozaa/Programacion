/* Accepted */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long int suma=1;
	int n,i;
	cin>>n;
	if(n==0)
		cout<<1;
	else
	{
		for(i=1;i<=n;i++)
		{
			suma=suma+pow(2,i);
		}
		cout<<suma;
	}
	return 0;
}
