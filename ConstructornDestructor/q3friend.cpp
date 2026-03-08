#include <iostream>
using namespace std;

class BoxOperations;

class Box {
private:
    int length, width, height;
public:
    friend class BoxOperations;

    void setDimensions(int l, int w, int h) {
        length = l;
        width = w;
        height = h;
    }
};

class BoxOperations {
public:
    void calculateVolume(Box box) {
        int volume = box.length * box.width * box.height;
        cout << "Volume of the box: " << volume << endl;
    }
};

int main() {
    Box myBox;
    BoxOperations operations;
    
    int l, w, h;
    
    cout << "Enter length of the box: ";
    cin >> l;
    cout << "Enter width of the box: ";
    cin >> w;
    cout << "Enter height of the box: ";
    cin >> h;
    
    myBox.setDimensions(l, w, h);
    operations.calculateVolume(myBox);
    
    return 0;
}
