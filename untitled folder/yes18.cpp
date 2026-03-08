#include <iostream>
using namespace std;

class TestClass{
	private:
		int val;
		void showVal(){cout << val << endl;}
	public:
		void setData(int x){val = x;}
};

int main(){
	TestClass test;
	test.setData(77);
	test.showVal();

	return 0;
}
