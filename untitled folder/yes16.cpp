#include <iostream>
using namespace std;

int main(){
	int num;
	int total = 0;

	cout << "Enter a number from 1 to 10: ";
	cin >> num;

	switch(num){
		case 1:
		case 2: total =5;
		case 3: total =10;
		case 4: total = total + 3;
		case 8: total = total + 6;
		default: total = total + 4;
	}

	cout << total << endl;
	return 0;
}
