#include <iostream>
using namespace std;

float average(float a, float b, float c);

int main(){
    float sum;
    double a, b, c;

    cout << "Enter 3 int: " << endl;
    cin >> a; cin >> b; cin >> c;

    sum = average(a, b, c);
    cout << sum << endl;
}

float average(float a, float b, float c){return ((a + b +c) / 3);}
