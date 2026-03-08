#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For tolower function

// Structures
typedef struct {
    char flightNumber[10];
    char destination[50];
    char shortName[10];
    char departureTime[20];
    int seatCapacity;
    int seats[100]; // Array to track seat availability (1 = booked, 0 = available)
    float price;
} Flight;

typedef struct {
    char bookingID[20];
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
int validateStringInput(char *input, int size);

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
    clearBuffer(); // Clear any leftover input
    return value;
}

// Validate string input to ensure it's only alphabetic characters
int validateStringInput(char *input, int size) {
    fgets(input, size, stdin);
    input[strcspn(input, "\n")] = '\0';

    for (int i = 0; input[i] != '\0'; i++) {
        if (!isalpha(input[i]) && input[i] != ' ') {
            return 0; // Invalid input
        }
    }
    return 1; // Valid input
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
    strcpy(flights[0].flightNumber, "FL123");
    strcpy(flights[0].destination, "New York");
    strcpy(flights[0].shortName, "NY");
    strcpy(flights[0].departureTime, "2025-02-01 10:00");
    flights[0].seatCapacity = 18;
    flights[0].price = 350.0;
    memset(flights[0].seats, 0, sizeof(flights[0].seats));

    // Initialize flight 2
    strcpy(flights[1].flightNumber, "FL456");
    strcpy(flights[1].destination, "London");
    strcpy(flights[1].shortName, "L");
    strcpy(flights[1].departureTime, "2025-02-02 15:00");
    flights[1].seatCapacity = 12;
    flights[1].price = 400.0;
    memset(flights[1].seats, 0, sizeof(flights[1].seats));

    // Initialize flight 3
    strcpy(flights[2].flightNumber, "FL789");
    strcpy(flights[2].destination, "Tokyo");
    strcpy(flights[2].shortName, "JP");
    strcpy(flights[2].departureTime, "2025-02-03 20:00");
    flights[2].seatCapacity = 24;
    flights[2].price = 500.0;
    memset(flights[2].seats, 0, sizeof(flights[2].seats));

    // Initialize flights 4
    strcpy(flights[3].flightNumber, "FL321");
    strcpy(flights[3].destination, "Paris");
    strcpy(flights[3].shortName, "FR");
    strcpy(flights[3].departureTime, "2025-02-04 12:00");
    flights[3].seatCapacity = 20;
    flights[3].price = 450.0;
    memset(flights[3].seats, 0, sizeof(flights[3].seats));

    // Initialize flight 5
    strcpy(flights[4].flightNumber, "FL654");
    strcpy(flights[4].destination, "Sydney");
    strcpy(flights[4].shortName, "AU");
    strcpy(flights[4].departureTime, "2025-02-05 18:00");
    flights[4].seatCapacity = 15;
    flights[4].price = 550.0;
    memset(flights[4].seats, 0, sizeof(flights[4].seats));

    flightCount = 5;
}

