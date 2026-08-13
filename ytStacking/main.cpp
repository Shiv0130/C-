#include <iostream>
#include <stack>
using namespace std;

void printStackElements(stack<int> stack){
while(!stack.empty()){
    cout<< stack.top()<<endl;
    stack.pop();
}
}
int main()
{
    stack<int>numberstack;
    numberstack.push(1);
    numberstack.push(2);
    numberstack.push(3);
    numberstack.pop();
    /*numberstack.pop();
    numberstack.pop();
    numberstack.pop();

    if(numberstack.empty()){
        cout<< "Stack is empty" <<endl;

    }
    else{
            cout<< "Stack is not empty;"<<endl;
    }

    cout<< "stack size:"<<numberstack.size() <<endl;*/

    printStackElements(numberstack);

    system("pause>0");
    return 0;
}
