#include <iostream>
using namespace std;

const int ITEM = 3;

class BeanBag {
private:
    string codeName;
    int stock[ITEM];

public:
    void latest_BeanBagStock() {
        cout << "--------------------------------------" << endl;
        cout << "#Current# Ready stocks Checking..." << endl;
        cout << "--------------------------------------" << endl;
        cout << "Code Tracing >>" << codeName << "<<" << endl;
        for (int i = 0; i < ITEM; ++i) {
            cout << "Group " << (i + 1) << " production: " << stock[i] << " item(s) ready" << endl;
        }
        cout << "------------------------------------------" << endl;
        cout << "Ready stocks for this Month" << endl;
        cout << "------------------------------------------" << endl;
        for (int i = ITEM - 1; i >= 0; --i) {
            cout << "Ready stock from group " << (i + 1) << ":" << stock[i] << endl;
        }
    }

    void beanBag_Details(int *arr) {
        cout << "#######################################" << endl;
        cout << "stocks Checking" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Enter Bean Bag Chair code: ";
        cin >> codeName;
        cout << "--------------------------------------" << endl;

        for (int i = 0; i < ITEM; ++i) {
            stock[i] = *(arr + i);
        }
    }
};

BeanBag ready;

void stockUpdate() {
    cout << "#######################################" << endl;
    cout << "stocks Checking" << endl;
    cout << "---------------------------------------" << endl;

    int* dynamicStock = new int[ITEM];

    cout << "Enter 3 stock values:" << endl;
    for (int i = 0; i < ITEM; ++i) {
        cout << "Group " << (i + 1) << ": ";
        cin >> dynamicStock[i];
    }

    ready.beanBag_Details(dynamicStock);
    ready.latest_BeanBagStock();

    delete[] dynamicStock;
}

int main() {
    cout << "COSY Bean Bag Chair Sdn. Bhd." << endl;

    BeanBag b;
    int initialStock[ITEM] = {9, 7, 5};

    b.beanBag_Details(initialStock);
    b.latest_BeanBagStock();

    stockUpdate();

    return 0;
}
