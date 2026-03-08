#include <stdio.h>

// Function prototypes
char get_choice();
void calculate(int num1, int num2, char choice);

int result = 1;

int main() {
    char choice;
    int num1, num2;

    // Display the menu
    printf(" A. Add numbers\n");
    printf(" B. Multiply numbers\n");
    printf(" C. Subtract numbers\n");
    printf(" D. Remainder of numbers\n");
    printf(" E. Power of numbers\n");

    // Get user choice
    choice = get_choice();

    // Prompt the user for two integer numbers
    printf("Enter 2 numbers: ");
    scanf("%d %d", &num1, &num2);

    // Call calculate function
    calculate(num1, num2, choice);

    return 0;
}

// Function to get user choice
char get_choice() {
    char choice;
    int valid = 0;

    while (!valid) {
        printf("What is your choice? : ");
        scanf(" %c", &choice); // Space before %c to ignore any whitespace

        // Convert choice to uppercase for consistency
        if (choice >= 'a' && choice <= 'e') {
            choice -= 32; // Convert to uppercase
        }

        // Check if the choice is valid
        if (choice >= 'A' && choice <= 'E') {
            valid = 1; // Valid choice
        } else {
            printf("Your choice is invalid.\n");
        }
    }

    return choice;
}

// Function to perform calculations based on user choice
void calculate(int num1, int num2, char choice) {
    switch (choice) {
        case 'A':
            printf("Answer: %d\n", num1 + num2);
            break;
        case 'B':
            printf("Answer: %d\n", num1 * num2);
            break;
        case 'C':
            printf("Answer: %d\n", num1 - num2);
            break;
        case 'D':
            if (num2 != 0) {
                printf("Answer: %d\n", num1 % num2);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case 'E':
            // Calculate power manually
            for (int i = 0; i < num2; i++) {
                result *= num1;
            }
            printf("Answer: %d\n", result);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }
}