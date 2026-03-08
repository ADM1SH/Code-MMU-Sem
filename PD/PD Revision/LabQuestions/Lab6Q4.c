#include <stdio.h>

// Function prototypes
float calculateCharges(int startHour, int startMinute, int endHour, int endMinute);
void display(float totalCharges);

int main() {
    int startHour, startMinute, endHour, endMinute;

    // Prompt user for input
    printf("Enter the time you entered the parking lot (HH MM): ");
    scanf("%d %d", &startHour, &startMinute);
    printf("Enter the time you left the parking lot (HH MM): ");
    scanf("%d %d", &endHour, &endMinute);

    // Calculate total charges
    float totalCharges = calculateCharges(startHour, startMinute, endHour, endMinute);

    // Display the total charges
    display(totalCharges);

    return 0;
}

float calculateCharges(int startHour, int startMinute, int endHour, int endMinute) {
    // Calculate parked time in minutes
    int parkedHours = endHour - startHour;
    int parkedMinutes = endMinute - startMinute;

    if (parkedMinutes < 0) {
        parkedHours--;
        parkedMinutes += 60;
    }

    // Total minutes parked
    int totalMinutes = parkedHours * 60 + parkedMinutes;
    float charges = 0.0;

    // Calculate charges
    if (totalMinutes <= 180) { // First 3 hours
        charges = 1.50;
    } else {
        // Charges for additional time
        int extraMinutes = totalMinutes - 180;
        int extraHours = extraMinutes / 60;
        extraMinutes = extraMinutes % 60;

        charges = 1.50 + extraHours + (extraMinutes > 0 ? 1 : 0); // RM1 for each extra hour and additional RM1 if there's leftover minutes
    }

    // Display parked hours and minutes
    printf("You have parked for %d hour(s) and %d minute(s)\n", parkedHours, parkedMinutes);

    return charges;
}

void display(float totalCharges) {
    printf("Total charges = $ %.2f\n", totalCharges);
}