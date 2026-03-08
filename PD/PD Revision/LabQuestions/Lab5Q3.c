#include <stdio.h>

int main() {
    char receiveDonations;
    int totalClients = 0;
    float overallTotalDonation = 0.0;

    do {
        // Ask if they receive donations
        printf("Do you receive donations from clients? (y/n): ");
        fflush(stdin); // Clear input buffer
        scanf(" %c", &receiveDonations);

        if (receiveDonations == 'y' || receiveDonations == 'Y') {
            char companyName[50];
            int frequency;
            float totalDonationForClient;

            // Ask for the company name and frequency of donation
            printf("Enter the name of the company: ");
            fflush(stdin); // Clear input buffer
            fgets(companyName, sizeof(companyName), stdin);

            printf("Enter the frequency of donation (number of donations): ");
            scanf("%d", &frequency);

            totalDonationForClient = 0.0;

            // Collect donation amounts based on frequency
            for (int i = 1; i <= frequency; i++) {
                float donationAmount;
                printf("Enter donation amount for donation %d: ", i);
                scanf("%f", &donationAmount);
                totalDonationForClient += donationAmount; // Accumulate total donation for the client
            }

            // Update overall totals
            overallTotalDonation += totalDonationForClient;
            totalClients++;

            // Display total donation for the client
            printf("Total donation for %s: %.2f\n", companyName, totalDonationForClient);
        }

    } while (receiveDonations == 'y' || receiveDonations == 'Y');

    // Display summary
    printf("\nSummary:\n");
    printf("Total number of clients: %d\n", totalClients);
    printf("Overall total donation: %.2f\n", overallTotalDonation);

    return 0;
}