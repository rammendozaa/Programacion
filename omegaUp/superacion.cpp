/* Accepted */
#include <iostream>
using namespace std;

int main()
{
	int costo, amigos, preciohom, preciomuj;
//	cout<<"Introduce el numero de amigos";
	cin>>amigos;
//	cout<<"Introduce el costo de condones hom";
	cin>>preciohom;
//	cout<<"Introduce el costo de muj";
	cin>>preciomuj;

	costo=(((amigos+1)*preciohom)+((amigos+1)*preciomuj));
	cout<<"$"<<costo;

	return 0;
}
