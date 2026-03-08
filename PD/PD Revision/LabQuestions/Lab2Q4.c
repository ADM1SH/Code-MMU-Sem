#include <stdio.h>

#define white 0.05
#define green 0.10
#define pink 0.15
float totalW, totalG, totalP, total;
int  qtyW, qtyG, qtyP; 

int main(){
    printf("Quantity of White A4 paper: ");
    scanf("%i", &qtyW);
    printf("Quantity og Green A4 paper: ");
    scanf("%i", &qtyG);
    printf("Quantity of Pink A4 paper: ");
    scanf("%i", &qtyP);
    printf("\n");

    totalW = qtyW * white;
    totalG = qtyW * green;
    totalP = qtyP * pink;
    total = totalW + totalG + totalP;

    printf("White A4 paper : RM %.2f (%i x %.2f)\n", totalW, qtyW, white);
    printf("Green A4 paper : RM %.2f (%i x %.2f)\n", totalG, qtyG, green);
    printf("Pink A4 paper  : RM %.2f (%i x %.2f)\n", totalP, qtyP, pink);
    printf("Total          : RM %.2f\n", total);

    return 0;

}