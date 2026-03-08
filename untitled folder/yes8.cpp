#include <iostream>
using namespace std;

class cube{
    private:
        int width, length, height;
    public:
        void setWidth(int w){
            width = w;
        }
        void setLength(int l){
            length = l;
        }
        void setHeight(int h){
            height = h;
        }

        int getWidth(){
            return width;
        }
        int getLength(){
            return length;
        }
        int getHeight(){
            return height;
        }

        int calcVolume(){
            return width * length * height;
        }
};

int main(){
    cube c1, c2;

    c1.setWidth(20);
    c1.setLength(30);
    c1.setHeight(50);

    c2.setWidth(4);
    c2.setLength(6);
    c2.setHeight(10);

    cout << "For Cube 1:\n";
    cout << "Width   : " << c1.getWidth() << endl;
    cout << "Length  : " << c1.getLength() << endl;
    cout << "Height  : " << c1.getHeight() << endl;
    cout << "The volume of Cube 1 is: " << c1.calcVolume() << endl << endl;

    cout << "For Cube 2:\n";
    cout << "Width   : " << c2.getWidth() << endl;
    cout << "Length  : " << c2.getLength() << endl;
    cout << "Height  : " << c2.getHeight() << endl;
    cout << "The volume of Cube 2 is: " << c2.calcVolume() << endl << endl;


    return 0;
}
