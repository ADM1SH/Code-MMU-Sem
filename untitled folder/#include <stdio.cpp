#include <stdio.h>

int main()
{
    char name[50];       // To store the guest's name
    char roomCode;       // Room code input
    int days;            // Number of days
    float roomPrice = 0; // Room price initialized to 0
    char roomType[20];   // To store the room type
    int valid = 0;       // Flag to check if input is valid

    // Display room options
    printf("---------------------------------------------------\n");
    printf("             WELCOME TO LEGEND HOTEL\n");
    printf("---------------------------------------------------\n");
    printf("Room Options:\n");
    printf("1 or D - Deluxe          RM 200.00\n");
    printf("2 or T - Twin Sharing    RM 170.00\n");
    printf("3 or S - Single          RM 120.00\n\n");

    // Input: Guest name
    printf("Enter your name: ");
    scanf("%49s", name);

    // Loop until a valid room code is entered
    while (!valid)
    {
        printf("Enter room code (1/D, 2/T, 3/S): ");
        scanf(" %c", &roomCode); // Space before %c to handle whitespace

        switch (roomCode)
        {
        case '1':
        case 'D':
        case 'd':
            roomPrice = 200.00;
            sprintf(roomType, "Deluxe");
            valid = 1; // Mark as valid input
            break;

        case '2':
        case 'T':
        case 't':
            roomPrice = 170.00;
            sprintf(roomType, "Twin Sharing");
            valid = 1; // Mark as valid input
            break;

        case '3':
        case 'S':
        case 's':
            roomPrice = 120.00;
            sprintf(roomType, "Single");
            valid = 1; // Mark as valid input
            break;

        default:
            printf("Invalid room code! Please enter a valid code.\n");
        }
    }

    // Input: Number of days
    printf("Enter number of days: ");
    scanf("%d", &days);

    // Calculate total payment
    float totalPayment = roomPrice * days;

    // Display result
    printf("\n---------------------------------------------------\n");
    printf("                  PAYMENT SUMMARY\n");
    printf("---------------------------------------------------\n");
    printf("Guest Name   : %s\n", name);
    printf("Room Type    : %s\n", roomType);
    printf("Room Price   : RM %.2f per night\n", roomPrice);
    printf("Number of Days: %d\n", days);
    printf("Total Payment: RM %.2f\n", totalPayment);
    printf("---------------------------------------------------\n");

    return 0;
}