#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int valores[n][2];
	int i,j,suma;
	for(i=0;i<n;i++)
		cin>>valores[i][0]>>valores[i][1];
	for(i=0;i<n;i++)
	{
		suma = 0;
		for(j=valores[i][0];j<=valores[i][1];j++)
		{
			if(j%2 != 0)
			{
				suma = suma + j;
			}
		}
		cout<<"Case "<<i+1<<": "<<suma<<'\n';
	}


	return 0;
}
