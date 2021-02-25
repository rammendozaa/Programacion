/* Accepted */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string getSmallestString(int n, int k) {
  int Ks = 0;
  int Zs = (k / 26);
  int As = 0;
  int kValue = 0;
  int auxN = n;
  int auxK = k;
  while (Zs >= 0) {
    auxN = n - Zs;
    auxK = k - (Zs * 26);
    if (auxN == auxK) {
      As = auxN;
      Ks = 0;
      kValue = 0;
      break;
    } else {
      if (auxN - 1 >= 0 && (auxK - (auxN - 1)) < 26) {
        kValue = (auxK - (auxN - 1));
        Ks = (kValue > 0) ? 1 : 0;
        As = auxN - 1;
      }
      if ((Zs + As + Ks) == n && ((Zs * 26) + As + kValue) == k) {
        break;
      } else {
        Zs--;
      }
    }
  }
  string onlyZ = "";
  string onlyA = "";
  if (As > 0) {
    string auxA (As, 'a');
    onlyA = auxA;
  }
  if (Zs > 0) {
    string auxZ (Zs, 'z');
    onlyZ = auxZ;
  }

  if (Ks == 1) {
    return onlyA + char((kValue - 1) + 'a') + onlyZ;
  }
  return onlyA + onlyZ;
}
/*
string getSmallestString(int n, int k) {
  int numberZ = 0;
  numberZ = (k / 26);
  if (26 + (n - 1) > k) {
    numberZ = 0;
  }
  k -= (26 * numberZ);
  n -= numberZ;
  k -= (n - 1);
  string letter = "_abcdefghijklmnopqrstuvwxyz";
  string onlyZ = "";
  string onlyA = "";
  if (numberZ > 0) {
    string auxZ (numberZ, 'z');
    onlyZ = auxZ;
  }
  if (n - 1 > 0) {
    string auxA (n - 1, 'a');
    onlyA = auxA;
  }
  if (k > 0) {
    return onlyA + char((k - 1)+ 'a') + onlyZ;
  }
  return onlyA + onlyZ;

}
*/

int main(void) {
  int n;
  int k;
  while (cin >> n) {
    cin >> k;
    cout << getSmallestString(n, k) << endl;
  }
  return 0;
}
