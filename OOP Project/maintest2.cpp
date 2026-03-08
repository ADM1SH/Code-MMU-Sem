#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <thread>
#include <chrono>
using namespace std;

void slowPrint(const string& text, int delayMs);

class Accommodation
{
    protected:
    int roomNumber;
    string roomType;
    int capacity;
	float price;
    int floor;
    bool isBooked;

    public:
    Accommodation(int num, string type, int cap, float pr, int fl, bool booked = false):
    roomNumber(num), roomType(type), capacity(cap), price(pr), floor(fl), isBooked(booked) {}
    
    void setdetails()
    {
        cout<<"Please Enter Your Room Number: ";
        cin>>roomNumber;
        cin.ignore();
        cout<<"Please Enter Your Room Type: ";
        getline(cin,roomType);
        cout<<"Please Enter Your Capacity: ";
        cin>>capacity;
        cout<<"Please Enter Room Price: ";
        cin>>price;
    }

    void setRoomNumber(int rN)
    { roomNumber = rN; }

    int getRoomNumber() 
    { return roomNumber; }

    string getRoomType() 
    { return roomType; }

    int getCapacity() 
    { return capacity; }

    float getPrice()
    { return price; }

    bool getBookingStatus() 
    { return isBooked; }

    virtual void setBookingStatus(bool status)
    { isBooked = status; }

    virtual ~Accommodation() {}

    virtual string getCategory() const = 0;

    void display()
    {
        cout << "\033[1;33m";
        cout<<"------------------------------------------"<<endl;
        cout<<"               ROOM DETAILS               "<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"Room Number   : "<<roomNumber<<endl;
        cout<<"Room Type     : "<<roomType<<endl;
        cout<<"Capacity      : "<<capacity<<endl;
        cout<<"Price         : RM"<< fixed << setprecision(2) << price << endl;;
        cout<<"Floor         : " << floor << endl;
        cout<<"------------------------------------------"<<endl;
        cout << "\033[0m";
    }
};

void simulateInitialBookings(Accommodation* rooms[], int roomCount) {
    srand(time(0));
    for (int i = 0; i < roomCount; ++i) {
        ifstream file("bookings.txt");
        string line;
        bool alreadyBooked = false;
        while (getline(file, line)) {
            if (line.find(to_string(rooms[i]->getRoomNumber()) + ",") == 0) {
                alreadyBooked = true;
                rooms[i]->setBookingStatus(true);
                break;
            }
        }
        file.close();
        if (!alreadyBooked && rand() % 5 == 0) { // 20% chance to random book
            rooms[i]->setBookingStatus(true);
        }
    }
}

class HotelRoom : public Accommodation
{
    public:
    HotelRoom(int number, const string& type, int cap, float pr, int fl, bool booked = false)
    : Accommodation(number, type, cap, pr, fl, booked) {}

    string getCategory() const override 
    {
        return "Hotel";
    }

};

class ChaletRoom : public Accommodation {
public:
    ChaletRoom(int number, const string& type, int cap, float pr, int fl, bool booked = false)
        : Accommodation(number, type, cap, pr, fl, booked) {}
    

    string getCategory() const override 
    {
        return "Chalet";
    }
};

