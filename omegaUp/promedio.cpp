/* Accepted */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  int n,valor;
  float promedio;
  cin>>n;
  int suma=0;
  for(int i=0;i<n;i++)
  {
    cin>>valor;
    suma=suma+valor;
  }
  promedio = (float)suma/(float)n;
  cout<<fixed;
  cout<<setprecision(2);
  cout<<promedio;
 	return 0;
}
