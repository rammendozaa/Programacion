/* Accepted */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int vectorToInt(vector <int>& res, bool isNeg) {
  int count = 1;
  int sum = 0;
  for (int i = res.size() - 1, count = 1 ; i >= 0 ; --i, count *= 10) {
    sum += (res[i] * count);
  }
  return (isNeg) ? -1 * sum : sum;
}

int myAtoi(string str) {
  bool isNeg = false;
  int i = 0;
  vector <int> res;
  while (i < str.length() && str[i] == ' ') {
    i++;
  }
  if (i == str.length() && str[i] > '9' && str[i] < '0' && str[i] != '+' && str[i] != '-') {
    return 0;
  }
  if (str[i] == '+') {
    i++;
  } else if (str[i] == '-') {
    isNeg = true;
    i++;
  }
  if (i == str.length() && str[i] > '9' && str[i] < '0') {
    return 0;
  }
  while (str[i] == '0') {
    i++;
  }
  if (i == str.length()) {
    return 0;
  }
  while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
    res.push_back(str[i] - '0');
    i++;
  }

  if (res.size() > 10) {
    return (isNeg) ? -2147483648 : 2147483647;
  } else if (res.size() == 10) {
    vector <int> posV = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
    vector <int> negV = {2, 1, 4, 7, 4, 8, 3, 6, 4, 8};
    int equal = 0;
    int i;
    if (isNeg) {
      i = 0;
      while (i < 10 && res[i] == negV[i]) {
        equal++;
        i++;
      }
      if ((equal < 10 && negV[equal] < res[equal]) || equal == 10) {
          return -2147483648;
      }
    } else {
      i = 0;
      while (i < 10 && res[i] == posV[i]) {
        equal++;
        i++;
      }
      if ((equal < 10 && posV[equal] < res[equal]) || equal == 10) {
          return 2147483647;
      }
    }
    return vectorToInt(res, isNeg);
  } else {
    return vectorToInt(res, isNeg);
  }
}

int main(void) {
  string str;
  while (getline(cin, str)) {
    cout << "str = " << str << " ";
    cout << myAtoi(str) << endl;
  }
  return 0;
}
