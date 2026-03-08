#include <iostream>
using namespace std;

int main(){
	int num, i, total = 0;

	while (i != 99){
		cout << "Enter a number: ";
		cin >> i;
		i = num;
		total += num;
	}

	cout << "The Total is: " << total - 99 << endl;

	return 0;
}

