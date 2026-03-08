#include <stdio.h>

const double SST = 0.06;
float bill, ST, total, indivBill;
int friends;

int main(){
    printf("\n");
    printf("Enter the Bill: RM ");
    scanf("%f", &bill);
    printf("Enter number of friends: ");
    scanf("%i", &friends);
    printf("\n");

    ST = bill * SST;
    total = bill + ST;
    indivBill = total / friends;

    printf("Lunch bill      : RM %.2f\n", bill);
    printf("Service tax     : RM %.2f\n", ST);
    printf("Total bill      : RM %.2f\n", total);
    printf("Individual bill : RM %.2f\n", indivBill);

    return 0;

}