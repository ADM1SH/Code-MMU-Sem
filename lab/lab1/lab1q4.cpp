#include <iostream>
#include <iomanip>
using namespace std;

int c;
float total, score;
float average(){return total / c;}

int main(){
	cout << "How many test scores do you want to enter? : ";
	cin >> c;

	float arr[c];
	float* prt = arr;
	for(int i = 0; i < c; i++){
		cout << "Enter test score " << (i + 1) << ": ";
		cin >> *(prt + i);
		total += *(prt + i);
	}

	//Bubble sort in Accending order
	for(int i = 0; i < c - 1; i++){
		for(int j = 0; j < c - i - 1; j++){
			if (*(prt + j) > *(prt + j + 1)){
				float temp = *(prt + j);
				*(prt + j) = *(prt + j + 1);
				*(prt + j + 1) = temp;
			}
		}
	}

	cout << endl << "The test score in ascending orfer, and teir average, are:" << endl << endl;
	cout << "\t score" << endl;
	cout << "\t -----" << endl << endl;
	for(int i = 0; i < c; i++){
		cout << "\t " << fixed << setprecision(2) << *(prt + i) << endl;
	}

	cout << endl << "Average score: " << fixed << setprecision(2) << average() << endl;

return 0;
}
