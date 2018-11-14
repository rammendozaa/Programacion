/* Accepted */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
vector <double> planetas;
vector <double> resultados;

double suma(double posoy)
{
	double fuerzas = 0;
	for(int i = 0 ; i < planetas.size() ; i++)
		fuerzas += 1 / (planetas[i] - posoy);
	return fuerzas;
}

double binary(double primer, double segundo)
{
	double mid; // = (primer + segundo) / 2;
	for(int i = 0 ; i < 50 ; i++)
	{
		mid = (primer + segundo) / 2;
		if(suma(mid) > 0)
			segundo = mid;
		else
			primer = mid;
	}
	return primer;
}

int main()
{
	cout << fixed;
	cout << setprecision(3);
	int n, fin;
	double aux;
	cin >> n;
	fin = n;
	while(n--)
	{
		cin >> aux;
		planetas.push_back(aux);
	}
	sort(planetas.begin(), planetas.end());
	cout << fin - 1 << "\n";
	for(int i = 0 ; i < planetas.size() - 1 ; i++)
		cout << binary(planetas[i], planetas[i + 1]) << " ";
	cout << "\n";

	return 0;
}
