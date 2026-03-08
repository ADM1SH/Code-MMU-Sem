
#include <iostream>


// Edit Booking
void editBooking(Accommodation* rooms[], int roomCount) {
    int roomNum;
    cout << "Enter room number to edit: ";
    cin >> roomNum;
    cin.ignore();

    bool found = false;

    for (int i = 0; i < roomCount; ++i) {
        if (rooms[i]->getRoomNumber() == roomNum) {
            string newName;
            cout << "Enter new guest name: ";
            getline(cin, newName);

            // Update file
            ifstream in("bookings.txt");
            ofstream out("temp.txt");
            string line;

            while (getline(in, line)) {
                if (line.find(to_string(roomNum) + ",") == 0) {
                    out << roomNum << "," << newName << "," << rooms[i]->getCategory() << endl;
                } else {
                    out << line << endl;
                }
            }

            in.close();
            out.close();

            ofstream final("bookings.txt");
            ifstream temp("temp.txt");
            while (getline(temp, line)) {
                final << line << "\n";
            }

            // Edit in-memory details
            rooms[i]->setdetails();

            cout << "Booking updated successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Room not found.\n";
    }
}