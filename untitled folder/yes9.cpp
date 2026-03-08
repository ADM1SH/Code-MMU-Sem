#include <iostream>
using namespace std;

class Numbers {
private:
    int n1, n2;
public:
    void setdata(int m, int n);
    void display();
};

// Function definitions outside the class
void Numbers::setdata(int m, int n) {
    n1 = m;
    n2 = n;
}

void Numbers::display() {
    cout << n1 << " " << n2 << endl;
}