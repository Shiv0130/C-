#include <iostream>
using namespace std;

// See if number is odd and even;

int main()
{
    /* int num;
       cout << "Enter number:";
       cin>>num;

       if (num%2==0) {
           cout<<"Number is even";
       }
       else{
           cout<<"Number is odd";
       }*/

    // Printing available operations
    cout<<"+,-,/,*"<<endl;

    // Declaring variables
    int num1,num2,result;

    // Prompting user to enter first number
    cout<<"Enter firstnum:"<<endl;
    cin>>num1;

    // Prompting user to enter second number
    cout<<"Enter secondnum"<<endl;
    cin>>num2;

    // Reading operation from user
    char c;
    cin>>c;

    // Switch statement based on operation
    switch(c)
    {
        // Addition case
        case '+':
            result=num1+num2;
            cout<<result<<endl;
            break;

        // Subtraction case
        case '-':
            result=num1-num2;
            cout<<result<<endl;
            break;

        // Division case
        case '/':
            result=num1/num2;
            cout<<result<<endl;
            break;

        // Multiplication case
        case '*':
            result=num1*num2;
            cout<<result<<endl;
            break;

        // Handling incorrect input (should use '*')
        default:
            if(c == '2'){
                cout<<"Enter firstnum"<<endl;
                cin>>num1;
                cout<<"Enter secondnum"<<endl;
                cin>>num2;
                int result2=num1*num2;
                cout<<result2<<endl;
            }
            else{
                cout<<"Invalid operation"<<endl;
            }
            break;
    }

    return 0;
}
