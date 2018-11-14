/* Accepted */
#include <iostream>
using namespace std;

int main()
{
	string cadena;
	int i;
	while(getline(cin,cadena))
	{
		for(i=cadena.length()-1;i>=0;i--)
		{
			cout<<cadena[i];
		}
		cout<<'\n';
	}
	return 0;
}
