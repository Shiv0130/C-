/*#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class to manage a collection of colors
class ColorManager {
private:
    vector<string> colors;  // Vector to store color names

public:
    // Method to add a color to the collection
    void addColor(const string& color) {
        colors.push_back(color);  // Add the color to the vector
        cout << "Color " << color << " added.\n";
    }

    // Method to display all colors in the collection
    void displayColors() {
        if (colors.empty()) {  // Check if there are no colors
            cout << "No colors available.\n";
            return;
        }
        cout << "Available colors:\n";
        for (const auto& color : colors) {  // Loop through the colors and display them
            cout << color << endl;
        }
    }

    // Method to delete a color from the collection
    void deleteColor(const string& color) {
        auto it = find(colors.begin(), colors.end(), color);  // Find the color in the vector
        if (it != colors.end()) {  // If color is found, delete it
            colors.erase(it);
            cout << "Color " << color << " deleted.\n";
        } else {
            cout << "Color " << color << " not found.\n";  // If not found, display an error message
        }
    }

    // Method to search for a color in the collection
    bool searchColor(const string& color) {
        auto it = find(colors.begin(), colors.end(), color);  // Search for the color
        if (it != colors.end()) {  // If found, display a success message
            cout << "Color " << color << " found.\n";
            return true;
        } else {
            cout << "Color " << color << " not found.\n";  // If not found, display an error message
            return false;
        }
    }
};

int main() {
    ColorManager manager;  // Create an instance of ColorManager
    int choice;  // Variable to store user's menu choice
    string color;  // Variable to store the color input

    // Menu system with options to add, display, delete, search, or quit
    do {
        // Display menu options
        cout << "******** Color Management System ********\n";
        cout << "1. Add color\n";
        cout << "2. Display color(s)\n";
        cout << "3. Delete color\n";
        cout << "4. Search color\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;  // Get user's choice

        // Perform action based on user's choice
        switch (choice) {
            case 1:
                // Option to add a color
                cout << "Enter color to add: ";
                cin >> color;
                manager.addColor(color);
                break;
            case 2:
                // Option to display all colors
                manager.displayColors();
                break;
            case 3:
                // Option to delete a color
                cout << "Enter color to delete: ";
                cin >> color;
                manager.deleteColor(color);
                break;
            case 4:
                // Option to search for a color
                cout << "Enter color to search: ";
                cin >> color;
                manager.searchColor(color);
                break;
            case 5:
                // Option to quit the program
                cout << "Exiting program.\n";
                break;
            default:
                // Handle invalid menu choices
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);  // Loop until the user chooses to quit

    return 0;  // Exit the program
}*/

#include <iostream>
#include <string>
using namespace std;

struct Node {
string data;
Node* next;
};

Node* createNode(string data) {
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

void deleteNode(Node*& head, string key) {
if (!head) return; //list is empty
if (head->data == key) { //node to delete is the head
Node* temp = head;
head = head->next;
delete temp;
return;
}

Node* temp = head;
while (temp->next && temp->next->data != key) {
temp = temp->next;
}

if (temp->next) {
Node* toDelete = temp->next;
temp->next = temp->next->next;
delete toDelete;
} else {
cout << "Colour not found!" << endl;
}
}

bool searchNode(Node* head, string key) {
while (head) {
if (head->data == key)
return true;
head = head->next;
}
return false;
}

int main() {
Node* head = nullptr;
int choice;
string colour;

do {
cout << "Menu:\n";
cout << "1. Add Colour\n";
cout << "2. Display Colours\n";
cout << "3. Delete Colour\n";
cout << "4. Search Colour\n";
cout << "5. Quit\n";
cout << "Enter your choice: ";
cin >> choice;

if (choice == 1) {
cout << "Enter the colour to add: ";
cin >> colour;
Node* newNode = createNode(colour);
newNode->next = head; // beginning
head = newNode;
} else if (choice == 2) {
printList(head);
} else if (choice == 3) {
cout << "Enter the colour to delete: ";
cin >> colour;
deleteNode(head, colour);
} else if (choice == 4) {
cout << "Enter the colour to search: ";
cin >> colour;
if (searchNode(head, colour)) {
cout << colour << " Found in the list." << endl;
} else {
cout << colour << " Not found in the list." << endl;
}
} else if (choice != 5) {
cout << "Invalid choice! Please try again." << endl;
}

} while (choice != 5);

return 0;
}



