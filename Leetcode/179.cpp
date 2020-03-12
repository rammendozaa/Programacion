/* Accepted */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string compareAndChoose(string& one, string &two) {
    string res = "";
    if (one[0] == two[0]) {
    int i = 1;
    int j = 1;
    string auxOne;
    string auxTwo;
    if (one.length() == two.length()) {
      while (i < one.length() && one[i] == two[i]) {
        i++;
      }
      if (i == one.length()) {
        res = one;
      } else {
        res = (one[i] > two[i]) ? one : two;
      }
    } else {
      while (i < one.length() && j < two.length() && (one[i] == two[j])) {
        i++;
        j++;
      }
      if (i == one.length() && j < two.length()) {
        i--;
        while (j < two.length() && one[i] == two[j]) {
          j++;
        }
        if (j == two.length()) {
          res = one;
        } else {
          res = (one[0] > two[j]) ? one : two;
          if (one[0] == two[j]) {
            res = (two[0] > one[one.length() - 1]) ? two : one;
          }
        }
      } else {
        res = (one[i] > two[j]) ? one : two;
      }
    }
    return res;
  }
  res = (one[0] > two[0]) ? one : two;
  return res;
}

string largestNumber(vector <int>& nums) {
  if (nums.size() == 0) {
    return "";
  }
  if (nums.size() == 1) {
    return to_string(nums[0]);
  }
  vector <string> num;
  int maxSize = -1;
  string auxS = "";
  for (auto a : nums) {
    auxS = to_string(a);
    maxSize = max(maxSize, (int)auxS.length());
    num.push_back(to_string(a));
  }
  sort(num.begin(), num.end(), greater <string>());
  vector <queue <string> > sizes(maxSize + 1);
  for (auto a : num) {
    sizes[a.length()].push(a);
  }
  string cad = "";
  string tentative = "";
  int chosen = 0;
  int allNums = nums.size();
  while (chosen < allNums) {
    for (int i = 1 ; i < sizes.size() ; ++i) {
      if (!sizes[i].empty()) {
        tentative = sizes[i].front();
        for (int j = 1 ; j < sizes.size() ; ++j) {
          if (i != j && !sizes[j].empty()) {
            if (tentative.length() < sizes[j].front().length()) {
                tentative = compareAndChoose(tentative, sizes[j].front());
            } else {
                tentative = compareAndChoose(sizes[j].front(), tentative);
            }
          }
        }
        sizes[tentative.length()].pop();
        cad += tentative;
        chosen++;
      } else {
        continue;
      }
    }
  }
    if (cad[0] == '0') {
        return "0";
    }
  return cad;
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << largestNumber(nums) << endl;
}
