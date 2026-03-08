#include <iostream>
using namespace std;

int sum (int x, int y){
   return x + y;
}

int main() {
    int result = sum(5, 10);
    cout << "The result is: " << result << endl;
    return 0;
}
