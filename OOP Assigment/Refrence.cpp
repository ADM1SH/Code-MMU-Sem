#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

class FlightBase {
public:
    virtual void add() = 0;
    virtual void edit() = 0;
    virtual void deleteEntry() = 0;
    virtual void display() const = 0;
    virtual ~FlightBase() {}
};

class Flight : public FlightBase {
private:
    string flightNumber;
    string destination;
    string departureTime;
    int seatCapacity;
    vector<bool> seats; // true = booked, false = available
    float price;

public:
    Flight() : flightNumber(""), destination(""), departureTime(""), seatCapacity(0), price(0.0f) {}

    Flight(const string& fn, const string& dest, const string& depTime, int capacity, float pr)
        : flightNumber(fn), destination(dest), departureTime(depTime), seatCapacity(capacity), price(pr), seats(capacity, false) {}

    void add() override {
        cout << "Enter Flight Number: ";
        getline(cin, flightNumber);
        cout << "Enter Destination: ";
        getline(cin, destination);
        cout << "Enter Departure Time (YYYY-MM-DD HH:MM): ";
        getline(cin, departureTime);
        cout << "Enter Seat Capacity: ";
        cin >> seatCapacity;
        cin.ignore();
        cout << "Enter Price: ";
        cin >> price;
        cin.ignore();
        seats.assign(seatCapacity, false);
        cout << "Flight added successfully.\n";
    }

    void edit() override {
        cout << "Editing Flight " << flightNumber << endl;
        cout << "Enter new Destination (current: " << destination << "): ";
        string input;
        getline(cin, input);
        if (!input.empty()) destination = input;

        cout << "Enter new Departure Time (current: " << departureTime << "): ";
        getline(cin, input);
        if (!input.empty()) departureTime = input;

        cout << "Enter new Seat Capacity (current: " << seatCapacity << "): ";
        getline(cin, input);
        if (!input.empty()) {
            int newCapacity = stoi(input);
            if (newCapacity != seatCapacity) {
                if (newCapacity < seatCapacity) {
                    seats.resize(newCapacity);
                } else {
                    seats.resize(newCapacity, false);
                }
                seatCapacity = newCapacity;
            }
        }

        cout << "Enter new Price (current: " << price << "): ";
        getline(cin, input);
        if (!input.empty()) price = stof(input);

        cout << "Flight updated successfully.\n";
    }

    void deleteEntry() override {
        // This method is a placeholder; deletion will be handled externally.
    }

    void display() const override {
        cout << "Flight Number: " << flightNumber
             << " | Destination: " << destination
             << " | Departure: " << departureTime
             << " | Price: $" << price
             << " | Seats: " << seatCapacity << endl;
    }

    bool isSeatAvailable(int seatNumber) const {
        if (seatNumber < 1 || seatNumber > seatCapacity) return false;
        return !seats[seatNumber - 1];
    }

    bool bookSeat(int seatNumber) {
        if (isSeatAvailable(seatNumber)) {
            seats[seatNumber - 1] = true;
            return true;
        }
        return false;
    }

    void freeSeat(int seatNumber) {
        if (seatNumber >= 1 && seatNumber <= seatCapacity) {
            seats[seatNumber - 1] = false;
        }
    }

    const string& getFlightNumber() const { return flightNumber; }
    const string& getDestination() const { return destination; }
    int getSeatCapacity() const { return seatCapacity; }
    float getPrice() const { return price; }
};

class Booking : public FlightBase {
private:
    string bookingID;
    string passengerName;
    string flightNumber;
    int seatNumber;

public:
    Booking() : bookingID(""), passengerName(""), flightNumber(""), seatNumber(0) {}

    Booking(const string& bID, const string& pName, const string& fNumber, int seatNum)
        : bookingID(bID), passengerName(pName), flightNumber(fNumber), seatNumber(seatNum) {}

    void add() override {
        cout << "Enter Booking ID: ";
        getline(cin, bookingID);
        cout << "Enter Passenger Name: ";
        getline(cin, passengerName);
        cout << "Enter Flight Number: ";
        getline(cin, flightNumber);
        cout << "Enter Seat Number: ";
        string input;
        getline(cin, input);
        seatNumber = stoi(input);
        cout << "Booking added successfully.\n";
    }

