/* Accepted */
#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

void findTDate(int tDays, unordered_map <int, string> &dNames){
	int tYear, tMonth, tDay, rDays;
	tYear = floor((double)tDays / (double)260);
	rDays = tDays % 260;
	tMonth = rDays % 13;
	rDays %= 20;
	cout << tMonth + 1 << " " << dNames[rDays] << " " << tYear << "\n";
}


int main(void){
	int cases;
	cin >> cases;
	unordered_map <string, int> hMonth;
	unordered_map <int, string> tDay;
	hMonth["pop"] = 0;
	hMonth["no"] = 1;
	hMonth["zip"] = 2;
	hMonth["zotz"] = 3;
	hMonth["tzec"] = 4;
	hMonth["xul"] = 5;
	hMonth["yoxkin"] = 6;
	hMonth["mol"] = 7;
	hMonth["chen"] = 8;
	hMonth["yax"] = 9;
	hMonth["zac"] = 10;
	hMonth["ceh"] = 11;
	hMonth["mac"] = 12;
	hMonth["kankin"] = 13;
	hMonth["muan"] = 14;
	hMonth["pax"] = 15;
	hMonth["koyab"] = 16;
	hMonth["cumhu"] = 17;
	hMonth["uayet"] = 18;
	tDay[0] = "imix";
	tDay[1] = "ik";
	tDay[2] = "akbal";
	tDay[3] = "kan";
	tDay[4] = "chicchan";
	tDay[5] = "cimi";
	tDay[6] = "manik";
	tDay[7] = "lamat";
	tDay[8] = "muluk";
	tDay[9] = "ok";
	tDay[10] = "chuen";
	tDay[11] = "eb";
	tDay[12] = "ben";
	tDay[13] = "ix";
	tDay[14] = "mem";
	tDay[15] = "cib";
	tDay[16] = "caban";
	tDay[17] = "eznab";
	tDay[18] = "canac";
	tDay[19] = "ahau";
	cout << cases << "\n";
	for(int i = 0 ; i < cases ; i++){
		int year;
		string day, month;
		cin >> day >> month >> year;
		int hDay, totalDays;
		hDay = stoi(day.substr(0, day.length() - 1));
		totalDays = (365 * year) + (hMonth[month] * 20) + hDay;
		findTDate(totalDays, tDay);
	}
	return 0;
}