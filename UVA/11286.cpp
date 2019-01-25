/* Accepted */
#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int entrada;
	while(cin >> entrada && entrada != 0)
	{
		unordered_map <string, int> numeros;
		int auxI;
		string auxS = "", input;
		for(int j = 0 ; j < entrada ; j++)
		{
			set <int> auxSet;
			for(int i = 0 ; i < 5 ; i++)
			{
				cin >> auxI;
				auxSet.insert(auxI);
			}
			for(auto a : auxSet)
			{
				input = to_string(a);
				auxS += input;
			}
			numeros[auxS]++;
			auxS = "";
		}
		vector <int> veces;
		int maximo = -1e9, cuantos = 0, posF;	
		
		for(auto a : numeros)
			veces.push_back(a.second);
		sort(veces.begin(), veces.end());
		posF = veces.size() - 1;
		maximo = veces[veces.size() - 1];
		for(int i = veces.size() - 1 ; veces[i] == maximo ; i--)
			cuantos += veces[i];
		cout << cuantos << "\n";
	}
}