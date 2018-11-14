/* Accepted */
#include <iostream>
using namespace std;

int main()
{
	string cadena;
	int i;
	char aux;
	while(getline(cin,cadena))
	{
		for(i=0;i<cadena.length();i++)
		{
			aux=toupper(cadena[i]);
			cout<<aux;
		}
		cout<<'\n';
		for(i=0;i<cadena.length();i++)
		{
			aux=tolower(cadena[i]);
			cout<<aux;
		}
		cout<<'\n';
	}
	return 0;
}
