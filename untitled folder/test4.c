#include <stdio.h>

int main(){
    FILE *pF = fopen("test.txh", "w");

    fprintf(pF, "TESTING");

    fclose(pF);

    return 0;
}