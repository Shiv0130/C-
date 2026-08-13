#include <iostream>
using namespace std;

// Function to display elements of an array
void display(int num[], int size){
    cout << "Display elements:" << endl;
    for(int i = 0; i < size; i++){
        cout << "Student " << i + 1 << ": " << num[i] << endl;
    }
}

int main()
{
    const int size = 5;
    int number[size] = {10, 20, 30, 40, 50};

    // Display the elements of the array
    display(number, size);

    return 0;
}
