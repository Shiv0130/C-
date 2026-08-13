#include <iostream>

using namespace std;

int main()
{
    float Cost;
    float minSellPrice;
    float maxSellPrice;
    float fixedCom;
    float percCom;
    float purchasingCost;
    float minAmount;
    float maxAmount;
    float minCom;
    float maxCom;

    cout << "Enter the fixed commission:";
    cin>> fixedCom;
    cout << "Enter the percentage of commisson:";
    cin>>percCom;
    cout<< "Enter purchasing Cost of car:";
    cin>>purchasingCost;
    cout<< "Enter minimum Amount:";
    cin>>minAmount;
    cout<<"Enter max amount:";
    cin>>maxAmount;

    minSellPrice=Cost+200+minAmount;
    maxSellPrice=Cost+2000+maxAmount;
    minCom=(percCom/100+20+0.3)*(minSellPrice-Cost);
    maxCom=(percCom/100+20+0.3)*(maxSellPrice-Cost);
    cout<<"The minimum selling price:"<<minSellPrice<<endl;
    cout<<"The maximum selling price:"<<maxSellPrice<<endl;
    cout<<"The commission range is:"<<minCom<<maxCom<<endl;


    return 0;
}
