/*Topic 2 part 2
//This is a demonstration od c++ program structure
#include <iostream>

using namespace std;

int main()
{
    int number1,number2,sum,product;
    //number1=10;
    //number2=20;
    //Let user enter the numbers:
    cout<<"Enter first number:";
    cin>>number1;

    cout<<"Enter second number:";
    cin>>number2;

     sum=number1+number2;
     cout << "The addition of both the numbers are:"<<sum << endl;

     product=number1*number2;
     cout << "The product of both the numbers are:"<<product << endl;

    /*string name="Jerry";
    int age=20;
    char initial='J';//Characters in C++ work with single strings whereas strings work with "";
    cout<<"Hello my name is:"<<name<<"and my intial is:"<<initial<<endl;


    cout << "Your number is:"<<number1 << endl;
    cout << "Your number is:"<<number2 << endl;*/

   // system("pause>0");//remobves all unneccessary parts of the execution
    //Executed code goes inside

    //return 0;
//}

//This is a demonstration od c++ program structure
//#include <iostream>

//using namespace std;

//int main()
//{
    //Write a program that grades the marks of a person
    //If a person gets 60 and above, its a "pass". If a person gets less than 60 it is a "Fail"

    /*int mark;
    cout<<"Enter your mark:";
    cin>>mark;

    if(mark>=60){
        cout<<"Pass";
    }
    else{
        cout<<"fail";
    }*/

    //Day of the week problem

    //Write a program that when given a number between 1 and 7 it gives the day
    //that corresponds to that number
    /*int number;
    cout<<"Enter a number between 1 and 7:";
    cin>>number;

    if(number==1){
        cout<<"Sunday";
    }
    else if(number==2){
        cout<<"Monday";
    }

    else if(number==3){
        cout<<"Tuesday";
    }
    else if(number==4){
        cout<<"Wednesday";
    }
    else if(number==5){
        cout<<"Thursday";
    }
    else if(number==6){
        cout<<"Friday";
    }
    else if(number==7){
        cout<<"Saturday";
    }
    else{
        cout<<"Enter a valid number!";
    }*/
    //Wouldn't it be better to approach this question with a switch

    /*switch(number){
        case 1:cout<<"Sunday";
        break;
        case 2:cout<<"Monday";
        break;
        case 3:cout<<"Tuesday";
        break;
        case 4:cout<<"Wednesday";
        break;
        case 5:cout<<"Thursday";
        break;
        case 6:cout<<"Friday";
        break;
        case 7:cout<<"Saterday";
        break;
        /* trial and error default{
            cout<<"Enter a valid number!";
            }*/
        //default:
            //cout<<"Enter a valid number!";
    //end of switch}

    //While loop
    //Write a program that keeps asking the user for a number until you enter a negative number.
    //At the end, the program should print the average of all the printed numbers

    /*//Code doesn't work
    int number,sum,avg;
    sum=0;
    avg=0;
   cout<<"Enter number:";
    cin>>number;

    while(number<0){
        cout<<"Enter number";
        cin>>number;
        sum+=number;
        avg=sum/number;
        number++;
        cout<<"The average of all numbers entered here is:"<<avg;
    }
    //cout<<"The average of all numbers entered here is:"<<avg;*/
//correction

/*int number,totNum;
double average,sum;

//Intialize variables
totNum=0;
sum=0;
cout<<"Enter a number:";
cin>>number;

while(number>0){
    totNum++;
    sum=sum+number;
    cout<<"Enter a number:";
    cin>>number;
}
average=sum/totNum;
cout<<"Your average of the" << totNum << "numbers are:"<<average<<endl;*/

//Do While Loop
    //Write a program that keeps asking the user for a number until you enter a negative number.
    //At the end, the program should print the average of all the printed numbers

    /*int number,totNum;
    double avg,sum;
    sum=0;
    totNum=0;

    cout<<"Enter number:";
    cin>>number;

    do{
        cout<<"Enter number:";
        cin>>number;
        totNum++;
        sum=sum+number;



    } while(number>0);
    avg=sum/totNum;
cout<<"Your average of the" << totNum << "numbers are:"<<avg<<endl;*/

//For Loop

//Write a program that takes in 10 numbers and then calculate the average of the numbers

