#include <stdio.h>

const float POUND = 2.20462;
const float INCH = 39.3701;
float heightM, heightINCH, weightKG, weightP, BMR;
int age[3];

int main(){
printf("Enter Height (m): ");
scanf("%f", &heightM);
printf("Enter weight (kg): ");
scanf("%f", &weightKG);
printf("Enter age: ");
scanf("%i", age);
printf("\n");

heightINCH = heightM * INCH;
weightP = weightKG * POUND;
BMR = 66 + (6.23 * weightP) + (12.7 * heightINCH);

printf("Height: %.2f inches\n", heightINCH);
printf("Weight: %.2f pounds\n", weightP);
printf("Basal Metabolic Rate (BMR): %.2f\n", BMR);

return 0;
}