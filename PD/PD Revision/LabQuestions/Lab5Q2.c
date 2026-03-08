#include <stdio.h>

int main() {
    char name[50];
    int id;
    int duration;
    float firstYearFee;
    float totalFees = 0.0;
    float annualFee;
    int year = 1;

    // Prompt user for input
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin); // Using fgets to allow spaces in name

    printf("Enter your ID number: ");
    scanf("%d", &id);

    printf("Enter the duration of study (in years): ");
    scanf("%d", &duration);

    printf("Enter the fee for the first year: ");
    scanf("%f", &firstYearFee);

    // Initialize annual fee to the first year fee
    annualFee = firstYearFee;

    // Calculate fees using a do-while loop
    do {
        printf("Year %d: Annual Fee = %.2f\n", year, annualFee);
        totalFees += annualFee; // Add annual fee to total fees
        annualFee *= 1.05; // Increase annual fee by 5%
        year++;
    } while (year <= duration);

    // Display total fees
    printf("Total course fees for %s (ID: %d) over %d years: %.2f\n", name, id, duration, totalFees);

    return 0;
}