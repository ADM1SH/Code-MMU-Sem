#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	float day1, day2, total = 0;

	cout << "Enter number of sales for day 1: ";
	cin >> day1;
	cout << "Enter number of sales for day 2: ";
	cin >> day2;

	total = day1 + day2;

	cout << "\nQTech Snd Bhd Sales figure for 2 days" << endl;
	cout << "Day 1: " << day1 << "\nDay2: " << day2 << endl << "Total: " << total << endl;

	return 0;
}
