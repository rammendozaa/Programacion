// Accepted
#include <iostream>
#include <vector>
using namespace std;

void mergeSort(int ini, int mid, int fin, vector <int>& nums, int& countInversions) {
  int k = 0;
  int first = ini;
  int last = fin;
  int iniRight = mid + 1;
  vector <int> orderedNumbers(fin - ini + 1);
  while (ini <= mid && iniRight <= fin) {
    if (nums[ini] <= nums[iniRight]) {
      orderedNumbers[k] = nums[ini];
      ini++;
    } else {
      countInversions += mid - ini + 1;
      orderedNumbers[k] = nums[iniRight];
      iniRight++;
    }
    k++;
  }

  while (ini <= mid) {
    orderedNumbers[k] = nums[ini];
    ini++;
    k++;
  }

  while (iniRight <= fin) {
    orderedNumbers[k] = nums[iniRight];
    k++;
    iniRight++;
  }

  for (int i = 0 ; i < k ; ++i) {
    nums[first + i] = orderedNumbers[i];
  }

}

void inversionCount(int ini, int fin, vector <int>& nums, int& countInversions) {
  if (ini < fin) {
    int mid = ini + ((fin - ini) >> 1);
    inversionCount(ini, mid, nums, countInversions);
    inversionCount(mid + 1, fin, nums, countInversions);
    mergeSort(ini, mid, fin, nums, countInversions);
  }
}

int main(void) {
  int n;
  cin >> n;
  vector <int> nums(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> nums[i];
  }
  int countInversions = 0;
  inversionCount(0, nums.size() - 1, nums, countInversions);
  cout << countInversions << endl;
}
