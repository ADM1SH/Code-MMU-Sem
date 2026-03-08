#include <stdio.h>

// Function to get user input
void getInput(float *weight, float *height) {
    printf("Please insert your weight in kilograms: ");
    scanf("%f", weight);
    
    printf("Please insert your height in meters: ");
    scanf("%f", height);
}

// Function to compute BMI
float computeBMI(float weight, float height) {
    return weight / (height * height);
}

// Function to display the BMI result
void displayResult(float BMI) {
    printf("Your BMI: %.2f\n", BMI);

    if (BMI < 18.5)
        printf("Underweight\n");
    else if (BMI >= 18.5 && BMI < 25.0)
        printf("Normal\n");
    else if (BMI >= 25.0 && BMI < 30.0)
        printf("Overweight\n");
    else
        printf("Obese\n");
}

// Main function
int main() {
    float weight, height, BMI;

    getInput(&weight, &height);
    BMI = computeBMI(weight, height);
    displayResult(BMI);

    return 0;
}