/*int number,i;
float sum,avg;
//cout<<"Enter number:";
//cin>>number:
    sum=0;
    for(i=0;i<10;i++){
            cout<<"Enter number:";
            cin>>number;
            sum+=number;
            avg=sum/i;
    }
    cout<<"The average of the numbers you entered are:"<<avg;


    system("pause>0");

    return 0;
}*/

//Topic 4 part 2
/*#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;


int main()
{
    //int num,num1;
    //cout<<"Enter an integer \n" ;//moves the  cursor to the next line
    //res=abs(num);
    //cout << "The positive number of the value supplied is:"<<res;
   // cout<<"Enter to numbers to calculate the larger"<<endl;
   // cin>>num;
   // cin>>num1;
   // char letter='t';
   // cout<<"The larger number is:"<<max(num,num1)<<endl;
   // cout<<"The given letter in uppercase is:"<<(char)toupper(letter);





    system("pause>0");

    return 0;
}*/

/*#include <iostream>

using namespace std;

int add(int x, int y)
{
    return x+y;
}

double add(double x,double y,double z)
{
return x+y+z;
}


int main()
{
    int num1,num2;
    cout<<"Enter num1:";
    cin>>num1;

    cout<<"Enter num2:";
    cin>>num2;

 cout<<"The addition of "<< num1 <<"and"<< num2 <<"is "<<add(num1,num2)<<endl;
 cout<<"The addition of three numbers is"<<add(5.6,8.7,9.3);

 cin.get();
 cin.ignore();
 //When your output window dissappears to quickly

    system("pause>0");

    return 0;
}*/


/*#include <iostream>
#include <iomanip>// Use this for setprecision and all that

using namespace std;
//Using Void
//void add(int x, int y )
//{
//    cout<<"The sum of these two numbers are:"<<x+y<<"\n";
//}
//void add(double x,double y,double z )
//{
  //  cout<<"The sum of the 3 numbers is"<<fixed<<setprecision(2)<<x+y+z<<endl;
//}
//void myname(string name)
//{
  //  cout<<"My name is:"<<name;

//}

void swapNumbers(int &x, int &y)
{
    cout<<"entering the swapnumbers function"<<endl;
    int temp;
    temp=x;
    x=y;
    y=temp;
    cout<<"exiting the swapnumbers function"<< endl;

}

int main()
{
//int num1,num2;

//cout<<"Enter num1:";
//cin>>num1;

//cout<<"Enter num2:";
//cin>>num2;

//add(num1,num2);
//add(7.5,6.2,9.4);


//myname("SlimShady");

    int x,y;
    y=10;
    x=20;

    cout<<"x:"<<x<<endl;
    cout<<"y:"<<y<<endl;

    swapNumbers(x,y);
    cout<<"x:"<<x<<endl;
    cout<<"y:"<<y<<endl;

    cin.get();
    cin.ignore();


    system("pause>0");

    return 0;
}*/


/*#include <iostream>

using namespace std;

int x = 10;
void play()
{
    static int v = 0;
    cout<<v<<endl;
    v++;

}

int main()
{
    for(int i =0; i<=5; i++)
    {
        play();
    }
    x=20;
    cout<<x<<endl;
    //cout<<v<<endl;
    cin.get();
    cin.ignore();
 //When your output window dissappears to quickly

    system("pause>0");

    return 0;
}*/

//Topic 5 Part 2

/*#include <iostream>

using namespace std;
//Pass an array referencing to a function
int calcAverage(int marks[], int length)
{
    int sum=0;
    int average=0;
    for(int i=0;i<length;i++)
        {
            sum=sum+marks[i];
        }
    average= sum/length;
    return average;
}


int main()
{
    //original way of approaching this question without using arrays
    //string student1,student2,student3;
    //student1="Khanna";
    //student2="Veki";
    //student3="Me";




    //cout<<student1<<endl;
    //cout<<student2<<endl;
    //cout<<student3<<endl;

    //Declare an array to store names of students

    //string student[]={"Khanna","Veki","Me"};

    //student[2]="Khaka";

    //cout<<student[0]<<endl;
    //cout<<student[1]<<endl;
    //cout<<student[2]<<endl;

    //for (int i=0; i<3 ;i++){
        //cout<<student[i]<<endl;
    //}

    //string student[5];
    //int mark[5];
    string student[3];
    int mark[3];

    //for(int i=0; i<5;i++){
        //cout<<"Enter name of student:";
        //cin>>student[i];
        //cout<<"Enter student mark:";
        //cin>>mark[i];

    //}

    for(int i=0; i<3;i++){
        cout<<"Enter name of student:";
        cin>>student[i];
        cout<<"Enter student mark:";
        cin>>mark[i];

    }

    cout<<"The average of the students marks is:"<<calcAverage(mark,3);

    //cout<<"My students are:";
   // for(int i=0; i<5;i++){
        //cout<<student[i]<<endl;
        //cout<<mark[i]<<endl;
    //}


    cin.get();
    cin.ignore();
 //When your output window dissappears to quickly

    system("pause>0");

    return 0;
}*/


