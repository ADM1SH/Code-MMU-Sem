#include <iostream>
#include <iomanip>
using namespace std;

float KE, m, v;
float kineticEnergy(float mass, float velocity){
	return 0.5 * mass * (velocity * velocity);
}

int main(){
	cout << "Enter an objects mass and velocity as required..." << endl << endl;

	cout << "Mass in KG: ";
	cin >> m;
	cout << "Velocity in meters per second: ";
	cin >> v;

	cout << endl << "The Kinetic Energy of the object is " << fixed << setprecision(2) << kineticEnergy(m, v) << " joules" << endl;
}
