#include <iostream>
using namespace std;

int main(){
	int subject, num;
	float total_payment, average_payment;
	float *fees;

	cout << "How many subjects you have registered: ";
	cin >> subject;

	fees = new float[subject]; //create a new dynamic array
	total_payment = 0.0;
	for (num = 0; num < subject; num++){
		cout << "Class " << num + 1 << " fees charge: ";
		cin >> fees[num]; // cin >> *(fees + i);
		total_payment += fees[num];
	}

	average_payment = total_payment / subject;

	cout << endl << "==========PAYMENT DETAILS===========" << endl;
	cout << "Fees charges : ";
	for(num = 0; num < subject; num++){cout << fees[num] << "(RM)...";}
	cout << endl << "Total Payment : RM " << total_payment;
	cout << endl << "Average Payment : RM " << average_payment << endl;
	delete [] fees;

	return 0;
}
