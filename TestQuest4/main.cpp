/*//4.1.
#include <iostream>

using namespace std;
void daysOfTheWeek(){
    //Array of the days of the week
string days[7]= {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

// Variable to store user input
int input;

//Prompt the user to enter a positive integer
cout<<"Enter a positive integer (1-7): ";
cin>>input;

//Check if the input is within the valid range
if (input>=1 && input<=7){
    //  Output the corresponding day
    cout<<"The day of the week is:"<<days[input-1]<<endl;
}
else{
// Output an error message for invalid input
cout<<"Invalid input ! Please enter a numver between 1 and 7."<<endl;
}
}



int main()
{
    daysOfTheWeek();
    return 0;
}*/

//4.2.
#include <iostream>
#include <string>

using namespace std;

int main() {
    int num_students;

    // Step 3: Prompt user for number of students
    cout << "Enter the number of students enrolled in the class: ";
    cin >> num_students;

    // Step 4: Dynamically allocate an array of strings
    string* students = new string[num_students];

    // Step 5: Prompt user for student names
    for(int i = 0; i < num_students; ++i) {
        cout << "Enter the name of student " << (i + 1) << ": ";
        cin >> students[i];
    }

    // Step 6: Display all the students' names
    cout << "The students enrolled in the class are:\n";
    for(int i = 0; i < num_students; ++i) {
        cout << students[i] << endl;
    }

    // Step 7: Free the allocated memory
    delete[] students;

    return 0;
}


