#include <iostream>
using namespace std;

class rectangle{
    private:
        int width, length;

    public:
        void setvalues(int w, int l){
            width = w;
            length = l;
        }
        int calcArea() {
            return width * length;
        }
};

int main(){
    rectangle rect;
    rect.setvalues(5, 10);
    cout <<"Area of rectangle: " << rect.calcArea() << endl;

    return 0;
}