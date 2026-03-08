#include <iostream>
#include <iomanip>
using namespace std;

// Define the struct
struct Rental {
    char name[20];
    float rent;
    int month;
};

// Function prototype
float report(struct Rental[]);

// Function definition
float report(struct Rental R[]) {
    float total = 0;

    cout << "----------------------------------------------------\n";
    cout << "- AMOUNT DUE MORE THAN RM1000.00 -\n";
    cout << "----------------------------------------------------\n";

    for (int i = 0; i < 3; i++) {
        float amountDue = R[i].rent * R[i].month;

        if (amountDue > 1000.00) {
            cout << "Tenant name     : " << R[i].name << endl;
            cout << "Monthly rental  : RM " << fixed << setprecision(2) << R[i].rent << endl;
            cout << "Unpaid months   : " << R[i].month << endl;
            cout << "Unpaid amount   : RM " << amountDue << endl << endl;
            total += amountDue;
        }
    }

    return total;
}

// Main function
int main() {
    // Declare and initialize the array of Rental records
    struct Rental R[3] = {
        {"Megan", 300, 4},
        {"Johnson", 250, 1},
        {"David", 790, 2}
    };

    // Call the report function and display the total amount due
    float grandTotal = report(R);
    cout << "Total rental to be collected : RM " << fixed << setprecision(2) << grandTotal << endl;

    return 0;
}

