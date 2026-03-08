#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Accommodation {
protected:
    int roomNumber;
    string roomType;
    int capacity;
    float price;
    bool isBooked;

public:
    Accommodation(int num, string type, int cap, float pr)
        : roomNumber(num), roomType(type), capacity(cap), price(pr), isBooked(false) {} 

    virtual ~Accommodation() {}

    int getRoomNumber() const { return roomNumber; }
    string getRoomType() const { return roomType; }
    int getCapacity() const { return capacity; }
    float getPrice() const { return price; }
    bool getIsBooked() const { return isBooked; }

    void setBooked(bool status) { isBooked = status; }

    virtual void display() const = 0;
    virtual string getCategory() const = 0;
};

class HotelRoom : public Accommodation {
public:
    HotelRoom(int num, string type, int cap, float pr)
        : Accommodation(num, type, cap, pr) {}

    void display() const override {
        cout << "[Hotel] Room #" << roomNumber
             << " | Type: " << roomType
             << " | Capacity: " << capacity
             << " | RM" << price
             << " | " << (isBooked ? "Booked" : "Available") << endl;
    }

    string getCategory() const override {
        return "Hotel";
    }
};

class ChaletRoom : public Accommodation {
public:
    ChaletRoom(int num, string type, int cap, float pr)
        : Accommodation(num, type, cap, pr) {}

    void display() const override {
        cout << "[Chalet] Room #" << roomNumber
             << " | Type: " << roomType
             << " | Capacity: " << capacity
             << " | RM" << price
             << " | " << (isBooked ? "Booked" : "Available") << endl;
    }

    string getCategory() const override {
        return "Chalet";
    }
};

// Global room list
vector<Accommodation*> rooms;

// Load sample data
void loadRooms() {
    // Add more hotel and chalet room choices
    rooms.push_back(new HotelRoom(101, "Standard", 2, 100.0));
    rooms.push_back(new HotelRoom(102, "Deluxe", 3, 180.0));
    rooms.push_back(new HotelRoom(103, "Suite", 4, 250.0));
    rooms.push_back(new HotelRoom(104, "Executive", 2, 320.0));
    rooms.push_back(new HotelRoom(105, "Penthouse", 6, 800.0));
    rooms.push_back(new HotelRoom(106, "Family", 5, 350.0));
    rooms.push_back(new ChaletRoom(201, "Forest View", 4, 400.0));
    rooms.push_back(new ChaletRoom(202, "Lakefront", 5, 600.0));
    rooms.push_back(new ChaletRoom(203, "Mountain Top", 2, 700.0));
    rooms.push_back(new ChaletRoom(204, "Luxury Villa", 8, 1200.0));
    rooms.push_back(new ChaletRoom(205, "Beachfront", 3, 900.0));
}

void searchRooms() {
    cout << "\n--- Available Rooms ---\n";
    bool found = false;
    for (auto room : rooms) {
        room->display();
        found = true;
    }
    if (!found) cout << "No rooms found.\n";
}

void bookRoom() {
    while (true) {
        int roomNum;
        cout << "\nEnter room number to book: ";
        cin >> roomNum;
        cin.ignore();

        Accommodation* selectedRoom = nullptr;
        for (auto room : rooms) {
            if (room->getRoomNumber() == roomNum) {
                selectedRoom = room;
                break;
            }
        }
        if (!selectedRoom) {
            cout << "Room not found. Try again.\n";
            continue;
        }

        string guestName;
        cout << "Enter your name: ";
        getline(cin, guestName);
        // Append booking to file (roomNumber, guestName, category)
        ofstream fout("bookings.txt", ios::app);
        if (fout) {
            fout << selectedRoom->getRoomNumber() << "," << guestName << "," << selectedRoom->getCategory() << endl;
            fout.close();
            cout << "Room #" << roomNum << " booked successfully ("
                 << selectedRoom->getCategory() << ", RM" << selectedRoom->getPrice() << ") for " << guestName << ".\n";
        } else {
            cout << "Error: Could not write booking to file.\n";
        }
        // Since we now allow multiple bookings per room, do not set isBooked flag
        break;
    }
}

