/* Accepted */
#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b)
{
	if(b == 0)
  	return a;
  else
  	gcd(b, a % b);
}

int main(void)
{
	int cases;
  long long int a, b;
  cin >> cases;
  while(cases--)
  {
  	cin >> a >> b;
  	if(gcd(a, b) == 1)
    	cout << "SI\n";
    else
    	cout << "NO\n";
  }

	return 0;
}
