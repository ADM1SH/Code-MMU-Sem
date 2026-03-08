#include <stdio.h>

char choice;
char e0l50 [] = "Re-do assignment";
char e50l70 [] = "Good";
char e70t100 [] = "Excellent";
char other [] = "Not available";
char examtype1 [] = "Quiz";
char examtype2 [] = "Assigment";
int total, sum, counter, marks1, marks2, result;

int main(){
    while (1){
        printf("Enter type of assessment: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'Q':
            case 'q':
                printf("Enter Quiz 1 marks: ");
                scanf("%i", &marks1);
                printf("Enter Quiz 2 marks: ");
                scanf("%i", &marks2);
                total = marks1 + marks2;
                printf("\n");
                printf("Assessment Type: %s", examtype1);
                printf("Quiz total: %i\n", total);
                break;
            case 'T':
            case 't':
                printf("Enter assignment marks: ");
                scanf("%i", &marks1);
                printf("\n");

                printf("Assessment type: %s\n", examtype2);
                
                if (marks1 >= 0 && marks1 <= 50){
                    printf("Status: %s\n", e0l50);
                }else if (marks1 > 50 && marks1 <= 70){
                    printf("Status: %s\n", e50l70);
                }else if (marks1 > 70 && marks1 <= 100){
                    printf("Status: %s\n", e70t100);
                } else{
                    printf("Invalid marks try again\n");
                }
                break;
            default:
                printf("Not Available, try again\n");
                continue;
        }
        break;
    }

    return 0;
}