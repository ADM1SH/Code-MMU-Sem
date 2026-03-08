#include <iostream>
#include <fstream>
#include <string>
#include "part1_classes.cpp"
using namespace std;

void bookRoom() {
    int roomNum;
    string guest;
    cout << "Room #: "; cin >> roomNum; cin.ignore();
    cout << "Name: "; getline(cin, guest);

    for (auto room : rooms) {
        if (room->getRoomNumber() == roomNum) {
            ofstream fout("bookings.txt", ios::app);
            fout << roomNum << "," << guest << "," << room->getCategory() << endl;
            fout.close();
            cout << "Booked " << room->getCategory() << " Room #" << roomNum << " for " << guest << endl;
            return;
        }
    }
    cout << "Room not found.\n";
}
