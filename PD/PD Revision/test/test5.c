#include <stdio.h>

int main(){
    FILE *file;
    int n;
    char name[100];

    file = fopen("data.txt", "w");

    if (file == NULL){
        printf("Error opening file!\n");
        return 1;
    }

    printf("how many name do you want it enter: ");
    scanf("%d", &n);
    getchar();

    printf("Enter %d names: \n", n);
    for(int i = 0; i < n; i++){
        printf("Enter name %d: ", i+1);
        fgets(name, sizeof(name), stdin);
        fputs(name, file);
    }

    fclose(file);

    printf("names saved successfully\n");

    return 0;

}