    void edit() override {
        cout << "Editing Booking " << bookingID << endl;
        cout << "Enter new Passenger Name (current: " << passengerName << "): ";
        string input;
        getline(cin, input);
        if (!input.empty()) passengerName = input;

        cout << "Enter new Flight Number (current: " << flightNumber << "): ";
        getline(cin, input);
        if (!input.empty()) flightNumber = input;

        cout << "Enter new Seat Number (current: " << seatNumber << "): ";
        getline(cin, input);
        if (!input.empty()) seatNumber = stoi(input);

        cout << "Booking updated successfully.\n";
    }

    void deleteEntry() override {
        // This method is a placeholder; deletion will be handled externally.
    }

    void display() const override {
        cout << "Booking ID: " << bookingID
             << " | Passenger Name: " << passengerName
             << " | Flight Number: " << flightNumber
             << " | Seat Number: " << seatNumber << endl;
    }

    const string& getBookingID() const { return bookingID; }
    const string& getFlightNumber() const { return flightNumber; }
    int getSeatNumber() const { return seatNumber; }
    const string& getPassengerName() const { return passengerName; }

    friend void displayBookingSummary(const Booking& booking);
};

void displayBookingSummary(const Booking& booking) {
    cout << "Booking Summary:\n";
    cout << "Booking ID: " << booking.bookingID << "\n";
    cout << "Passenger Name: " << booking.passengerName << "\n";
    cout << "Flight Number: " << booking.flightNumber << "\n";
    cout << "Seat Number: " << booking.seatNumber << "\n";
}

class FlightBookingSystem {
private:
    Flight** flights;
    Booking** bookings;
    int flightCount;
    int bookingCount;
    int flightCapacity;
    int bookingCapacity;

    void resizeFlights() {
        int newCapacity = flightCapacity * 2;
        Flight** newFlights = new Flight*[newCapacity];
        for (int i = 0; i < flightCount; ++i) {
            newFlights[i] = flights[i];
        }
        delete[] flights;
        flights = newFlights;
        flightCapacity = newCapacity;
    }

    void resizeBookings() {
        int newCapacity = bookingCapacity * 2;
        Booking** newBookings = new Booking*[newCapacity];
        for (int i = 0; i < bookingCount; ++i) {
            newBookings[i] = bookings[i];
        }
        delete[] bookings;
        bookings = newBookings;
        bookingCapacity = newCapacity;
    }

    int findFlightIndex(const string& flightNumber) const {
        for (int i = 0; i < flightCount; ++i) {
            if (flights[i]->getFlightNumber() == flightNumber) {
                return i;
            }
        }
        return -1;
    }

    int findBookingIndex(const string& bookingID) const {
        for (int i = 0; i < bookingCount; ++i) {
            if (bookings[i]->getBookingID() == bookingID) {
                return i;
            }
        }
        return -1;
    }

public:
    FlightBookingSystem()
        : flightCount(0), bookingCount(0), flightCapacity(10), bookingCapacity(10) {
        flights = new Flight*[flightCapacity];
        bookings = new Booking*[bookingCapacity];
    }

    ~FlightBookingSystem() {
        for (int i = 0; i < flightCount; ++i) {
            delete flights[i];
        }
        delete[] flights;

        for (int i = 0; i < bookingCount; ++i) {
            delete bookings[i];
        }
        delete[] bookings;
    }

    void loadPredefinedFlights() {
        // Adding some predefined flights
        addFlight(new Flight("FL123", "New York", "2025-02-01 10:00", 18, 350.0f));
        addFlight(new Flight("FL456", "London", "2025-02-02 15:00", 12, 400.0f));
        addFlight(new Flight("FL789", "Tokyo", "2025-02-03 20:00", 24, 500.0f));
        addFlight(new Flight("FL012", "Beijing", "2025-02-04 00:00", 24, 700.0f));
        addFlight(new Flight("FL045", "Seoul", "2025-02-05 05:00", 24, 1100.0f));
    }

    void addFlight(Flight* flight) {
        if (flightCount == flightCapacity) {
            resizeFlights();
        }
        flights[flightCount++] = flight;
    }

    void addBooking(Booking* booking) {
        if (bookingCount == bookingCapacity) {
            resizeBookings();
        }
        bookings[bookingCount++] = booking;
    }

