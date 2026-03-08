#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 3

// Structure to hold book information
typedef struct {
    char code[6];
    float price;
    int quantitySold;
} Book;

int main() {
    Book books[MAX_BOOKS] = {
        {"B1001", 34.50, 0},
        {"B1002", 77.30, 0},
        {"B1003", 54.90, 0}
    };

    int continueShopping = 1;
    float overallTotal = 0.0;

    while (continueShopping == 1) {
        char bookCode[6];
        int quantity;
        float billAmount;

        // Ask for book code
        printf("Enter the book code: ");
        scanf("%s", bookCode);

        // Check if the book code is valid
        int bookFound = 0;
        for (int i = 0; i < MAX_BOOKS; i++) {
            if (strcmp(books[i].code, bookCode) == 0) {
                bookFound = 1;

                // Ask for quantity
                printf("Enter quantity: ");
                scanf("%d", &quantity);

                // Calculate bill amount
                billAmount = books[i].price * quantity;
                overallTotal += billAmount;
                books[i].quantitySold += quantity;

                // Display bill amount
                printf("Bill amount for %s: RM %.2f\n", books[i].code, billAmount);
                break;
            }
        }

        // If book code is invalid
        if (!bookFound) {
            printf("Invalid book code. Please try again.\n");
        }

        // Ask if the user wants to continue
        printf("Would you like to continue [Type 1 to continue]: ");
        scanf("%d", &continueShopping);
    }

    // Display summary
    if (overallTotal > 0) {
        printf("\nSummary of Sales:\n");
        for (int i = 0; i < MAX_BOOKS; i++) {
            if (books[i].quantitySold > 0) {
                printf("Book Code: %s, Quantity Sold: %d, Total Sales: RM %.2f\n", 
                       books[i].code, books[i].quantitySold, books[i].quantitySold * books[i].price);
            }
        }
        printf("Overall Total: RM %.2f\n", overallTotal);
    } else {
        printf("No purchase made.\n");
    }

    return 0;
}