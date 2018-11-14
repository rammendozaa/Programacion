/* Accepted */
#include <iostream>
using namespace std;

int main()
{
	int buscar,lap;
	cin>>lap;
	int lapices[lap];
	cin>>buscar;
	for(int i=0;i<lap;i++)
	{
		cin>>lapices[i];
	}
	int contador=0;
	int j=0;
	while(j<lap)
	{
		if(lapices[j]==buscar)
		{	contador++;}
		j++;
	}
	cout<<contador;
return 0;
}
