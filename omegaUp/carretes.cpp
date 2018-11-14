/* Accepted */
#include <iostream>
using namespace std;

int main()
{
	int c;
	cin>>c;
	cin.ignore();
	if(c==1 || c>200 || c==0)
		cout<<"ERROR";
	char fin[c];
	char ini[c];
	int finali[c];
	int inicial[c];
	int i,j,k;
	int suma=0;
	int abajo=0;
	int arriba=0;
	cin>>fin;
	cin.ignore();
	cin>>ini;
	cin.ignore();
	for(j=0;j<c;j++)
	{
		if(fin[j]=='\0')
			fin[j]='0';
		if(ini[j]=='\0')
			ini[j]='0';
	}
	i=c-1;
	int h;
	for(h=0;h<c;h++)
	{
		finali[h]=(int)fin[h]-48;
		inicial[h]=(int)ini[h]-48;
	}
	while(i>=0)
	{
		if(finali[i]<inicial[i])
		{
			finali[i]=finali[i]+10;
			arriba=(finali[i]-inicial[i]);
		}
		else
		{
			arriba=(finali[i]-inicial[i]);
		}
		if(inicial[i]<finali[i])
		{
			inicial[i]=inicial[i]+10;
			abajo=(inicial[i]-finali[i]);
		}
		else
		{
			abajo=(inicial[i]-finali[i]);
		}
		i--;
		if(arriba<abajo)
			suma=suma+arriba;
		else
			suma=suma+abajo;
	}
	cout<<suma;
	return 0;
}
