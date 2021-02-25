#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int minimumDeviation(vector <int>& nums) {
  int minDif;
  priority_queue <int, vector <int>, greater <int> > qStoB;
  priority_queue <int> qBtoS;
  unordered_map <int, int> numToCount;
  for (auto a : nums) {
    qStoB.push(a);
    qBtoS.push(a);
    numToCount[a]++;
  }
  minDif = qBtoS.top() - qStoB.top();
  while (true) {
    //find better exit clause
    if ((qBtoS.top() % 2 != 0 && qStoB.top() % 2 == 0) ||
      (minDif < qBtoS.top() - qStoB.top())) {
        minDif = min(minDif, qBtoS.top() - qStoB.top());
        return minDif;
    }
    if (qBtoS.top() % 2 == 0) {
      numToCount[qBtoS.top()]--;
      numToCount[qBtoS.top() >> 1]++;
      int auxI = qBtoS.top() >> 1;
      qBtoS.pop();
      qBtoS.push(auxI);
      qStoB.push(auxI);
    }
    while (numToCount.find(qStoB.top()) == numToCount.end() ||
      numToCount[qStoB.top()] == 0) {
        qStoB.pop();
    }
    if ((qBtoS.top() % 2 != 0 && qStoB.top() % 2 == 0) ||
      (minDif < qBtoS.top() - qStoB.top())) {
        minDif = min(minDif, qBtoS.top() - qStoB.top());
        return minDif;
    }
    minDif = min(minDif, qBtoS.top() - qStoB.top());
    if (qStoB.top() % 2 != 0) {
      numToCount[qStoB.top()]--;
      numToCount[qStoB.top() << 1]++;
      int auxI = qStoB.top() << 1;
      qStoB.pop();
      qStoB.push(auxI);
      qBtoS.push(auxI);
    }
    while (numToCount.find(qBtoS.top()) == numToCount.end() ||
      numToCount[qBtoS.top()] == 0) {
        qBtoS.pop();
    }
    minDif = min(minDif, qBtoS.top() - qStoB.top());
  }
  return minDif;
}


int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << minimumDeviation(nums) << endl;
}
