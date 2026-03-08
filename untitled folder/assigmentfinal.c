#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For tolower function

// Structures
typedef struct {
    char flightNumber[10];
    char destination[50];
    char departureTime[20];
    int seatCapacity;
    int seats[100]; // Array to track seat availability (1 = booked, 0 = available)
    float price;
} Flight;

typedef struct {
    char bookingID[20];  // Changed to char array for string IDs
    char passengerName[50];
    char flightNumber[10];
    int seatNumber;
} Booking;

// Global Variables
Flight flights[100];
Booking bookings[100];
int flightCount = 0, bookingCount = 0;

// Function Prototypes
void loadFlights();
void loadBookings();
void saveBookings();
void displayMenu();
void searchFlights();
void bookTicket();
void viewBookings();
void cancelTicket();
void clearBuffer();
int validateNumericInput();
void toLowerCase(char *str);

int main() {
    loadFlights();
    loadBookings();

    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        choice = validateNumericInput();

        switch (choice) {
            case 1: searchFlights(); break;
            case 2: bookTicket(); break;
            case 3: viewBookings(); break;
            case 4: cancelTicket(); break;
            case 5: saveBookings(); printf("Exiting system. Goodbye!\n"); return 0;
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function Definitions

// Display the main menu
void displayMenu() {
    printf("\n--- Flight Ticket Booking System ---\n");
    printf("1. Search Flights\n");
    printf("2. Book a Ticket\n");
    printf("3. View Bookings\n");
    printf("4. Cancel a Ticket\n");
    printf("5. Exit\n\n"); // Added another newline - Idham
}

// Clear the input buffer
void clearBuffer() {
    while (getchar() != '\n');
}

// Validate numeric input to prevent infinite loops
int validateNumericInput() {
    int value;
    while (scanf("%d", &value) != 1) {
        printf("Invalid input! Please enter a valid number: ");
        clearBuffer();
    }
    clearBuffer(); // Clear any leftover input
    return value;
}

// Convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Load predefined flights
void loadFlights() {
    // Initialize flight 1
    strncpy(flights[0].flightNumber, "FL123", sizeof(flights[0].flightNumber) - 1);
    strncpy(flights[0].destination, "New York", sizeof(flights[0].destination) - 1);
    strncpy(flights[0].departureTime, "2025-02-01 10:00", sizeof(flights[0].departureTime) - 1);
    flights[0].seatCapacity = 18;
    flights[0].price = 350.0;
    memset(flights[0].seats, 0, sizeof(flights[0].seats));

    // Initialize flight 2
    strncpy(flights[1].flightNumber, "FL456", sizeof(flights[1].flightNumber) - 1);
    strncpy(flights[1].destination, "London", sizeof(flights[1].destination) - 1);
    strncpy(flights[1].departureTime, "2025-02-02 15:00", sizeof(flights[1].departureTime) - 1);
    flights[1].seatCapacity = 12;
    flights[1].price = 400.0;
    memset(flights[1].seats, 0, sizeof(flights[1].seats));

    // Initialize flight 3
    strncpy(flights[2].flightNumber, "FL789", sizeof(flights[2].flightNumber) - 1);
    strncpy(flights[2].destination, "Tokyo", sizeof(flights[2].destination) - 1);
    strncpy(flights[2].departureTime, "2025-02-03 20:00", sizeof(flights[2].departureTime) - 1);
    flights[2].seatCapacity = 24;
    flights[2].price = 500.0;
    memset(flights[2].seats, 0, sizeof(flights[2].seats));

    // Start - Idham
    // Added two more flight destinations

    // Initialize flight 4
    strncpy(flights[3].flightNumber, "FL012", sizeof(flights[3].flightNumber) - 1);
    strncpy(flights[3].destination, "Beijing", sizeof(flights[3].destination) - 1);
    strncpy(flights[3].departureTime, "2025-02-04 00:00", sizeof(flights[3].departureTime) - 1);
    flights[3].seatCapacity = 24;
    flights[3].price = 700.0;
    memset(flights[3].seats, 0, sizeof(flights[3].seats));

    // Initialize flight 5
    strncpy(flights[4].flightNumber, "FL045", sizeof(flights[4].flightNumber) - 1);
    strncpy(flights[4].destination, "Seoul", sizeof(flights[4].destination) - 1);
    strncpy(flights[4].departureTime, "2025-02-05 05:00", sizeof(flights[4].departureTime) - 1);
    flights[4].seatCapacity = 24;
    flights[4].price = 1100.0;
    memset(flights[4].seats, 0, sizeof(flights[4].seats));    

    flightCount = 5;

    // End - Idham
}
// Load bookings from file
void loadBookings() {
    FILE *file = fopen("bookings.txt", "r");
    if (!file) return;

    while (fscanf(file, "%19s %49s %9s %d\n", bookings[bookingCount].bookingID,
                  bookings[bookingCount].passengerName,
                  bookings[bookingCount].flightNumber,
                  &bookings[bookingCount].seatNumber) == 4) {
        int flightIndex = -1;
        for (int i = 0; i < flightCount; i++) {
            if (strcmp(flights[i].flightNumber, bookings[bookingCount].flightNumber) == 0) {
                flightIndex = i;
                break;
            }
        }
        if (flightIndex != -1) {
            flights[flightIndex].seats[bookings[bookingCount].seatNumber - 1] = 1;
        }
        bookingCount++;
    }
    fclose(file);
}

// Save bookings to file
void saveBookings() {
    FILE *file = fopen("bookings.txt", "w");
    if (!file) {
        printf("Error saving bookings to file.\n");
        return;
    }

    for (int i = 0; i < bookingCount; i++) {
        fprintf(file, "%s %s %s %d\n", bookings[i].bookingID,
                bookings[i].passengerName,
                bookings[i].flightNumber,
                bookings[i].seatNumber);
    }
    fclose(file);
}

// Display available flights
void searchFlights() {
    printf("\nAvailable Flights:\n");
    for (int i = 0; i < flightCount; i++) {
        printf("Flight Number: %s | Destination: %s | Departure: %s | Price: $%.2f\n",
               flights[i].flightNumber, flights[i].destination,
               flights[i].departureTime, flights[i].price);
    }
}

// Book a ticket
void bookTicket() {
    char flightNumber[10];
    char passengerName[50];
    int seatNumber;

    searchFlights(); // Show available flights - Idham
    printf("\nEnter Flight Number: ");
    scanf("%9s", flightNumber);
    clearBuffer();

    int flightIndex = -1;
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            flightIndex = i;
            break;
        }
    }

    if (flightIndex == -1) {
        printf("Flight not found!\n");
        return;
    }

    printf("\nAvailable Seats for Flight %s:\n", flights[flightIndex].flightNumber);
    for (int i = 0; i < flights[flightIndex].seatCapacity; i++) {
        if (flights[flightIndex].seats[i] == 0) {
            printf("[%2d] ", i + 1);
        } else {
            printf("[ X ] ");
        }
        if ((i + 1) % 6 == 0) printf("\n");
    }

    printf("\nEnter Seat Number: ");
    seatNumber = validateNumericInput();

    if (seatNumber < 1 || seatNumber > flights[flightIndex].seatCapacity || 
        flights[flightIndex].seats[seatNumber - 1] == 1) {
        printf("Invalid or already booked seat number!\n");
        return;
    }

    printf("Enter Passenger Name: ");
    fgets(passengerName, sizeof(passengerName), stdin);
    passengerName[strcspn(passengerName, "\n")] = '\0';

    flights[flightIndex].seats[seatNumber - 1] = 1;

    sprintf(bookings[bookingCount].bookingID, "B%04d", bookingCount + 1);
    strcpy(bookings[bookingCount].passengerName, passengerName);
    strcpy(bookings[bookingCount].flightNumber, flights[flightIndex].flightNumber);
    bookings[bookingCount].seatNumber = seatNumber;
    bookingCount++;

    printf("\nBooking successful! Your Booking ID is %s\n", bookings[bookingCount - 1].bookingID);
}

// View all bookings
void viewBookings() {
    if (bookingCount == 0) {
        printf("\nNo bookings available.\n");
        return;
    }

    printf("\nAll Bookings:\n");
    for (int i = 0; i < bookingCount; i++) {
        printf("Booking ID: %s | Passenger Name: %s | Flight Number: %s | Seat Number: %d\n",
               bookings[i].bookingID, bookings[i].passengerName,
               bookings[i].flightNumber, bookings[i].seatNumber);
    }
}