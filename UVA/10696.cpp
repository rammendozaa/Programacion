#include <iostream>
using namespace std;

long uno(long i)
{
	if(i>=101)
		i=i-10;
	else
		i=uno(uno(i+11));
	return i;
}

int main()
{
	int n;
	long resultado;
	cin>>n;
	while(n != 0)
	{
		resultado = uno(n);
		cout<<"f91("<<n<<") = "<<resultado<<'\n';
		cin>>n;
	}




	return 0;
}
