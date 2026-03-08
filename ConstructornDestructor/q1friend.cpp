#include <iostream>
using namespace std;

class ClassA{
private:
    int dataA;
public:
    ClassA(int value) : dataA(value) {}

    friend void showData(ClassA obj);
};

void showData(ClassA obj) {
    cout << "DataA: " << obj.dataA << endl;
}

int main() {
    ClassA obj(42);
    showData(obj);
    return 0;
}
