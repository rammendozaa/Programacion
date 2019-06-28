/* AC */
#include <iostream>
#include <unordered_map>
#include <vector> 
using namespace std;

vector <long long int> daysPass(13, 0);
unordered_map <long long int, long long int> dayMonths;

bool isLeap(long long int year){
	return (year % 4 == 0) ? (year % 100 == 0) ? (year % 400 == 0) ? true : false : true : false;
}

long long int daysLeft(long long int day, long long int month, long long int year){
	long long int left = (isLeap(year)) ? 366 : 365;
	vector <long long int> monthAcc = daysPass;
	if(isLeap(year))
		for(long long int i = 2 ; i <= 12 ; i++)
			monthAcc[i]++;
	return left - (monthAcc[month - 1] + day);

}

//these are gonna be 1/1/yyyy
void findDate(long long int day, long long int month, long long int year, long long int n){
	vector <long long int> monthAcc = daysPass;
		if(isLeap(year))
			for(long long int i = 2 ; i <= 12 ; i++)
				monthAcc[i]++;
		long long int i = 1;
		while(monthAcc[i] < n){
			i++;
		}
		cout << (((n - monthAcc[i - 1]) == 0) ? 1 : n - monthAcc[i - 1]) << " " << i << " " << year << "\n";
}

void findDateOtro(long long int day, long long int month, long long int year, long long int n){
	vector <long long int> monthAcc = daysPass;
	if(isLeap(year))
		dayMonths[2] = 29;
	else
		dayMonths[2] = 28; 
	long long int daysLeftMonth = dayMonths[month] - day;
	//cout << day << " " << month << " " << year << " " << month << " 2 " << daysLeftMonth << " \t|\t";
	if(daysLeftMonth > n) 	
		cout << day + n << " " << month << " " << year << "\n";
	else if(daysLeftMonth == n)
		cout << dayMonths[month] << " " << month << " " << year << "\n";
	else{
		n -= daysLeftMonth;
		month++;
		while(n > dayMonths[month]){
			n -= dayMonths[month];
			month++;
		}
		cout << n << " " << month << " " << year << "\n";
	} 
}	

int main(void){
	dayMonths[1] = 31;
	dayMonths[2] = 28;
	dayMonths[3] = 31;
	dayMonths[4] = 30;
	dayMonths[5] = 31;
	dayMonths[6] = 30;
	dayMonths[7] = 31;
	dayMonths[8] = 31;
	dayMonths[9] = 30;
	dayMonths[10] = 31;
	dayMonths[11] = 30;
	dayMonths[12] = 31;
	daysPass[0] = 0;
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	for(long long int i = 1 ; i <= 12 ; i++)
		daysPass[i] = (daysPass[i - 1] + dayMonths[i]);
	long long int n, day, month, year, remDays;
	while(cin >> n >> day >> month >> year && (n != 0 || day != 0 || month != 0 || year != 0)){
		remDays = daysLeft(day, month, year);
		if(n == 0)
			cout << day << " " << month << " " << year << "\n";
		else{
			if(n > remDays){
				day = 1;
				month = 1;
				n -= remDays;
				year++;
				long long int leftDays = (isLeap(year)) ? 366 : 365;
				while(n > leftDays){
					n -= (isLeap(year)) ? 366 : 365;
					year++;
					leftDays = (isLeap(year)) ? 366 : 365; 
				} 
				findDate(1, 1, year, n);
			}
			else
				findDateOtro(day, month, year, n);
		}
	}
}