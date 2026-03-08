#include <iostream>
using namespace std;

//Function prototype
void increment(int *x);

int main(){
    int num;
    cout << "Enter an int: "; 
    cin >> num;
    increment(&num);
    cout << num << endl;

    return 0;
}

void increment(int *x){(*x)++;}