#include <iostream>
#include <string>
#include <iomanip>
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
    Accommodation(int num, string type, int cap, float pr, bool booked = false)
        : roomNumber(num), roomType(type), capacity(cap), price(pr), isBooked(booked) {}

    void setdetails()
    {
        cout << "Please Enter Your Room Number: ";
        cin >> roomNumber;
        cin.ignore(); // Clear newline left by cin
        cout << "Please Enter Your Room Type: ";
        getline(cin, roomType);
        cout << "Please Enter Capacity: ";
        cin >> capacity;
        cout << "Please Enter Room Price: ";
        cin >> price;
    }

    void setRoomNumber(int rN) { roomNumber = rN; }

    int getRoomNumber() { return roomNumber; }
    string getRoomType() { return roomType; }
    int getCapacity() { return capacity; }
    float getPrice() { return price; }
    bool getBookingStatus() { return isBooked; }

    virtual ~Accommodation() {}

    virtual void display() const {
        cout << "------------------------------------------" << endl;
        cout << "               ROOM DETAILS               " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Room Number   : " << roomNumber << endl;
        cout << "Room Type     : " << roomType << endl;
        cout << "Capacity      : " << capacity << endl;
        cout << "Price         : RM" << fixed << setprecision(2) << price << endl;
        cout << "------------------------------------------" << endl;
    }

    virtual string getCategory() const = 0;
};

class HotelRoom : public Accommodation
{
public:
    HotelRoom(int number, const string& type, int cap, float pr, bool booked = false)
        : Accommodation(number, type, cap, pr, booked) {}

    string getCategory() const override {
        return "Hotel";
    }
};

class ChaletRoom : public Accommodation
{
public:
    ChaletRoom(int number, const string& type, int cap, float pr, bool booked = false)
        : Accommodation(number, type, cap, pr, booked) {}

    string getCategory() const override {
        return "Chalet";
    }
};

int main()
{
    // Test Case 1: Display Hotel Room Details
    cout << "Test Case 1: Display Hotel Room Details" << endl;
    Accommodation* a = new HotelRoom(101, "Standard", 2, 100.00);
    a->display();
    delete a;
    cout << endl;

    // Test Case 2: Display Chalet Room Details
    cout << "Test Case 2: Display Chalet Room Details" << endl;
    Accommodation* b = new ChaletRoom(201, "Lake View", 4, 500.00);
    b->display();
    delete b;
    cout << endl;

    // Test Case 3: Verify Category Functionality for Hotel Room
    cout << "Test Case 3: Verify Category Functionality for Hotel Room" << endl;
    HotelRoom hr(102, "Deluxe", 3, 150.00);
    cout << hr.getCategory() << endl; // Should output "Hotel"
    cout << endl;

    // Test Case 4: Verify Category Functionality for Chalet Room
    cout << "Test Case 4: Verify Category Functionality for Chalet Room" << endl;
    ChaletRoom cr(202, "Mountain View", 6, 300.00);
    cout << cr.getCategory() << endl; // Should output "Chalet"
    cout << endl;

    // Test Case 5: Manual Input Verification for Hotel Room
    cout << "Test Case 5: Manual Input Verification for Hotel Room" << endl;
    Accommodation* c = new HotelRoom(0, "", 0, 0.0);
    c->setdetails(); // Manually input values for the hotel room
    cout << "[Hotel] Room #" << c->getRoomNumber()
         << " | " << c->getRoomType()
         << " | RM" << fixed << setprecision(2) << c->getPrice() << endl;
    delete c;
    cout << endl;

    // Test Case 6: Manual Input Verification for Chalet Room
    cout << "Test Case 6: Manual Input Verification for Chalet Room" << endl;
    Accommodation* d = new ChaletRoom(0, "", 0, 0.0);
    d->setdetails(); // Manually input values for the chalet room
    cout << "[Chalet] Room #" << d->getRoomNumber()
         << " | " << d->getRoomType()
         << " | RM" << fixed << setprecision(2) << d->getPrice() << endl;
    delete d;
    cout << endl;

    return 0;
}