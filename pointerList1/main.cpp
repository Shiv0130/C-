#include <iostream>
#include <string>
using namespace std;

//design for structure
struct Customer {
    string name;
    Customer* next;
};


class VirtualLine {
private:
    Customer* front;
    Customer* rear;

public:
    VirtualLine() : front(nullptr), rear(nullptr) {}


    void addCustomer() {
        Customer* newCustomer = new Customer;
        newCustomer->name = customerName;
        newCustomer->next = nullptr;

        if (rear == nullptr) {  // If the queue is empty
            front = rear = newCustomer;
        } else {
            rear->next = newCustomer;
            rear = newCustomer;
        }
        cout << "Customer " << customerName << " added to the line.\n";
    }

    void callCustomer() {
        if (front == nullptr) {
            cout << "There is no customer for now.\n";
            return;
        }

        Customer* temp = front;
        cout << "Calling customer: " << temp->name << endl;

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;  // If the queue becomes empty
        }

        delete temp;
    }
};

int main() {
    VirtualLine line;
    int choice;
    string customerName;

    do {
        cout << "******** Welcome to Virtual line system ************\n";
        cout << "1. Call a customer\n";
        cout << "2. Add a customer\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                line.callCustomer();
                break;
            case 2:
                cout << "Enter the name of the customer: ";
                cin >> customerName;
                line.addCustomer(customerName);
                break;
            case 3:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
