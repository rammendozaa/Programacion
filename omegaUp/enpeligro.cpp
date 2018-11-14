/* Accepted */
#include <iostream>
#include <cmath>
using namespace std;
int main()
{

	long int digito;
	long double entero;
	long long int valor;
	int contador=0;
//	cout<<"\nIngrese el numero\n";
	cin>>digito;
	while(digito>0)
	{
		digito=digito/10;
		contador++;
	}
	valor=(contador*45*pow(10,(contador-1)));
	//entero=(long double)valor;
	cout<<valor;
	return 0;
}
