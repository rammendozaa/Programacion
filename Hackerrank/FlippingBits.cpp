// Accepted
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <long long int> toBinary (long long int numb) {
  vector <long long int> binary(32, 0);
  int i = 31;
  while (numb >= 0 && i >= 0) {
    binary[i] = (numb % 2);
    numb >>= 1;
    --i;
  }
  return binary;
}

// XOR 1 - to flip bit
long long int flipBits(vector <long long int> binary) {
  for (int i = 0 ; i <= 31 ; ++i) {
    binary[i] = (binary[i] ^ 1);
  }
  long long int numb = 0;
  for (int i = 0 ; i <= 31 ; ++i) {
    if (binary[i]) {
      numb += pow(2, 31 - i);
    }
  }
  return numb;

}

int main(void) {
  long long int n;
  cin >> n;
  while (n--) {
    long long int numb;
    cin >> numb;
    vector <long long int> binary = toBinary(numb);
    long long int result = flipBits(binary);
    cout << result << endl;
  }
}
