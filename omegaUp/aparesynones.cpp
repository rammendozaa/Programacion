/* Accepted */
#include <iostream>
//#include <string>
using namespace std;

int main()
{
	int inic;
	cin>>inic;
	cin.ignore();
	int entrada[inic];
	int par[inic];
	int non[inic];
	int i,j,k,l,p,n,sumap,suman,promp,promn;
	for(i=0;i<inic;i++)
	{
		cin>>entrada[i];
	}
	p=0;
	n=0;
	for(j=0;j<inic;j++)
	{
		if(entrada[j]%2==0)
		{
			par[p]=entrada[j];
			p++;
		}
		else
		{
			non[n]=entrada[j];
			n++;
		}
	}
	sumap=par[0];
	suman=non[0];
	for(k=1;k<p;k++)
	{
		sumap=sumap+par[k];
	}
	for(l=1;l<n;l++)
	{
		suman=suman+non[l];
	}
	promp=sumap/p;
	promn=suman/n;
	if(promp>promn)
		cout<<"APARICIO";
	else if(promp<promn)
		cout<<"NONILA";
	else
		cout<<"EMPATE!";

	return 0;
}
