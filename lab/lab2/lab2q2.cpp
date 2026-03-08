#include <iostream>
using namespace std;

void get_a_b_c(double& a, double& b, double& c){
	cout << "Enter a, b and c ";
	cin >> a >> b >> c;
}

double bb_4ac(){
	double a, b, c;
	get_a_b_c(a, b, c);
	return b*b - 4 * a * c;
}

int main(){
	double discriminent = bb_4ac();
	cout << "The discriminant is " << discriminent << endl;

	return 0;
}
