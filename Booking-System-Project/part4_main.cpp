#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "part1_classes.cpp"
#include "part2_booking.cpp"
#include "part3_cancellation.cpp"
using namespace std;

void checkMyBooking() {
    cin.ignore();
    string name;
    cout << "Enter name: "; getline(cin, name);
    transform(name.begin(), name.end(), name.begin(), ::tolower);

    ifstream fin("bookings.txt");
    string line;
    cout << "Your bookings:\n";
    while (getline(fin, line)) {
        string lower = line;
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        if (lower.find(name) != string::npos) cout << line << endl;
    }
    fin.close();
}

void displayMenu() {
    cout << "\n1. View Rooms\n2. Book Room\n3. Cancel Booking\n4. Check My Booking\n5. Exit\n> ";
}

int main() {
    loadRooms();
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        if (choice == 1) for (auto r : rooms) r->display();
        else if (choice == 2) bookRoom();
        else if (choice == 3) cancelBooking();
        else if (choice == 4) checkMyBooking();
        else if (choice == 5) break;
        else cout << "Invalid.\n";
    }
    for (auto r : rooms) delete r;
    return 0;
}
