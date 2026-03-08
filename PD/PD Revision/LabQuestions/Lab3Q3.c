#include <stdio.h>

#define deluxe 200
#define twinSharing 170
#define Single 120
char choice, name[50], roomtype;
char roomtype1 [] = "Deluxe";
char roomtype2 [] = "Twin Sharing";
char roomtype3 [] = "Single";
int days, bill, counter, roomprice;

int main(){
    printf("\n");
    printf("-----------------------------------------------------------\n");
    printf("                     WELCOME TO HOTEL                      \n");
    printf("-----------------------------------------------------------\n");
    printf(" Rooms: Deluxe(1 or D)   Twin Sharing(2 or T)  Single(3 or S)\n");
    printf("\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter number days: ");
    scanf("%i", &days);

    while (1){
    printf("Enter room code: ");
    scanf(" %c", &choice);

    switch (choice){
        case '1':
        case 'D':
        case 'd':
            bill = days * deluxe;
            counter = counter + 1;
            roomprice = deluxe;
           break;
        case '2':
        case 'T':
        case 't':
            bill = days * twinSharing;
            counter = counter + 2;
            roomprice = twinSharing;
            break;
        case '3':
        case 'S':
        case 's':
            bill = days * Single;
            counter = counter + 3;
            roomprice = Single;
            break; 
        default:
            printf("invalid choice\n");
            continue;
    }
    break;
    }

    printf("-----------------------------------------------------------\n");
    printf("                     PAYMENT  RECEIPT                      \n");
    printf("-----------------------------------------------------------\n");
    
    printf("Customer name: %s\n", name);
    if (counter == 1){
        printf("Room Type: %s\n", roomtype1);
    } else if (counter == 2){
        printf("Room type: %s", roomtype2);
    }else {
        printf("Room Type: %s", roomtype3);
    }
    
    printf("Room Price: RM %i\n", roomprice);
    printf("Number of days: %i\n", days);
    printf("Bill: RM %i\n", bill);

    return 0;
}


