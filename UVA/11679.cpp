#include <iostream>
#include <vector>
using namespace std;

bool todosPos(vector <int> arreglo)
{
  for(auto a : arreglo)
    if(a < 0)
      return false;
  return true;
}

int main(void)
{
  int banks, lineas;
  while(cin >> banks >> lineas && (banks != 0 || lineas != 0))
  {
    vector <int> dinero(banks);
    int auxI, debtor, creditor, mon;
    for(int i = 0 ; i < banks ; i++)
    {
      cin >> auxI;
      dinero[i] = auxI;
    }
    for(int i = 0 ; i < lineas ; i++)
    {
      cin >> debtor >> creditor >> mon;
      dinero[debtor - 1] -= mon;
      dinero[creditor - 1] += mon;
    }
    if(todosPos(dinero))
      cout << "S\n";
    else
      cout << "N\n";
  }
  return 0;
}
