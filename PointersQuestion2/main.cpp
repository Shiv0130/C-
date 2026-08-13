/*//Write a C++ program that’s prompts the user for two integers.
// Using the concepts of functions and pointers find the largest,smallest or if the numbers is equal.
#include <iostream>
using namespace std;

void MaxNum(int &x, int &y){
int max=0;
if(x>y){
        max=x;
        cout<<max;


} else{
    max=y;
    cout<<max;

}

int main()
{
    int a,b;
    int *ptrA=&a;
    int *ptrB=&b;

    cout<<"Enter num1:";
    cin>>a;
    cout<<ptrA<<endl;
    cout <<"Enter num2:";
    cin>>b;
    cout<<ptrB<<endl;
    cout<<"Numbers displayed:"<<endl;
    cout<<a<<endl<<b<<endl;

    cout<<"Max number is:";
    MaxNum(a,b);


    return 0;
}*/

#include <iostream>
using namespace std;

// Function to find and print the maximum number
void MaxNum(int &x, int &y) {
    if (x > y) {
        cout << "Max number is: " << x << endl;
    } else if (y > x) {
        cout << "Max number is: " << y << endl;
    } else {
        cout << "Both numbers are equal." << endl;
    }
}

// Function to find and print the minimum number
void MinNum(int &x, int &y) {
    if (x < y) {
        cout << "Min number is: " << x << endl;
    } else if (y < x) {
        cout << "Min number is: " << y << endl;
    } else {
        cout << "Both numbers are equal." << endl;
    }
}

int main() {
    int a, b; // Declare two integer variables
    int *ptrA = &a; // Pointer to store the address of variable a
    int *ptrB = &b; // Pointer to store the address of variable b

    // Prompt user to enter the first number
    cout << "Enter num1: ";
    cin >> a;
    // Display the address of the first number
    cout << "Address of num1: " << ptrA << endl;

    // Prompt user to enter the second number
    cout << "Enter num2: ";
    cin >> b;
    // Display the address of the second number
    cout << "Address of num2: " << ptrB << endl;

    // Display the entered numbers
    cout << "Numbers displayed:" << endl;
    cout << a << endl << b << endl;

    // Call MaxNum function to find and display the maximum number
    MaxNum(a, b);
    // Call MinNum function to find and display the minimum number
    MinNum(a, b);

    return 0;
}

