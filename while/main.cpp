#include <iostream>

using namespace std;


int main()
{
    /*int count=0; // count itration or loops
    int sum=0;//holds running total
    int mark; // user marks
    int avg;


cout<<"Enter marks:"<<endl;
    while (count<10){

        sum=sum+mark;
        count++;
        cin>>mark;
    }
    cout<<"The sum is:"<<sum<<endl;
    avg=sum/count;

    cout<<"The average marks are:"<<avg<<endl;*/

    cout<<"1.Addition"<<endl;
    cout<<"2.Multiplication"<<endl;
    cout<<"3.Division"<<endl;
    cout<<"4.Subtraction"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"select operation (1-4) and 5 to exit"<<endl;

    int input;
    cin>>input;

    while (input != 5){
        if(input==1){
            cout<<"Selected Addition"<<endl;
            break;
        }
        //cin>>mark;

    }
    if (input==5){
        cout<<"Selected to end the program"<<endl;
    }


    return 0;
}
