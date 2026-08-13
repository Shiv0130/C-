/*#include <iostream>

using namespace std;

int main()
{
    //Declaring variable to set up my favourite number;
    int favNum;
    //Declaring variable to set up a counter for the while loop;
    int count;

    //Prompt the user to enter a number;

    cout<<"Enter number:";
    cin>>favNum;
    //intialise counter to 0;
    count=0;
    //Counter used in loop below 10

    while (count<10){
            //Check the condition if it isn't equal to 7.Then re prompt the user to try again.
            if (favNum!=7) {
                cout<<"Try again,Enter number:";
                cin>>favNum;
                //increment counter

                count++;


                else{
                    cout<<"Burrifil,Number is correct";
                    break;
                }
            }
    }
    return 0;
}*/

#include <iostream>

using namespace std;

int main()
{
    // Declare your favorite number
    int setNumber = 7;

    // Declare variable to store user's guess
    int guess;

    // Declare variable to count the number of attempts
    int count = 0;

    // Start the loop
    while (count < 10) {
        // Prompt the user to guess a number
        cout << "Guess a number between 1 and 10: ";
        cin >> guess;

        // Check if the guess is correct
        if (guess == setNumber) {
            cout << "Access granted!" << endl;
            break; // Exit the loop if the guess is correct
        } else {
            cout << "Try again." << endl;
            count++; // Increment the count of attempts
        }
    }

    // If the loop exits without breaking, it means the user has used all attempts
    if (count >= 10) {
        cout << "You have used all your attempts. Access denied!" << endl;
    }

    return 0;
}
