#include <cstdio>
#include <cstdio>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;

// Base class representing a general room accommodation
class Accommodation {
protected:
    int roomNumber, capacity, floor;
    float price;
    bool isBooked;
    string roomType;
public:

    // Constructor with initializer lists
    Accommodation(int num, string type, int cap, float pr, int flr, bool booked = false)
        : roomNumber(num), capacity(cap), floor(flr), price(pr), isBooked(booked), roomType(type) {}

    // Function to set user booking details
    void setdetails() {
        // User enters details for a room (room number, type, capacity, price)
        cout << "\033[1;33mPlease Enter Your Room Number: \033[0m";
        while (!(cin >> roomNumber)) {
            cout << "Invalid input. Please enter a valid room number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore();
        cout << "\033[1;33mPlease Enter Your Room Type: \033[0m";
        getline(cin, roomType);
        cout << "\033[1;33mPlease Enter Your Capacity: \033[0m";
        while (!(cin >> capacity)) {
            cout << "Invalid input. Please enter a valid capacity: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cout << "\033[1;33mPlease Enter Room Price: \033[0m";
        while (!(cin >> price)) {
            cout << "Invalid input. Please enter a valid price: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore();
    }

    // Mutator Function
    void setRoomNumber(int rN) { roomNumber = rN; }

    // Accessor Functions
    int getRoomNumber() const { return roomNumber; }
    string getRoomType() const { return roomType; }
    int getCapacity() const { return capacity; }
    float getPrice() const { return price; }
    bool getBookingStatus() const { return isBooked; }
    int getFloor() const { return floor; }

    // Virtual Function to set booking status
    virtual void setBookingStatus(bool status) { isBooked = status; }
    virtual ~Accommodation() {}
    virtual string getCategory() const = 0;

    // Display customer's room details
    void display() const {
        cout << "\033[1;33m";
        cout << "------------------------------------------" << endl;
        cout << "               ROOM DETAILS               " << endl;
        cout << "------------------------------------------" << endl;
        cout << "\033[0m";
        cout << "Floor         : " << floor << endl;
        cout << "Room Number   : " << roomNumber << endl;
        cout << "Room Type     : " << roomType << endl;
        cout << "Capacity      : " << capacity << endl;
        cout << "Price         : RM" << fixed << setprecision(2) << price << endl;
        cout << "------------------------------------------" << endl;
    }

    // Friend function declaration to display room summary
    friend void displayRoomSummary(const Accommodation&);
};

// Derived class representing a hotel room
class HotelRoom : public Accommodation {
public:

    // Constructor with parameters
    HotelRoom(int number, const string& type, int cap, float pr, int flr, bool booked = false)
        : Accommodation(number, type, cap, pr, flr, booked) {}

    // Default constructor
    HotelRoom() : Accommodation(0, "Standard", 1, 100.0f, 1, false) {}
    // Return category string
    string getCategory() const override { return "Hotel"; }
};

// Derived class representing a chalet room
class ChaletRoom : public Accommodation {
public:

    // Constructor with parameters
    ChaletRoom(int number, const string& type, int cap, float pr, int flr, bool booked = false)
        : Accommodation(number, type, cap, pr, flr, booked) {}

    // Default constructor
    ChaletRoom() : Accommodation(0, "Family", 4, 300.0f, 1, false) {}
    // Return category string
    string getCategory() const override { return "Chalet"; }
};

// Displays a summary of the room's details (room number, category, type, capacity, price, status, floor)
void displayRoomSummary(const Accommodation& room) {
    cout << "Room " << room.roomNumber << " (" << room.getCategory() << "): "
         << room.roomType << ", Capacity: " << room.capacity
         << ", Price: RM" << fixed << setprecision(2) << room.price
         << ", Status: " << (room.isBooked ? "\033[1;31mBooked\033[0m" : "\033[1;32mAvailable\033[0m")
         << ", Floor: " << room.floor << endl;
}

// Simulates initial room bookings using bookings.txt and 20% random chance
void simulateInitialBookings(vector<Accommodation*>& rooms) {
    srand(static_cast<unsigned int>(time(nullptr)));
    ifstream file("bookings.txt");
    vector<int> bookedRoomNumbers;
    string line;
    // Read booked room numbers from bookings.txt file
    while (getline(file, line)) {
        size_t pos = line.find(',');
        if (pos != string::npos) {
            int roomNum = stoi(line.substr(0, pos));
            bookedRoomNumbers.push_back(roomNum);
        }
    }
    file.close();

    // Set booking status based on file, with 20% random booking chance if not in file
    for (auto& room : rooms) {
        bool isBookedInFile = false;
        for (int bookedNum : bookedRoomNumbers) {
            if (room->getRoomNumber() == bookedNum) {
                room->setBookingStatus(true);
                isBookedInFile = true;
                break;
            }
        }
        // Apply 20% chance of booking if not already booked in file
        if (!isBookedInFile) {
            if ((rand() % 10) < 2) { // 0 or 1 => 20% chance
                room->setBookingStatus(true);
            } else {
                room->setBookingStatus(false);
            }
        }
    }
}

// Helper function to convert string to lowercase
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Forward declarations for booking-related functions
void cancelBooking();
void searchBooking();

// Handles user interaction to book an available room by category and floor
void bookRoom(vector<Accommodation*>& rooms) {
    string category;
    int floorNum;
    cout << "\n\033[1;33mEnter room category to book (Hotel/Chalet): \033[0m";
    getline(cin, category);
    cout << "\033[1;33mEnter floor number: \033[0m";
    cin >> floorNum;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\033[1;31mInvalid input. Floor number must be a number.\033[0m\n";
        return;
    }
    cin.ignore();

    vector<Accommodation*> availableRooms;
    string categoryLower = toLower(category);
    // Find all available rooms matching category and floor
    for (auto& room : rooms) {
        if (!room->getBookingStatus() && toLower(room->getCategory()) == categoryLower && room->getFloor() == floorNum) {
            availableRooms.push_back(room);
        }
    }

    if (availableRooms.empty()) {
        cout << "\033[1;31mNo available rooms found for category " << category << " on floor " << floorNum << ".\033[0m\n";
        return;
    }

    // Display available rooms for selection
    cout << "\n\033[1;33mAvailable rooms:\033[0m\n";
    for (size_t i = 0; i < availableRooms.size(); ++i) {
        cout << i + 1 << ". Room " << availableRooms[i]->getRoomNumber()
             << " (" << availableRooms[i]->getRoomType() << "), Capacity: "
             << availableRooms[i]->getCapacity() << ", Price: RM"
             << fixed << setprecision(2) << availableRooms[i]->getPrice() << endl;
    }

    int choice;
    cout << "\033[1;33mSelect room to book (number): \033[0m";
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\033[1;31mInvalid input. Choice must be a number.\033[0m\n";
        return;
    }
    cin.ignore();

    if (choice < 1 || choice >(int)availableRooms.size()) {
        cout << "\033[H\033[J";
        cout << "\033[1;31mInvalid choice.\033[0m\n";
        return;
    }

    string guestName;
    cout << "\033[1;33mEnter your name: \033[0m";
    getline(cin, guestName);

    Accommodation* selectedRoom = availableRooms[choice - 1];

    // Append booking info to bookings.txt
    ofstream file("bookings.txt", ios::app);
    if (file.is_open()) {
        file << selectedRoom->getRoomNumber() << "," << guestName << "," << selectedRoom->getCategory() << endl;
        file.close();

        // Mark room as booked
        selectedRoom->setBookingStatus(true);
        cout << "\n\033[1;32mBooking successful for Room\033[0m" << selectedRoom->getRoomNumber() << "!\n";
        cout << "\n\n\033[1;33mPress any key to return...\033[0m";
        getchar();
        cout << "\033[H\033[J";
    }
    else {
        cout << "Error: Could not open bookings.txt\n";
    }
}

// Cancels a booking based on matching room number and guest name in file
void cancelBooking() {
    string room, name;
    cout << "\033[1;33mEnter room number to cancel: \033[0m";
    getline(cin, room);
    cout << "\033[1;33mEnter guest name: \033[0m";
    getline(cin, name);

    ifstream in("bookings.txt");
    ofstream out("temp.txt");
    string line;
    bool found = false;

    while (getline(in, line)) {
        if (line.find(room + "," + name + ",") == 0 && !found) {
            found = true;
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
        cout << "\n\033[1;32mBooking cancelled successfully.\033[0m\n";
    } else {
        cout << "\033[H\033[J";
        cout << "\033[1;31mBooking not found.\033[0m\n";
    }

    cout << "\n\n\033[1;33mPress any key to return...\033[0m";
    getchar();
    cout << "\033[H\033[J";
}

// Searches for bookings in bookings.txt using a case-insensitive keyword
void searchBooking() {
    string keyword;
    cout << "\033[1;33mEnter search keyword: \033[0m";
    getline(cin, keyword);
    ifstream file("bookings.txt");
    string line;
    bool found = false;
    while (getline(file, line)) {
        string lowerLine = toLower(line);
        string lowerKeyword = toLower(keyword);
        if (lowerLine.find(lowerKeyword) != string::npos) {
            cout << line << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "\033[1;31mNo matching bookings found.\033[0m\n";
    }
}

// Allows editing of booking information (guest name and room details)
void editBooking(vector<Accommodation*>& rooms) {
    int roomNum;
    cout << "\033[1;33mEnter room number to edit: \033[0m";
    cin >> roomNum;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\033[1;31mInvalid room number input.\033[0m\n";
        return;
    }
    cin.ignore();

    bool found = false;

    // Find room to edit by room number
    for (auto& room : rooms) {
        if (room->getRoomNumber() == roomNum) {
            string newName;
            cout << "\033[1;33mEnter new guest name: \033[0m";
            getline(cin, newName);

            // Update booking file with new guest name
            ifstream in("bookings.txt");
            ofstream out("temp.txt");
            string line;

            while (getline(in, line)) {
                if (line.find(to_string(roomNum) + ",") == 0) {
                    out << roomNum << "," << newName << "," << room->getCategory() << endl;
                }
                else {
                    out << line << endl;
                }
            }

            in.close();
            out.close();

            // Replace original file with updated temp file
            ofstream final("bookings.txt");
            ifstream temp("temp.txt");
            while (getline(temp, line)) {
                final << line << "\n";
            }

            // Allow user to edit in-memory room details (room number, type, capacity, price)
            room->setdetails();

            cout << "\n\033[1;32mBooking updated successfully.\033[0m\n";
            found = true;
            cout << "\n\n\033[1;33mPress any key to return...\033[0m";
            getchar();
            cout << "\033[H\033[J";
            break;
        }
    }

    if (!found) {
        cout << "\033[H\033[J";
        cout << "\033[1;31mRoom not found.\033[0m\n";
    }
}

// Clears the console screen depending on OS
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void delay(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(n));
    
}

// Displays an ASCII welcome splash screen with delay
void splashScreen() {
    clearScreen();
    // Set text color to yellow
    cout << "\033[1;33m";
    cout << R"(
        ==========WELCOME TO OUR==========

       / \                               / \
      /   \                             /   \
     /_____\___________________________/_____\
    |  __  |   __  __  __  __  __  __  |  __ |
    | |  | |  |  ||  ||  ||  ||  ||  | | |  ||
    | |__| |  |__||__||__||__||__||__| | |__||
    |  __  |   __  __  __  __  __  __  |  __ |
    | |  | |  |  ||  ||  ||  ||  ||  | | |  ||
    | |__| |  |__||__||__||__||__||__| | |__||
    |______|___________________________|_____|
    |      |         H O T E L         |     |
    |  []  |                           | []  |
    |  []  |                           | []  |
    |  []  |___________________________| []  |
    |      |                           |     |
    |  []  |                           | []  |
    |  []  |                           | []  |
    |  []  |___________________________| []  |
    |______|___________________________|_____|
    
    
                    Loading...)" << endl;
}

int main() {
    // Main menu loop handling user input and actions
    // Set up hotel and chalet rooms
    vector<Accommodation*> rooms;
    int floors = 5;
    int roomsPerFloor = 4;
    // Create hotel rooms (floors 1-3)
    for (int fl = 1; fl <= 3; ++fl) {
        for (int num = 1; num <= roomsPerFloor; ++num) {
            rooms.push_back(new HotelRoom(fl * 100 + num, "Standard", 2, 150.0f, fl));
        }
    }
    // Create chalet rooms (floors 4-5)
    for (int fl = 4; fl <= floors; ++fl) {
        for (int num = 1; num <= roomsPerFloor; ++num) {
            rooms.push_back(new ChaletRoom(fl * 100 + num, "Family", 4, 300.0f, fl));
        }
    }

    splashScreen();
    delay(5);

    // Simulate initial bookings from file and random chance
    simulateInitialBookings(rooms);

    int currentFloor = 1;
    int choice;
    do {
        // Display main menu options with sequential numbering
        cout << "\n\033[1;34m--- Room Booking System ---\033[0m\n";
        cout << "\033[1;33m1. View Rooms by Floor\033[0m\n";
        cout << "\033[1;33m2. Book a Room\033[0m\n";
        cout << "\033[1;33m3. Cancel Booking\033[0m\n";
        cout << "\033[1;33m4. Edit Booking\033[0m\n";
        cout << "\033[1;33m5. Search Booking\033[0m\n";
        cout << "\033[1;33m6. Exit\033[0m\n";
        cout << "\033[1;33mEnter your choice: \033[0m";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\033[1;31mInvalid choice. Please enter a number.\033[0m\n";
            continue;
        }
        cin.ignore();

        switch (choice) {
        case 1:
            // View rooms floor by floor with navigation
            while (true) {
                clearScreen();
                cout << "\033[1;33mShowing floor " << currentFloor << "/" << floors << ":\033[0m\n\n";
                for (auto& room : rooms) {
                    if (room->getFloor() == currentFloor) {
                        room->display();
                        cout << "Status        : " << (room->getBookingStatus() ? "\033[1;31mBooked\033[0m" : "\033[1;32mAvailable\033[0m") << endl;
                        cout << "Category      : " << room->getCategory() << "\n\n";
                    }
                }
                // Navigation options for floors
                cout << "\033[1;33mNavigation: [N]ext floor, [P]revious floor, [E]xit viewing\033[0m\n";
                cout << "\033[1;33mEnter choice: \033[0m";
                string navChoice;
                getline(cin, navChoice);
                if (navChoice == "N" || navChoice == "n") {
                    if (currentFloor < floors) {
                        ++currentFloor;
                    }
                    else {
                        cout << "\033[1;31mYou are on the top floor.\033[0m\n";
                    }
                }
                else if (navChoice == "P" || navChoice == "p") {
                    if (currentFloor > 1) {
                        --currentFloor;
                    }
                    else {
                        cout << "\033[1;31mYou are on the ground floor.\033[0m\n";
                    }
                }
                else if (navChoice == "E" || navChoice == "e") {
                    break;
                }
                else {
                    cout << "\033[H\033[J";
                    cout << "\033[1;31mInvalid choice.\033[0m\n";
                }
            }
            clearScreen();
            break;
        case 2:
            // Book a room based on user input
            bookRoom(rooms);
            break;
        case 3:
            // Cancel a booking based on user input
            cancelBooking();
            break;
        case 4:
            // Edit an existing booking
            editBooking(rooms);
            break;
        case 5:
            // Search for a booking
            searchBooking();
            break;
        case 6:
            // Exit the programs
            cout << "\033[1;34mExiting...\033[0m\n";
            break;
        default:
            cout << "\033[H\033[J";
            cout << "\033[1;31mInvalid choice. Try again.\033[0m\n\n";
        }
    } while (choice != 6);

    // Clean up dynamically allocated rooms
    for (auto ptr : rooms) {
        delete ptr;
    }

    return 0;
}
