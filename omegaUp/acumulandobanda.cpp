/* Accepted */
#include <iostream>
using namespace std;

int main()
{
	int coop[5];
	int num;
	int i=1;
	int sum;
	cin>>coop[0];
	cin>>coop[1];
	cin>>coop[2];
	cin>>coop[3];
	cin>>coop[4];
	cin>>num;
	sum=coop[0];
	while(i<num)
	{
		sum=sum+coop[i];
		i++;
	}
	cout<<sum;

	return 0;
}
