#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const float ticket_price = 300;

/*
CORE FUNC NOT DONE YET:
seat_availability*/

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

int Terminal_options();
void Available_Flights();
void Book_Flight();
float Calculate_sum_tickets(float x, float y, float z);
void Save_bookings(struct Passenger_data passdata);
void View_Booked_Flights();
void Cancel_Booked_Flight();
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
                Cancel_Booked_Flight();
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
    printf("Infant (on lap baby) : ");
    scanf("%d", &pass_data.infant_tickets);

    printf("\033[H\033[J");//clean terminal
    printf("\n[1] Economy || [2] Premium-Economy || [3] Business || [4] First\n");
    printf("Enter Flight Class : ");
    scanf("%d", &class_choice);

    switch(class_choice)
    {
        case 1:
            strcpy(pass_data.Pass_Flight_Class, "Economy");
            adult_price = ticket_price * pass_data.adult_tickets;
            child_price = (ticket_price / 2) * pass_data.child_tickets;
            infant_price = (ticket_price / 10) * pass_data.infant_tickets;
            break;
        case 2:
            strcpy(pass_data.Pass_Flight_Class, "Premium-Economy");
            adult_price = (ticket_price + 200) * pass_data.adult_tickets;
            child_price = ((ticket_price / 2) + 100) * pass_data.child_tickets;
            infant_price = ((ticket_price / 10) + 20) * pass_data.infant_tickets;
            break;
        case 3:
            strcpy(pass_data.Pass_Flight_Class, "Business");
            adult_price = (ticket_price + 500) * pass_data.adult_tickets;
            child_price = ((ticket_price / 2) + 250) * pass_data.child_tickets;
            infant_price = ((ticket_price / 10) + 50) * pass_data.infant_tickets;
            break;
        case 4:
            strcpy(pass_data.Pass_Flight_Class, "First");
            adult_price = (ticket_price + 700) * pass_data.adult_tickets;
            child_price = ((ticket_price / 2) + 350) * pass_data.child_tickets;
            infant_price = ((ticket_price / 10) + 70) * pass_data.infant_tickets;
            break;
        default:
            printf("\033[H\033[J");
            printf("\033[1;31mInvalid Flight Class!\033[0m\n");
            return;//go back to main menu
    }

    int total_passengers = pass_data.adult_tickets + pass_data.child_tickets + pass_data.infant_tickets;
    pass_data.Pass_Flight_NOWSeats = pass_data.Pass_Flight_MAXseats - total_passengers; //calculate to reduce seat availability



    printf("\033[H\033[J");//clean terminal
    printf("\nEnter your departure date [e.g. 5/2/2025]: ");
    scanf("%s", &pass_data.Departure_date);
    if(strcmp(pass_data.Ticket_Type, "One-Way") == 0)
    {
        strcpy(pass_data.return_date, "-");
    }
    else
    {
        printf("Enter your return date [e.g. 10/2/2025]: ");
        scanf("%s", &pass_data.return_date);
    }

    pass_data.total_price = Calculate_sum_tickets(adult_price, child_price, infant_price);

    printf("\033[H\033[J");//clean terminal
    Print_Receipt(pass_data);
}

float Calculate_sum_tickets(float x, float y, float z)
{
    float total = x + y + z;

    return total;
}

void Save_bookings(struct Passenger_data passdata)
{
    FILE *fp;
    fp = fopen("SavedBookings.txt", "a");

    fprintf(fp, "\n%s\t %s\t %s\t %s\t %d\t %d\t %.2f\t %d\t %d\t %d\t %s\t %s\t %.2f", passdata.Pass_Flight_code, passdata.Pass_Destinations, passdata.Pass_Flight_Class, passdata.Ticket_Type, passdata.Pass_Flight_NOWSeats, passdata.Pass_Flight_MAXseats, passdata.Pass_Flight_cost, passdata.adult_tickets, passdata.child_tickets, passdata.infant_tickets, passdata.Departure_date, passdata.return_date, passdata.total_price);

    fclose(fp);
}

