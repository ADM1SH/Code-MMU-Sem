#include <stdio.h>

// Function declarations
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main() {
    char option;
    
    do {
        printf("\nSimple Calculator\n");
        printf("Options:\n");
        printf("a. Add\n");
        printf("b. Subtract\n");
        printf("c. Multiply\n");
        printf("d. Divide\n");
        printf("e. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%c", &option);
        
        float num1, num2;
        printf("\nEnter first number: ");
        scanf("%f", &num1);
        printf("\nEnter second number: ");
        scanf("%f", &num2);
        
        switch(option) {
            case 'a':
                printf("\nResult: %.2f\n", add(num1, num2));
                break;
            case 'b':
                printf("\nResult: %.2f\n", subtract(num1, num2));
                break;
            case 'c':
                printf("\nResult: %.2f\n", multiply(num1, num2));
                break;
            case 'd':
                if (num2 == 0) {
                    printf("\nError: Division by zero is not allowed!\n");
                } else {
                    printf("\nResult: %.2f\n", divide(num1, num2));
                }
                break;
            case 'e':
                printf("\nExiting calculator...\n");
                break;
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    } while(option != 'e');
    
    return 0;
}

// Function definitions
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}
