#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const float ticket_price = 300;

struct Flight_info //just for flight info/details output
{
    char Flight_code[50];
    char Destinations[50];
    int Flight_seats;
    float Flight_price;
};

struct Passenger_data
{
    char Pass_Flight_code[50];
    char Pass_Destinations[50];
    char Pass_Flight_Class[50];
    char Ticket_Type[50];
    int Pass_Flight_MAXseats;
    int Pass_Flight_NOWSeats;
    float Pass_Flight_cost;
    int adult_tickets;
    int child_tickets;
    int infant_tickets;
    char seat_placement[50]; //still confused with this
    char Departure_date[50];
    char return_date[50];
    float total_price;
};

void display_menu();
int read_valid_integer(const char *prompt);
void Book_Flight();
void View_Booked_Flights();
int Terminal_options();
void Available_Flights();
void Book_Flight();
float Calculate_sum_tickets(float x, float y, float z);
void Save_bookings(struct Passenger_data passdata);
void View_Booked_Flights();
void Cancel_Booked_Flight(); // Function name changed here
void Print_Receipt(struct Passenger_data passdata);

int main()
{
    int choice;
    
    while(choice != 5)
    {
        choice = Terminal_options();

        switch(choice)
        {
            case 1:
                printf("\033[H\033[J"); //clean terminal
                Available_Flights();
                break;
            case 2:
                printf("\033[H\033[J"); //clean terminal
                Book_Flight();
                break;
            case 3:
                printf("\033[H\033[J"); //clean terminal
                View_Booked_Flights();
                break;
            case 4:
                printf("\033[H\033[J"); //clean terminal
                Cancel_Booked_Flight(); // Calling the correct function
                break;
            case 5:
                printf("\033[H\033[J"); //clean terminal
                exit(0);
                break;
        }

        if(choice > 5)
        {
            printf("\033[H\033[J"); //clean terminal
            printf("\n\n\n\033[1;31mWrong input entered!\033[0m\n");
        }
    }

    return 0;
}

int Terminal_options()
{
    int choice;

        printf("\n\n\n===================================\n");
        printf("Welcome to trip.com flight booking");
        printf("\n===================================\n");
        printf("1. Currently Available Flights");
        printf("\n2. Book Flight");
        printf("\n3. View Booked Flights");
        printf("\n4. Cancel a Flight");
        printf("\n5. Exit Terminal");
        printf("\n===================================\n");
        printf("What would you like to do? \nEnter Number : ");
        scanf("%d", &choice);

    return choice;
}

void Available_Flights()
{
    struct Flight_info flight_data[100];

        //0
        strcpy(flight_data[0].Flight_code, "BK475");
        strcpy(flight_data[0].Destinations, "Bangkok");
        flight_data[0].Flight_seats = 200;
        flight_data[0].Flight_price = 350;

        //1
        strcpy(flight_data[1].Flight_code, "TK452");
        strcpy(flight_data[1].Destinations, "Tokyo");
        flight_data[1].Flight_seats = 500;
        flight_data[1].Flight_price = 250;

        //2
        strcpy(flight_data[2].Flight_code, "LN475");
        strcpy(flight_data[2].Destinations, "London");
        flight_data[2].Flight_seats = 250;
        flight_data[2].Flight_price = 900;

        //3
        strcpy(flight_data[3].Flight_code, "SL285");
        strcpy(flight_data[3].Destinations, "Seoul");
        flight_data[3].Flight_seats = 400;
        flight_data[3].Flight_price = 800;

        //4
        strcpy(flight_data[4].Flight_code, "SG593");
        strcpy(flight_data[4].Destinations, "Singapore");
        flight_data[4].Flight_seats = 200;
        flight_data[4].Flight_price = 200;

        //5
        strcpy(flight_data[5].Flight_code, "TP786");
        strcpy(flight_data[5].Destinations, "Taipei");
        flight_data[5].Flight_seats = 350;
        flight_data[5].Flight_price = 600;

        //6
        strcpy(flight_data[6].Flight_code, "IS375");
        strcpy(flight_data[6].Destinations, "Istanbul");
        flight_data[6].Flight_seats = 450;
        flight_data[6].Flight_price = 950;

        //7
        strcpy(flight_data[7].Flight_code, "BL947");
        strcpy(flight_data[7].Destinations, "Bali");
        flight_data[7].Flight_seats = 350;
        flight_data[7].Flight_price = 750;

    
    for (int  i = 0; i < 8; i++)
    {
        printf("\n==============================================================================================\n");
        printf("Flight Code : \033[42m%s\033[0m || Destination : \033[42m%s\033[0m || Available Seats : \033[42m%d\033[0m || Flight Price : \033[42m%.2f\033[0m", flight_data[i].Flight_code, flight_data[i].Destinations, flight_data[i].Flight_seats, flight_data[i].Flight_price);
    }
        printf("\n==============================================================================================\n");
}

