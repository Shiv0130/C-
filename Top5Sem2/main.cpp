/*1. Sample code
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stackType<int> stack;
    int x, y;


x = 4; y = 0; stack.push(7);
stack.push(x);
stack.push(x + 5); y =
stack.top(); stack.pop();
stack.push(x + y);
stack.push(y - 2);
stack.push(3); x =
stack.top(); stack.pop();
cout << "x = " << x <<
endl; cout << "y = " << y
<< endl;
while (!stack.isEmptyStack())
{
cout << stack.top() << endl; stack.pop();
}
    return 0;
}*/

//Corrected version of this code:
/*#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> stack; // Use std::stack instead of stackType
    int x, y;

    x = 4;
    y = 0;
    stack.push(7);
    stack.push(x);
    stack.push(x + 5);
    y = stack.top(); // Assign top value to y
    stack.pop();
    stack.push(x + y);
    stack.push(y - 2);
    stack.push(3);
    x = stack.top();
    stack.pop();

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    while (!stack.empty()) // Use .empty() instead of isEmptyStack()
    {
        cout << stack.top() << endl;
        stack.pop();
    }

    system("pause>0");
    return 0;
}*/

//2.
/*#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stack;
    int x;

    // Initial value pushed to stack
    stack.push(5);

    // Take input values, process until -999 is entered
    cin >> x;
    while (x != -999) {
        // Check if x is even
        if (x % 2 == 0) {
            // Push even numbers to the stack
            stack.push(x);
        }
        else
            // Print odd numbers
            cout << "x = " << x << endl;

        // Take next input
        cin >> x;
    }

    // Display all elements currently in the stack
    cout << "Stack Elements:";
    while (!stack.empty()) {
        cout << " " << stack.top();
        stack.pop();
    }
    cout << endl;

    system("pause>0");

    return 0;
}*/

//6.
/*#include <iostream>
#include <string>
#include <stack>  // Standard stack class in C++
using namespace std;

// Template function that transfers elements from stack s to stack t
template <class Type>
void mystery(stack<Type>& s, stack<Type>& t) {
    // While s is not empty, pop elements from s and push them to t
    while (!s.empty()) {
        t.push(s.top());
        s.pop();
    }
}

int main() {
    stack<string> s1;
    stack<string> s2;
    string list[] = {"Winter", "Spring", "Summer", "Fall", "Cold", "Warm", "Hot"};

    // Push elements from list to s1 stack
    for (int i = 0; i < 7; i++)
        s1.push(list[i]);

    // Transfer elements from s1 to s2 using the mystery function
    mystery(s1, s2);

    // Print all elements in s2, which now has elements in reverse order of s1
    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    system("pause>0");

    return 0;
}*/

//9.
/*#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);

    // Pop the top element (20), so now 10 is at the top
    myStack.pop();

    // Display the current top element (should be 10)
    cout << myStack.top() << endl;

    // Push new elements to stack
    myStack.push(25);
    myStack.push(2 * myStack.top());  // Push 50, which is 2 * 25
    myStack.push(-10);

    // Pop the top element (-10)
    myStack.pop();

    // Create a copy of myStack and print elements of the copy
    stack<int> tempStack = myStack;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    // Display the top element of the original stack (should be 50)
    cout << myStack.top() << endl;

    system("pause>0");

    return 0;
}*/

//10.
/*#include <iostream>
#include <stack>  // Include the standard stack library

using namespace std;

// Node structure for linked list
template <class Type>
struct nodeType {
    Type info;
    nodeType<Type>* link;
};

// Linked list class
template <class Type>
class linkedListType {
public:
    linkedListType();  // Constructor
    ~linkedListType(); // Destructor
    void printListReverse();  // Function to print the list in reverse
    void insertAtEnd(const Type& value); // Function to add an element at the end

private:
    nodeType<Type>* first;  // Pointer to the first node in the linked list
};

// Constructor initializes the linked list
template <class Type>
linkedListType<Type>::linkedListType() : first(nullptr) {}

// Destructor to clean up the linked list
template <class Type>
linkedListType<Type>::~linkedListType() {
    nodeType<Type>* current = first;
    while (current != nullptr) {
        nodeType<Type>* temp = current;
        current = current->link;
        delete temp;
    }
}

// Function to insert an element at the end of the linked list
template <class Type>
void linkedListType<Type>::insertAtEnd(const Type& value) {
    nodeType<Type>* newNode = new nodeType<Type>;
    newNode->info = value;
    newNode->link = nullptr;

    if (first == nullptr) {
        first = newNode;  // List is empty
    } else {
        nodeType<Type>* current = first;
        while (current->link != nullptr) {
            current = current->link;  // Traverse to the end
        }
        current->link = newNode;  // Link the new node
    }
}

// Function to print the linked list in reverse order
template <class Type>
void linkedListType<Type>::printListReverse() {
    stack<Type> stack;  // Use std::stack from STL
    nodeType<Type>* current = first;  // Start from the first node

    // Traverse the linked list and push each element onto the stack
    while (current != nullptr) {
        stack.push(current->info);
        current = current->link;
    }

    // Pop and print each element from the stack, which gives reverse order
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;  // End the line after printing all elements
}

// Example usage (main function)
int main() {
    linkedListType<int> list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Linked list in reverse order: ";
    list.printListReverse();  // Call the function to print in reverse
    return 0;
}*/

#include <iostream>
#include <stack>

using namespace std;

// Function template to clear all elements from an STL stack
template <class Type>
void clear(stack<Type>& s) {
    // Pop elements from stack until it is empty
    while (!s.empty())
        s.pop();
}

// Example usage of the clear function
int main() {
    stack<int> myStack;

    // Pushing some elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Stack size before clearing: " << myStack.size() << endl;

    // Clear the stack
    clear(myStack);

    cout << "Stack size after clearing: " << myStack.size() << endl;

    return 0;
}




