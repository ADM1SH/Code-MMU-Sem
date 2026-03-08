#include <stdio.h>
#include <string.h>

float penang = 45;
float kelantan = 38;
float perlis = 63;
char returnT, destination[50];
char destination1 [] = "Penang";
char destination2 [] = "Kelantan";
char destination3 [] = "Perlis";
int code, adult, adultP, child, childP, total, price;

int main(){
    printf("\n");
    printf("-------------------------------------\n");
    printf("            DESTINATIONS             \n");
    printf("-------------------------------------\n");
    printf("  1. %s              (RM %.2f)\n", destination1, penang);
    printf("  2. %s            (RM %.2f)\n", destination2, kelantan);
    printf("  3. %s              (RM %.2f)\n", destination3, perlis);
    printf("-------------------------------------\n");
    printf("Enter adult             : ");
    scanf("%d", &adult);
    printf("Enter child             : ");
    scanf("%d", &child);
    
    printf("Return ticket [Y/N]     : ");
    scanf("%s", &returnT);

    printf("Enter destination code  : ");
    scanf("%d", &code);

    while (1){
        switch(code){
            case 1:
                price = penang;
                strcpy(destination, destination1);
                if (returnT == 'Y' || returnT == 'y'){
                    total = penang * adult + (penang / 2 * child) * 2;
                    adultP = penang * adult;
                    childP = penang / 2 * child;
                    returnT = 'Y';
                } else if (returnT == 'n' || returnT == 'N'){
                    total = penang * adult + (penang / 2 * child);
                    adultP = penang * adult;
                    childP = penang / 2 * child;
                    returnT = 'N';
                } else {
                    printf("Invalid input try again.");
                    continue;
                }
                break;
            case 2:
                price = kelantan;
                strcpy(destination, destination2);
                if (returnT == 'Y' || returnT == 'y'){
                    total = kelantan * adult + (kelantan / 2 * child) * 2;
                    adultP = kelantan * adult;
                    childP = kelantan / 2 * child;
                    returnT = 'Y';
                } else if (returnT == 'n' || returnT == 'N'){
                    total = kelantan * adult + (kelantan / 2 * child);
                    adultP = kelantan * adult;
                    childP = kelantan / 2 * child;
                    returnT = 'N';
                } else {
                    printf("Invalid input try again.");
                    continue;
                }
                break;
            case 3:
                price = perlis;
                strcpy(destination, destination3);
                if (returnT == 'Y' || returnT == 'y'){
                    total = perlis * adult + (penang / 2 * child) * 2;
                    adultP = perlis * adult;
                    childP = perlis / 2 * child;
                    returnT = 'Y';
                } else if (returnT == 'n' || returnT == 'N'){
                    total = perlis * adult + (perlis / 2 * child);
                    adultP = perlis * adult;
                    childP = perlis / 2 * child;
                    returnT = 'N';
                } else {
                    printf("Invalid input try again.");
                    continue;
                }
                break;
            default:
                 printf("Invalid input try again");
                continue;
        }
        break;
    }

    printf("\n");
    printf("-------------------------------------\n");
    printf("              RECEIPT                \n");
    printf("-------------------------------------\n");
    printf("Destination    : %s\n", destination);
    printf("Price          : RM %.2d\n", price);
    printf("Adults         : %i\n", adult);
    printf("Child          : %i\n", child);
    printf("Adults price   : RM %i\n", adultP);
    printf("Child price    : RM %i\n", childP);
    printf("Return ticket  : %c\n", returnT);
    printf("Payment        : RM %.2d\n", total);

    return 0;
}