void Book_Flight()
{
    Available_Flights();

    int class_choice, ticket_choice;
    float adult_price, child_price, infant_price;
    struct Passenger_data pass_data;
    
    printf("\n\nEnter Flight Code : ");
    scanf("%s", &pass_data.Pass_Flight_code);

    if(strcmp(pass_data.Pass_Flight_code, "BK475") == 0)
    {
        strcpy(pass_data.Pass_Destinations, "Bangkok");
        pass_data.Pass_Flight_MAXseats = 200;
        pass_data.Pass_Flight_cost = 350;
    }
    else if (strcmp(pass_data.Pass_Flight_code, "TK452") == 0)
    {
         strcpy(pass_data.Pass_Destinations, "Tokyo");
         pass_data.Pass_Flight_MAXseats = 500;
         pass_data.Pass_Flight_cost = 250;
    }
    else if (strcmp(pass_data.Pass_Flight_code, "LN475") == 0)
    {
         strcpy(pass_data.Pass_Destinations, "London");
         pass_data.Pass_Flight_MAXseats = 250;
         pass_data.Pass_Flight_cost = 900;
    }
    else if (strcmp(pass_data.Pass_Flight_code, "SL285") == 0)
    {
         strcpy(pass_data.Pass_Destinations, "Seoul");
         pass_data.Pass_Flight_MAXseats = 400;
         pass_data.Pass_Flight_cost = 800;
    }
    else if (strcmp(pass_data.Pass_Flight_code, "SG593") == 0)
    {
         strcpy(pass_data.Pass_Destinations, "Singapore");
         pass_data.Pass_Flight_MAXseats = 200;
         pass_data.Pass_Flight_cost = 200;
    }
    else if (strcmp(pass_data.Pass_Flight_code, "TP786") == 0)
    {
         strcpy(pass_data.Pass_Destinations, "Taipei");
         pass_data.Pass_Flight_MAXseats = 350;
         pass_data.Pass_Flight_cost = 600;
    }
    else if (strcmp(pass_data.Pass_Flight_code, "IS375") == 0)
    {
         strcpy(pass_data.Pass_Destinations, "Istanbul");
         pass_data.Pass_Flight_MAXseats = 450;
         pass_data.Pass_Flight_cost = 950;
    }
    else if (strcmp(pass_data.Pass_Flight_code, "BL947") == 0)
    {
         strcpy(pass_data.Pass_Destinations, "Bali");
         pass_data.Pass_Flight_MAXseats = 350;
         pass_data.Pass_Flight_cost = 350;
    }
    else
    {
        printf("\033[H\033[J");//clean terminal
        printf("\033[1;31mInvalid Flight Code!\033[0m");
        return;//go back to main menu
    }

    printf("\033[H\033[J");//clean terminal
    printf("\n[1] One-Way || [2] Round-Trip\n");
    printf("Enter your preferred ticket type : ");
    scanf("%d", &ticket_choice);

    switch(ticket_choice)
    {
        case 1:
            strcpy(pass_data.Ticket_Type, "One-Way");
            break;
        case 2:
            strcpy(pass_data.Ticket_Type, "Round-Trip");
            break;
        default:
            printf("\033[H\033[J");//clean terminal
            printf("\033[1;31mInvalid ticket type!\033[0m");
            return;//go back to main menu
    }

    printf("\033[H\033[J");//clean terminal
    printf("How many Passengers?\n");
    printf("Adult : ");
    scanf("%d", &pass_data.adult_tickets);

    printf("Child : ");
    scanf("%d", &pass_data.child_tickets);

    printf("Infant : ");
    scanf("%d", &pass_data.infant_tickets);

    pass_data.Pass_Flight_NOWSeats = pass_data.adult_tickets + pass_data.child_tickets + pass_data.infant_tickets;

    // Check seat availability
    if (pass_data.Pass_Flight_NOWSeats > pass_data.Pass_Flight_MAXseats)
    {
        printf("\033[H\033[J");
        printf("\033[1;31mNot enough seats available for booking!\033[0m");
        return; // Go back to menu
    }

    pass_data.total_price = Calculate_sum_tickets(pass_data.adult_tickets, pass_data.child_tickets, pass_data.infant_tickets);
    Save_bookings(pass_data);

    Print_Receipt(pass_data);
}

float Calculate_sum_tickets(float x, float y, float z)
{
    return (x + y + z) * ticket_price;
}

void Save_bookings(struct Passenger_data passdata)
{
    FILE *file = fopen("bookings.txt", "a");
    if (file != NULL)
    {
        fprintf(file, "Flight Code: %s\n", passdata.Pass_Flight_code);
        fprintf(file, "Destination: %s\n", passdata.Pass_Destinations);
        fprintf(file, "Ticket Type: %s\n", passdata.Ticket_Type);
        fprintf(file, "Number of Adults: %d\n", passdata.adult_tickets);
        fprintf(file, "Number of Children: %d\n", passdata.child_tickets);
        fprintf(file, "Number of Infants: %d\n", passdata.infant_tickets);
        fprintf(file, "Total Price: %.2f\n", passdata.total_price);
        fprintf(file, "Total Seats Booked: %d\n", passdata.Pass_Flight_NOWSeats);
        fprintf(file, "\n========================================\n");
        fclose(file);
    }
    else
    {
        printf("Unable to save booking.");
    }
}

void Print_Receipt(struct Passenger_data passdata)
{
    printf("\nReceipt:\n");
    printf("Flight Code: %s\n", passdata.Pass_Flight_code);
    printf("Destination: %s\n", passdata.Pass_Destinations);
    printf("Ticket Type: %s\n", passdata.Ticket_Type);
    printf("Number of Adults: %d\n", passdata.adult_tickets);
    printf("Number of Children: %d\n", passdata.child_tickets);
    printf("Number of Infants: %d\n", passdata.infant_tickets);
    printf("Total Price: %.2f\n", passdata.total_price);
    printf("Total Seats Booked: %d\n", passdata.Pass_Flight_NOWSeats);
}

void Cancel_Booked_Flight()
{
    // Implementation for canceling a booked flight
    // You'll have to implement this with some way to track and remove bookings.
}