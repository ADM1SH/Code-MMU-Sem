#include <stdio.h>
#include<stdlib.h>

int MMO; //Main menu option
int FDO; //Flight detail option
int ps [10][9]; //Plane seats


//Function Protoype
void lines(); // Decoration
void menu_d(); // Main menu
void flight_d(); // Flight details
void load_f();// loading in flight details
void flight_layout(); // Flight array layout
void book_t(); // Book tickets
void view_b(); // View bookings
void cancel_t(); // Cancel ticket


int main()
{
  int E = 0; // For looping back to the main menu
  while (E < 1)
  {
  // Main Menu
  menu_d();
  
  // Going into the sub menus
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

void menu_d() // Main menu
{
  lines();
  printf("\t\tMain Menu");
  lines();
  printf("\n\n\nOptions");
  printf("\n\n1. Flight Details\t[1]\n2. Book Ticket\t\t[2]\n3. View Bookings\t[3]\n4. Cancel Ticket\t[4]\n5. Exit\t\t\t[5]");
  printf("\n\nInsert Option [x] : ");
  scanf("%d", &MMO);
}

void flight_d() // Flight details
{
  lines();
  printf("\t\tFlight Details");
  lines();
  printf("\n1. Flight Number : 3008\n\n\tDestination\t: Sweden\n\tDeparture Date\t: 20/04/2025 [0630]\n\tSeat Capasity\t: 90\n\tPrice\t\t: RM 1,000\n");
  lines();
  printf("\n2. Flight Number : 1420\n\n\tDestination\t: Japan\n\tDeparture Date\t: 14/02/2025 [1215]\n\tSeat Capasity\t: 90\n\tPrice\t\t: RM 1,000\n");
  lines();
  printf("\n3. Flight Number : 2707\n\n\tDestination\t: Malaysia\n\tDeparture Date\t: 13/05/2025 [1645]\n\tSeat Capasity\t: 90\n\tPrice\t\t: RM 1,000\n");
  lines();
  printf("\n4. Flight Number : 3428\n\n\tDestination\t: America\n\tDeparture Date\t: 06/09/2025 [2200]\n\tSeat Capasity\t: 90\n\tPrice\t\t: RM 1,000\n");\
  lines();
  printf("\nInsert Flight Number : ");
  scanf("%d", &FDO);
  load_f();

}

void load_f() // Loading in the .txt files for reading
{
  int x = 0, r, c;
  FILE *fp;
  switch (FDO)
  {
    case 3008:
      fp = fopen("sweden.txt", "r");
      break;

    case 1420:
      fp = fopen("japan.txt", "r");
      break;

    case 2707:
      fp = fopen("malaysia.txt", "r");
      break;

    case 3428:
      fp = fopen("america.txt", "r");
      break;

    default:
      printf("Invalid option! Please enter code again");
      return flight_d();
      break;
  }
  while (fscanf(fp, "%d", &x) == 1)// Using a temp var to hold the values
  {
    ps[r][c] = x;
    c++;
    if(c == 9)
    {
      c=0;
      r++;
    }
  }
  flight_layout();
  printf("\n");
  lines();
  book_t();
  fclose(fp);
}

void flight_layout() // Pretty layouts :3
{
  printf("\n");
  // r means row, c means column
  for (int r = 0; r < 10; r++)
  {
    switch (r)
    {
    case 0:
      printf("\nFirst Class----------");
      printf("\n\n");
      break;
    
    case 2:
      printf("\nBusiness Class----------");
      printf("\n\n");
      break;

    case 6:
      printf("\nEconomy Class----------");
      printf("\n\n");
      break;

    default:
      break;
    }
    if (r < 9)
    {
      printf("Row  %d:\t", r+1);
    }
    else
    {
      printf("Row %d:\t", r+1);
    }

    for (int c = 0; c < 9; c++)
    {
      switch (c)
      {
      case 3:
        printf("\t");
        break;
      case 6:
        printf("\t");
        break;
        default:
        break;
      }
      switch (c)
      {
      case 0:
        printf("a");
        break;
      case 1:
        printf("b");
        break;
      case 2:
        printf("c");
        break;
      case 3:
        printf("d");
        break;
      case 4:
        printf("e");
        break;
      case 5:
        printf("f");
        break;
      case 6:
        printf("g");
        break;
      case 7:
        printf("h");
        break;
      case 8:
        printf("i");
        break;
      
      default:
        break;
      }
      printf(".[");
      switch (ps[r][c])
      {
        case 0:
          printf(" Open ");
          break;
        case 1:
          printf("Closed");
          break;
      }

      printf("]  ");
    }
    printf("\n\n");
  }
}

void book_t() // Book ticket
{
  char sn[5];
  printf("Enter Seat Number (Ex. 1a) : ");
  scanf("%s",&sn);
}

void view_b()
{
  printf("\nFeature Currently Unavailible");
  /*int bookingCount;
    FILE *fp;
    fp = fopen("booking_list.txt","r");

    if(fp == NULL)
    {
        printf("\nNo booking available");
    }

    else
    {
        for(int i = 0; i < bookingCount; i++)
        {
          lines();
          printf("book_id         :%d\n",booking[i].bookingID);
          printf("passenger_name  :%s\n",booking[i].passengerNname);
          printf("flight_detail   :%s\n",booking[i].flightDetail);
          printf("seat_num        :%d\n",booking[i].seatNum);
          lines();
        }
    }

    fclose(fp);*/
}


void cancel_t()
{
 printf("\nFeature Currently Unavailible");
}