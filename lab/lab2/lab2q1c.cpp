#include <iostream>
#include <iomanip>
using namespace std;

double KE, m, v;
void kineticEnergy(double& KE, double& mass, double& velocity){
        KE = 0.5 * mass * (velocity * velocity);
}

int main(){
        cout << "Enter an objects mass and velocity as required..." << endl << endl;

        cout << "Mass in KG: ";
        cin >> m;
        cout << "Velocity in meters per second: ";
        cin >> v;

        kineticEnergy (KE, m, v);
        cout << endl << "The Kinetic Energy of the object is " << fixed << setprecision(2) << KE << " joules" << endl;

        return 0;
}
