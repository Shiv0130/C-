/*#include <iostream>

using namespace std;
//void printsomething();

int main()
{
    printsomething();
    return 0;
}

void printsomething(){
cout<<"its never to early to start drinking"<<endl;
}*/


#include <iostream>


/*
---------------
Explaination:
---------------

a) Function overloading is a form of polymorphisim,
this is where the function name is used to perform
different operations as they are called.

b) However, function overloading cannot be based solely on the return
type.
Two functions cannot consist of the same characters(numbers or words)

c) Functions overloading can cause ambiguity if the compiler
cannot match with the provided arguments. It is also import
to not overuse a function.


*/

using namespace std;

// Function to add two integers

//adding means output/return a+b
int add(int a, int b) {
    return a + b;
}

// Overloaded function to add three integers
int add(int a, int b, int c) {
    return a + b + c;
}

// Overloaded function to add two doubles
double add(double a, double b) {
    return a + b;
}

// This creates a main function, which creates the keyword/final function to display which is sum1, 2 or 3.

int main() {
    int sum1 = add(2, 3);            // Calls the first add function
    int sum2 = add(2, 3, 4);         // Calls the second add function

    // *** may use "double" or "float" when working with decimals(Float only when both numbers are decimals)

    double sum3 = add(2.4 , 8.3);     // Calls the third add

    cout << "Below are three answers of sums \n--------------------------------" << endl;
    //sums:
    cout << "Sum1: " << sum1 <<endl;
    cout << "Sum2: " << sum2 <<endl;
    cout << "Sum3: " << sum3 <<endl;

    return 0;
}
