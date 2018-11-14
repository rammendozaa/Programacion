/* Accepted */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <long long int> people;

long long int divis(long long int number)
{
	long long int sum = 0;
	for(auto a : people)
		sum += floor(number / a);
	return sum;
}


long long int binary(long long int valor, long long int izq, long long int der)
{
	long long int mid = ceil(izq + (der - izq) / 2);
	if(izq > der)
		return mid;
	if(divis(mid) < valor)
		binary(valor, mid + 1 , der);
	else
		binary(valor, izq, mid - 1);
}


/*
long long int binary(long long int valor)
{
	long long int ini = 1, fin = 1000000000, res = -1, mid;
	while(ini <= fin)
	{
		mid = ini + ((fin - ini) / 2);
		if(divis(mid) < valor)
		{
				ini = mid + 1;
				//res = mid;
		}
		else
		{
			fin = mid - 1;
			res = mid;
		}
	}
	//if res in if
	//return res + 1;
	return res;

}
*/
void merge(long long int ini, long long int mid, long long int fin)
{
	long long int i, j, k;
	long long int tam1 = mid - ini + 1;
	long long int tam2 = fin - mid;

	vector <long long int> izq(tam1);
	vector <long long int> der(tam2);
	for(i = 0 ; i < tam1 ; i++)
		izq[i] = people[ini + i];
	for(j = 0 ; j < tam2 ; j++)
		der[j]  = people[mid + 1 + j];
	i = 0;
	j = 0;
	k = ini;
	while(i < tam1 && j < tam2)
	{
		if(izq[i] <= der[j])
		{
			people[k] = izq[i];
			i++;
		}
		else
		{
			people[k] = der[j];
			j++;
		}
		k++;
	}
	while(i < tam1)
	{
		people[k] = izq[i];
		i++;
		k++;
	}
	while(j < tam2)
	{
		people[k] = der[j];
		k++;
		j++;
	}

}

void mergeSort(long long int ini, long long int fin)
{
	if(ini < fin)
	{
		long long int mid = (fin + ini) / 2;
		mergeSort(ini, mid);
		mergeSort(mid + 1, fin);
		merge(ini, mid, fin);
	}
}


int main(void)
{
	long long int peeps, value, aux, final;
	cin >> peeps >> value;
	for(int i = 0 ; i < peeps ; i++)
	{
		cin >> aux;
		people.push_back(aux);
	}
		mergeSort(0, people.size() - 1);
		cout << binary(value, 0, 1000000000000000000) << "\n";
	return 0;
}
