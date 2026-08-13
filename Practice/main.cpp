//Practice
/*#include <iostream>

using namespace std;

class Node{
int head = new Node();
int second = new Node();
int third = new Node();
};
int main()
{

    cout << "Hello world!" << endl;
    return 0;
}*/

//Correction
/*#include <iostream>
#include <memory> // Include memory for smart pointers

using namespace std;

// Template class to make the linked list type-flexible
template <typename T>
class LinkedList {
private:
    // Define a Node structure within the LinkedList class
    struct Node {
        T data;                      // Data of any type (T) stored in the node
        shared_ptr<Node> next;       // Pointer to the next node in the list
        Node(T val) : data(val), next(nullptr) {} // Constructor to initialize node with data
    };

    shared_ptr<Node> head;           // Pointer to the first node in the list

public:
    // Constructor initializes the head pointer to nullptr, indicating an empty list
    LinkedList() : head(nullptr) {}

    // Function to add an element in sorted order
    void add(T value) {
        // Create a new node with the given value
        auto newNode = make_shared<Node>(value);

        // If list is empty or the new value is smaller than the head, insert at beginning
        if (!head || head->data >= value) {
            newNode->next = head;  // Set new node's next to current head
            head = newNode;        // Update head to the new node
        } else {
            // Find the correct position to insert new node to keep list sorted
            auto current = head;
            while (current->next && current->next->data < value) {
                current = current->next; // Move to the next node
            }
            // Insert newNode after current
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to remove an element by value
    void remove(T value) {
        // If list is empty, print a message and return
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        // If the value is at the head, update head to next node
        if (head->data == value) {
            head = head->next; // Move head to the next node
            return;
        }

        // Find the node with the value to be deleted
        auto current = head;
        while (current->next && current->next->data != value) {
            current = current->next; // Move to the next node
        }

        // If node is found, unlink it from the list
        if (current->next) {
            current->next = current->next->next;
        } else {
            cout << "Element " << value << " not found in the list.\n";
        }
    }

    // Function to display all elements in the list
    void display() const {
        auto current = head; // Start from the head
        while (current) {    // Traverse until the end of the list
            cout << current->data << " "; // Print the data
            current = current->next;      // Move to the next node
        }
        cout << endl; // New line after displaying the list
    }
};

int main() {
    // Instantiate two lists: one for integers, one for strings
    LinkedList<int> intList;
    LinkedList<string> strList;

    int choice; // Variable to store user's menu choice
    do {
        // Display the menu
        cout << "\nMenu:\n";
        cout << "1. Add to integer list\n";
        cout << "2. Remove from integer list\n";
        cout << "3. Display integer list\n";
        cout << "4. Add to string list\n";
        cout << "5. Remove from string list\n";
        cout << "6. Display string list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Read user's choice

        if (choice == 1) {
            // Add to integer list
            int value;
            cout << "Enter integer to add: ";
            cin >> value;
            intList.add(value);
        } else if (choice == 2) {
            // Remove from integer list
            int value;
            cout << "Enter integer to remove: ";
            cin >> value;
            intList.remove(value);
        } else if (choice == 3) {
            // Display integer list
            cout << "Integer list: ";
            intList.display();
        } else if (choice == 4) {
            // Add to string list
            string value;
            cout << "Enter string to add: ";
            cin >> value;
            strList.add(value);
        } else if (choice == 5) {
            // Remove from string list
            string value;
            cout << "Enter string to remove: ";
            cin >> value;
            strList.remove(value);
        } else if (choice == 6) {
            // Display string list
            cout << "String list: ";
            strList.display();
        }
    } while (choice != 0); // Continue until user chooses to exit

    return 0; // End of program
}*/

//Question 2
/*#include <iostream>

using namespace std;

int fibonacci(int n){

if(n==0){
    return 0;
}
if(n==1){
    return 1;
}

return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    int n;
    cout<<"Enter Fibonacci(n) postion:";
    cin>> n;

    int result = fibonacci(n);

    cout << "Fibonacci number at position" << n << "is" << result <<endl;
    return 0;
}*/

//practice exam pt 1
/*#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) // Base case: factorial of 0 or 1 is 1
        return 1;
    else
        return n * factorial(n - 1); // Recursive call
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Factorial of " << number << " is " << factorial(number) << endl;
    return 0;
}*/

/*#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    int top;
    int arr[MAX]; // Array to store stack elements

public:
    Stack() : top(-1) {} // Constructor initializing top as -1

    bool push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow\n";
            return false;
        } else {
            arr[++top] = x;
            return true;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return -1;
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    cout << "Popped element: " << stack.pop() << endl;
    return 0;
}*/

/*#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int>& q) {
    stack<int> s;

    // Push all elements from the queue to the stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Push elements back from the stack to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}*/

/*#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int data, int position) {
        if (position <= 0) {
            insertAtBeginning(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* temp = head;
        for (int i = 1; i < position && temp; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(1);
    list.insertAtEnd(3);
    list.insertAtPosition(2, 1);
    list.display();
    return 0;
}*/

/*#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search right half
        } else {
            right = mid - 1; // Search left half
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int result = binarySearch(arr, size, target);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found.\n";
    return 0;
}*/

/*#include <iostream>
#include <queue>
#include <string>
using namespace std;

class HospitalQueue {
    queue<string> patients;

public:
    void addPatient(const string& name) {
        patients.push(name);
        cout << name << " has been added to the queue.\n";
    }

    void removePatient() {
        if (patients.empty()) {
            cout << "No patients in the queue.\n";
        } else {
            cout << patients.front() << " has been removed from the queue.\n";
            patients.pop();
        }
    }

    void displayQueue() {
        if (patients.empty()) {
            cout << "No patients in the queue.\n";
        } else {
            queue<string> temp = patients;
            cout << "Patients in queue: ";
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }
};

int main() {
    HospitalQueue hospital;
    int choice;
    string name;

    do {
        cout << "\n1. Add patient\n2. Remove patient\n3. Display queue\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                cin >> name;
                hospital.addPatient(name);
                break;
            case 2:
                hospital.removePatient();
                break;
            case 3:
                hospital.displayQueue();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}*/







