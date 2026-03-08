#include <stdio.h>

int main(){
    char PN[50];
    int i; 
    float PP, total;

    for (i = 0; i < 3; i++){
        fflush(stdin);
        printf("\n");

        printf("Enter Product's name : ");
        fgets(PN, sizeof(PN), stdin);
        printf("\n");

        printf("Enter price          : RM ");
        scanf("%f", &PP);
        total += PP;

        printf("%s: RM %.2f\n", PN, PP);
    }

    printf("\n");
    printf("Total: RM %.2f\n", total);

    return 0;
}