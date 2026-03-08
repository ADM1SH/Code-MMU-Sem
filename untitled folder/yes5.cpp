#include <iostream>
using namespace std;

void displaySquare(int num) {
    int square = num * num;
    cout << "The square of " << num << " is " << square << endl;
}

int main() {
    displaySquare(7);
    return 0;
}
