#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Class for Doubly Linked List
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the front
    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert a node at the end
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to delete a node
    void deleteNode(int value) {
        if (head == nullptr) return;

        Node* temp = head;

        // If the node to be deleted is the head
        if (head->data == value) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            delete temp;
            return;
        }

        // Traverse the list to find the node to be deleted
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        // If the node is not found
        if (temp == nullptr) return;

        // Update the pointers and delete the node
        if (temp->next != nullptr) temp->next->prev = temp->prev;
        if (temp->prev != nullptr) temp->prev->next = temp->next;
        delete temp;
    }

    // Function to print the list from head to tail
    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to print the list from tail to head
    void displayBackward() {
        if (head == nullptr) return;
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertFront(5);
    dll.insertEnd(30);

    cout << "List in forward direction: ";
    dll.displayForward();

    cout << "List in backward direction: ";
    dll.displayBackward();

    dll.deleteNode(20);
    cout << "List after deleting 20: ";
    dll.displayForward();

    return 0;
}
