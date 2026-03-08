#include <iostream>
using namespace std;

class Cube{
    private:
        int width, length, height;
    public:
        // Mutator
        void setWidth(const int& newWidth){width = newWidth;}
        void setLength(const int& newLength){length = newLength;}
        void setHeight(const int& newHeight){height = newHeight;}

        //Accessor
        int getWidth() const{return width;}
        int getLength() const{return length;}
        int getHeight() const {return height;}

        int calcVolume() const{return width * length * height;}
};

int main() {
    Cube c1, c2;

    c1.setWidth(20); c1.setLength(30); c1.setHeight(50);
    cout << "Volume cube 1: " << c1.calcVolume() << endl;

    c2.setWidth(4); c2.setLength(6); c2.setHeight(10);
    cout << "Volume cube 2: " << c2.calcVolume() << endl;

    return 0;
}