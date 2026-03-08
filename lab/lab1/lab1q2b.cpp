#include <iostream>
using namespace std;

int main() {
    int number;
    int total = 0;

    do {
        cout << "Enter a number: ";
        cin >> number;

        if (number != 99) {
            total += number;
        }
    } while (number != 99);

    cout << "The total is " << total << endl;

    return 0;
}
