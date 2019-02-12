/* Accepted */
#include <bits/stdc++.h>
using namespace std;
using comp = complex<double>;
using lli = long long int;
const double PI = acos(-1.0);

long long int nearestPowerOfTwo(long long int n){
	long long int ans = 1;
	while(ans < n) ans <<= 1;
	return ans;
}

void fft(vector<comp> & X, int inv){
	int n = X.size();
	for(int i = 1, j = 0; i < n - 1; ++i){
		for(int k = n >> 1; (j ^= k) < k; k >>= 1);
		if(i < j) swap(X[i], X[j]);
	}
	for(int k = 1; k < n; k <<= 1){
		//wk is a 2k-th root of unity
		comp wk = polar(1.0, PI / k * inv);
		for(int i = 0; i < n; i += k << 1){
			comp w(1);
			for(int j = 0; j < k; ++j, w = w * wk){
				comp t = X[i + j + k] * w;
				X[i + j + k] = X[i + j] - t;
				X[i + j] += t;
			}
		}
	}
	if(inv == -1)
		for(int i = 0; i < n; ++i)
			X[i] /= n;
}

void multiply(vector <comp> &A, vector <comp> &B)
{
	int degree = nearestPowerOfTwo(max(A.size(), B.size())) << 1;
	A.resize(degree);
	B.resize(degree);
	fft(A, 1);
	fft(B, 1);
	for(int i = 0 ; i < degree ; i++)
		A[i] *= B[i];
	fft(A, -1);
}

int main(void)
{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
    string cadena;
    cin >> cadena;
    vector <comp> A, B;
    for(auto a : cadena)
    {
      if(a == 'A')
      {
        A.push_back(1);
        B.push_back(0);
      }
      else
      {
        A.push_back(0);
        B.push_back(1);
      }
    }
		if(cadena.length() == 1)
			cout << 0 << "\n";
		else if(cadena.length() == 2 && cadena == "AB")
			cout << 0 << "\n";
		else if(cadena.length() == 2 && cadena == "BA")
			cout << 1 << "\n";
		else
		{
			reverse(A.begin(), A.end());
			multiply(B, A);
			for(int i = cadena.length() - 2  ; i >= 0 ; i--)
			{
				if(B[i].real() - 0 < 1e-3)
					cout << 0 << "\n";
				else
					cout << B[i].real() << "\n";
			}
		}
}
