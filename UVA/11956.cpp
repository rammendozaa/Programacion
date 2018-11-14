#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main(void)
{
	int cases, caso = 0;
	string auxS;
	cin >> cases;
	while(cases--)
	{
		cin >> auxS;
		vector <int> numeros(100, 0);
		int pos = 0;
		for(int i = 0 ; i < auxS.length() ; i++)
		{
			if(auxS[i] == '<')
			{
				if(pos == 0)
					pos = 99;
				else
					pos -= 1;
			}
			else if(auxS[i] == '>')
			{
				if(pos == 99)
					pos = 0;
				else
					pos += 1;
			}

			else if(auxS[i] == '+')
            {
                if(numeros[pos] == 255)
                    numeros[pos] = 0;
                else
                    numeros[pos] += 1;
            }
			else if(auxS[i] == '-')
            {
                if(numeros[pos] == 0)
                    numeros[pos] = 255;
                else
                    numeros[pos] -= 1;
            }
        }
        cout << "Case " << dec << ++caso << ":";
        for(auto a : numeros)
            cout << " " <<  setfill('0') << setw(2) << uppercase << hex << a;
        cout << "\n";
	}
	return 0;
}
