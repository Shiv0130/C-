/*#include <iostream>

using namespace std;
class Human{
public:
    string name = "Tony";
    string occupation = "Tech entrepreneur";
    int age = 30;


    void eat(){
    cout<<"This person is eating";
    }

    void drink(){
    cout<<"This person is drinking";
    }

    void sleep(){
    cout<<"This person is sleeping";
    }


};
int main()
{
    Human human1;
    Human human2;
    //human1.name="Tony";
    //human1.occupation="Tech entrepreneur";
    //human1.age= 30;

    //cout<<"name:"<<human1.name<<endl;
    //cout<<"occupation:"<< human1.occupation<<endl;
    //cout<< human1.age<<endl;

    //human1.eat();
    //human1.drink();
    //human1.sleep();

    //human2.name="Banner";
    //human2.occupation="Biology expert";
    //human2.age=28;

    cout<<"name:"<<human1.name<<endl;
    cout<<"occupation:"<< human1.occupation<<endl;
    cout<<"age:"<< human1.age<<endl;


    cout<<"name:"<<human2.name<<endl;
    cout<<"occupation:"<< human2.occupation<<endl;
    cout<< "age:"<< human2.age<<endl;

    human2.eat();
    human2.drink();
    human2.sleep();





    //cout << "Hello world!" << endl;


    return 0;
}*/

/*#include <iostream>

using namespace std;
class Car{
public:
    string make;
    string model;
    int year;
    string colour;

    void accelerate(){
    cout<< "The car is moving"<<endl;
    }

    void brake(){
    cout<<"The car is stationary"<<endl;
    }
};

int main()
{

Car car1;
car1.make="Mercedes";
car1.model="C63";
car1.year= 2000;
car1.colour="silver";




    cout << car1.make << endl;
    cout << car1.model << endl;
    cout << car1.year << endl;
    cout << car1.colour << endl;

    car1.accelerate();
    car1.brake();



    return 0;
}*/

/*#include <iostream>

using namespace std;
class Stove{
public:
    int temperature = 0;

};
int main()
{
    Stove stove;

    stove.temperature = 1000000;

    cout<< "The temperature setting is:"<< stove.temperature;





    return 0;
}*/

/*#include <iostream>

using namespace std;

class Stove{

private:
    int temperature = 0;

public:

    getTemperature(){
    return temperature;
    }

    void setTemperature(int temperature){
    if(temperature < 0){
        this-> temperature =0;
    }
    else if(temperature>=6){
        this-> temperature=6;
    }
    else{
        this-> temperature = temperature;
    }

    }

};
int main()
{
    Stove stove;

    //stove.setTemperature(-3);
    //stove.setTemperature(10000);
    stove.setTemperature(5);


    cout<< "The temperature setting is:"<< stove.getTemperature();





    return 0;
}*/

/*#include <iostream>

using namespace std;
class Animal{
public:
    bool alive= true;
    void eat(){
    cout<< "This animal is eating\n";
    }

};

    class Dog : public Animal{
    public:
        void bark(){
        cout<<"The dog is making woof woof"<<endl;
        }

    };

    class Cat : public Animal{
public:
    void meow(){
    cout<<"The cat making meow meow"<<endl;}
    };
int main()
{
    Dog dog;
    cout<<dog.alive<<endl;
    dog.eat();
    dog.bark();

    Cat puss;
    cout<<puss.alive<<endl;
    puss.eat();
    puss.meow();








    return 0;
}*/
#include <iostream>

using namespace std;
class Shape{
public:
    double area;
    double volume;
    };
    class Cube : public Shape{

public:
    double side;
    Cube(double side){
        this-> side = side;
        this-> area = side* side* 6;
        this-> volume = side *side *side;

    }
    };

    class Sphere : public Shape{
public:
    double radius;
    Sphere(double radius){
        this-> radius = radius;
        this area = 4 * 3.14159 * (radius* radius);
        this-> volume =(4/3.0)*3.14159 *(radius *radius *radius);

    }
    };
int main()
{
    Cube cube(10);
    Sphere sphere(5);


    //cout<<"Area:"<<cube.area<<"cm"<<endl;
    //cout<<"Volume:"<<cube.volume<<"cm"<<endl;

    cout<<"Area:"<<sphere.area<<"cm"<<endl;
    cout<<"Volume:"<<sphere.volume<<"cm"<<endl;



    return 0;
}


