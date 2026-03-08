#include <stdio.h>

int main() {
    int n;

    printf("How many numbers do you want to enter? ");
    scanf("%d", &n);

    float prices[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Number %d: ", i + 1);
        scanf("%f", &prices[i]);
    }

    printf("\nYou entered: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", prices[i]);
    }

    printf("\n");
    return 0;
}
