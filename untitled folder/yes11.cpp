#include<iostream>
using namespace std;

class Qualification
{   
	public:
	string level, name;
};

class Person
{	string name; 
	Qualification Q;
	public:
		void setDetails()
		{ 
			cout<<"Please enter your name \t\t\t:";
			getline(cin, name);
			cout<<"Please enter your Qualification level\t:";
			cin>>Q.level;
			cin.ignore();
			cout<<"Please enter your Qualification name\t:";
			getline(cin, Q.name);
			cout<<endl;
		}
		void display()
		{ 
			cout<<"Your name \t\t:"<<name<<endl;
			cout<<"Qualification level\t:"<<Q.level<<endl;
			cout<<"Qualification name\t:"<<Q.name<<endl<<endl;
		}
};


int main() {
    Person persons[5];

    // Get user input using a for loop
    for (int i = 0; i < 5; i++) {
        cout << "Enter details for person " << i + 1 << ":" << endl;
        persons[i].setDetails();
    }

    // Display using a while loop
    int i = 0;
    while (i < 5) {
        cout << "Details of person " << i + 1 << ":" << endl;
        persons[i].display();
        i++;
    }

    return 0;
}