// Load bookings from file
void loadBookings() {
    FILE *file = fopen("bookings.txt", "r");
    if (!file) return;

    while (fscanf(file, "%s %s %s %d\n", bookings[bookingCount].bookingID,
                  bookings[bookingCount].passengerName,
                  bookings[bookingCount].flightNumber,
                  &bookings[bookingCount].seatNumber) != EOF) {
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
    int seatNumber, numPassengers;
    const int columns = 6; // Seats per row for display

    searchFlights(); // Display available flights

    printf("\nEnter Flight Number: ");
    scanf("%s", flightNumber);
    clearBuffer();

    toLowerCase(flightNumber);

    int flightIndex = -1;
    for (int i = 0; i < flightCount; i++) {
        char storedFlightNumber[10];
        strcpy(storedFlightNumber, flights[i].flightNumber);
        toLowerCase(storedFlightNumber);

        if (strcmp(storedFlightNumber, flightNumber) == 0) {
            flightIndex = i;
            break;
        }
    }

    if (flightIndex == -1) {
        printf("Flight not found!\n");
        return;
    }

    printf("\nHow many passengers? ");
    numPassengers = validateNumericInput();

    if (numPassengers > flights[flightIndex].seatCapacity) {
        printf("Not enough seats available for %d passengers.\n", numPassengers);
        return;
    }

    for (int p = 0; p < numPassengers; p++) {
        printf("\nBooking for Passenger %d\n", p + 1);

        printf("Available Seats for Flight %s:\n", flights[flightIndex].flightNumber);
        int availableSeats = 0;
        for (int i = 0; i < flights[flightIndex].seatCapacity; i++) {
            if (flights[flightIndex].seats[i] == 0) {
                printf("[%2d] ", i + 1);
                availableSeats++;
            } else {
                printf("[ X ] ");
            }

            if ((i + 1) % columns == 0) printf("\n");
        }

        if (availableSeats == 0) {
            printf("\nNo seats available on this flight.\n");
            return;
        }

        printf("\n\nEnter Seat Number: ");
        seatNumber = validateNumericInput();

        if (seatNumber < 1 || seatNumber > flights[flightIndex].seatCapacity ||
            flights[flightIndex].seats[seatNumber - 1] == 1) {
            printf("Invalid or already booked seat number!\n");
            p--; // Retry for the same passenger
            continue;
        }

        printf("Enter Passenger Name: ");
        while (!validateStringInput(passengerName, sizeof(passengerName))) {
            printf("Invalid input! Please enter a valid name: ");
        }

        flights[flightIndex].seats[seatNumber - 1] = 1;

        sprintf(bookings[bookingCount].bookingID, "%s-%s%d", flights[flightIndex].flightNumber, flights[flightIndex].shortName, seatNumber);
        strcpy(bookings[bookingCount].passengerName, passengerName);
        strcpy(bookings[bookingCount].flightNumber, flights[flightIndex].flightNumber);
        bookings[bookingCount].seatNumber = seatNumber;
        bookingCount++;

        printf("Booking successful! Your booking ID is %s.\n", bookings[bookingCount - 1].bookingID);
    }
}

// View all bookings
void viewBookings() {
    char passengerName[50];
    printf("\nEnter your name to view bookings: ");
    while (!validateStringInput(passengerName, sizeof(passengerName))) {
        printf("Invalid input! Please enter a valid name: ");
    }

    int found = 0;
    printf("\nYour Bookings:\n");
    for (int i = 0; i < bookingCount; i++) {
        if (strcmp(bookings[i].passengerName, passengerName) == 0) {
            printf("Booking ID: %s | Flight Number: %s | Seat Number: %d\n",
                   bookings[i].bookingID, bookings[i].flightNumber,
                   bookings[i].seatNumber);
            found = 1;
        }
    }

    if (!found) {
        printf("No bookings found for %s.\n", passengerName);
    }
}

// Cancel a ticket
void cancelTicket() {
    printf("\nEnter Booking ID to cancel: ");
    char bookingID[20];
    scanf("%s", bookingID);
    clearBuffer();

    int bookingIndex = -1;
    for (int i = 0; i < bookingCount; i++) {
        if (strcmp(bookings[i].bookingID, bookingID) == 0) {
            bookingIndex = i;
            break;
        }
    }

    if (bookingIndex == -1) {
        printf("Booking not found!\n");
        return;
    }

    int flightIndex = -1;
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, bookings[bookingIndex].flightNumber) == 0) {
            flightIndex = i;
            break;
        }
    }

    if (flightIndex != -1) {
        flights[flightIndex].seats[bookings[bookingIndex].seatNumber - 1] = 0;
    }

    for (int i = bookingIndex; i < bookingCount - 1; i++) {
        bookings[i] = bookings[i + 1];
    }
    bookingCount--;

    printf("Booking canceled successfully.\n");
}
