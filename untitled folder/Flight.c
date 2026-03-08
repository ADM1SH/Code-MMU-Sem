#include <stdio.h>

int MMO; //Main Menu Option
int FDO; //Flight Detail Option



//Function Protoype
void lines();
void flight_d();
void book_t();
void view_b();
void cancel_t();


int main()
{
  int E = 0;
  while (E < 1)
  {
  //Main Menu
  lines();
  printf("\t\tMain Menu");
  lines();
  printf("\n\n\nOptions");
  printf("\n\n1. Flight Details\t[1]\n2. Book Ticket\t\t[2]\n3. View Bookings\t[3]\n4. Cancel Ticket\t[4]\n5. Exit\t\t\t[5]");
  printf("\n\nInsert Option [x] : ");
  scanf("%d", &MMO);
  
  switch (MMO)
  {
  case 1 :
    flight_d();
    break;
  case 2 :
    book_t();
    break;
  case 3 :
    view_b();
    break;
  case 4 :
    cancel_t();
    break;
  case 5 :
    E = 1;
    printf("Exiting...");
    break;
  default:
    printf("\nInvalid Option. Please Re-Enter");
    break;
  }
  }
}


//Function Definition
void lines()
{
  printf("\n------------------------------------------------------\n");
}
void flight_d()
{
  lines();
  printf("\t\tFlight Details");
  lines();
  printf("\n1. Flight Number : 3008\n\n\tDestination\t: Sweden\n\tDeparture Date\t: 20/04/2025 [0630]\n\tSeat Capasity\t: 90\n\tPrice\t\t: RM 1,000\n");
  lines();
  printf("\n2. Flight Number : 0420\n\n\tDestination\t: Japan\n\tDeparture Date\t: 14/02/2025 [1215]\n\tSeat Capasity\t: 90\n\tPrice\t\t: RM 1,000\n");
  lines();
  printf("\n3. Flight Number : 0707\n\n\tDestination\t: Malaysia\n\tDeparture Date\t: 13/05/2025 [1645]\n\tSeat Capasity\t: 90\n\tPrice\t\t: RM 1,000\n");
  lines();
  printf("\n4. Flight Number : 6969\n\n\tDestination\t: America\n\tDeparture Date\t: 06/09/2025 [2200]\n\tSeat Capasity\t: 90\n\tPrice\t\t: RM 1,000\n");\
  lines();
  printf("\n\n\nInsert Flight Number : ");
  scanf("%d", &FDO);
  printf("\n%d", FDO); //Testing scanf
}

void book_t()
{
  printf("\nFeature Currently Unavailible");
}

void view_b()
{
  printf("\nFeature Currently Unavailible");
}

void cancel_t()
{
 printf("\nFeature Currently Unavailible");
}