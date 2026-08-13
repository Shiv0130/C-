#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    float listPrice;
    float DealerCost;
    float Offer;

    cout<<"Enter the list price:";
    cin>>listPrice;

    DealerCost=listPrice*0.85;
    Offer=DealerCost+500;
    cout<<"The cost of the car"<<DealerCost<<endl;
    cout<<"The least offer accepted is:"<<Offer<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
