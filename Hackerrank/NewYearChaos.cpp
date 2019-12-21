// Accepted
#include <iostream>
#include <vector>
using namespace std;

bool swapRight(vector <int>& line, vector <int>& linePos,
  vector <int>& swapsCount, int number, int pos) {
    while (linePos[number] != number) {
      int swapFirst = line[linePos[number]];
      int swapSecond = line[linePos[number] + 1];
      swap(line[linePos[number]], line[linePos[number] + 1]);
      swap(linePos[swapFirst], linePos[swapSecond]);
      swapsCount[number]++;
      if (swapsCount[number] > 2) {
        return false;
      }
    }
    return true;
}

int main(void) {
  int n;
  cin >> n;
  vector <int> line(n + 1, 0);
  vector <int> linePos(n + 1);
  vector <int> swapsCount(n + 1, 0);
  for (int i = 1 ; i <= n ; ++i) {
    cin >> line[i];
    linePos[line[i]] = i;
  }

  bool possible = true;
  int i = n;
  while (i > 0) {
    int pos = linePos[i];
    if (pos == i) {
      i--;
    } else {
      if (!swapRight(line, linePos, swapsCount, i, pos)) {
        cout << "Too chaotic" << endl;
        possible = false;
        break;
      }
      i--;
    }
  }

  if (possible) {
    int sum = 0;
    for (int i = 0 ; i <= n ; ++i) {
      sum += swapsCount[i];
    }
    cout << sum << endl;
  }
}

===============================================================================

int main(void) {
  int n;
  int swapsCount = 0;
  cin >> n;
  vector <int> line(n + 1);

  for (int i = 1 ; i <= n ; ++i) {
    cin >> line[i];
  }

  for (int i = n ; i > 0 ; --i) {
    if (line[i] - i > 2) {
      cout << "Too chaotic" << endl;
      return 0;
    }
    for (int j = max(line[i] - 1, 1) ; j < i ; ++j) {
      if (line[j] > line[i]) {
        swapsCount++;
      }
    }
  }
  cout << swapsCount << endl;
}
