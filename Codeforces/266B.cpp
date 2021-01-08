/* Accepted */
#include <string>
#include <iostream>
using namespace std;

int main (void) {
  int n, t;
  cin >> n >> t;
  string start;
  string finish;
  char auxChar;
  cin >> start;
  while (t--) {
    int i = 0;
    while (i < n - 1) {
      if (start[i] == 'B' && start[i + 1] == 'G') {
        start[i] = 'G';
        start[i + 1] = 'B';
        i += 2;
        continue;
      }
      i++;
    }
  }
  cout << start << endl;
}
