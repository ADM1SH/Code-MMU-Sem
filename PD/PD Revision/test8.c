#include <stdio.h>

#define TITLE_LENGTH 100  // Define a constant for the maximum title length

// Declare the structure named book
struct book {
    float price;                // Attribute for the price of the book
    char title[TITLE_LENGTH];   // Attribute for the title of the book
};

int main() {
    // Example of how to use the book structure
    struct book myBook;

    // Assign values to the book attributes
    myBook.price = 19.99;
    snprintf(myBook.title, TITLE_LENGTH, "The Great Gatsby");

    // Print the book details
    printf("Book Title: %s\n", myBook.title);
    printf("Book Price: $%.2f\n", myBook.price);

    return 0;
}