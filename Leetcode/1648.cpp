#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define lli long long int

/*
lli gauss(lli n) {
  return (((n * (n + 1)) % (lli)(1e9 + 7)) << 1);
}

lli getSum(lli fin, lli ini) {
  return ((fin * (fin - ini)) % (lli)(1e9 + 7));
}

int maxProfit (vector <int>& inventory, int ordenes) {
  if (inventory.size() == 1) {
    return (((lli)inventory[0] * (lli)ordenes) % (lli)(1e9 + 7)) - ((((lli)(ordenes - 1) * (lli)ordenes) % (lli)(1e9 + 7)) >> 1);
  }
  sort(inventory.begin(), inventory.end(), greater <lli>());
  inventory.push_back(0);
  int i = 0;
  lli howMany;
  lli maxProfit = 0;
  lli orders = (lli)ordenes;
  lli fin;
  lli ini;
  while (orders > 0) {
    fin = (lli)inventory[i];
    ini = (lli)inventory[i + 1];
    while (fin == ini) {
      i++;
      fin = (lli)inventory[i];
      ini = (lli)inventory[i + 1];
    }
    howMany = ((i + 1) * (fin - ini));
    if (howMany <= orders) {
      orders -= howMany;
      maxProfit += ((((getSum(fin, ini)) - (gauss((fin - ini - 1))))) * (i + 1));
//      maxProfit %= (lli)(1e9 + 7);
//      cout << maxProfit << endl;
    } else {
      lli rows = orders / (i + 1);
      maxProfit += (((((fin * rows)) - (gauss(rows - 1)))) * (i + 1));
//      maxProfit %= (lli)(1e9 + 7);
//      cout << maxProfit << endl;
      maxProfit += ((orders % (i + 1)) * (ini + 1));
//      maxProfit %= (lli)(1e9 + 7);
      orders = 0;
      cout << maxProfit << endl;
    }
//    maxProfit %= (lli)(1e9 + 7);
    i++;
  }
  return maxProfit;
}
*/

lli gauss(lli n) {
return (((n * (n + 1)) % (lli)(1e9 + 7)) / 2);
}

lli getSum(lli fin, lli ini) {
  return (fin * (fin - ini));
}


lli maxProfit(vector<int>& inventory, int orders) {
if (inventory.size() == 1) {
return (((lli)inventory[0] * (lli)orders) % (lli)(1e9 + 7)) - ((((lli)(orders - 1) * (lli)orders) % (lli)(1e9 + 7)) >> 1);
}
sort(inventory.begin(), inventory.end(), greater <lli>());
inventory.push_back(0);
int i = 0;
lli howMany;
lli maxProfit = 0;
while (orders > 0) {
while (inventory[i] == inventory[i + 1]) {
  i++;
}
howMany = (lli)(i + 1) * (lli)(inventory[i] - inventory[i + 1]);
if (howMany <= orders) {
  orders -= howMany;
  lli resSum = getSum((lli)inventory[i], (lli)inventory[i + 1]) % (lli)(1e9 + 7);
  lli resGauss = gauss((lli)(inventory[i] - inventory[i + 1] - 1)) % (lli)(1e9 + 7);
  cout << resSum << " _ " << resGauss << endl;
  maxProfit += (((resSum - resGauss) % (lli)(1e9 + 7)) * (lli)(i + 1));
  cout << "mp " << maxProfit << endl;
} else {
  lli rows = orders / (i + 1);
  if (rows == 0) {
    maxProfit += ((lli)(orders % (i + 1)) * (lli)(inventory[i])) % (lli)(1e9 + 7);
    return maxProfit;
  }
  lli resSum = ((lli)inventory[i] * (lli)rows) % (lli)(1e9 + 7);
  lli resGauss = gauss(rows - 1) % (lli)(1e9 + 7);
  maxProfit += (((resSum - resGauss) % (lli)(1e9 + 7)) * (lli)(i + 1));
  maxProfit += ((lli)(orders % (i + 1)) * (lli)(inventory[i + 1] + 1)) % (lli)(1e9 + 7);
  orders = 0;
  cout << "MP " << maxProfit << endl;
  return maxProfit;
}
i++;
}
return maxProfit;
}

int main (void) {
  int orders;
  vector <int> inventory;
  int balls;
  cin >> orders;
  while (cin >> balls) {
    inventory.push_back(balls);
  }
  cout << maxProfit(inventory, orders) << endl;
  return 0;
}
