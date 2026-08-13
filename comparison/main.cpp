#include <iostream>

using namespace std;

void compareMe(int num1, int num2) {
    if (num1 == num2) {
        cout << "Both numbers are equal." << endl;
    } else if (num1 < num2) {
        cout << num1 << " is the smallest number." << endl;
        cout << num2 << " is the biggest number." << endl;
    } else {
        cout << num2 << " is the smallest number." << endl;
        cout << num1 << " is the biggest number." << endl;
    }
}

int main() {
    int num1, num2;
    cout << "Enter the first integer: ";
    cin >> num1;
    cout << "Enter the second integer: ";
    cin >> num2;

    compareMe(num1, num2);

    return 0;
}
