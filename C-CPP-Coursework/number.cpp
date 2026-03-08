#include <iostream>
using namespace std;

class Number{
    private:
        int N1, N2;
    public:
        //Mutator
        void setN1(const int& newN1){N1 = newN1;}
        void setN2(const int& newN2){N2 = newN2;}

        //Accessor
        int getN1() const{return N1;}
        int getN2() const{return N2;}

        void setdata(int a, int b) { N1 = a; N2 = b; }

};

int main(){
    Number n;

    n.setN1(5); n.setN2(12);
    cout << "N1 = " << n.getN1() << endl << "N2 = " << n.getN2() << endl;

    n.setdata(11, 11);
    cout<< endl << "N1 = " << n.getN1() << endl << "N2 = " << n.getN2() << endl;

    return 0;
}