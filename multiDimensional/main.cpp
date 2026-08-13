#include <iostream>
using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLS = 3;

// Function to input matrix elements
void inputMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display matrix
void displayMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to calculate and display row totals
void calculateRowTotal(int matrix[][MAX_COLS], int rows, int cols) {
    cout << "Row totals:" << endl;
    for (int i = 0; i < rows; ++i) {
        int rowTotal = 0;
        for (int j = 0; j < cols; ++j) {
            rowTotal += matrix[i][j];
        }
        cout << "Row " << i << " total: " << rowTotal << endl;
    }
}

// Function to calculate and display column totals
void calculateColumnTotal(int matrix[][MAX_COLS], int rows, int cols) {
    cout << "Column totals:" << endl;
    for (int j = 0; j < cols; ++j) {
        int colTotal = 0;
        for (int i = 0; i < rows; ++i) {
            colTotal += matrix[i][j];
        }
        cout << "Column " << j << " total: " << colTotal << endl;
    }
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS];

    // Input matrix
    inputMatrix(matrix, MAX_ROWS, MAX_COLS);

    // Display matrix
    displayMatrix(matrix, MAX_ROWS, MAX_COLS);

    // Calculate and display row totals
    calculateRowTotal(matrix, MAX_ROWS, MAX_COLS);

    // Calculate and display column totals
    calculateColumnTotal(matrix, MAX_ROWS, MAX_COLS);

    return 0;
}
