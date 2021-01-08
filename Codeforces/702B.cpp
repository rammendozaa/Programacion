#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <set>
using namespace std;

int main(void) {
  vector <long long int> powersTwo;
  int ini = 1;
  while (ini < 1000000000) {
    powersTwo.push_back(ini);
    ini *= 2;
  }
  int n;
  cin >> n;
  vector <int> nums(n);
  map <int, int> values;
  set <pair <int, int> > index;
  for (int i = 0 ; i < n ; ++i) {
    cin >> nums[i];
  }
  for (auto a : powersTwo) {
    for (int i = 0 ; i < nums.size() ; ++i) {
      if (values.find(a - nums[i]) != values.end()) {
        int ind1 = values[a - nums[i]];
        int ind2 = i;
        if (ind1 > ind2) {
          index.insert(make_pair(ind2, ind1));
        } else if (ind1 < ind2){
          index.insert(make_pair(ind1, ind2));
        }
      }
      values[nums[i]] = i;
    }
  }
  cout << index.size() << endl;
}
