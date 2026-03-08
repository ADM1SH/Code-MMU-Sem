#include <stdio.h>

#define SIZE 3

// Define the structure
struct HotelBooking {
    char cust_name[50];
    char room_type;
    float price;
    int no_room;
    float total_price;
};

int main() {
    struct HotelBooking bookings[SIZE];
    FILE *file = fopen("customerbooking.txt", "w");  // Open file for writing

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        printf("Customer name: ");
        scanf(" %49[^\n]", bookings[i].cust_name);  // Read full name safely

        printf("Room Type (S/D/F/P): ");
        scanf(" %c", &bookings[i].room_type);

        printf("Number of Rooms: ");
        scanf("%d", &bookings[i].no_room);

        // Determine room price based on type
        switch (bookings[i].room_type) {
            case 'S': bookings[i].price = 300.00; break;
            case 'D': bookings[i].price = 350.00; break;
            case 'F': bookings[i].price = 450.00; break;
            case 'P': bookings[i].price = 800.00; break;
            default:
                printf("Invalid room type! Try again.\n");
                i--;  // Repeat the iteration for valid input
                continue;
        }

        // Calculate total price
        bookings[i].total_price = bookings[i].price * bookings[i].no_room;

        // Write to file
        fprintf(file, "Name: %s\n", bookings[i].cust_name);
        fprintf(file, "Booking: %d ", bookings[i].no_room);

        // Print room type description
        switch (bookings[i].room_type) {
            case 'S': fprintf(file, "Standard Room\n"); break;
            case 'D': fprintf(file, "Deluxe Room\n"); break;
            case 'F': fprintf(file, "Family Room\n"); break;
            case 'P': fprintf(file, "Presidential Suite\n"); break;
        }

        fprintf(file, "Total price: RM %.2f\n\n", bookings[i].total_price);
    }

    fclose(file);
    printf("Booking records saved to customerbooking.txt\n");

    return 0;
}