#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    //Declare neccessary variables to store input and calculations//
int AccNum,minServUsed,minServUsedDay,minServUsedNight;
char service_code;
double dAmountDue=0.0;

//Regular service rate constants//
const float rBasedCost=100.0;
const double rRate=0.20;


//Premium service rate constants//
const float pBaseCost=250.0;
const float pDayRate=1.0;
 const float pNightRate=0.5;

//Prompt User input//
cout<<"Enter account number:";
cin>>AccNum;
cout<<"Service code R/r or p/P:";
cin>>service_code;


switch(service_code){
    //Checks if character is in upper or lower character to execute the same code
case 'r':
case 'R':
    cout<<"Enter the number of minutes the service was used";
    cin>>minServUsed;
    //Calculate Bill for regular service
    if(minServUsed>50){
        dAmountDue=rBasedCost +(minServUsed-50)*rRate;
    } else {
        dAmountDue=rBasedCost;
    }
    //break the case to terminate when conditions are met
    break;

    //Checks if character is in upper or lower character to execute the same code
case 'p':
case 'P':
    cout<<"Please enter the number of minutes used during the day:";
    cin>>minServUsedDay;
    cout<<"Please enter the number of minutes used during the night ";
    cin>>minServUsedNight;

    //Calculate Bill for Premium service
    if(minServUsedDay>75){
        dAmountDue=(minServUsedDay-75)*pDayRate;

    }
    if(minServUsedNight>100){
        dAmountDue=(minServUsedNight-100) *pNightRate;
    }
    dAmountDue=dAmountDue+pBaseCost;
    break;
default:
    cout<<"You have entered an invalid code"<<endl;
    return 1;
    //break the case to terminate when conditions are met
    break;

}
//Output the bill
cout<<"Your bill is:R"<<dAmountDue<<endl;



    return 0;
}