void View_Booked_Flights()
{
    struct Passenger_data passdata;
    FILE *peakaboo = fopen("SavedBookings.txt", "r");
    char user_flightcode[50];

    if(peakaboo == NULL)
    {
        printf("\033[H\033[J");
        printf("\n\n\033[1;31mThere is no bookings saved yet!\033[0m");
        return;
    }
    else
    {
        while(fscanf(peakaboo, "%s %s %s %s %d %d %f %d %d %d %s %s %f", passdata.Pass_Flight_code, passdata.Pass_Destinations, passdata.Pass_Flight_Class, passdata.Ticket_Type, &passdata.Pass_Flight_NOWSeats, &passdata.Pass_Flight_MAXseats, &passdata.Pass_Flight_cost, &passdata.adult_tickets, &passdata.child_tickets, &passdata.infant_tickets, passdata.Departure_date, passdata.return_date, &passdata.total_price) == 13)
        {
            int i;
            printf("\n\033[1;9%dmFlight Code\033[0m          : \033[1;4%dm%s\033[0m", i, i, passdata.Pass_Flight_code);
            printf("\n\033[1;9%dmDestination\033[0m          : \033[1;3%dm%s\033[0m", i, i, passdata.Pass_Destinations);
            printf("\n\033[1;9%dmFlight Class\033[0m         : \033[1;3%dm%s\033[0m", i, i, passdata.Pass_Flight_Class);
            printf("\n\033[1;9%dmTicket Type\033[0m          : \033[1;3%dm%s\033[0m", i, i, passdata.Ticket_Type);
            printf("\n\033[1;9%dmSeats\033[0m                : \033[1;3%dm%d/%d\033[0m", i, i, passdata.Pass_Flight_NOWSeats, passdata.Pass_Flight_MAXseats);
            printf("\n\033[1;9%dmFlight Cost\033[0m          : \033[1;3%dm%.2f\033[0m", i, i, passdata.Pass_Flight_cost);
            printf("\n\033[1;9%dmAdult Tickets\033[0m        : \033[1;3%dm%d\033[0m", i, i, passdata.adult_tickets);
            printf("\n\033[1;9%dmChild Tickets\033[0m        : \033[1;3%dm%d\033[0m", i, i, passdata.child_tickets);
            printf("\n\033[1;9%dmInfant Tickets\033[0m       : \033[1;3%dm%d\033[0m", i, i, passdata.infant_tickets);
            printf("\n\033[1;9%dmDeparture Date\033[0m       : \033[1;3%dm%s\033[0m", i, i, passdata.Departure_date);
            printf("\n\033[1;9%dmReturn Date\033[0m          : \033[1;3%dm%s\033[0m", i, i, passdata.return_date);
            printf("\n\033[1;9%dmTotal Price\033[0m          : \033[1;3%dm%.2f\033[0m\n\n", i, i, passdata.total_price);

            i++;
            if(i == 8)
            {
                i = 0;
                continue;
            }
        }
    }
}

void Cancel_Booked_Flight()
{
    
}

void Print_Receipt(struct Passenger_data passdata)
{
    char save_choice;

    printf("\n\n==========================================================");
    printf("\n                         RECEIPT                            ");
    printf("\n============================================================");
    printf("\n                      FLIGHT DETAILS                        ");
    printf("\n------------------------------------------------------------");
    printf("\nFlight code                        : %s", passdata.Pass_Flight_code);
    printf("\nDestination                        : %s", passdata.Pass_Destinations);
    printf("\nFlight Class                       : %s", passdata.Pass_Flight_Class);
    printf("\nTicket type                        : %s", passdata.Ticket_Type);
    printf("\nMax seat                           : %d/%d", passdata.Pass_Flight_NOWSeats, passdata.Pass_Flight_MAXseats);
    printf("\nFlight cost                        : %.2f", passdata.Pass_Flight_cost);
    printf("\n------------------------------------------------------------");
    printf("\n                       PASSENGERS                           ");
    printf("\n------------------------------------------------------------");
    printf("\nAdult tickets                      : %d", passdata.adult_tickets);
    printf("\nChild tickets                      : %d", passdata.child_tickets);
    printf("\nInfant tickets                     : %d", passdata.infant_tickets);
    printf("\nSeat placement                     : %s", passdata.seat_placement);
    printf("\n------------------------------------------------------------");
    printf("\n                         DATE                         ");
    printf("\n------------------------------------------------------------");
    printf("\nDeparture Date                     : %s", passdata.Departure_date);
    printf("\nReturn Date                        : %s ", passdata.return_date);
    printf("\n============================================================");
    printf("\nTotal Price                       : \033[42m%.2f\033[0m", passdata.total_price);
    printf("\n============================================================");

    Save_bookings(passdata);
    printf("\n\033[1;32mBooking receipt has been saved to the cloud successfully!\n\nYou may view your booking in the View Bookings prompt[3]\033[0m");
}

/*
PLAN:

-Make the passdata.Pass_Flight_NOWSeats scan the file on 
passdata.Pass_Flight_NOWSeats variable to have consistent 
saved number for seat availability
-Do cancel booking by creating a temp file and rewrite everything
in savedbookings.txt without the entered input and then delete the
original savedbookings.txt and rename the temp file to savedbookings.txt
-Do search flight/viewbooking and add search in file function by using the
daasd.c and test.c as reference, if its too hard then just copy and paste*/