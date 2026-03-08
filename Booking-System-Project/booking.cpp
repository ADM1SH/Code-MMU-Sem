#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void bookRoom(Accommodation* rooms[], int roomCount) {
    int roomNum;
    string guestName;
    bool found = false;

    //Ask user to enter room number
    cout << "\nEnter the room number you want to book: ";
    cin >> roomNum;
    cin.ignore(); 

    // Loop through all rooms to find a match
    for (int i = 0; i < roomCount; ++i) {
        // Check if the room number matches and is not already booked
        if (rooms[i]->getRoomNumber() == roomNum && !rooms[i]->getBookingStatus()) {
            cout << "Enter your name: ";
            getline(cin, guestName);

            //Open booking.txt to save
            ofstream file("bookings.txt", ios::app); //append mode
            if (file.is_open()) {
                // Write room number, guest name and room category 
                file << roomNum << "," << guestName << "," << rooms[i]->getCategory() << endl;
                file.close();

                //Confirmation
                cout << "Booking successful for Room " << roomNum << "!\n";
            } else {
                cout << "Error: Could not open bookings.txt\n";
            }

            found = true;
            break; // stop checking after booking
        }
    }

    // If no matching room was found or already booked
    if (!found) {
        cout << "Room not found or already booked.\n";
    }
}
