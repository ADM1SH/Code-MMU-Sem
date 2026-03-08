#include <iostream>
using namespace std;

class ClassB;

class ClassA
{
private:
    int data;
public:
    ClassA(int value) : data(value) {}

    friend class ClassB;
};

class ClassB {
public:
    void Display(ClassA obj) {
        cout << "Data from ClassA: " << obj.data << endl;
    }
};

int main() {
    ClassA a(100);
    ClassB b;
    b.Display(a);
    return 0;
}
