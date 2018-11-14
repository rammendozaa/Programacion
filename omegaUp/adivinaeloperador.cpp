/* Accepted */
#include <iostream>
using namespace std;

int main()
{
	int num[3];
	int i;
	for(i=0;i<3;i++)
	{
		cin>>num[i];
	}
	if(num[0]+num[1]==num[2])
		cout<<"+";
	else if(num[0]*num[1]==num[2])
		cout<<"*";
	else if(num[0]/num[1]==num[2])
		cout<<"/";
	else if(num[0]-num[1]==num[2])
		cout<<"-";
	else
		cout<<"D:";

	return 0;
}
