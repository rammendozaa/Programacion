/* Accepted */
#include <iostream>
using namespace std;

int ascii(int a)
{
	if(a>96)
		a=a-32;
	return a;
}

int main()
{

	int suma;
	int contador=1;
	int i=0;
	int j=2;
	int k=0;
	char a[100];
	cin>>a;
	suma=ascii((int)a[0])+ascii((int)a[1]);//+ascii((int)a[2])+ascii((int)a[3]);
	while(a[j]!='\0')
	{
		suma=suma+ascii((int)a[j]);
		j++;
	}

	while(contador<=suma)
	{
		if(suma%contador==0)
		{
			i++;
		}
			contador++;
	}
	cout<<i;
return 0;
}
