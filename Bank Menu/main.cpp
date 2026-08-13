#include <iostream>

using namespace std;

void menu() {
    cout << "------------Menu-------------" << endl;
    cout << "1. Deposit Cash" << endl;
    cout << "2. Withdraw Cash" << endl;
    cout << "3. Check Balance" << endl;
    cout << "4. Exit Application" << endl;
    cout << "------------------------------" << endl;
}

void deposit(double &balance, float amount) {
    balance += amount;
    cout << "Deposit Successful. Current Balance: " << balance << endl;
}

void withdraw(double &balance, float amount) {
    if (amount > balance) {
        cout << "Insufficient balance." << endl;
    } else {
        balance -= amount;
        cout << "Withdrawal Successful. Current Balance: " << balance << endl;
    }
}

void check_balance(double balance) {
    cout << "Current Account Balance: " << balance << endl;
}


int main() {
    int choice;
    double balance = 0.0;
    float amount;

    do {
        menu();
        cout << "Please enter choice from menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                deposit(balance, amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdraw(balance, amount);
                break;
            case 3:
                check_balance(balance);
                break;
            case 4:
                cout << "Exiting application." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid number." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
