#include <iostream>
using namespace std;

int main() {
    int numStudents;

    // Step 1: Ask how many students
    cout << "How many students are in class? ";
    cin >> numStudents;
    cin.ignore(); // To avoid input bug after cin

    // Step 2: Create arrays
    string names[50];  // assume max 50 students
    int scores[50];

    // Step 3: Loop to get input
    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter name for student " << (i+1) << ": ";
        getline(cin, names[i]);

        cout << "Enter score for " << names[i] << ": ";
        cin >> scores[i];
        cin.ignore(); // clear buffer
    }

    // Step 4: Calculate total & average using loop
    int total = 0;
    for (int i = 0; i < numStudents; i++) {
        total += scores[i];
    }

    float average = static_cast<float>(total) / numStudents;

    // Step 5: Display all data
    cout << "\n--- STUDENT SCORES ---\n";
    for (int i = 0; i < numStudents; i++) {
        cout << names[i] << ": " << scores[i] << endl;
    }

    // Step 6: Show average and address using pointer
    cout << "\nClass average: " << average << endl;

    float* ptrAverage = &average;
    cout << "Memory address of average: " << ptrAverage << endl;

    // Step 7: Bonus message using if
    if (average > 80) {
        cout << "🎉 Great job, class!" << endl;
    } else {
        cout << "📘 Keep practicing!" << endl;
    }

    return 0;
}
