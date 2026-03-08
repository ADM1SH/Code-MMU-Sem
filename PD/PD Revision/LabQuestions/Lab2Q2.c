#include <stdio.h>

int main(){
    #define pi 3.14159
    float radius, time, CircVelo;
    
    CircVelo = 2 * pi * radius / time;

    printf("Enter radius (cm): ");
    scanf("%f", &radius);
    printf("Enter time (s): ");
    scanf("%f", &time);
    printf("\n");
    printf("Radius: %.2f\n", radius);
    printf("Time: %.2f\n", time);
    printf("Circular Velocity: %.2f\n", CircVelo);

    return 0;
}