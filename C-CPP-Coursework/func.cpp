#include <iostream>
using namespace std;

//Function prototype
double divide(double a, double b);

int main(){
    float sum;
    double a = 10.0, b = 2.5;
    sum = divide(a, b);
    cout << sum << endl;
    
}

double divide(double a, double b){
    return a / b;
}