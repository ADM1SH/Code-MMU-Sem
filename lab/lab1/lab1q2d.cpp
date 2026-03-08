#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	float total, finTotal;

	cout << "Welcome to Yummy Ice-Cream" << endl << endl;

	cout << "**********Ice-Cream Flavor**********" << endl;
	float C = 3.5; cout << "[C] Chocolate" << endl;
	float V = 3.0; cout << "[V] Vanilla" << endl;
	float S = 2.5; cout << "[S] Strawberry" << endl << endl;

	cout << "Enter Name       : ";
	string name; getline(cin, name);

	char loop = 'y'; do{
		cout << "Enter Flavour    : ";
		char choice; cin >> choice;
		choice = tolower(choice);

		while(choice != 'c' && choice != 'v' && choice != 's'){
			cout << "input is invalid please enter only c, v or s: ";
			cin >> choice;
			choice = tolower(choice);
		}

		int qty; cout << "Enter Quantity   : ";
		cin >> qty;

		switch(choice){
			case 'c':
				total = qty * C;
				break;
			case 'v':
				total = qty * V;
				break;
			case 's':
				total = qty * S;
				break;
		}

		cout << "Do you want to buy more? Y/N : ";
		cin >> loop;
		finTotal += total;

		loop = tolower(loop);
	}while (loop == 'y');

	cout << endl << "**********RECEIPT**********" << endl;
	cout << "Name         : " << name << endl;
	cout << "Total Price  : " << finTotal << setprecision(2) << endl;

	return 0;
}







