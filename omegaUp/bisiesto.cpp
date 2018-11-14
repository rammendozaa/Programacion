/* Accepted */
#include <iostream>
using namespace std;

int main()
{
  int anio;
  	int j=0;
  cin>>anio;
  int arreglo[anio];
  char siono[anio];
  for(int i=0;i<anio;i++)
    cin>>arreglo[i];
  for(int i=0;i<anio;i++)
  {
   	if(arreglo[i]%4==0)
    {
      if(arreglo[i]%100==0)
      {
        if(arreglo[i]%400==0)
        {
          siono[j]='S';
          j++;
        }
        else
        {
          siono[j]='N';
        	j++;
        }
      }
      else
      {
        siono[j]='S';
        j++;
      }
    }
    else
    {
      siono[j]='N';
      j++;
    }
  }
for(j=0;siono[j]!='\0';j++)
  cout<<siono[j]<<'\n';
 	return 0;
}
