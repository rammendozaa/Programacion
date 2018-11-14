/* Accepted */
#include <string>
#include <iostream>
using namespace std;

int cuantas(char c,string p)
{
	int i=0;
	int j;
	char car;
	for(j=0;j<p.length();j++)
	{
		car=p.at(j);
		if(c==car)
			i++;
		else
			continue;
	}
	return i;
}

int main()
{
	int n;
	string abc="abcdefghijklmnopqrstuvwxyz";
	int i=0;
	int j;
	int veces;
	char car;
	int finally=0;
	char prueb[50];
	string pruebas;
	string resultante="";
	cin>>n;
	while(i<n)
	{
		cin.ignore();
		cin>>pruebas;
		if(pruebas.length()<26)
		{
			resultante=resultante+"NO WAY\n";
		}
		else{
		for(j=0;j<abc.length();j++)
		{
			car=(char)abc.at(j);
			veces=cuantas(car,pruebas);
			if(veces==0)
			{
				resultante=resultante+"NO WAY\n";
				break;
			}
			else if(veces>=1)
			{
				finally++;
				if(finally==26)
				{
					resultante=resultante+"PERFECT\n";
					finally=0;
					break;
				}
				continue;
			}
		}
		}
		i++;
	}
	cout<<resultante;
	return 0;
}
