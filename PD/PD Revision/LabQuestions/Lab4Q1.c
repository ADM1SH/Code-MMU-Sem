#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char movie[50];
int moviecode, numticket, movieday, total, counter, ticketprice;
float mif = 13;
float amtw = 12;
const double discount1 = 0.8;
const double discount2 = 0.7;

int main(){
    printf("\n");
    printf("------------------------------------------\n");
    printf("             MOVIE TITLE                  \n");
    printf("------------------------------------------\n");
    printf("1. Mission Impossible - Fallout (RM %.2f)\n", mif);
    printf("2. Ant-Man and The Wasp         (RM %.2f)\n", amtw);
    printf("------------------------------------------\n");
    printf("\n");
    
    printf("Enter movie code: ");
    scanf("%d", &moviecode);
    if (moviecode == 1){
        strcpy(movie, "Mission Impossible - Fallout");
        counter = 1;
    }else if(moviecode == 2){
        strcpy(movie, "Ant-Man and The wasp");
        counter = 2;
    }else{
        printf("WWrong input please try again\n");
        exit(0);
    }
    
    printf("Enter number of tickets: ");
    scanf("%d", &numticket);

    while (1){
        printf("Enter movie day (1-7) ");
        scanf("%d",&movieday);

        switch (movieday){
            case 1: case 2: case 3: case 4: case 5:
                if (counter == 1){
                    ticketprice = 13 * discount1;
                    total = numticket * ticketprice;
                } else if (counter == 2){
                    ticketprice = 12 * discount2;
                    total = numticket * discount2;
                }
                break;
            case 6: case 7:
                if (counter == 1){
                    total = numticket * 13;
                } else if (counter == 2){
                    total = numticket * 12;
                }
                break;
            default:
                printf("invalid input try again\n");
                continue;
        }
        break;
    }

   printf("\n");
   printf("------------------------------------------\n");
   printf("                 RECEIPT                  \n");
   printf("------------------------------------------\n");
   printf("Movie            : %s\n", movie);
   printf("No. of Tickets   : %d\n", numticket);
   printf("Total Price      : RM %d\n2", total);

   return (0);

}