/* Accepted - Leetcode */
#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool wordBreak(string s, vector <string>& words) {
	vector <bool> found(s.length() + 1, false);
	found[0] = true;
	map <string, bool> mapa;
	for (auto a : words) {
		mapa[a] = true;
	}

	for (int i = 1 ; i <= s.length() ; ++i) {
		for(int j = i - 1 ; j >= 0; j--) {
			if (found[j] && mapa.find(s.substr(j, i - j)) != mapa.end()) {
				found[i] = true;
				break;
			}
		}
	}
	return found[s.length()];
}

int main(void) {
	string cad;
	int n;
	cin >> n >> cad;
	vector <string> cads(n);
	for (int i = 0 ; i < n ; ++i) {
		cin >> cads[i];
	}
	cout << wordBreak(cad, cads) << endl;
}
