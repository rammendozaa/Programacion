/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int maxEmpty;
  int currEmpty;
  string in;
  while (cin >> in) {
    maxEmpty = 0;
    int i = 0;
    int j = in.length() - 1;
    while (i < in.length() && in[i] == '.') {
      i++;
    }
    while (j >= 0 && in[j] == '.') {
      j--;
    }
    maxEmpty = max(maxEmpty, i - 1);
    maxEmpty = max(maxEmpty, (int)(in.length() - 2 - j));
    while (i <= j) {
      currEmpty = 0;
      while (i <= j && in[i] == '.') {
        i++;
        currEmpty++;
      }
      i++;
      if (currEmpty < 2) {
        continue;
      }
      if (currEmpty % 2 == 0) {
        maxEmpty = max(maxEmpty, (currEmpty >> 1) - 1);
      } else {
        maxEmpty = max(maxEmpty, (currEmpty >> 1));
      }
    }
    cout << maxEmpty << endl;
  }
}
