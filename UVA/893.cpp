/* WA */
#include <iostream>
#include <map>
using namespace std;

long long remaining, day, month, year, originalyear;
map <int, int> an;

bool isLeap(int year)
{
	if(year % 4 == 0)
		if(year % 100 == 0)
			if(year % 400 == 0)
				return true;
			else
				return false;
		else
			return true;
	else
		return false;

}


int sumDays()
{
	int sum = 0;
	for(int i = 1 ; i <= 12 ; i++)
	{
		if(i == month)
		{
			sum += day;
			return sum;
		}
		if(i == 2 && isLeap(year))
			sum += an[i] + 1;
		else
			sum += an[i];
	}
	return sum;
}

int daysNY()
{
	if(!isLeap(year))
		return 365 - sumDays();
	else
		return 366 - sumDays();
}

int findYear()
{
	int anio = year;
	if(remaining >= daysNY())
	{
		remaining -= daysNY();
		anio++;
	}
	while(remaining >= (isLeap(anio) ? 366 : 365))
	{
		remaining -= (isLeap(anio) ? 366 : 365);
		anio++;
		if(remaining == (isLeap(anio) ? 366 : 365))
			break;
	}
	year = anio;
	return year;
}

int findMonth(int y)
{
	int i = (y == originalyear) ? month : 1;
	remaining = (y == originalyear) ? remaining + 1 : remaining;
	while(i <= 12)
	{
		if(remaining <= ((isLeap(y) && i == 2) ? an[i] + 1 : an[i]))
			return i;
		if(isLeap(y) && i == 2)
		{
			remaining -= an[i] + 1;
		}
		else
			remaining -= an[i];
		i++;
	}
}

int findDay()
{
	return remaining;
}

int main(void)
{
	long dayN, monthN, yearN;
	an[1] = 31;
	an[2] = 28;
	an[3] = 31;
	an[4] = 30;
	an[5] = 31;
	an[6] = 30;
	an[7] = 31;
	an[8] = 31;
	an[9] = 30;
	an[10] = 31;
	an[11] = 30;
	an[12] = 31;
	while(cin >> remaining >> day >> month >> year && remaining != 0 && day != 0 && month != 0 && year != 0)
	{
		originalyear = year;
			yearN = findYear();
			monthN = findMonth(yearN);
			cout << findDay() << " " << monthN << " " << yearN << "\n";
	}
	return 0;
}
