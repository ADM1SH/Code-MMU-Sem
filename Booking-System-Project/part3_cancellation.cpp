#include <iostream>
#include <fstream>
#include <string>
#include "part1_classes.cpp"
using namespace std;

void cancelBooking() {
    int roomNum;
    string guest;
    cout << "Room #: "; cin >> roomNum; cin.ignore();
    cout << "Name: "; getline(cin, guest);

    ifstream fin("bookings.txt");
    ofstream fout("temp.txt");
    string line;
    bool found = false;

    while (getline(fin, line)) {
        if (line.find(to_string(roomNum) + "," + guest) == string::npos) {
            fout << line << endl;
        } else {
            found = true;
        }
    }

    fin.close();
    fout.close();
    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");

    if (found) cout << "Booking cancelled.\n";
    else cout << "Booking not found.\n";
}
