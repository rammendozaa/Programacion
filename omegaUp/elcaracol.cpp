/* Accepted */
#include <iostream>
using namespace std;

int main()
{
	int alt,sub,baj,dist,dias;
	cin>>alt;
	cin>>sub;
	cin>>baj;
	dias=0;
	dist=0;
	while(dist<alt)
	{
		dias++;
		dist=dist+sub;
		if(dist>=alt)
		{
			cout<<dias;
			break;
		}
		dist=dist-baj;
	}
	return 0;
}
