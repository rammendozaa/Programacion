// Accepted
#include <iostream>
#include <vector>
using namespace std;

void swapToPosition(vector <int>& values, vector <int>& valuesPos, int number) {
  int posAtNumber = valuesPos[number];
  int valueAtPos = values[number];
  swap(values[posAtNumber], values[number]);
  swap(valuesPos[number], valuesPos[valueAtPos]);
}

int main(void) {
  int n;
  int countSwaps = 0;
  cin >> n;
  vector <int> values(n + 1);
  vector <int> valuesPos(n + 1);
  for (int i = 1 ; i <= n ; ++i) {
    cin >> values[i];
    valuesPos[values[i]] = i;
  }

  for (int i = 1 ; i <= n ; ++i) {
    if (values[i] != i) {
      swapToPosition(values, valuesPos, i);
      countSwaps++;
    }
  }
  cout << countSwaps << endl;

}
