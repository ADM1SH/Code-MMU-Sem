#include <iostream>
using namespace std;

class CD{
	public:
		int one;

		CD(int two){
			cout << "\nA constructor is called." << endl;
			one=two;
		}
		CD(){
			cout << "\nA default constructor is called." << endl;
		}
		~CD(){
			cout << "\nDestruction " << one << endl;
		}
		int add(){
			return(one+one);
		}
};

int main(){
	CD myobj1(4);
	CD myobj2;

	cout << "\nThe Value in Object1 is :: " << myobj1.one << endl;
	cout << "\nEnter a Number :: ";
	cin >> myobj2.one;
	cout << myobj2.add() << endl;

	return(0);
}

/* OUTPUT:
A constructor is called.

A default constructor is called.

The Value in Object1 is :: 4

Enter a Number :: 2
4

Destruction 2

Destruction 4

*/