/*#include <iostream>

using namespace std;
//Multidimesional arrays
int din[2][3]={{78,89,69},
                     {56,89,78}};
int main()
{
    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
            cout<<din[r][c]<< " ";
        }
        cout<<endl;
    }


    cin.get();
    cin.ignore();
 //When your output window dissappears to quickly

    system("pause>0");

    return 0;
}*/

/*#include <iostream>

using namespace std;

int main()
{//Pointers
    //int x =45;
    //int *p;
    //p=&x;
    //cout<<x<<endl;
    //cout<<&x<<endl;
    //cout<<"Now using pointer"<<endl;
    //cout<<p<<endl;
    //cout<<*p<<endl;// This is called dereferencing

    //int *p;
    //int *n;

    //p= new int;
    //n = new int;
    //int sum;
    //*p=20;
    //*n =60;
    //sum=*p+*n;

    //cout<<"The sum of"<<*p<< " and "<<*n<< " is "<<sum<<endl;

    //delete p;
    //delete n;

    int size;
    int mark[size];

    cin.get();
    cin.ignore();
 //When your output window dissappears to quickly

    system("pause>0");

    return 0;
}*/

/*#include <iostream>

using namespace std;

int main()
{//Dynamic arrays

    int size;
    int* marks;
    cout<<"Enter size of an array:"<<endl;
    cin>>size;
    marks = new int[size];
    for(int i=0;i<size;i++)
        {
            cout<<"Enter mark:";
            cin>>marks[i];
        }

        cout<<"These are our marks:";
        for(int i=0;i<size;i++)
            {
                //cout<<marks[i]<<" ";
                cout<<*(marks+i)<<" ";
            }
        delete[] marks;


    cin.get();
    cin.ignore();
 //When your output window dissappears to quickly

    system("pause>0");

    return 0;
}*/

/*#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{//String Manipulation
    //strlen
    //strcat
    //strcmp
    //string name = "Jerry";
    char name1[] = "Jerry";
    char name2[]="Sharon";
    //cout<<strlen(name1);
    //cout<<strcmp(name2,name1);
    cout<<strcat(name1,name2);
    cout<<name1;
    cin.get();
    cin.ignore();
 //When your output window dissappears to quickly

    system("pause>0");

    return 0;
}*/

//Topic 6 classes

/*#include <iostream>

using namespace std;

class Box
{//class members
public://attributes
    double length;
    double width;
    double height;
    Box()
    {
        cout<<"This is an automatic constructor";
    }
    Box(double length, double width,double height)
    {
        this-> length=length;
        this-> width=width;
        this-> height=height;

    }


    //methods
    double calculateArea()
    {
        return width*height;
    }

    double calculateVolume()
    {
        return width*height*length;
    }

    ~Box()
    {
        cout<<"This is a destructor";
    }

};

int main()
{
    Box box1;
    Box box2;
    Box box3(5.3,6.8,7.9);
    box1.length=20;
    box1.width=15;
    box1.height=10;

    box2.length=40;
    box2.width=30;
    box2.height=100;

    cout<<"Length of box is:"<<box1.length<<endl;
    cout<<"Height of box is:"<<box1.height<<endl;
    cout<<"Width of box is:"<<box1.width<<endl;
    cout<<"Area of box1 is:"<<box1.calculateArea()<<endl;

    cout<<"Length of box is:"<<box2.length<<endl;
    cout<<"Height of box is:"<<box2.height<<endl;
    cout<<"Width of box is:"<<box2.width<<endl;
    cout<<"Area of box2 is:"<<box2.calculateArea()<<endl;

    cout<<"Length of box is:"<<box3.length<<endl;
    cout<<"Height of box is:"<<box3.height<<endl;
    cout<<"Width of box is:"<<box3.width<<endl;
    cout<<"Area of box2 is:"<<box3.calculateArea()<<endl;
    cin.get();
    cin.ignore();
 //When your output window dissappears to quickly

    system("pause>0");

    return 0;
}*/


