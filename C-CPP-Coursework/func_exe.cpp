#include <iostream>
using namespace std;

//Function prototype
int multiply(int a, int b);

int main(){
    int result;
    result = multiply(4, 7);
    cout << result << endl;

    return 0;
}

int multiply(int a, int b){return a * b;}