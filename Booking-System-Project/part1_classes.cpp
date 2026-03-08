#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Accommodation {
protected:
    int roomNumber;
    string roomType;
    int capacity;
    float price;

public:
    Accommodation(int num, string type, int cap, float pr)
        : roomNumber(num), roomType(type), capacity(cap), price(pr) {}

    virtual ~Accommodation() {}

    int getRoomNumber() const { return roomNumber; }
    string getRoomType() const { return roomType; }
    float getPrice() const { return price; }
    virtual void display() const = 0;
    virtual string getCategory() const = 0;
};

class HotelRoom : public Accommodation {
public:
    HotelRoom(int num, string type, int cap, float pr) : Accommodation(num, type, cap, pr) {}
    void display() const override {
        cout << "[Hotel] Room #" << roomNumber << " | " << roomType << " | RM" << price << endl;
    }
    string getCategory() const override { return "Hotel"; }
};

class ChaletRoom : public Accommodation {
public:
    ChaletRoom(int num, string type, int cap, float pr) : Accommodation(num, type, cap, pr) {}
    void display() const override {
        cout << "[Chalet] Room #" << roomNumber << " | " << roomType << " | RM" << price << endl;
    }
    string getCategory() const override { return "Chalet"; }
};

vector<Accommodation*> rooms;

void loadRooms() {
    rooms.push_back(new HotelRoom(101, "Standard", 2, 100));
    rooms.push_back(new HotelRoom(102, "Deluxe", 3, 180));
    rooms.push_back(new ChaletRoom(201, "Forest View", 4, 400));
    rooms.push_back(new ChaletRoom(202, "Lakefront", 5, 600));
}