void cancelBooking() {
    while (true) {
        int roomNum;
        cout << "\nEnter room number to cancel booking: ";
        cin >> roomNum;
        cin.ignore();

        string guestName;
        cout << "Enter your name to cancel your booking: ";
        getline(cin, guestName);

        bool found = false;
        // Read all bookings and write back those not matching this cancellation
        ifstream fin("bookings.txt");
        ofstream fout("bookings_tmp.txt");
        string line;
        while (getline(fin, line)) {
            size_t p1 = line.find(',');
            size_t p2 = line.rfind(',');
            if (p1 == string::npos || p2 == string::npos) continue;
            int fileRoomNum = stoi(line.substr(0, p1));
            string fileGuest = line.substr(p1 + 1, p2 - p1 - 1);
            if (fileRoomNum == roomNum && fileGuest == guestName && !found) {
                // Skip this booking (delete only one booking per call)
                found = true;
                continue;
            }
            fout << line << endl;
        }
        fin.close();
        fout.close();
        remove("bookings.txt");
        rename("bookings_tmp.txt", "bookings.txt");
        if (found) {
            cout << "Booking for room #" << roomNum << " under name " << guestName << " has been cancelled.\n";
        } else {
            cout << "No matching booking found to cancel. Try again.\n";
            continue;
        }
        break;
    }
}

void checkMyBooking() {
    cout << "\nEnter your name to view your bookings: ";
    cin.ignore();
    string guestName;
    getline(cin, guestName);
    ifstream fin("bookings.txt");
    if (!fin) {
        cout << "No bookings found.\n";
        return;
    }
    bool found = false;
    string line;
    cout << "\n--- Your Bookings ---\n";
    while (getline(fin, line)) {
        size_t p1 = line.find(',');
        size_t p2 = line.rfind(',');
        if (p1 == string::npos || p2 == string::npos) continue;
        string fileGuest = line.substr(p1 + 1, p2 - p1 - 1);
        if (fileGuest == guestName) {
            string fileRoomNum = line.substr(0, p1);
            string fileCategory = line.substr(p2 + 1);
            cout << "Room #" << fileRoomNum << " (" << fileCategory << ")\n";
            found = true;
        }
    }
    if (!found) cout << "No bookings found under your name.\n";
    fin.close();
}

void displayMenu() {
    cout << "\n===== Hotel & Chalet Booking System =====\n";
    cout << "1. View Available Rooms\n";
    cout << "2. Book a Room\n";
    cout << "3. Cancel a Booking\n";
    cout << "4. View My Bookings\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    loadRooms();
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;
        // Instead of switch, use a looped structure with re-prompting on invalid input
        if (choice == 1) {
            while (true) {
                searchRooms();
                cout << "Press 0 to return to main menu: ";
                int dummy;
                cin >> dummy;
                if (dummy == 0) break;
            }
        } else if (choice == 2) {
            while (true) {
                bookRoom();
                cout << "Book another room? (1 = Yes, 0 = No): ";
                int again;
                cin >> again;
                if (again == 1) continue;
                else break;
            }
        } else if (choice == 3) {
            while (true) {
                cancelBooking();
                cout << "Cancel another booking? (1 = Yes, 0 = No): ";
                int again;
                cin >> again;
                if (again == 1) continue;
                else break;
            }
        } else if (choice == 4) {
            while (true) {
                checkMyBooking();
                cout << "Check another name? (1 = Yes, 0 = No): ";
                int again;
                cin >> again;
                if (again == 1) continue;
                else break;
            }
        } else if (choice == 5) {
            cout << "Thank you for using the booking system.\n";
            for (auto room : rooms) delete room;
            rooms.clear();
            return 0;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}