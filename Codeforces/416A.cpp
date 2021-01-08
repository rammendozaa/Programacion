/* Accepted */
#include <string>
#include <iostream>
using namespace std;

int main (void) {
  int value;
  int cases;
  char yn;
  string lege;
  int mini = -2e9;
  int maxi = 2e9;
  cin >> cases;
  while (cases--) {
    cin >> lege >> value >> yn;
    if (yn == 'N' && lege[0] == '>') {
      if (maxi >= value) {
        maxi = value;
        if (lege.length() == 2) {
          maxi--;
        }
      }
    } else if (yn == 'N' && lege[0] == '<') {
      if (mini <= value) {
        mini = value;
        if (lege.length() == 2) {
          mini++;
        }
      }
    } else if (yn == 'Y' && lege[0] == '>') {
      if (mini <= value) {
        mini = value + 1;
        if (lege.length() == 2) {
          mini--;
        }
      }
    } else if (yn == 'Y' && lege[0] == '<') {
      if (maxi >= value) {
        maxi = value - 1;
        if (lege.length() == 2) {
          maxi++;
        }
      }
    }
  }
  (mini > maxi) ? cout << "Impossible\n" : cout << mini << endl;
  return 0;
}
