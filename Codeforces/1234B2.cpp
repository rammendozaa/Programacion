/* Accepted */
#include <iostream>
#include <vector>
#include <map>
#include <deque>
using namespace std;

int main(void) {
  int n;
  int maxSize;
  cin >> n >> maxSize;
  vector <int> nums(n);
  map <int, bool> isIn;
  deque <int> q;
  for (int i = 0 ; i < n ; ++i) {
    cin >> nums[i];
    isIn[nums[i]] = false;
  }
  for (auto a : nums) {
    if (!isIn[a]) {
      isIn[a] = true;
      q.push_front(a);
      if (q.size() > maxSize) {
        isIn[q.back()] = false;
        q.pop_back();
      }
    }
  }
  cout << q.size() << endl;
  while(!q.empty()) {
    cout << q.front() << " ";
    q.pop_front();
  }
  cout << endl;
}
