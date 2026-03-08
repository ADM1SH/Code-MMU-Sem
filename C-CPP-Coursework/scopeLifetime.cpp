//What will be printed by the following code? Explain why.
#include <iostream>
using namespace std;

void test() {
    static int count = 0;
    count++;
    cout << count << " ";
}

int main() {
    for(int i = 0; i < 3; i++) {
        test();
    }
    return 0;
}

/*
    output: 1 2 3. The output is 1 2 3 because of how the static variable count behaves in the test() function.
*/ 