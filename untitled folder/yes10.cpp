#include<iostream>
using namespace std;
class Rectangle
{  
	private: 
		int width, length; 

	public:
		void setvalues (int m, int n)
		{	width = m;  length = n; }

		int calcArea()
		{	return width*length; }
} ;

int main()
{
	Rectangle M[3];	
    int i  = 0;	
    while( i < 3 )
	{ 
		M[i].setvalues(i+3,i+2);
		cout<<M[i].calcArea()<<endl;		
        i++;
	}
}