/*#include <iostream>

using namespace std;

int main()
{
    char choice;

    do{
        cout<<"----Capper Restaurant Menu----"<<endl;
        cout<<"A) Pizza B) Coke C) Fries Q) Quit" <<endl;
        cout<<"Please select food item"<<endl;
        cin>>choice;

        if(choice== "a" || choice=="A"){
            cout<<"The pice of pizza is R100" endl;
        }
        else if(choice=="b" || choice=="B"){
            cout<<"The pice of coke is R30" endl;
        }
        if(choice=="c" || choice=="C"){
            cout<<"The pice of fries is R10" endl;
        }

    }

    while(choice!="q" && "Q");
    cout << "Exit" << endl;
    system("PAUSE");
    return 0;
}*/

/*#include <iostream>
using namespace std;

int main() {
    char choice;

    do {
        cout << "----Capper Restaurant Menu----" << endl;
        cout << "A) Pizza B) Coke C) Fries Q) Quit" << endl;
        cout << "Please select a food item" << endl;
        cin >> choice;

        if (choice == 'a' || choice == 'A') {
            cout << "The price of pizza is R100" << endl;
        } else if (choice == 'b' || choice == 'B') {
            cout << "The price of coke is R30" << endl;
        } else if (choice == 'c' || choice == 'C') {
            cout << "The price of fries is R10" << endl;
        } else if (choice == 'q' || choice == 'Q') {
            cout << "Exiting..." << endl;
        } else {
            cout << "Invalid choice. Please select again." << endl;
        }

    } while (choice != 'q' && choice != 'Q');

    system("PAUSE");
    return 0;
}*/


#include <iostream>
using namespace std;

int main() {
    char choice


    do {
        cout << "----Capper Restaurant Menu----" << endl;
        cout << "A) Pizza B) Coke C) Fries Q) Quit" << endl;
        cout << "Please select a food item" << endl;
        cin >> choice;

        switch (choice) {
            case 'a':
            case 'A':
                cout << "The price of pizza is R100" << endl;
                break;
            case 'b':
            case 'B':
                cout << "The price of coke is R30" << endl;
                break;
            case 'c':
            case 'C':
                cout << "The price of fries is R10" << endl;
                break;
            case 'q':
            case 'Q':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please select again." << endl;
        }

    } while (choice != 'q' && choice != 'Q');

    system("PAUSE");
    return 0;
}


