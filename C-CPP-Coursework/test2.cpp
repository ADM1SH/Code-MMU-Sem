#include <iostream>
using namespace std;

void setToZero(int &x);

int main(){
    int num = 99;

    setToZero(num);

    return 0;
}

void setToZero(int &x){
    x = 0; 
    cout << x << endl;
}