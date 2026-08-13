#include <iostream>
#include <cmath> // call cmath library pre-defined functions or user defined //return // void
#include <iomanip>

//Functions are defined 1.// Function prototypes

//2.types...!!!!.That called by Value
/*2. Calling by reference
3. Function Templates
4. Friend Functions
5. Passing array to functions*/
using namespace std;

//float calcArea(float length, float width);//Declare
//float calArea(float length, float width , float height);
//void mymessage();

int main()
{
    /*float a=5.0;
    float b= 6.0;
    float c=8.0;
    //Calling the function
    float area = calcArea(a,b);
    float area2 =calArea(a,b,c);
    mymessage();*/
    /*float a=6.0;
    int g = pow(a,5);
    cout<<setprecision(2)<<endl;
    cout<<g<<endl;*/
    int a = 6;
    int g = sqrt(a);

    cout<<g<<endl;





    /*cout << area << endl;
    cout<< area2<<endl;*/
    return 0;
}

//function implentation
/*float calcArea(float length,float width){

return length*width;
}

void mymessage(){
cout<<"The area is:"<<endl;
}

float calArea(float length, float width, float height){
return length*width*height;
}*/
