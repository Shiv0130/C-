#include <iostream>

using namespace std;
    /*int factorial(int n ){
    if(n==0 || n==1){
        return 1;
    }
    return n* factorial(n-1);
    }*/

    int fibonnaci(int n){
    //Base cases
    if(n == 0 ) {
        return 0;
    } if(n == 1){
    return 1;
    }
    //Reursive case
    return fibonnaci(n-1) + fibonnaci(n-2);
    }

int main()
{
    /*int number;
    cout<< "Enter a positive integer:";
    cin>>number;
    int result = factorial(number);
    cout<< " Factorial of " << number <<  " is "  <<  result  <<endl;*/

    int n;
    cout<<"Enter the postion(n) for Fibonnaci number:";
    cin>> n;

    //Calculate Fibonnaci number
    int result = fibonnaci(n);
    cout<<" Fibonnaci number at postion " << n << " is " << result << endl;


    return 0;
}
