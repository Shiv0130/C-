#include <iostream>
int factorial(int num){
//int result = 1;
//for(int i =1; i<=num; i++){
  //  result = result * i;
//}
//return result;

if(num > 1){
    return num * factorial(num -1);
}
else{
        return 1;

}

}
using namespace std;

//void walk(int steps){
//itrative approach
//for(int i=0;i<steps;i++){
  //  cout<<"You take a step!\n"<<endl;
//}

//recursive approach
//if(steps > 0){
  //  cout<< "You take a step\n";
   // walk(steps-1);
//}

//}

int main()
{
    //recursion = a programming technique where a function invokes itself from within break a complex concept into a repeatable step
    //(iterative vs recursive)

    //advantages = less code and is cleaner
    //                      useful for sorting and searching algorithms

    //disadvantages = uses more memory
    //                              slower

    //walk(100);

    cout<< factorial(10);



    return 0;
}
