#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class Accommodation
{
    protected:
    int roomNumber;
    string roomType;
    int capacity;
	float price;
    bool isBooked;

    public:
    Accommodation(int num, string type, int cap, float pr, bool booked = false):
    roomNumber(num), roomType(type), capacity(cap), price(pr), isBooked(booked) {}
    
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
    HotelRoom(int number, const string& type, int cap, float pr, bool booked = false)
    : Accommodation(number, type, cap, pr, booked) {}

    string getCategory() const override 
    {
        return "Hotel";
    }

};

class ChaletRoom : public Accommodation {
public:
    ChaletRoom(int number, const string& type, int cap, float pr, bool booked = false)
        : Accommodation(number, type, cap, pr, booked) {}
    

    string getCategory() const override 
    {
        return "Chalet";
    }
};

//booking function
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

int main() {
    const int roomCount = 4;
    Accommodation* rooms[roomCount] = {
        new HotelRoom(101, "Single", 1, 120.00),
        new HotelRoom(102, "Double", 2, 200.00),
        new ChaletRoom(201, "Family", 4, 350.00),
        new ChaletRoom(202, "Luxury", 2, 500.00)
    };

    simulateInitialBookings(rooms, roomCount);

    int choice;
    do {
        cout << "\n\033[1;36m--- Room Booking System ---\033[0m\n";
        cout << "1. View Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "\033[1;32m--- Viewing All Rooms ---\033[0m\n\n";
                for (int i = 0; i < roomCount; ++i) {
                    rooms[i]->display();
                    cout << "Status        : " << (rooms[i]->getBookingStatus() ? "Booked" : "Available") << endl;
                    cout << "Category      : " << rooms[i]->getCategory() << "\n\n";
                }
                break;
            case 2:
                bookRoom(rooms, roomCount);
                break;
            case 3:
                cancelBooking();
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