#include <iostream>
using namespace std;
struct Node {
    string color;
    Node* next;
};

Node* createNode(string color) {
    Node* newNode = new Node();
    newNode->color = color;
    newNode->next = nullptr;
    return newNode;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->color << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {

    Node* head = createNode("Black");
    head->next = createNode("Red");
    head->next->next = createNode("Purple");
    head->next->next->next = createNode("Yellow");
    head->next->next->next->next = createNode("Blue");

    printList(head);

    return 0;
}
