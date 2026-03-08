#include <stdio.h>

int main(){
    char choice;
    double distance, time, speed, mass, height, work, radian, degree;
    const double GRAVITY = 9.8;

    while (1){
        printf("\n1. Calculate Speed\n");
        printf("2. Calculate Work\n");
        printf("3. Convert radian to degree\n");
        printf("4. Exit\n");
        printf("-------------------------------\n");

        // Get user choice
        printf("Enter your choice : ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                // Calculate Speed
                printf("\nEnter distance (m) : ");
                scanf("%lf", &distance);
                printf("Enter time (s) : ");
                scanf("%lf", &time);
                speed = distance / time;
                printf("Speed is %.2f m/s\n", speed);
                break;

            case '2':
                // Calculate Work
                printf("\nEnter mass (kg) : ");
                scanf("%lf", &mass);
                printf("Enter height (m) : ");
                scanf("%lf", &height);
                work = mass * GRAVITY * height;
                printf("Work is %.2f Joules\n", work);
                break;

            case 3:
                // Convert Radian to Degree
                printf("\nEnter radian : ");
                scanf("%lf", &radian);
                degree = radian * 57.2958;
                printf("%.2f radian is equals to %.2f degree\n", radian, degree);
                break;

            case 4:
                // Exit the program
                printf("\nExiting program. Goodbye!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }
    }

    return 0;   
    }
