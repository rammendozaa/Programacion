/* Accepted */
#include <iostream>
using namespace std;
int main()
{
  int mike,otros,i,j,lefaltan;
  j=0;
  cin>>mike>>otros;
  int goles[otros];
  for(i=0;i<otros;i++)
    	cin>>goles[i];
  lefaltan = goles[otros-1]-mike;
  for(i=0;i<otros;i++)
  {
    	if(goles[i]>mike)
        	j++;
  }
  cout<<lefaltan<<'\n'<<j;

 	return 0;
}
