#include <iostream>
using namespace std;

void shift(int a, int &b){
	a += 20;
	b += 10;
}

int main(){
	int first = 10, second = 20;
	shift(first, second);
	cout << first << " " << second << endl;

	return 0;
}
