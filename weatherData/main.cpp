#include <iostream>
using namespace std;

const int MONTHS = 12; // Constant for the number of months in a year
const int DATA_POINTS = 2; // Each month will have 2 data points: high and low temperature

// Function prototypes
void getData(double temps[][DATA_POINTS]);
double averageHigh(const double temps[][DATA_POINTS]);
double averageLow(const double temps[][DATA_POINTS]);
int indexHighTemp(const double temps[][DATA_POINTS]);
int indexLowTemp(const double temps[][DATA_POINTS]);

int main() {
    // Array to store high and low temperatures for each month
    double temperatures[MONTHS][DATA_POINTS];

    // Fill the array with data from user input
    getData(temperatures);

    // Calculating and displaying the average high and low temperatures for the year
    cout << "Average high temperature for the year: " << averageHigh(temperatures) << " degrees." << endl;
    cout << "Average low temperature for the year: " << averageLow(temperatures) << " degrees." << endl;

    // Identifying and displaying the highest and lowest temperature of the year, including the month they occurred
    int highIndex = indexHighTemp(temperatures);
    int lowIndex = indexLowTemp(temperatures);
    cout << "Highest temperature of the year was in month " << highIndex + 1 << " with " << temperatures[highIndex][0] << " degrees." << endl;
    cout << "Lowest temperature of the year was in month " << lowIndex + 1 << " with " << temperatures[lowIndex][1] << " degrees." << endl;

    return 0;
}

// Function to input high and low temperatures for each month
void getData(double temps[][DATA_POINTS]) {
    cout << "Enter the high and low temperatures for each month." << endl;
    for (int month = 0; month < MONTHS; ++month) {
        cout << "Month " << month + 1 << " (High Low): ";
        // Stores each month's high and low temperature in the temps array
        cin >> temps[month][0] >> temps[month][1];
    }
}

// Calculates the average high temperature over the year
double averageHigh(const double temps[][DATA_POINTS]) {
    double sum = 0; // Sum of all high temperatures
    for (int month = 0; month < MONTHS; ++month) {
        sum += temps[month][0]; // Add the high temperature of each month to the sum
    }
    return sum / MONTHS; // Divide by the total number of months to get the average
}

// Calculates the average low temperature over the year
double averageLow(const double temps[][DATA_POINTS]) {
    double sum = 0; // Sum of all low temperatures
    for (int month = 0; month < MONTHS; ++month) {
        sum += temps[month][1]; // Add the low temperature of each month to the sum
    }
    return sum / MONTHS; // Divide by the total number of months to get the average
}

// Returns the index (month) of the highest high temperature in the array
int indexHighTemp(const double temps[][DATA_POINTS]) {
    int index = 0; // Start with the first month
    double highest = temps[0][0]; // Assume the first month has the highest temperature
    for (int month = 1; month < MONTHS; ++month) {
        if (temps[month][0] > highest) { // If find a higher temperature
            highest = temps[month][0]; // Update the highest temperature
            index = month; // Update the month index
        }
    }
    return index; // Return the month index of the highest temperature
}

// Returns the index (month) of the lowest low temperature in the array
int indexLowTemp(const double temps[][DATA_POINTS]) {
    int index = 0; // Start with the first month
    double lowest = temps[0][1]; // Assume the first month has the lowest temperature
    for (int month = 1; month < MONTHS; ++month) {
        if (temps[month][1] < lowest) { // If find a lower temperature
            lowest = temps[month][1]; // Update the lowest temperature
            index = month; // Update the month index
        }
    }
    return index; // Return the month index of the lowest temperature
}
