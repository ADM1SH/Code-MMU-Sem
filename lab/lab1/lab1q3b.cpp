#include <iostream>
using namespace std;

int main(){
	int arr [2][3] = {
		{10, 20, 30},
		{40, 50, 60}
	};

	for (int i = 0; i < 2; i++){
		cout << "Row " << (i + 1) << ": ";
		for (int x = 0; x < 3; x++){
			cout << arr[0][x] << " ";
		}
		cout << endl;
	}

	return 0;
}
