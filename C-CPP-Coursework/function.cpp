#include <iostream>
using namespace std;

void findMax(int &maxVal) {
    int num;
    maxVal = INT_MIN; // Initialize to the smallest possible int
    for (int i = 0; i < 3; ++i) {
        cout << "Enter a number: ";
        cin >> num;
        if (num > maxVal) {
            maxVal = num;
        }
    }
}

int main() {
    int result;
    findMax(result);
    cout << "The largest value is: " << result << endl;
    return 0;
}
