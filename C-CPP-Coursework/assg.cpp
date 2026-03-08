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
    Accommodation(int num, string type, int cap, float pr, bool booked = false):
    roomNumber(num), roomType(type), capacity(cap), price(pr), isBooked(booked) {}
    
    void setdetails()
    {
        cout<<"Please Enter Your Room Number";
        cin>>roomNumber;
        cout<<"Please Enter Your Room Type";
        getline(cin,roomType);
        cout<<"Please Enter Your Capacity";
        cin>>capacity;
        cout<<"Please Enter Room Price";
        cin>>price;
    }

    int setRoomNumber(int rN)
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

    virtual ~Accommodation() {}

    virtual void display() const = 0;

    virtual string getCategory() const = 0;

    void display()
    {
        cout<<"------------------------------------------"<<endl;
        cout<<"               ROOM DETAILS               "<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"Room Number   : "<<roomNumber<<endl;
        cout<<"Room Type     : "<<roomType<<endl;
        cout<<"Capacity      : "<<capacity<<endl;
        cout<<"Price         : RM"<< fixed << setprecision(2) << price << endl;;
        cout<<"------------------------------------------"<<endl;
    }

    friend void displayRoomSummary(const Accommodation& room);

};

void displayRoomSummary(const Accommodation& room) {
    cout<<"------------------------------------------"<<endl;
    cout << "              ROOM SUMMARY           \n";
    cout<<"------------------------------------------"<<endl;
    cout << "Room Number : " << room.roomNumber << endl;
    cout << "Room Type   : " << room.roomType << endl;
    cout << "Capacity    : " << room.capacity << " person(s)" << endl;
    cout << "Price       : RM" << fixed << setprecision(2) << room.price << endl;
    cout << "Status      : " << (room.isBooked ? "Booked" : "Available") << endl;
    cout << "Category    : " << room.getCategory() << endl;
    cout<<"------------------------------------------"<<endl;
    
}


class HotelRoom : public Accommodation
{
    public:
    HotelRoom(int number, const string& type, int cap, float pr, bool booked = false)
    : Accommodation(number, type, cap, pr, booked) {}

    void display() const override {}

    string getCategory() const override 
    {
        return "Hotel";
    }

};

class ChaletRoom : public Accommodation {
public:
    ChaletRoom(int number, const string& type, int cap, float pr, bool booked = false)
        : Accommodation(number, type, cap, pr, booked) {}

    void display() const override {}
    

    string getCategory() const override 
    {
        return "Chalet";
    }
};

int main()
{
    Accommodation* a = new HotelRoom(101, "Standard", 2, 100.00); 
    a->display();
    Accommodation* b = new ChaletRoom(201, "Lake View", 4, 500.00); 
    b->display();

    HotelRoom h(101, "Standard", 2, 100.00);
    ChaletRoom(201, "Lake View", 4, 500.00); 

    delete a;
    delete b;

    return 0;
}
