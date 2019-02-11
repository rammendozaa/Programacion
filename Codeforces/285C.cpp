/* Accepted */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int num, cont = 0;
	cin >> num;
	vector <long long int> entrada(num), unos;
	for(int i = 0 ; i < num ; i++)
	{
		unos.push_back(i + 1);
		cin >> entrada[i];
	}
	sort(entrada.begin(), entrada.end());
	for(int i = 0 ; i < num ; i++)
		cont += abs(unos[i] - entrada[i]);
	cout << cont << "\n";

}
