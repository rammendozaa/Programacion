#include <iostream>
using namespace std;

int main()
{
	int fin,inicio,mayor=-1,n;
	int contador=0;
//	cin>>inicio>>fin;
	int j;
	while(cin>>inicio>>fin)
	{
		for(j=inicio;j<=fin;j++)
		{
				n=j;
				while(n != 1)
				{
					if(n%2 == 1)
						n = 3*n + 1;
					else
						n = n>>1;
					contador++;
				}
				contador++;
				mayor = max(mayor,contador);
				contador = 0;
		}
		cout<<inicio<<" "<<fin<<" "<<mayor<<'\n';
		mayor = -1;
	}
		return 0;
}
