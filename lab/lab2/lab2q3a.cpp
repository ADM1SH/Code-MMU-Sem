#include <iostream>
#include <iomanip>
using namespace std;

int total;
float grade(){return total / 5;}

int main(){
	string name;
	int marks[5];

	cout << "Enter Name: ";
	getline(cin, name);

	for (int i = 0; i < 5; i++){
		cout << "Enter Marks: ";
		cin >> marks[i];
		total += marks[i];
	}

	cout << "Name    : " << name << endl;
	cout << "Average : " << fixed << setprecision(2) << grade() << endl;

	if (grade() >= 80){
		cout << "Grade   : A" << endl;
	} else if (grade() >= 60){
			cout << "Grade   : B" << endl;
		}else if (grade() >= 50){
				cout << "Grade   : C" << endl;
			}else {cout << "Grade   : F" << endl;}

	return 0;
}
