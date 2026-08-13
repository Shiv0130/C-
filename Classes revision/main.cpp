#include <iostream>
#include <string>
using namespace std;

// Class definition
class secretType {
private:
    // Instance variables
    string name;
    int age;
    int weight;
    double height;

public:
    // Default constructor
    secretType() {
        name = "";
        age = 0;
        weight = 0;
        height = 0.0;
    }

    // Parameterized constructor
    secretType(string newName, int newAge, int newWeight, double newHeight) {
        name = newName;
        age = newAge;
        weight = newWeight;
        height = newHeight;
    }

    // Function to print instance variables
    void print() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
        cout << "Height: " << height << endl;
    }

    // Function to set the name
    void setName(string newName) {
        name = newName;
    }

    // Function to set the age
    void setAge(int newAge) {
        age = newAge;
    }

    // Function to set the weight
    void setWeight(int newWeight) {
        weight = newWeight;
    }

    // Function to set the height
    void setHeight(double newHeight) {
        height = newHeight;
    }

    // Function to get the name
    string getName() const {
        return name;
    }

    // Function to get the age
    int getAge() const {
        return age;
    }

    // Function to get the weight
    int getWeight() const {
        return weight;
    }

    // Function to get the height
    double getHeight() const {
        return height;
    }
};

int main() {
    // Create an object using the default constructor
    secretType person1;

    // Create an object using the parameterized constructor
    secretType person2("John Doe", 30, 180, 5.9);


    // Print details of person2
    cout << "Details of person2:" << endl;
    person2.print();
    cout << endl;

    // Set values for person1
    person1.setName("Alice");
    person1.setAge(25);
    person1.setWeight(150);
    person1.setHeight(5.5);

    // Print updated details of person1
    cout << "Updated details of person1:" << endl;
    person1.print();

    return 0;
}

/*#include <iostream>
#include <string>
using namespace std;

// Assume the personType class is defined as follows:
class personType {
private:
    string firstName;
    string lastName;

public:
    // Function to set the first name
    void setFirstName(string newFirstName) {
        firstName = newFirstName;
    }

    // Function to set the last name
    void setLastName(string newLastName) {
        lastName = newLastName;
    }

    // Function to get the first name
    string getFirstName() const {
        return firstName;
    }

    // Function to get the last name
    string getLastName() const {
        return lastName;
    }
};

int main() {
    // Declare and initialize a personType object
    personType student;
    student.setFirstName("Buddy");
    student.setLastName("Arora");

    // Output the data stored in the object student
    cout << "First Name: " << student.getFirstName() << endl;
    cout << "Last Name: " << student.getLastName() << endl;

    // Change the first name and last name of student
    student.setFirstName("Susan");
    student.setLastName("Miller");

    // Output the updated data stored in the object student
    cout << "Updated First Name: " << student.getFirstName() << endl;
    cout << "Updated Last Name: " << student.getLastName() << endl;

    return 0;
}*/

