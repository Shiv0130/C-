#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Product {
private:
    string id;
    string name;
    float cost,price,VAT;

public:
    //Default constructor
    Product() {}

    //Parameterized constructor
    Product(string id, string name, float cost, float price, float VAT){
    this->id=id;
    this->name=name;
    this->cost=cost;
    this->price=price;
    this->VAT=VAT;

    }

    //Accessor and mutator for product name
    string getname() const {
        return name;

    }
    void setName(string newName){
        name=newName;
    }

    //Accessor and mutator for ID
    string getID() const{
        return id;
    }

    void setID(string newID ){
        id=newID;

    }

    //Accessor and mutator for product cost

    double getCost() const{
    return cost;
    }

    void setCost(double newCost){
    cost=newCost;
    }

    void setPrice(float newPrice){
        price=newPrice;
    }

 //Accessor and mutator for product VAT

    double getVAT() const{
    return VAT;
    }

    void setVAT(double newVAT){
    VAT=newVAT;
    }

    //Calculate the VAT amount

    double calcVatAmt() const {
    return VAT*cost;

    }

    //Calculate profit
    double calcProfit() const {
    return price - (cost-calcVatAmt());
    }

    //Calculate markup
    double calcMarkUp() const {
    return (calcProfit() / cost) * 100;
    }

    //Display product details
    void displayDetails() const{
    cout<<"Product ID:"<<id<<endl;
    cout<<"Product Name:"<<name<<endl;
    cout<<"Product Cost:R"<<fixed<< setprecision(2)<<cost<<endl;
    cout<<"Product Price:"<<fixed<< setprecision(2)<<price<<endl;
    cout<<"Product VAT:"<<fixed<< setprecision(2)<<VAT<<endl;
    cout<<"VAT Amount: R:"<<fixed<< setprecision(2)<<calcVatAmt()<<endl;
    cout<<"Product Profit: R"<<fixed<< setprecision(2)<<calcProfit()<<endl;
    cout<<"Markup:"<<fixed<< setprecision(2)<<calcMarkUp()<<"%"<<endl;
    }





};

int main()
{
    //Example usage of Product class
    Product product1("P001","T-Shirt",50.0,100.0,0.15);
    product1.displayDetails();

    cout << endl;

    //Modify product details
    product1.setName("Jeans");
    product1.setCost(80.0);
    product1.setPrice(150.0);
    product1.setVAT(0.2);
    product1.displayDetails();


    return 0;
}



