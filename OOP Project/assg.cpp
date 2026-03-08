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

    virtual ~Accommodation() {}

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

};

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