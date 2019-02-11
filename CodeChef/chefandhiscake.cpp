/* Accepted */
#include <iostream>
using namespace std;

int main(void)
{
	long long int cases;
	cin >> cases;
	while(cases--)
	{
		long long int x, y, arr;
		char input, g = 'G', r = 'R';
		cin >> x >> y;
		arr = x * y;
		bool er = true;
		char entrada[x][y], ge[x][y], erre[x][y];
		for(long long int i = 0 ; i < x ; i++)
		{
			for(long long int j = 0 ; j < y ; j++)
			{
				cin>>entrada[i][j];
				if(er)
				{
					ge[i][j] = g;
					erre[i][j] = r;
					er = !er;
				}
				else
				{
					ge[i][j] = r;
					erre[i][j] = g;
					er = !er;
				}
			}
			if(y % 2 == 0)
				er = !er;
		}
		long long int cambiosR1 = 0, cambiosG1 = 0, cambiosR2 = 0,
		 cambiosG2 = 0, total1, total2;
		for(long long int i = 0 ; i < x ; i++)
		{
			for(long long int j = 0 ; j < y ; j++)
			{
				if(entrada[i][j] == 'R' && ge[i][j] == 'G')
				{
					cambiosR1++;
				}
				else if(entrada[i][j] == 'G' && ge[i][j] == 'R')
				{
					cambiosG1++;
				}
			}
		}
		for(long long int i = 0 ; i < x ; i++)
		{
			for(long long int j = 0 ; j < y ; j++)
			{
				if(entrada[i][j] == 'R' && erre[i][j] == 'G')
				{
					cambiosR2++;
				}
				else if(entrada[i][j] == 'G' && erre[i][j] == 'R')
				{
					cambiosG2++;
				}
			}
		}
		total1 = (cambiosR1 * 5) + (cambiosG1 * 3);
		total2 = (cambiosR2 * 5) + (cambiosG2 * 3);
		long long int res = min(total1, total2);
		cout << res << "\n";
		//cout << total1 << " " << total2 << "\n";
	}
}
