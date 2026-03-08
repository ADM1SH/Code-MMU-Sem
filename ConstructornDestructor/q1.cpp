#include <iostream>
#include <string>
using namespace std;

class Book{
	string title_;
	public:
		Book(string title) : title_(title){
			cout << "Book: " << title_ << " created." << endl;
		}
		~Book(){
			cout << "Book: " << title_ << " destroyed." << endl;
		}
};

int main(){
	Book book1("1984");
	Book book2("Brave New World");

	return 0;
}

/* OUTPUT:
Book: 1984 created.
Book: Brave New World created.
Book: Brave New World destroyed.
Book: 1984 destroyed.
*/
