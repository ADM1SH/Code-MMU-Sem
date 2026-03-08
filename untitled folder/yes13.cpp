#include <iostream>
using namespace std;

int main() {
    // Declare your variables
    string name;
    int age;
    float cgpa;

    // Ask for input
    cout << "Enter your name: ";
    getline(cin, name); // allows spaces

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your CGPA: ";
    cin >> cgpa;

    // Display the results
    cout << "\n=== Student Profile ===" << endl;
    cout << "Name : " << name << endl;
    cout << "Age  : " << age << endl;
    cout << "CGPA : " << cgpa << endl;

    return 0;
}
