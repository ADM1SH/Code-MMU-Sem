#include <iostream>
#include <iomanip>
using namespace std;

struct Rental {
    string name;
    double rent;
    int months;
};

float report(Rental R[]) {
    cout << fixed << setprecision(2);
    float total = 0;
    for (int i = 0; i <= 2; i++){
        cout << "Tenant Name     : " << R[i].name << endl;
        cout << "Monthly Rental  : " << R[i].rent << endl;
        cout << "Unpaid Months   : " << R[i].months << endl;
        float unpaid = R[i].rent * R[i].months;
        cout << "Unpaid Amount   : " << unpaid << endl << endl;
        total += unpaid;
    }
    return total;
}

int main() {
    const int NUM_EMPS = 5;
    int index, hours[NUM_EMPS];
    double payRate[NUM_EMPS], grossPay;

    cout << "Enter the hours worked and hourly pay rates of " << NUM_EMPS << " employees.\n\n";

    for (index = 0; index < NUM_EMPS; index++) {
        cout << "Hours worked by employee #" << (index + 1) << ": ";
        cin >> hours[index];
        cout << "Hourly pay rate for employee #" << (index + 1) << ": RM ";
        cin >> payRate[index];
        cout << endl;
    }

    cout << "\nHere is the gross pay for each employee:\n";
    cout << fixed << setprecision(2);

    for (index = 0; index < NUM_EMPS; index++) {
        grossPay = hours[index] * payRate[index];
        cout << "Employee #" << (index + 1) << " : RM " << grossPay << endl;
    }

    Rental R[3] = {
        {"Megan", 300.00, 4},
        {"David", 790.00, 2},
        {"Lisa", 450.00, 3}
    };
    float total = report(R);
    cout << "Total rental to be collected is: RM" << total << endl;

    return 0;
}