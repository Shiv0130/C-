//classes
/*#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor to initialize length and width
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    // Method to calculate the perimeter
    double calculatePerimeter() {
        return 2 * (length + width);
    }

    // Method to calculate the area
    double calculateArea() {
        return length * width;
    }
};

int main() {
    double length, width, fenceCostPerMeter, fertilizeCostPerSquareMeter;

    // Prompt user for input dimensions and costs
    cout << "Enter the length of the yard/farm in meters: ";
    cin >> length;
    cout << "Enter the width of the yard/farm in meters: ";
    cin >> width;
    cout << "Enter the cost per meter to put up the fence: ";
    cin >> fenceCostPerMeter;
    cout << "Enter the cost per square meter to fertilize the area: ";
    cin >> fertilizeCostPerSquareMeter;

    // Create an instance of Rectangle with user inputs
    Rectangle yard(length, width);

    // Calculate perimeter and area
    double perimeter = yard.calculatePerimeter();
    double area = yard.calculateArea();

    // Calculate costs
    double fenceCost = perimeter * fenceCostPerMeter;
    double fertilizingCost = area * fertilizeCostPerSquareMeter;

    // Output the costs
    cout << "The cost to put up the fence is: $" << fenceCost << endl;
    cout << "The cost to fertilize the area is: $" << fertilizingCost << endl;

    return 0;
}*/

/*#include <iostream>
#include <vector>
using namespace std;

// Base class Shapes
class Shapes {
protected:
    double length;
    double width;

public:
    // Constructor to initialize length and width
    Shapes(double l, double w) : length(l), width(w) {}

    // Virtual method to calculate area
    virtual double Area() = 0; // Pure virtual function making this an abstract class
};

// Derived class Triangle
class Triangle : public Shapes {
public:
    // Constructor to initialize length and width
    Triangle(double l, double w) : Shapes(l, w) {}

    // Override Area method
    double Area() override {
        return (length * width) / 2;
    }
};

// Derived class Rectangle
class Rectangle : public Shapes {
public:
    // Constructor to initialize length and width
    Rectangle(double l, double w) : Shapes(l, w) {}

    // Override Area method
    double Area() override {
        return length * width;
    }
};

int main() {
    // Create a vector of Shapes pointers
    vector<Shapes*> shapes;

    // Add a Triangle instance to the vector
    shapes.push_back(new Triangle(10, 5));

    // Add a Rectangle instance to the vector
    shapes.push_back(new Rectangle(10, 5));

    // Iterate through the vector and print the areas
    for (Shapes* shape : shapes) {
        cout << "The area of the shape is: " << shape->Area() << endl;
    }

    // Clean up dynamic memory
    for (Shapes* shape : shapes) {
        delete shape;
    }

    return 0;
}*/

//file handling

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    // Sample data to write to the file
    string sampleData = "Andrew Miller 87.5 89 65.7 37 98.5";

    // Create and open the input file for writing sample data
    ofstream inputFile("test.txt");
    if (!inputFile) {
        cerr << "Error creating input file." << endl;
        return 1;
    }

    // Write the sample data to the input file
    inputFile << sampleData << endl;

    // Close the input file
    inputFile.close();

    // Declare variables
    string firstName, lastName;
    double scores[5];
    double sum = 0;
    double average;

    // Open the input file for reading
    ifstream inputFileRead("test.txt");
    if (!inputFileRead) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    // Open the output file for writing
    ofstream outputFile("testavs.out");
    if (!outputFile) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    // Read the student name from the input file
    inputFileRead >> firstName >> lastName;
    string studentName = firstName + " " + lastName;

    // Read the five test scores from the input file
    for (int i = 0; i < 5; i++) {
        inputFileRead >> scores[i];
        sum += scores[i];  // Calculate the sum of the scores
    }

    // Calculate the average of the five test scores
    average = sum / 5;

    // Write the student name to the output file
    outputFile << "Student Name: " << studentName << endl;

    // Write the five test scores to the output file
    outputFile << "Test Scores: ";
    for (int i = 0; i < 5; i++) {
        outputFile << scores[i] << " ";
    }
    outputFile << endl;

    // Write the average test score to the output file with a precision of two decimal places
    outputFile << "Average Test Score: " << fixed << setprecision(2) << average << endl;

    // Close the input file
    inputFileRead.close();

    // Close the output file
    outputFile.close();

    return 0;
}

