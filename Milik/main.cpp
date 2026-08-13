/*#include <iostream>

using namespace std;
int producedMilk;
float numofcartons;
int milkCart;
float produceLiter;
float costCartonmilk;
float profit;
float costOfProduction;
int main()
{
    cout << "Enter the number of milk produces in the morning:";
    cin>> producedMilk;
    milkCart=3.78;
    produceLiter=0.38;
    costCartonmilk=0.27;



    numofcartons=producedMilk/milkCart;
    costCartonmilk=0.38*producedMilk;
    profit=producedMilk*costCartonmilk;

    cout<<"Cost of producing milk is:"<<costCartonmilk<<endl;
    cout<<"Profits for producing milk:"<<profit<<endl;

    return 0;
}*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float producedMilk;
    float milkCarton = 3.78; // liters
    float produceLiter = 0.38; // cost per liter
    float costCartonmilk = 0.27; // profit per carton
    float numofcartons;
    float costOfProduction;
    float profit;

    cout << "Enter the total amount of milk produced in the morning (in liters): ";
    cin >> producedMilk;

    numofcartons = ceil(producedMilk / milkCarton);
    costOfProduction = producedMilk * produceLiter;
    profit = numofcartons * costCartonmilk;

    cout << "Number of milk cartons needed: " << numofcartons << endl;
    cout << "Cost of producing milk: $" << costOfProduction << endl;
    cout << "Profit for producing milk: $" << profit << endl;

    return 0;
}

