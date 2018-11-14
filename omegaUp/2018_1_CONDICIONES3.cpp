/* Accepted */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float n;
	float impuesto;
	cin>>n;
	if (n>=0.01 && n<=969.50)
		impuesto=(n-0.01)*0.0192;
	else if (n>=969.51 && n<=1703.80)
		impuesto=((n-969.51)*0.1088)+56.91;
	else if (n>=1703.81 && n<=4782.61)
		impuesto=((n-1703.81)*0.16)+136.85;
	else if (n>=4782.62 && n<=14391.44)
		impuesto=((n-4782.62)*0.2352)+766.15;
	else if (n>=14391.45 && n<=19188.61)
		impuesto=((n-14391.45)*0.32)+3470.25;
	else if (n>=19188.62 && n<=57565.76)
		impuesto=((n-19188.62)*0.34)+5005.35;
	else if	(n>=57565.77 && n<=200000.00)
		impuesto=((n-57565.77)*0.35)+18053.63;
	cout<<impuesto;
	return 0;
}
