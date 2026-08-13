#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    int num[ ] ={1,2,3,4,5};
    int length=sizeof(num)/sizeof(num[0]);
    cout << sizeof(num) << endl;
    cout << sizeof(num[0]) << endl;

    for (int i=0; i<length;i++){
    cout << "Element" << i<<":"<<num[i] <<endl;

    }

    return 0;
}
