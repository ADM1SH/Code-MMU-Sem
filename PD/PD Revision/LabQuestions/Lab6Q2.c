#include <stdio.h>

char got_input(){
    char choice;

    printf ("Would you like to continue? (y/n): ");
    choice = getchar();

    while (getchar() != '\n');

    if (choice == 'y' || choice == 'Y'){
        return 1;
    }else{
        return 0;
    }
}

float cm_to_inches(){
    const float cm_to_inches = 1.0 / 2.54;
}