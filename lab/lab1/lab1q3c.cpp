#include <iostream>
#include <iomanip>
using namespace std;

int c;
float sum;
float average(){return sum / c;}

int main(){
	cout << "How many days would you like to record the tempereture? : ";
	cin >> c;

	for(int i = 0; i < c; i++){
		cout << "Enter the temperature for day " << (i + 1) << ": ";
		float temp; cin >> temp;
		sum += temp;
	}

	cout << endl << "The average temperature is: " << fixed << setprecision(2) << average() << " Celcius" << endl;


	return 0;
}
