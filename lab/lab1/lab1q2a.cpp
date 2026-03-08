#include <iostream>
using namespace std;

int main(){
	int i, numbers[10], even, odd, total = 0;

	for(i = 0; i < 10; i++){
		cout << "Enter 10 integers";
		cin >> numbers[i];
		total += numbers[i];

		if(numbers[i] %2 == 0){
			even ++;
		} else {odd ++;}
	}

	cout << "There are " << even << " even numbers and " << odd << " odd numbers" << endl;
	cout << "The total of all the 10 integers are " << total << endl;

}


