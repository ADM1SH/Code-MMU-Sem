#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void cancelBooking() {
    string room, name;
    cout << "Enter room number to cancel: ";
    getline(cin, room);
    cout << "Enter guest name: ";
    getline(cin, name);

    ifstream in("bookings.txt");
    ofstream out("temp.txt");
    string line;
    bool found = false;

    while (getline(in, line)) {
        if (line.find(room + "," + name + ",") == 0 && !found) {
            found = true; // skip this line
        } else {
            out << line << "\n";
        }
    }

    in.close();
    out.close();

    if (found) {
        ofstream final("bookings.txt");
        ifstream temp("temp.txt");
        while (getline(temp, line)) {
            final << line << "\n";
        }
        cout << "Booking cancelled.\n";
    } else {
        cout << "Booking not found.\n";
    }
}