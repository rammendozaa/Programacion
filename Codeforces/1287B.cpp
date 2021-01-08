#include <iostream>
#include <string>
#include <vector>
using namespace std;
// function that receives 3 string and compares them
  // if the difference module 2 == 0 or they're all different then yes
bool isSet(string one, string two, string three) {
  int diffOne = 0;
  int diffTwo = 0;
  int diffThree = 0;
  for (int i = 0 ; i < one.size() ; ++i) {
      if (one[i] != two[i])
        diffOne++;
  }
  for (int i = 0 ; i < one.size() ; ++i) {
    if (one[i] != three[i])
      diffTwo++;
  }
  for (int i = 0 ; i < one.size() ; ++i) {
    if (three[i] != two[i])
      diffThree++;
  }
  return (diffOne % 2 == 0 || diffOne == one.size())
    && (diffTwo % 2 == 0 || diffTwo == one.size())
      && (diffThree % 2 == 0 || diffThree == one.size());
}

int main(void) {
  int number;
  int size;
  int ways = 0;
  cin >> number >> size;
  vector <string> cads(number);
  for (int i = 0 ; i < number ; ++i) {
    cin >> cads[i];
  }
  for (int i = 0 ; i < number - 2 ; ++i) {
    for (int j = i + 1 ; j < number - 1 ; ++j) {
      for (int k = j + 1 ; k < number ; ++k) {
        if (isSet(cads[i], cads[j], cads[k])) {
          ways++;
        }
      }
    }
  }
  cout << ways << endl;


}
// while loop that iterates all combinations of three strings
