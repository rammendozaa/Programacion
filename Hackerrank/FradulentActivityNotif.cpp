// Accepted
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int findNext(vector <int> counts, int pos) {
  while (counts[pos] == 0 && pos < counts.size()) {
    pos++;
  }
  return pos;
}

float findMedian(vector <int> counts, int half, bool isEven) {
  int sum = 0;
  for (int i = 0 ; i < counts.size() ; ++i) {
    sum += counts[i];
    if (sum == half) {
      if (isEven) {
        int suma = i;
        counts[i]--;
        i++;
        suma += findNext(counts, i);
        return (float)suma / (float)2;
      } else {
        return (float)i;
      }
    }
    if (sum > half) {
      return (float)i;
    }
  }
  cout << "returns0" << endl;
  return 0;
}

int main(void) {
  int n;
  int d;
  int half;
  int notifCount = 0;
  cin >> n >> d;
  bool isEven = (d % 2 == 0);
  half = (isEven) ? (d >> 1) : (d >> 1) + 1;
  vector <int> nums(n);
  vector <int> count(201, 0);
  for (int i = 0 ; i < n ; ++i) {
    cin >> nums[i];
  }

  int i = 0;
  while (i < d) {
    count[nums[i]]++;
    i++;
  }

  while (i < n) {
    float median = findMedian(count, half, isEven);
    if ((2 * median) <= nums[i]) {
      notifCount++;
    }
    count[nums[i]]++;
    count[nums[i - d]]--;
    i++;
  }
  cout << notifCount++ << endl;
}
