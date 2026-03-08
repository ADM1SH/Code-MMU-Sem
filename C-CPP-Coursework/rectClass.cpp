#include <iostream>
using namespace std;

class Rectangle {
private:
    int width, length;
public:
    void setvalues(int w, int l) { width = w; length = l; }
    int calcArea() { return width * length; }
};

int main() {
    Rectangle r;
    r.setvalues(10, 11);
    cout << "Area: " << r.calcArea() << endl;
    return 0;
}


