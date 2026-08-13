#include <iostream>
#include <cmath>
using namespace std;

/*void circle(){
float radius;
double Diameter,Circumference,area;
cout<<"Enter radius";
cin>>radius;
Diameter = 2* radius;
Circumference = 2* 3.14 *radius;
area=(3.14 *radius**2);
cout<<"Diameter is:"<<Diameter;
cout<<"Circumference is:"<<Circumference;
cout<<"Area :"<<area;

}*/

void circle() {
    float radius;
    double Diameter, Circumference, area;
    cout << "Enter radius: ";
    cin >> radius;
    Diameter = 2 * radius;
    Circumference = 2 * 3.14 * radius;
    area = 3.14 * pow(radius, 2); // Corrected area calculation
    cout << "Diameter is: " << Diameter << endl; // Added newline character
    cout << "Circumference is: " << Circumference << endl; // Added newline character
    cout << "Area: " << area << endl; // Added newline character
}

int main()

{
    /*int number;

    cout << "Enter number:" ;
    cin>>number;

    if (number%2==0){
        cout<<"Number is even";
    }else {
    cout<<"Number is odd";
    }*/

    circle();

    return 0;
}
