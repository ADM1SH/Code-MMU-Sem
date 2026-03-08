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
    char bookingID[20]; // Changed from int to char array
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

// Display the main menu
void displayMenu() {
    printf("\n--- Flight Ticket Booking System ---\n");
    printf("1. Search Flights\n");
    printf("2. Book a Ticket\n");
    printf("3. View Bookings\n");
    printf("4. Cancel a Ticket\n");
    printf("5. Exit\n");
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
    clearBuffer();
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
    flightCount = 3;

    strcpy(flights[0].flightNumber, "FL123");
    strcpy(flights[0].destination, "New York");
    strcpy(flights[0].departureTime, "2025-02-01 10:00");
    flights[0].seatCapacity = 18;
    flights[0].price = 350.0;
    memset(flights[0].seats, 0, sizeof(flights[0].seats));

    strcpy(flights[1].flightNumber, "FL456");
    strcpy(flights[1].destination, "London");
    strcpy(flights[1].departureTime, "2025-02-02 15:00");
    flights[1].seatCapacity = 12;
    flights[1].price = 400.0;
    memset(flights[1].seats, 0, sizeof(flights[1].seats));

    strcpy(flights[2].flightNumber, "FL789");
    strcpy(flights[2].destination, "Tokyo");
    strcpy(flights[2].departureTime, "2025-02-03 20:00");
    flights[2].seatCapacity = 24;
    flights[2].price = 500.0;
    memset(flights[2].seats, 0, sizeof(flights[2].seats));
}

// Load bookings from file
void loadBookings() {
    FILE *file = fopen("bookings.txt", "r");
    if (!file) return;

    while (fscanf(file, "%19s %49s %9s %d", 
                  bookings[bookingCount].bookingID,
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

// Book a ticket
void bookTicket() {
    char flightNumber[10], passengerName[50];
    int seatNumber;

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

    printf("Enter Seat Number: ");
    seatNumber = validateNumericInput();

    if (seatNumber < 1 || seatNumber > flights[flightIndex].seatCapacity || 
        flights[flightIndex].seats[seatNumber - 1] == 1) {
        printf("Invalid or already booked seat number!\n");
        return;
    }

    printf("Enter Passenger Name: ");
    fgets(passengerName, sizeof(passengerName), stdin);
    passengerName[strcspn(passengerName, "\n")] = '\0';

    // Assign booking ID
    snprintf(bookings[bookingCount].bookingID, sizeof(bookings[bookingCount].bookingID), 
             "%s-%d", flightNumber, seatNumber);

    strcpy(bookings[bookingCount].passengerName, passengerName);
    strcpy(bookings[bookingCount].flightNumber, flightNumber);
    bookings[bookingCount].seatNumber = seatNumber;

    flights[flightIndex].seats[seatNumber - 1] = 1;
    bookingCount++;

    printf("\nBooking successful! Your Booking ID: %s\n", bookings[bookingCount - 1].bookingID);
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

// Cancel a ticket
void cancelTicket() {
    printf("\nEnter Booking ID to cancel: ");
    char bookingID[20];
    scanf("%19s", bookingID);

    for (int i = 0; i < bookingCount; i++) {
        if (strcmp(bookings[i].bookingID, bookingID) == 0) {
            printf("Booking canceled successfully.\n");
            bookings[i] = bookings[--bookingCount];
            return;
        }
    }

    printf("Booking not found!\n");
}
