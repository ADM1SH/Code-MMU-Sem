#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	const int NUM_EMPS = 5;
	int index, hours[NUM_EMPS];
	double payRate[NUM_EMPS], grossPay[NUM_EMPS];

	cout << "Enter the hours worked and hourly pay rate of " << NUM_EMPS << " employees. \n";
	for(int i = 0; i < NUM_EMPS; i++){
		cout << "Hours worked for employee #" << (i + 1) << ": ";
		cin >> hours[i];
		cout << "Enter hourly pay rate for employe: ";
		cin >> payRate[i];
		grossPay[i] = hours[i] * payRate[i];
	}

	cout << endl << "Here is the gross pay for each employee" << endl;

	for(int i = 0; i < NUM_EMPS; i++){
		cout << "Employee #" << (i + 1) << ": RM " << grossPay[i] << setprecision(2) << endl;
	}

	return 0;
}
