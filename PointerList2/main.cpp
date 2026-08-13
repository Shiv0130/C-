#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
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

int main() {

    Node* head = createNode(1);
    head->next = createNode(11);
    head->next->next = createNode(3);
    head->next->next->next = createNode(1000);
    head->next->next->next->next = createNode(5);

    printList(head);

    return 0;
}
