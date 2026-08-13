#include <iostream>

using namespace std;

int main()
{
    /*int a=7;
    int *ptr =&a;
    int b = *ptr;
    *ptr +=1;
    cout<<b<<endl;
    cout<<ptr<<endl;
    cout << a<< endl;*/

    /*int temp[5]= {};
    cout<<"Plase enter 5 temperatures:"<<endl;
    for(int i=0;i<5;i++){
        cin>>temp[i];
    }
    cout<<"Values in the array:"<<endl;
    for(int i=0; i<5;i++){
        cout<<temp[i]<<endl;
    }*/


    int temp[5]= {};
    int *ptr=&temp[0];
    cout<<"Plase enter 5 temperatures:"<<endl;
    for(int i=0;i<5;i++){
        cin>>temp[i];
        *(ptr+i)+=10;
    }
    cout<<"Values in the array:"<<endl;
    for(int i=0; i<5;i++){
        cout<<temp[i]<<endl;
    }

    return 0;
}
