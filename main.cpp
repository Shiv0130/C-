#include <iostream>
#include<iomanip>
#include <math.h>

/*using namespace std;

int main()
{
    float listPrice;
    float DealerCost;
    float Offer:

        cout<<"Enter the list price:";
        cin>>listPrice;

        DealerCost=listPrice*0.85;
        Offer=DealerCost+500;
        cout<<"The cost of the car"<<DealerCost<<endl;
        cout<<"The least offer accepted is:"<<Offer<<endl;

    return 0;
}*/

/*correction:*/using namespace std;

int main()
{
    float listPrice;
    float cost;
    float output;

    cout << "Enter the list price: ";
    cin >> listPrice;

    cost = listPrice * 0.85;
    output = cost + 500;

    cout << "The dealer's cost of the car: $" << cost << endl;

    if (output < 500) {
        cout << "Offer denied" << endl;
    } else {
        cout << "The least offer accepted is: $" << output << endl;
    }

    return 0;
}
/*int main()
{
    float volSphere;
    float r;
    float surfArea;

        cout<<"Enter the radius:";
        cin>>r;
        volSphere=(4.0/3.0)(3.141592)*r^2;
        surfArea =(4.0)*(3.141592)(r)^2;
        cout<<"The volume is:"<<volSphere<<endl;
        cout<<"The surface area is:"<<surfArea<<endl;*/

/*using namespace std;

int main()
{
    float volSphere;
    float r;
    float surfArea;

    cout << "Enter the radius: ";
    cin >> r;

    // Calculate volume and surface area using correct formulas
    volSphere = (4.0 / 3.0) * 3.141592 * pow(r, 3); // Formula for volume
    surfArea = 4.0 * 3.141592 * pow(r, 2); // Formula for surface area

    cout << "The volume is: " << volSphere << endl;
    cout << "The surface area is: " << surfArea << endl;

    return 0;
}*/