//booking function
void bookRoom(Accommodation* rooms[], int roomCount) {
    string selectedType;
    cout << "\n\033[1;35mSelect Room Category:\033[0m\n";
    cout << "1. Hotel Room\n";
    cout << "2. Chalet Room\n";
    cout << "Enter choice: ";
    int typeChoice;
    cin >> typeChoice;
    cin.ignore();

    if (typeChoice == 1)
        selectedType = "Hotel";
    else if (typeChoice == 2)
        selectedType = "Chalet";
    else {
        cout << "Invalid room type selected.\n";
        return;
    }

    int floorChoice;
    cout << "\n\033[1;35mSelect Floor (1 to 5):\033[0m ";
    cin >> floorChoice;
    cin.ignore();
    if (floorChoice < 1 || floorChoice > 5) {
        cout << "Invalid floor selected.\n";
        return;
    }

    cout << "\n\033[1;34mAvailable " << selectedType << " Rooms on Floor " << floorChoice << ":\033[0m\n";
    bool hasAvailable = false;
    for (int i = 0; i < roomCount; ++i) {
        if (rooms[i]->getCategory() == selectedType &&
            !rooms[i]->getBookingStatus() &&
            rooms[i]->getRoomNumber() / 100 == floorChoice) {
            rooms[i]->display();
            hasAvailable = true;
        }
    }

    if (!hasAvailable) {
        cout << "No available rooms of selected type.\n";
        return;
    }

    int roomNum;
    string guestName;
    bool found = false;

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
                rooms[i]->setBookingStatus(true);
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

void splashScreen() {
    cout << "\033[1;34m";
    cout << "=============================================\n";
    cout << "         Welcome to SmartStay Hotels         \n";
    cout << "        Your Comfort Is Our Priority         \n";
    cout << "=============================================\n";
    cout << "\033[0m";
    this_thread::sleep_for(chrono::seconds(2));
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void searchBooking();
int main() {
    splashScreen();

    const int floors = 5;
    const int roomsPerFloor = 4;
    const int roomCount = floors * roomsPerFloor;
    Accommodation* rooms[roomCount];
    int index = 0;

    for (int floor = 1; floor <= floors; ++floor) {
        for (int r = 1; r <= roomsPerFloor; ++r) {
            int roomNumber = floor * 100 + r;
            string type = (floor % 2 == 0) ? "Luxury" : "Standard";
            if (floor % 2 == 0)
                rooms[index++] = new ChaletRoom(roomNumber, type, 2 + (r % 3), 200.0 + (r * 15), floor);
            else
                rooms[index++] = new HotelRoom(roomNumber, type, 1 + (r % 2), 120.0 + (r * 10), floor);
        }
    }

    simulateInitialBookings(rooms, roomCount);

    int choice;
    do {
        cout << "\n\033[1;36m--- Room Booking System ---\033[0m\n";
        cout << "1. View Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "5. Search Booking\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "\033[1;32m--- Viewing Rooms By Floor ---\033[0m\n";
                int currentFloor = 1;
                char nav;
                do {
#ifdef _WIN32
                    system("cls");
#else
                    system("clear");
#endif
                    cout << "\033[1;36m-- Viewing Floor " << currentFloor << " of " << floors << " --\033[0m\n\n";
                    cout << "\n\033[1;33mFloor Map: ";
                    for (int i = 0; i < roomCount; ++i) {
                        if (rooms[i]->getRoomNumber() / 100 == currentFloor) {
                            cout << "[" << (rooms[i]->getBookingStatus() ? "\033[1;31m✗" : "\033[1;32m✓") << "\033[1;33m]";
                        }
                    }
                    cout << "\033[0m\n\n";

                    bool hasRooms = false;
                    cout << "\033[1;35m--- Hotel Rooms ---\033[0m\n";
                    for (int i = 0; i < roomCount; ++i) {
                        if (rooms[i]->getRoomNumber() / 100 == currentFloor && rooms[i]->getCategory() == "Hotel") {
                            rooms[i]->display();
                            cout << "Status        : " << (rooms[i]->getBookingStatus() ? "Booked" : "Available") << endl;
                            cout << "Category      : " << rooms[i]->getCategory() << "\n\n";
                            hasRooms = true;
                        }
                    }
                    cout << "\033[1;35m--- Chalet Rooms ---\033[0m\n";
                    for (int i = 0; i < roomCount; ++i) {
                        if (rooms[i]->getRoomNumber() / 100 == currentFloor && rooms[i]->getCategory() == "Chalet") {
                            rooms[i]->display();
                            cout << "Status        : " << (rooms[i]->getBookingStatus() ? "Booked" : "Available") << endl;
                            cout << "Category      : " << rooms[i]->getCategory() << "\n\n";
                            hasRooms = true;
                        }
                    }
                    if (!hasRooms) {
                        cout << "No rooms available on this floor.\n";
                    }
                    cout << "\nNavigate Floors: [N]ext, [P]revious, [E]xit: ";
                    cin >> nav;
                    nav = toupper(nav);
                    if (nav == 'N') {
                        currentFloor = (currentFloor % floors) + 1;
                    } else if (nav == 'P') {
                        currentFloor = (currentFloor == 1) ? floors : currentFloor - 1;
                    }
                } while (nav != 'E');
                break;
            }
            case 2:
                bookRoom(rooms, roomCount);
                break;
            case 3:
                cancelBooking();
                break;
            case 5:
                searchBooking();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    // Cleanup
    for (int i = 0; i < roomCount; ++i) {
        delete rooms[i];
    }

    return 0;
}

void searchBooking() {
    cout << "\nSearch by:\n1. Guest Name\n2. Room Number\nEnter choice: ";
    int searchType;
    cin >> searchType;
    cin.ignore();
    string term;
    cout << "Enter search term: ";
    getline(cin, term);

    ifstream file("bookings.txt");
    string line;
    bool found = false;
    while (getline(file, line)) {
        if ((searchType == 1 && line.find("," + term + ",") != string::npos) ||
            (searchType == 2 && line.find(term + ",") == 0)) {
            cout << "\n\033[1;32mMatch Found: \033[0m" << line << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "\033[1;31mNo matching booking found.\033[0m\n";
    }
}

void slowPrint(const string& text, int delayMs) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    cout << endl;
}