    void displayFlights() const {
        cout << "\nAvailable Flights:\n";
        for (int i = 0; i < flightCount; ++i) {
            flights[i]->display();
        }
    }

    void displayBookings() const {
        if (bookingCount == 0) {
            cout << "\nNo bookings available.\n";
            return;
        }
        cout << "\nAll Bookings:\n";
        for (int i = 0; i < bookingCount; ++i) {
            bookings[i]->display();
        }
    }

    void bookTicket() {
        displayFlights();
        cout << "\nEnter Flight Number to book: ";
        string flightNumber;
        getline(cin, flightNumber);
        // convert to uppercase for comparison
        transform(flightNumber.begin(), flightNumber.end(), flightNumber.begin(), ::toupper);

        int flightIndex = findFlightIndex(flightNumber);
        if (flightIndex == -1) {
            cout << "Flight not found!\n";
            return;
        }
        Flight* flight = flights[flightIndex];

        cout << "Enter number of passengers: ";
        int passengerCount;
        cin >> passengerCount;
        cin.ignore();

        if (passengerCount < 1 || passengerCount > 50) {
            cout << "Number of passengers must be between 1 and 50.\n";
            return;
        }

        cout << "\nAvailable Seats for Flight " << flightNumber << ":\n";
        int columns = 6;
        int availableSeats = 0;
        for (int i = 0; i < flight->getSeatCapacity(); ++i) {
            if (flight->isSeatAvailable(i + 1)) {
                cout << "[" << i + 1 << "] ";
                availableSeats++;
            } else {
                cout << "[ X ] ";
            }
            if ((i + 1) % columns == 0) cout << "\n";
        }
        cout << "\n";

        if (availableSeats < passengerCount) {
            cout << "Not enough available seats for all passengers.\n";
            return;
        }

        for (int i = 0; i < passengerCount; ++i) {
            cout << "Enter Seat Number for Passenger " << i + 1 << ": ";
            int seatNum;
            cin >> seatNum;
            cin.ignore();

            if (!flight->isSeatAvailable(seatNum)) {
                cout << "Invalid or already booked seat number!\n";
                --i; // retry this passenger
                continue;
            }

            cout << "Enter Passenger " << i + 1 << " Name: ";
            string passengerName;
            getline(cin, passengerName);

            // Generate booking ID: FL + first two uppercase letters of destination + seat number
            string code = flight->getDestination().substr(0, 2);
            transform(code.begin(), code.end(), code.begin(), ::toupper);
            string bookingID = "FL" + code + to_string(seatNum);

            Booking* newBooking = new Booking(bookingID, passengerName, flightNumber, seatNum);
            addBooking(newBooking);
            flight->bookSeat(seatNum);

            cout << "Booking successful for passenger " << passengerName << " with Booking ID: " << bookingID << "\n";
        }
    }

    void cancelTicket() {
        cout << "Enter Booking ID to cancel: ";
        string bookingID;
        getline(cin, bookingID);

        int bookingIndex = findBookingIndex(bookingID);
        if (bookingIndex == -1) {
            cout << "Booking not found!\n";
            return;
        }

        Booking* booking = bookings[bookingIndex];
        int flightIndex = findFlightIndex(booking->getFlightNumber());
        if (flightIndex != -1) {
            flights[flightIndex]->freeSeat(booking->getSeatNumber());
        }

        delete booking;
        for (int i = bookingIndex; i < bookingCount - 1; ++i) {
            bookings[i] = bookings[i + 1];
        }
        bookingCount--;

        cout << "Booking canceled successfully. The seat has been freed.\n";
    }

    void displayMenu() {
        cout << "\n--- Flight Ticket Booking System ---\n";
        cout << "1. Search Flights\n";
        cout << "2. Book a Ticket\n";
        cout << "3. View Bookings\n";
        cout << "4. Cancel a Ticket\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
    }
};

int main() {
    FlightBookingSystem system;
    system.loadPredefinedFlights();

    while (true) {
        system.displayMenu();
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                system.displayFlights();
                break;
            case 2:
                system.bookTicket();
                break;
            case 3:
                system.displayBookings();
                break;
            case 4:
                system.cancelTicket();
                break;
            case 5:
                cout << "Exiting system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}