/*#include <iostream>

using namespace std;

//Inheritance demonstration
class Animal
{
public:
    void sleep()
    {cout<<"I am able to sleep"<<endl;

    }
    void eat()
    {
        cout<<"I am able to eat"<<endl;
    }
    void run()
    {
        cout<<"I can run"<<endl;
    }
};
class Dog : public Animal //can be private Animal by saying private Animal
{
public:
    void sound()
    {
        cout<<"I can Bark"<<endl;
    }
};
int main()
{
    Animal an;
    an.eat();
    cout<<"==========="<<endl;
    cout<< "As a dog"<<"  ";
    Dog myDog;
    myDog.eat();
    myDog.sleep();
    myDog.sound();

    cin.get();
    cin.ignore();
 //When your output window dissappears to quickly

    system("pause>0");

    return 0;
}*/

/*#include <iostream>

using namespace std;
//template<class T>
//class Line
//{ //private:
    //int x;
    //T x;
  //public:
      //void setx(int a)
      //void setx(T a)
      //{
        //  x=a;
      //}
      //T getx()
      //{
        //  return x;
      //}
      //T sum(T a, T b)
      //{
    //      return a+b;
  //    }
//};
//T add(T a, T b)
//{
  //  return a+b;
//}
//int add(int a, int b)
    //{
     //   return a+b;
   //}
//double add(double a, double b)
    //{
        //return a+b;
   // }
//float add(float a, float b,float c)
    //{
        //return a+b+c;
    //}
    //class Animal
    //{
   // public:
       // void sleep()
       // {
        //    cout<<"I am able to sleep"<<endl;
       // }
       // void eat()
       //virtual void()
       // {
        //    cout<<"I am able to eat" <<endl;
      //  }
    //};
   // class Lion: public Animal
    //{
    //public:
        //void eat()
        //{
        //    cout<<"I only eat meat"<<endl;
      //  }
    //};
class Count
{
private:
    int value;
public:
    Count(int v)
    {
        value=v;
    }
    void operator ++()
    {
        value = value +3;
        cout << value << endl;
    }
};




int main()
{ //string name="John";
//string last="Wick";
    //cout<< add(2,5)<<endl;
    //cout<< add(8.9,6.7)<<endl;
    //cout<< add(7.8,6.6,9.1)<<endl;
    //cout<<add(name,last)<<endl;
    //Line l;
    //Line<int>l;
    //l.x=32;
    //l.setx(56.9);
    //cout<<"I'm getting x = " <<l.getx()<<endl;
    //cout<<l.sum(7,9)<<endl;

    //Line<double>l1;
    //l1.setx(56.9);
    //cout<<"I'm getting x = " <<l1.getx()<<endl;
    //cout<<l1.sum(7.5,9.8)<<endl;

    //Animal a;
    //a.eat();
    //a.sleep();
    //Lion l;
    //l.eat();
    //l.sleep();

    //Lion l;
    //Animal*a = &l;
    Count c(5);
    ++c;
    c.operator++();
    int x =12;
    ++x;
    cout<< x << endl;




    cin.get();
    cin.ignore();
 //When your output window dissappears to quickly

    system("pause>0");

    return 0;
}*/

/*#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream file;
    file.open("example.txt");


   system("pause>0");
    return 0;
}*/

/*#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file;
    file.open("example.txt",ios::out / ios::in);


   system("pause>0");
    return 0;
}*/


/*#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string text;
    fstream file;

    file.open("example.txt", ios::out | ios::in | ios::trunc);
    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    cout << "Write text to be written on file:" << endl;
    getline(cin, text);

    // Writing to file
    file << text << endl;

    // Moving the file pointer to the beginning of the file
    file.seekg(0, ios::beg);

    // Reading from file
    getline(file, text);
    cout << "Read from file: " << text << endl;

    // Closing the file
    file.close();

    return 0;
}*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
char text[200];

fstream file;
file.open("example.txt",ios::out);

cout<<"Write text to be written in file:";


file<< text <<endl;


file.open("example.txt",ios::app);e

cout<<"Write more text to be written in file:"<<endl;


file<< text <<endl;

file.open("example.txt",ios::out);
cin.getline(text,sizeof(text));

file>>text;
cout<<text<<endl;

file.close();
    return 0;
}









