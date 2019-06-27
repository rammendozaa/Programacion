/*
vector <int> accDays(13, 0);
unordered_map <int, int> monthDays;
unordered_set <int> leapYears;

bool isLeap(int year){
	return (year % 4 == 0) ? (year % 100 == 0) ? (year % 400 == 0) ? true : false : true : false;
}

int remDaysYear(int day, int month, int year){
	int remDay = 365;
	if(isLeap(year))
		remDay = 366;
	remDay -= (accDays[month - 1] + day);
}

int remDaysMonth(int day, int month, int year){
	int remDay = monthDays[month];
	if(isLeap(year) && month == 2)
		remDay++;
	return remDay - day;
}

int main(void){
	int n, day, month, year;
	monthDays[1] = 31; 
	monthDays[2] = 28; 
	monthDays[3] = 31; 
	monthDays[4] = 30; 
	monthDays[5] = 31; 
	monthDays[6] = 30; 
	monthDays[7] = 31; 
	monthDays[8] = 31; 
	monthDays[9] = 30; 
	monthDays[10] = 31; 
	monthDays[11] = 30; 
	monthDays[12] = 31; 
	accDays[0] = 0;
	for(int i = 1 ; i <= 12 ; i++)
		accDays[i] = (monthDays[i] + accDays[i - 1]); 
	while(cin >> n >> day >> month >> year && (n != 0 && day != 0 && month != 0 && year != 0)){



	}
	return 0;
}
*/

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
	long long int daysLeftMonth = dayMonths[month] - day;
	cout << dayMonths[month] << "  |  ";
	if(daysLeftMonth > n) 	
		cout << day + n << " " << month << " " << year << "\n";
	else if(daysLeftMonth == n)
		cout << 1 << " " << month + 1 << " " << year << "\n";
	else{
		cout << day << " " << month << " " << year << " \t||\t" << daysLeftMonth << "\t|\t" << n << "\t|\t";
		n -= daysLeftMonth;
		month++;
		while(n >= dayMonths[month]){
			n -= dayMonths[month];
			month++;
		}
		cout << n << " " << month << " " << year << "\n";
		/*
		n -= daysLeftMonth;
		month++;
		day = 1;
		cout << day << " " << month << " " << year << " \t||\t" << daysLeftMonth << "\t|\t" << n << "\t|\t";
		while(n > dayMonths[month]){
			n -= dayMonths[month];
			month++;
		}
		cout << ((n == 0) ? 1 : day + n) << " " << month << " " << year << "\n";
		*/
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