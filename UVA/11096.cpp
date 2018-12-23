/* Accepted */
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
typedef double coord_t;         // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

struct Punto {
	coord_t x, y;

	bool operator <(const Punto &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};


double distance(Punto uno, Punto dos)
{
	return sqrt(((dos.x - uno.x) * (dos.x - uno.x)) + ((dos.y - uno.y) * (dos.y - uno.y)));
}


coord2_t cross(const Punto &O, const Punto &A, const Punto &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
//from Wikipedia https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain#C++
double convexHull(vector<Punto> P, int que)
{
	size_t n = P.size(), k = 0;
	if (n <= 3)
	{
		double distancia = 0;
		distancia += distance(P[0], P[P.size() - 1]);
		for(long long int i = 0 ; i < P.size() - 1; i++)
			distancia += distance(P[i], P[i + 1]);
		return distancia;
		//return P;
	}
	vector<Punto> H(2*n);

	sort(P.begin(), P.end());

	for (size_t i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	for (size_t i = n-1, t = k+1; i > 0; --i) {
		while (k >= t && cross(H[k-2], H[k-1], P[i-1]) <= 0) k--;
		H[k++] = P[i-1];
	}

	H.resize(k-1);
	double distancia = 0;
	distancia += distance(H[0], H[H.size() - 1]);
	for(long long int i = 0 ; i < H.size() - 1; i++)
		distancia += distance(H[i], H[i + 1]);
	return distancia;
}

int main()
{
	long long int cases;
	cin >> cases;
	while(cases--)
	{
		cout << fixed << setprecision(5);
		long long int nails;
		double longRubber;
		cin >> longRubber >> nails;
		if(nails == 0)
			cout << longRubber << "\n";
		else if(nails == 1)
		{
			Punto aux;
			cin >> aux.x >> aux.y;
			cout << longRubber << "\n";
		}
		else if(nails == 2)
		{
			Punto uno, dos;
			cin >> uno.x >> uno.y >> dos.x >> dos.y;
			if(2 * distance(uno, dos) > longRubber)
				cout << 2 * distance(uno, dos) << "\n";
			else
				cout << longRubber << "\n";
		}
		else
		{
			Punto aux;
			vector <Punto> clavos;
			double res;
			for(long long int i = 0 ; i < nails ; i++)
			{
				cin >> aux.x >> aux.y;
				clavos.push_back(aux);
			}
			res = convexHull(clavos, nails);
			if(res > longRubber)
				cout << res << "\n";
			else
				cout << longRubber << "\n";
		}
	}
	return 0;
}
