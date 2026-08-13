#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

// Function to convert height from meters to feet
double ConvMetersToFeet(double &mHeight) {
    return mHeight * 3.26084;
}

// Function to convert weight from kilograms to pounds
int convKGtoPounds(int &kWeight) {
    return static_cast<int>(round(kWeight * 2.20462));
}

// Function to determine the jacket size based on height in feet and weight in pounds
string detJacketSize(double &fHeight, int &pWeight) {
    string size;

    if (fHeight >= 6.5 && pWeight >= 86 && pWeight <= 95) {
        size = "Extra Large 2";
    } else if (fHeight >= 6.3 && fHeight < 6.5) {
        size = "Extra Large";
    } else if (fHeight >= 5.9 && fHeight < 6.3) {
        size = "Large";
    } else if (fHeight >= 5.7 && fHeight < 5.9) {
        if (pWeight >= 56 && pWeight <= 65) {
            size = "Medium";
        } else {
            size = "Large";
        }
    } else { // fHeight < 5.7
        if (pWeight >= 50 && pWeight <= 55) {
            size = "Small";
        } else {
            size = "Medium";
        }
    }

    return size;
}

int main() {
    double mHeight;
    int kWeight;

    // Input validation for height in meters
    while (true) {
        cout << "Enter your height in meters: ";
        if (cin >> mHeight && mHeight > 0) {
            break;
        } else {
            cout << "Invalid input. Please enter a positive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Input validation for weight in kilograms
    while (true) {
        cout << "Enter your weight in kilograms: ";
        if (cin >> kWeight && kWeight > 0) {
            break;
        } else {
            cout << "Invalid input. Please enter a positive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Convert height from meters to feet and weight from kilograms to pounds
    double fHeight = ConvMetersToFeet(mHeight);
    int pWeight = convKGtoPounds(kWeight);

    // Determine the jacket size based on converted height and weight
    string jacketSize = detJacketSize(fHeight, pWeight);

    // Output the determined jacket size
    cout << "Your suitable jacket size is: " << jacketSize << endl;

    return 0;
}


