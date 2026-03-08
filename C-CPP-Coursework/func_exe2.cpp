#include <iostream>
using namespace std;

/*
    the diffrence between call by value and call by refrence is:
    -call by value is the function gets a copy. changes inside the function dosent effect the original variable
    -call by refrence gets access to the original variable. changes inside the function do affect the original
*/

//Function prototype
void swap(int &x, int &y);

int main(){
    int a = 1, b = 9;
    swap(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}