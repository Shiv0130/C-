// Q2b_Assignment.cpp
// Part b: Linked List Implementation of Self-Adjusting List

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class SelfAdjustingLinkedList {
private:
    Node* head;
    int size;

public:
    SelfAdjustingLinkedList() : head(nullptr), size(0) {}

    // Insert at the front (head)
    void insert(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Find element and move to front
    bool find(int data) {
        if (head == nullptr) {
            return false;
        }

        // Element already at front
        if (head->data == data) {
            return true;
        }

        Node* current = head;
        Node* prev = nullptr;

        // Search for the element
        while (current != nullptr && current->data != data) {
            prev = current;
            current = current->next;
        }

        // Element not found
        if (current == nullptr) {
            return false;
        }

        // Move element to front
        prev->next = current->next;  // Remove from current position
        current->next = head;         // Point to old head
        head = current;               // Update head

        return true;
    }

    void display() {
        Node* current = head;
        cout << "List: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~SelfAdjustingLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    SelfAdjustingLinkedList list;

    cout << "=== Linked List Implementation ===" << endl;
    cout << "\nInserting elements: 10, 20, 30, 40, 50" << endl;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);
    list.display();

    cout << "\nFinding 20..." << endl;
    list.find(20);
    list.display();

    cout << "\nFinding 10..." << endl;
    list.find(10);
    list.display();

    return 0;
}
