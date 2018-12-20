/* Accepted */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <utility>
#include <iomanip>
using namespace std;

vector <pair<double, double> > speeds;
pair <double, double> cheater;
double runningS, cyclingS;
double runners, kilo;
	
double seconds(double runDis)
{
	double minimo = 1e12, velAct;
	double cyDis = kilo - runDis;
	double velocidadCheater;
	for(long long int i = 0 ; i < runners - 1 ; i++)
	{
		velAct = (runDis / speeds[i].first) + (kilo - runDis) / speeds[i].second;
		minimo = min(minimo, velAct);
	}
	velocidadCheater = (runDis / speeds[runners - 1].first) + (kilo - runDis) / speeds[runners - 1].second;
	return ((velocidadCheater - minimo) * -3600);
}

void ternary()
{
	double left, right, mid1, mid2;
	left = 0;
	right = kilo;
	double res1, res2, maximo = -1;
	mid1 = left + (right - left) / 3;
	mid2 = right - (right - left) / 3;
	while((mid2 - mid1) > 1e-5)
	{
		mid1 = left + (right - left) / 3;
		mid2 = right - (right - left) / 3;
		res1 = seconds(mid1);
		res2 = seconds(mid2);
		if(res1 > res2)
			right = mid2;
		else
			left = mid1;
	}
	if(res1 < 0)
		cout << "The cheater cannot win.\n";
	else
		cout << fixed << "The cheater can win by " << (int)round(res1) << " seconds with r = " << setprecision(2) << mid2 << "km and k = " << (kilo - mid2) << "km.\n";
}

int main(void)
{
	while(cin >> kilo)
	{	
		cin >> runners;
		speeds.clear();
		for(long long int i = 0 ; i < runners ; i++)
		{
			cin >> runningS >> cyclingS;
			speeds.push_back(make_pair(runningS, cyclingS));
		}
		ternary();
	}
}