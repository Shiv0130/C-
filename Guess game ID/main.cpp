/*#include <iostream>

using namespace std;

int main()
{
    int IDnum;
    int attempts;
    int count;
    int num;

    IDnum=0;
    attempts=0;
    count=0;

    cout<<"Enter a number between 1-20:";
        cin>>num;

    while(count<20){
        cout<<"Enter a number between 1-20:";
        cin>>num;

        if (num==IDnum){
            cout<<"Correct guess";
        }else{ cout<<"Wrong answer";
        break;

        }

        if(attempts>3){
                cout<<"Too many attempts logging off";
                attempts++;

            break;
        }


    }
    return 0;
}*/

#include <iostream>

using namespace std;

int main() {
    // Declare variables
    int IDnum;      // The correct answer (first digit of SA ID)
    int attempts;   // Variable to count the number of attempts
    int count;      // Counter variable (unused)
    int num;        // User's guess

    // Initialize variables
    IDnum = 0;      // Set your SA ID's first digit as the correct answer
    attempts = 0;   // Initialize the number of attempts
    count = 0;      // Unused variable

    // Prompt the user for their guess
    cout << "Enter a number between 1-20: ";
    cin >> num;

    // Start the loop (unused count variable, should probably be removed)
    while (count < 20) {
        // Prompt the user for their guess
        cout << "Enter a number between 1-20: ";
        cin >> num;

        // Check if the guess is correct
        if (num == IDnum) {
            cout << "Correct guess"; // Inform the user of the correct guess
            break; // Exit the loop since the guess is correct
        } else {
            cout << "Wrong answer"; // Inform the user of the wrong guess

            // Increment the attempts counter
            attempts++;

            // Check if the user has exceeded the maximum number of attempts
            if (attempts > 3) {
                cout << "Too many attempts logging off"; // Inform the user of too many attempts
                break; // Exit the loop
            }
        }
    }
    return 0;
}

