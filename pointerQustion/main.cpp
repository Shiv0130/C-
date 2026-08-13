//#include <iostream>

//using namespace std;
 //void swapNumbers(int &num1,int &num2)
 //{
 //int temp=*num1;
 //*num1=*num2;
// *num2=temp;
// }

//int main()
//{
    //int a=10;
    //int b=20;
    //cout<<swapNumbers(&a,&b)<<endl;


    //return 0;
//}



#include <iostream>

using namespace std;
void swapNum(int &x , int &y){
    int temp = x;
    x = y ;
    y = temp;

}
//Get two numbers from the user and multiply the numbers by 20 using pointers then swap the numbers
int main()
{
    int a;
    int b;
    int *ptrA = &a; //&referencing     * derefencing
    int *ptrB = &b;

    cout<<"Enter integer a:"<<endl;
    cin>>a;
    cout<<"Address of a:"<<ptrA<<endl;

    cout<<"Enter integer b:"<<endl;
    cin>>b;
    cout<<"Address of b:"<<ptrB<<endl;

    cout<<"Original"<<endl;
    cout<<a<<endl;
    cout<<b<<endl;

    cout<<"Multiply by 20"<<endl;
    *ptrA *= 20 ;
    *ptrB *= 20 ;

    cout<<*ptrA<<endl;
    cout<<*ptrB<<endl;

    swapNum(a, b);
    cout<<"The swapped numbers are:"<<"a:"<<a<<"b:"<<b<<endl;



    return 0;
}
