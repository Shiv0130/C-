#include <iostream>

// Define the 'Box' class
class Box {
private:
    // Attributes for the dimensions of the box
    double length, width, height;

public:
    // Constructor to initialize a Box with its dimensions
    Box(double l, double w, double h) : length(l), width(w), height(h) {}

    // Overloading the '+' operator
    // This allows us to "add" two Box objects together
    Box operator+(const Box& b) {
        // Here, adding two boxes means combining their volumes
        // We calculate the volume of each and add them together
        double combinedVolume = length * width * height + b.length * b.width * b.height;

        // We create a new Box object with the combined volume
        // Note: The new Box dimensions are a bit abstract in this context,
        // assuming a box with only volume and no specific dimensions.
        return Box(1, 1, combinedVolume);
    }

    // Method to display the volume of the box
    void displayVolume() {
        std::cout << "Volume: " << length * width * height << " cubic units\n";
    }
};

int main() {
    // Create two Box objects
    Box box1(2, 3, 4); // A box with dimensions 2x3x4
    Box box2(1, 1, 1); // A smaller box with dimensions 1x1x1

    // Add the two boxes together using the overloaded '+' operator
    // Behind the scenes, this calls the 'operator+' method we defined,
    // creating a new Box with the combined volume of box1 and box2.
    Box combinedBox = box1 + box2;

    // Display the volume of the combined box
    combinedBox.displayVolume();

    return 0;
}
