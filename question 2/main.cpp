#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Function to calculate Full Period Mark by weighting test and assignment scores
float calcFullPeriodMark(float test1, float test2, float assignment) {
    // Each test is weighted at 33%, and the assignment is weighted at 34%
    return (0.33 * test1) + (0.33 * test2) + (0.34 * assignment);
}

// Function to calculate Final mark based on full period marks and exam marks
float calcFinalMark(float fullPeriodMark, float examMark) {
    // Full period mark contributes 40% and exam contributes 60% to the final mark
    return (0.40 * fullPeriodMark) + (0.60 * examMark);
}

// Function to check if a student has passed based on their marks
string checkMarks(float fullPeriodMark, float finalMark) {
    // Check pass criteria: Full period mark must be at least 40 and final mark at least 50
    if (fullPeriodMark >= 40 && finalMark >= 50) {
        return "PASS";
    } else {
        return "FAIL";
    }
}

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Vector to store all student results
    vector<tuple<string, string, float, float, string>> results;

    for (int i = 0; i < numStudents; i++) {
        string name, surname;
        float test1, test2, assignment, exam;

        // Input student details and marks
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter student surname: ";
        cin >> surname;
        cout << "Enter Test 1 mark: ";
        cin >> test1;
        cout << "Enter Test 2 mark: ";
        cin >> test2;
        cout << "Enter Assignment mark: ";
        cin >> assignment;
        cout << "Enter Exam mark: ";
        cin >> exam;

        // Calculate marks and check for passing criteria
        float fullPeriodMark = calcFullPeriodMark(test1, test2, assignment);
        float finalMark = calcFinalMark(fullPeriodMark, exam);
        string passFail = checkMarks(fullPeriodMark, finalMark);

        // Store student results
        results.push_back(make_tuple(name, surname, fullPeriodMark, finalMark, passFail));
    }

    // Display all student results
    cout << left << setw(15) << "Name" << setw(15) << "Surname" << setw(20) << "Full Period Mark" << setw(15) << "Final Mark" << setw(15) << "Pass or Fail" << endl;
    for (const auto& result : results) {
        cout << left << setw(15) << get<0>(result) << setw(15) << get<1>(result) << setw(20) << fixed << setprecision(2) << get<2>(result) << setw(15) << fixed << setprecision(2) << get<3>(result) << setw(15) << get<4>(result) << endl;
    }

    return 0;
}
