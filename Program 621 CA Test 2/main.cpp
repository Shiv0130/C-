#include <iostream>

using namespace std;

int main()
/*{
    int num=0;
    while(num<100){
        if(num%2==0){
            cout<<num<<endl;
        }
        num++;

    }*/


/*void printUserDetails(string name, string surname , int age){
cout<<"Enter your name:";
cin>>name;
cout<<"Enter your surname:";
cin>>surname;
cout<<"Enter your age:";
cin>>age;

if(age>=18){
cout<<"We are happy that you are now an adult"<<endl;
}
}
    return 0;
}*/

#include <iostream>
#include <string>

using namespace std;

void printUserDetails(string name, string surname, int age) {
    if (age > 18) {
        cout << name << " " << surname << " " << age << " We are happy to say you are now an adult." << endl;
    } else {
        int years_left = 18 - age;
        cout << name << " " << surname << " " << age << " Sorry you are still young and you have " << years_left << " years before you turn 18." << endl;
    }
}

int main() {
    printUserDetails("John", "Doe", 25);
    printUserDetails("Jane", "Smith", 16);
    return 0;
}

