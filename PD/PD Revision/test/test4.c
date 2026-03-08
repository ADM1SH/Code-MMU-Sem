#include <stdio.h>

int main(){
    /*
    FILE *pF = fopen("test.txt", "w");

    fprintf(pF, "TESTING");

    fclose(pF);
    */

    if (remove("test.txt") == 0){
        printf("File deleted successfully\n");
    } else{
        printf("Error deleting file\n");
    }

    return 0;
} 