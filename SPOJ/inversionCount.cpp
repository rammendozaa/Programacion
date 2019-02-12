/* Accepted */
#include <iostream>
#include <vector>
using namespace std;
vector <long long int> numeros(200003);
long long int contador = 0;

void merge(long long int ini, long long int mid, long long int fin)
{
	long long int k = 0, izq = ini, iniDer = mid + 1;
	vector <long long int> auxArreglo(fin - ini + 10);
	while(ini <= mid && iniDer <= fin)
	{
		if(numeros[ini] <= numeros[iniDer])
		{
			auxArreglo[k] = numeros[ini];
			ini++;
		}
		else
		{
			contador += (mid - ini + 1);
			auxArreglo[k] = numeros[iniDer];
			iniDer++;
		}
		k++;
	}
	while(ini <= mid)
	{
		auxArreglo[k] = numeros[ini];
		ini++;
		k++;
	}
	while(iniDer <= fin)
	{
		auxArreglo[k] = numeros[iniDer];
		iniDer++;
		k++;
	}
	for(long long int i = 0 ; i < k ; i++)
		numeros[izq + i] = auxArreglo[i];

}

void mergeSort(long long int ini, long long int fin)
{
	if(ini < fin)
	{
		long long int mid = (fin + ini) >> 1;
		mergeSort(ini, mid);
		mergeSort(mid + 1, fin);
		merge(ini, mid, fin);
	}
}



int main(void)
{
	ios::sync_with_stdio(false);
	int cases;
	cin >> cases;
	while(cases--)
	{
		contador = 0;
		long long int auxI, nums;
		numeros.clear();
		cin >> nums;
		for(int i = 0 ; i < nums ; i++)
		{
			cin >> auxI;
			numeros.push_back(auxI);
		}
		mergeSort(0, nums - 1);
		cout << contador << "\n";
	}
	return 0;
}
