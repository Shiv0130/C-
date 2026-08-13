/*5.
#include <iostream>
using namespace std;
struct Node{
int data;
Node * next;
};

    Node * createNode(int data){
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = nullptr;
    return newNode;
    }

    void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{

Node * head = createNode(23);
head->next = createNode(16);
head-> next -> next = createNode(0);
    printList(head);
    return 0;
}*/

/*#include <iostream>
using namespace std;

// Define the structure of a Node in the linked list
struct Node {
    int data;   // Data part to store the integer
    Node* next; // Pointer to the next node
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();   // Allocate memory for a new node
    newNode->data = data;         // Set the data of the node
    newNode->next = nullptr;      // Initialize the next pointer as null
    return newNode;               // Return the new node
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;    // Start from the head
    while (temp != nullptr) {
        cout << temp->data << " -> ";   // Print the data of each node
        temp = temp->next;              // Move to the next node
    }
    cout << "NULL" << endl;
}

// Function to delete a node with a specific value from the linked list
void deleteNode(Node*& head, int value) {
    Node* temp = head;
    Node* prev = nullptr;

    // If the node to be deleted is the head node
    if (temp != nullptr && temp->data == value) {
        head = temp->next; // Change head to the next node
        delete temp;       // Free the old head
        return;
    }

    // Search for the node with the given value
    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the node was not found
    if (temp == nullptr)
        return;

    // Unlink the node from the list and delete it
    prev->next = temp->next;
    delete temp;
}

int main() {
    // Create the initial linked list with nodes 23 -> 16 -> 0 -> NULL
    Node* head = createNode(23);
    head->next = createNode(16);
    head->next->next = createNode(0);

    // a. Make A point to the node containing info 23.
    Node* A = head;  // A points to the first node with data 23

    // b. Make list (head) point to the node containing 16.
    Node* list = head->next;  // list now points to the second node with data 16

    // c. Make B point to the last node in the list.
    Node* B = head;           // Initialize B to head
    while (B->next != nullptr) {
        B = B->next;          // Traverse to the last node
    }
    // Now, B points to the last node (0)

    // d. Make list point to an empty list.
    list = nullptr;   // list is now pointing to an empty list (nullptr)

    // e. Set the value of the node containing 25 to 35.
    // Assuming there is a node with data 25 in the linked list
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == 25) {
            temp->data = 35;  // Change the value from 25 to 35
            break;
        }
        temp = temp->next;
    }
    // If no node has 25, no changes are made

    // f. Create and insert the node with info 10 after the node pointed to by A (node with data 23).
    Node* newNode = createNode(10);    // Create a new node with data 10
    newNode->next = A->next;           // Insert it after A (next node is what A points to next)
    A->next = newNode;                 // Set A's next to the new node

    // g. Delete the node with info 23. Also, deallocate the memory occupied by this node.
    deleteNode(head, 23);  // Deletes the node with value 23

    // Print the final state of the linked list
    printList(head);

    return 0;
}*/

/*6.
#include <iostream>
using namespace std;

// Define a node structure for the linked list
struct Node {
    int info;   // Data field
    Node* link; // Pointer to the next node
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();  // Allocate memory for a new node
    newNode->info = data;        // Assign the data to the node
    newNode->link = nullptr;     // Set the next pointer to null
    return newNode;
}

// Function to print the linked list
void printList(Node* list) {
    Node* p = list;  // Start with the head node

    // Traverse the list until the end (where p becomes nullptr)
    while (p != nullptr) {
        cout << p->info << " ";  // Print the info field of the current node
        p = p->link;             // Move to the next node
    }

    cout << endl;  // Print a newline after the loop ends
}

int main() {
    // Create a simple linked list: 10 -> 20 -> 30 -> 40 -> NULL
    Node* list = createNode(10);   // Create the first node with info 10
    list->link = createNode(20);   // Create the second node with info 20
    list->link->link = createNode(30); // Create the third node with info 30
    list->link->link->link = createNode(40); // Create the fourth node with info 40

    // Call the function to print the list
    printList(list);

    return 0;
}*/

/*7.
p = A;
p = p->link;
s = p;
p->link = NULL;

if (s->link != NULL) {
    s = s->link;
    cout << p->info << " " << s->info << endl;
} else {
    cout << p->info << " NULL" << endl;
}

*/


