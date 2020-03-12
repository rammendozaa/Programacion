#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
  int one;
  int two;
  for (int i = 1 ; i <= 100 ; ++i) {
    double res = (double)((double)1 / (double)i);
    string resStr = " " + res;
    cout << res << " " << resStr << endl;
  }
  return 0;
}
