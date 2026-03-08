#include <stdio.h>

int main(){
    float choc = 1.30;
    int qty = 5;
    float total;
    char name[] = "John";

    total = choc * qty;

    printf("Choclate price: %.2f$\n", choc);
    printf("%s bought %i units of chocolate\n", name, qty);
    printf("\n");
    printf("Total amount to pay is: %.2f$\n", total);

    return 0;
}