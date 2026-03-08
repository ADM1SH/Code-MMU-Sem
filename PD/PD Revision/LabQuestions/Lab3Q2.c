#include <stdio.h>

int main() {
    float l5 = 1.00, e5l10 = 1.50, e10l15 = 2.00, e15m = 2.50;
    float weight, bill, rate;
    char ironing;

    printf("\n");
    printf("------------------------------\n");
    printf("  Welcome to Clean Laundry\n");
    printf("------------------------------\n");

    printf("Laundry weight : ");
    scanf("%f", &weight);

    printf("\n");
    printf("Need ironing [Y/N] : ");
    scanf(" %c", &ironing);

    printf("\n");

    if (weight <= 5) {
        bill = weight * l5;
        rate = l5;
    } else if (weight > 5 && weight <= 10) {
        bill = weight * e5l10;
        rate = e5l10;
    } else if (weight > 10 && weight <= 15) {
        bill = weight * e10l15;
        rate = e10l15;
    } else {
        bill = weight * e15m;
        rate = e15m;
    }

    if (ironing == 'Y' || ironing == 'y') {
        bill += 5;
    }

    printf("Your Bill\n");
    printf("----------\n");
    printf("Weight  : %.2f kg\n", weight);
    printf("Rate    : RM %.2f per kg\n", rate);
    printf("Ironing : %c (RM %s)\n", ironing, (ironing == 'Y' || ironing == 'y') ? "5.00" : "0.00");
    printf("Bill    : RM %.2f\n", bill);

    return 0;
}