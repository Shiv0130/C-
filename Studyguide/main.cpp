/*My attempt:
#include <iostream>

using namespace std;

int main()
{
    float price,dealerCost,acceptOffer=0;
    cout<<"Enter price:";
    cin>> price ;
    dealerCost=0.85*price;
    if(dealerCost<500){
            acceptOffer=dealerCost;
        cout<<"The dealer would accept"<<acceptOffer;
    }


    return 0;
}*/

/*Correction
#include <iostream>

using namespace std;

int main()
{
    // Declare variables to store price, dealer's cost, and the minimum offer accepted by the dealer.
    float price, dealerCost, acceptOffer = 0;

    // Prompt the user to input the list price of the car.
    cout << "Enter price: ";
    cin >> price;

    // Calculate the dealer's cost, which is 85% of the listed price.
    dealerCost = 0.85 * price;

    // Check if the dealer's cost is less than $500.
    if (dealerCost < 500) {
        // If the dealer's cost is less than $500, accept any offer that is at least $500 over the dealer's cost.
        acceptOffer = dealerCost + 500;
        // Output the least amount that the dealer would accept for the car.
        cout << "The dealer would accept: $" << acceptOffer << endl;
    } else {
        // If the dealer's cost is $500 or more, simply output the dealer's cost.
        cout << "The dealer would accept: $" << dealerCost << endl;
    }

    return 0;
}*/

/*#include <iostream>
#include <cmath>

using namespace std;

int main()
{
//volume sphere =(4.0/3.0)pir^3
//surface area=4.0pir^2
int r;
const float pi=3.141592;
float volumeSphere,surfaceArea;
cout<<"Enter radius:";
cin>>r;

volumeSphere=4.0/3.0*pi*r**3;
surfaceArea=(4.0)(pi)(r**2);

cout<<"The volume is:"<<volumeSphere<<endl;
cout<<"The surface Area is:"<<surfaceArea<<endl;
}
return 0;
*/

/*#include <iostream> // Includes the necessary input/output stream library
#include <cmath>    // Includes the necessary mathematical functions library
using namespace std; // Allows the use of standard namespace without having to prefix it

int main() {
    // Declare the necessary variables
    int r;          // Stores the radius of the sphere
    const float pi = 3.141592; // Defines the value of pi as a constant
    float volumeSphere, surfaceArea; // Stores the calculated volume and surface area of the sphere

    // Prompt the user to enter the radius of the sphere
    cout << "Enter radius: ";
    cin >> r; // Read the user input and store it in the 'r' variable

    // Calculate the volume of the sphere using the formula (4.0 / 3.0) * pi * r^3
    volumeSphere = (4.0 / 3.0) * pi * pow(r, 3);

    // Calculate the surface area of the sphere using the formula 4.0 * pi * r^2
    surfaceArea = 4.0 * pi * pow(r, 2);

    // Output the calculated volume and surface area of the sphere
    cout << "The volume is: " << volumeSphere << endl;
    cout << "The surface Area is: " << surfaceArea << endl;

    return 0; // Indicate successful program execution
}*/

//Topic 3.

//3.1.my answer:

/*#include <iostream>

using namespace std;

int main() {
    int first,second,next,i,num;
    cout<< "Enter first number";
    cin>>first;
    cout<<"Enter second number:";
    cin>>second;

    cout<<"Enter number for fibonnacci sequence:";
    cin>>num;

    cout<<"Fibonnacci sequence:"<<endl;

    for(i=0;i<num; i++){
            if(first<=second && first<0 &&second<0 && num<0){


            }
            cout<<first<<endl;
            next=first+second;
            first=second;
            second=next;


    }



    return 0;
}*/

//Correction for code:
/*#include <iostream>

using namespace std;

int main() {
    // Declare variables for storing Fibonacci numbers
    int first, second, next, num;

    // Prompt the user to enter the number of terms
    cout << "Enter the number of terms in the Fibonacci sequence: ";
    cin >> num;

    // Check if num is non-negative
    if (num <= 0) {
        cout << "Error: Number of terms should be positive." << endl;
        return 1; // Exit with error
    }

    // Initialize first and second numbers
    cout << "Enter the first number: ";
    cin >> first;
    cout << "Enter the second number: ";
    cin >> second;

    // Check if second is greater than first
    if (second <= first) {
        cout << "Error: Second number should be greater than the first number." << endl;
        return 1; // Exit with error
    }

    // Generate and display Fibonacci sequence
    cout << "Fibonacci sequence:" << endl;
    for (int i = 0; i < num; ++i) {
        cout << first << " "; // Display the current Fibonacci number
        next = first + second; // Calculate the next Fibonacci number
        first = second; // Update first to the value of second
        second = next; // Update second to the value of next
    }

    return 0; // Exit without error
}*/

//3.2.
//My attempt
/*#include <iostream>
#include <cmath>
using namespace std;

int main() {
int radius;
float volume,pi=3.14;

cout<<"Enter the radius";
cin>>radius;
volume= 0.33*pi*pow(radius,2);
if(volume>0){
    cout<<"The volume is:"<<volume<<setprecision(2);
}



    return 0;
}*/


//correction
/*#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    float radius, volume, maxVolume = 0, optimalAngle;
    const float pi = 3.14159;

    cout << "Enter the radius: ";
    cin >> radius;

    // Loop through all possible sector angles
    for (float angle = 0.01; angle <= 2 * pi; angle += 0.01) {
        // Calculate the height of the cone
        float h = radius - radius * cos(angle / 2);

        // Calculate the volume of the cone
        volume = (1.0 / 3) * pi * pow(radius, 2) * h;

        // Update maximum volume and optimal angle
        if (volume > maxVolume) {
            maxVolume = volume;
            optimalAngle = angle;
        }
    }

    cout << "The optimal sector angle for maximum volume is: " << setprecision(2) << fixed << optimalAngle << " radians" << endl;
    cout << "The maximum volume is: " << setprecision(2) << fixed << maxVolume << " cubic inches" << endl;

    return 0;
}*/

/*#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    /* Attempt correct code with pseudocode correction This code is absolute rubbish:float totalNumUnit,rentForUnits,incRent,maintainAmt,unitToBeRented;
    cout<<"Enter the total number of units:";
    cin>>totalNumUnit;
    cout<<"Enter the rent for the units:";
    cin>>rentForUnits;
     cout<<"Enter the increased rent:";
    cin>>incRent;
    cout<<"Enter maintainance amount";
    cin>>maintainAmt;
    unitToBeRented=totalNumUnit*rentForUnits;
    cout<<"The total unit is:"<<unitToBeRented;*/

    /*float totalNumUnits,rentForUnits,incRent,maintainAmt;
    cout<<"Enter the total number of units:";
    cin>>totalNumUnits;
    cout<<"Enter the rent for the units:";
    cin>>rentForUnits;
    cout<<"Enter the increased rent:";
    cin>>incRent;
    cout<<"Enter maintainance amount";
    cin>>maintainAmt;

    int maxProfit=0;
    int optimalUnits =0;

    for(int i=0;i<totalNumUnits;i++){
        float income=(totalNumUnits-i)*(rentForUnits+(i*incRent));
        float expenses = (totalNumUnits-i) *maintainAmt;
        float profit=income-expenses;

        if (profit>maxProfit){
            maxProfit=profit;
            optimalUnits=totalNumUnits-i;
        }

    }
    cout<<"The optimal units are:"<<optimalUnits;*/



    //return 0;
//}

/*#include <iostream>

using namespace std;

int main() {
    // Input variables
    int totalNumUnits;      // Total number of apartment units
    double rentForUnits;    // Initial rent for each unit per month
    double incRent;         // Increase in rent for each vacant unit
    double maintainAmt;     // Average monthly maintenance cost for each occupied unit

    // Input
    cout << "Enter total number of apartment units: ";
    cin >> totalNumUnits;
    cout << "Enter initial rent for each unit per month: ";
    cin >> rentForUnits;
    cout << "Enter increase in rent for each vacant unit: ";
    cin >> incRent;
    cout << "Enter average monthly maintenance cost for each occupied unit: ";
    cin >> maintainAmt;

    double maxProfit = 0;   // Maximum profit
    int optimalUnits = 0;   // Optimal number of units to be rented

    // Loop through all possible scenarios
    for (int i = 0; i <= totalNumUnits; i++) {
        // Calculate income for current scenario
        double income = (totalNumUnits - i) * (rentForUnits + (i * incRent));
        // Calculate expenses for current scenario
        double expenses = (totalNumUnits - i) * maintainAmt;
        // Calculate profit for current scenario
        double profit = income - expenses;

        // Update maximum profit and optimal units if current profit is greater
        if (profit > maxProfit) {
            maxProfit = profit;
            optimalUnits = totalNumUnits - i;
        }
    }

    // Output optimal number of units to be rented for maximum profit
    cout << "Number of units to be rented for maximum profit: " << optimalUnits << endl;

    return 0;
}*/

/*#include <iostream> // Include the input/output stream library for basic input/output operations

using namespace std; // Use the standard namespace for convenience

int main() { // The main function where execution begins
    int n; // Declare a variable to store the input number
    cout << "Enter a nonnegative integer: "; // Prompt the user to enter a nonnegative integer
    cin >> n; // Read the input from the user and store it in variable n

    int factorial = 1; // Initialize a variable to store the factorial, starting with 1

    if (n == 0) { // Check if the input number is 0
        cout << "Factorial of 0 is 1" << endl; // If yes, print that the factorial of 0 is 1
    } else { // If the input number is not 0
        for (int i = 1; i <= n; ++i) { // Iterate from 1 to the input number
            factorial *= i; // Update the factorial by multiplying it with the current value of i
        }
        cout << "Factorial of " << n << " is " << factorial << endl; // Print the factorial of the input number
    }

    return 0; // Indicate successful completion of the program
}*/

//Topic 4:
//My attempt:
/*#include <iostream> // Include the input/output stream library for basic input/output operations

using namespace std; // Use the standard namespace for convenience
//4.1.
bool isVowel(char letter)
{
    if (letter=='A'|| letter='a'){
        return true;
    }elseif(letter=='E'|| letter='e'){
    return true;
    }elseif(letter=='O'|| letter='o'){
    return true;
    }elseif(letter='U'|| letter='u'){
    return true;
    }else{
        return false;
    }
}
int main() { // The main function where execution begins
    char letter;

    cout<<"Enter a letter:";
    cin>>letter;

    cout<<isVowel();



    return 0; // Indicate successful completion of the program
}*/

//correction

/*#include <iostream>

using namespace std;

bool isVowel(char letter) {
  if (letter == 'A' || letter == 'a') {
    return true;
  } else if (letter == 'E' || letter == 'e') {
    return true;
  } else if (letter == 'I' || letter == 'i') {
    return true;
  } else if (letter == 'O' || letter == 'o') {
    return true;
  } else if (letter == 'U' || letter == 'u') {
    return true;
  } else {
    return false;
  }
}

int main() {
  char letter;
  cout << "Enter a letter: ";
  cin >> letter;

  if (isVowel(letter)) {
    cout << "Letter is a vowel" << endl;
  } else {
    cout << "Letter is not a vowel" << endl;
  }

  return 0;
}*/

//4.1.
/*#include <iostream>
#include <string>

bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    std::string testStrings[] = {"madam", "abba", "22", "67876", "444244", "trymeuemyrt"};

    for (const std::string& str : testStrings) {
        if (isPalindrome(str)) {
            std::cout << "\"" << str << "\" is a palindrome.\n";
        } else {
            std::cout << "\"" << str << "\" is not a palindrome.\n";
        }
    }

    return 0;
}*/

//4.2.

/*#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string testStrings[] = {"madam", "abba", "22", "67876", "444244", "trymeuemyrt"};

    for (const string& str : testStrings) {
        if (isPalindrome(str)) {
            cout << "\"" << str << "\" is a palindrome.\n";
        } else {
            cout << "\"" << str << "\" is not a palindrome.\n";
        }
    }

    return 0;
}*/

//4.3.

/*#include <iostream>

using namespace std;

double areaOfRectangle(double length, double width) {
  return length * width;
}

double areaOfCircle(double radius) {
  return 3.14 * radius * radius;
}

double volumeOfCylinder(double radius, double height) {
  return 3.14 * radius * radius * height;
}

int main() {
  while (true) {
    cout << "Geometry Calculator Menu:" << endl;
    cout << "1. Area of Rectangle" << endl;
    cout << "2. Area of Circle" << endl;
    cout << "3. Volume of Cylinder" << endl;
    cout << "4. Quit" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
      double length, width;
      cout << "Enter length and width: ";
      cin >> length >> width;
      cout << "Area of Rectangle: " << areaOfRectangle(length, width) << std::endl;
    } else if (choice == 2) {
      double radius;
      cout << "Enter radius: ";
      cin >> radius;
      cout << "Area of Circle: " << areaOfCircle(radius) << endl;
    } else if (choice == 3) {
      double radius, height;
      cout << "Enter radius and height: ";
      cin >> radius >> height;
      cout << "Volume of Cylinder: " << volumeOfCylinder(radius, height) << endl;
    } else if (choice == 4) {
      break;
    }
  }
  return 0;
}*/

//4.4.
/*#include <iostream>
#include <cmath>

using namespace std;

// Function to count the number of odd, even, and zero digits in a number
void countDigits(long long num, int& oddCount, int& evenCount, int& zeroCount) {
    oddCount = evenCount = zeroCount = 0;

    while (num != 0) {
        int digit = abs(num % 10); // Extract the last digit
        if (digit == 0)
            zeroCount++;
        else if (digit % 2 == 0)
            evenCount++;
        else
            oddCount++;

        num /= 10; // Move to the next digit
    }
}

int main() {
    long long number;
    cout << "Enter a number: ";
    cin >> number;

    int oddCount, evenCount, zeroCount;
    countDigits(number, oddCount, evenCount, zeroCount);

    cout << "Number of odd digits: " << oddCount << std::endl;
    cout << "Number of even digits: " << evenCount << std::endl;
    cout << "Number of zero digits: " << zeroCount << std::endl;

    return 0;
}


//Topic 5:
//5.1.
#include <iostream>

int smallestIndex(int array[], int size) {
    int smallest = array[0];
    int smallest_index = 0;
    for (int i = 1; i < size; ++i) {
        if (array[i] < smallest) {
            smallest = array[i];
            smallest_index = i;
        }
    }
    return smallest_index;
}

//5.2.
#include <iostream>

int lastLargestIndex(int array[], int size) {
    int largest = array[0];
    int largest_index = 0;
    for (int i = 1; i < size; ++i) {
        if (array[i] >= largest) {
            largest = array[i];
            largest_index = i;
        }
    }
    return largest_index;
}


//5.3.
#include <iostream>
#include <string>

using namespace std;

const int NUM_CANDIDATES = 5;

void electionResults(string names[], int votes[]) {
    int total_votes = 0;

    // Calculate total votes
    for (int i = 0; i < NUM_CANDIDATES; ++i) {
        total_votes += votes[i];
    }

    // Output results
    cout << "Candidate Votes Received % of Total Votes" << endl;
    for (int i = 0; i < NUM_CANDIDATES; ++i) {
        double percentage = (static_cast<double>(votes[i]) / total_votes) * 100;
        cout << names[i] << " " << votes[i] << " " << percentage << endl;
    }

    // Determine winner
    int winner_index = lastLargestIndex(votes, NUM_CANDIDATES);
    cout << "The Winner of the Election is " << names[winner_index] << "." << endl;
}

int main() {
    string candidate_names[NUM_CANDIDATES];
    int votes_received[NUM_CANDIDATES];

    // Input candidate names and votes received
    for (int i = 0; i < NUM_CANDIDATES; ++i) {
        cout << "Enter candidate " << i+1 << " name: ";
        cin >> candidate_names[i];
        cout << "Enter votes received by candidate " << i+1 << ": ";
        cin >> votes_received[i];
    }

    // Call function to display results
    electionResults(candidate_names, votes_received);

    return 0;
}

#include <iostream>

const int MONTHS = 12;
const int DATA_POINTS = 2;

void getData(int temperatures[][DATA_POINTS]) {
    for (int i = 0; i < MONTHS; ++i) {
        std::cout << "Enter high temperature for month " << i+1 << ": ";
        std::cin >> temperatures[i][0];
        std::cout << "Enter low temperature for month " << i+1 << ": ";
        std::cin >> temperatures[i][1];
    }
}

double averageHigh(int temperatures[][DATA_POINTS]) {
    double sum = 0;
    for (int i = 0; i < MONTHS; ++i) {
        sum += temperatures[i][0];
    }
    return sum / MONTHS;
}

int indexHighTemp(int temperatures[][DATA_POINTS]) {
    int highest_index = 0;
    for (int i = 1; i < MONTHS; ++i) {
        if (temperatures[i][0] > temperatures[highest_index][0]) {
            highest_index = i;
        }
    }
    return highest_index;
}

int indexLowTemp(int temperatures[][DATA_POINTS]) {
    int lowest_index = 0;
    for (int i = 1; i < MONTHS; ++i) {
        if (temperatures[i][1] < temperatures[lowest_index][1]) {
            lowest_index = i;
        }
    }
    return lowest_index;
}*/


//Topic 6:
/*#include <iostream>
#include <iomanip>

using namespace std;
class counterType{
private:
    int count;
public:
    void setCount(int count){
    cin>>count;
    }
    int getCount(){
        if(setCount(count)<0){
            return setCount(0);
        }
        else{
            setCount++;
        }
    }
};
int main(){
counterType counting;
counting.setCount;
counting.getCount;
return 0;
}*/
/*//correction 6.1:
#include <iostream>
using namespace std;

class counterType {
private:
    int counter;

public:
    void setCounter(int value) {
        if (value >= 0) {
            counter = value;
        }
    }

    void initializeCounter() {
        counter = 0;
    }

    int getCounter() const {
        return counter;
    }

    void incrementCounter() {
        counter++;
    }

    void decrementCounter() {
        if (counter > 0) {
            counter--;
        }
    }
};

int main() {
    int x;
    counterType counter;
    cout << "Enter a value for x: ";
    cin >> x;
    counter.setCounter(x);
    // Initializing counter to 0 after setting it to the input value
    counter.initializeCounter();
    // Incrementing and then decrementing the counter
    counter.incrementCounter();
    counter.decrementCounter();
    // Retrieving and displaying the current value of the counter
    cout << "Current counter value: " << counter.getCounter() << endl;
    return 0;
}*/

/*#include <iostream>
using namespace std;

class swimmingPool {
private:
    float length, width, depth;
    float fillRate, drainRate; // in gallons per minute

public:
    // Constructor to initialize instance variables
    swimmingPool(float l, float w, float d, float fillR, float drainR)
        : length(l), width(w), depth(d), fillRate(fillR), drainRate(drainR) {}

    // Method to calculate the volume of the pool in gallons
    float volume() const {
        return length * width * depth * 7.48;
    }

    // Method to calculate the amount of water needed to fill the pool
    float waterNeeded(float currentVolume) const {
        return volume() - currentVolume;
    }

    // Method to calculate the time to fill the pool
    float timeToFill(float currentVolume) const {
        return waterNeeded(currentVolume) / fillRate;
    }

    // Method to calculate the time to drain the pool
    float timeToDrain(float currentVolume) const {
        return currentVolume / drainRate;
    }

    // Method to add water for a specific amount of time
    float addWater(float time) const {
        return time * fillRate;
    }

    // Method to drain water for a specific amount of time
    float drainWater(float time) const {
        return time * drainRate;
    }
};

int main() {
    // Example usage
    swimmingPool pool(30, 15, 6, 10, 5); // length, width, depth, fillRate, drainRate

    float currentVolume = 1000; // current water volume in gallons

    cout << "Total volume of the pool: " << pool.volume() << " gallons" << endl;
    cout << "Water needed to fill the pool: " << pool.waterNeeded(currentVolume) << " gallons" << endl;
    cout << "Time to fill the pool: " << pool.timeToFill(currentVolume) << " minutes" << endl;
    cout << "Time to drain the pool: " << pool.timeToDrain(currentVolume) << " minutes" << endl;
    cout << "Water added in 30 minutes: " << pool.addWater(30) << " gallons" << endl;
    cout << "Water drained in 30 minutes: " << pool.drainWater(30) << " gallons" << endl;

    return 0;
}*/

/*#include <iostream>
#include <string>
using namespace std;

class bankAccount {
private:
    string holderName;
    int accountNumber;
    string accountType;
    double balance;
    double interestRate;
    static int nextAccountNumber;

public:
    // Constructor
    bankAccount(string name, string type, double bal, double rate)
        : holderName(name), accountType(type), balance(bal), interestRate(rate) {
        accountNumber = nextAccountNumber++;
    }

    // Method to get account details
    string getAccountDetails() const {
        return "Account Number: " + to_string(accountNumber) + "\n" +
               "Holder Name: " + holderName + "\n" +
               "Account Type: " + accountType + "\n" +
               "Balance: " + to_string(balance) + "\n" +
               "Interest Rate: " + to_string(interestRate * 100) + "%\n";
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        }
    }

    // Method to add interest
    void addInterest() {
        balance += balance * interestRate;
    }

    // Static method to get the next account number (optional)
    static int getNextAccountNumber() {
        return nextAccountNumber;
    }
};

// Initialize static member variable
int bankAccount::nextAccountNumber = 1000;

int main() {
    const int MAX_ACCOUNTS = 10;
    bankAccount accounts[MAX_ACCOUNTS] = {
        {"John Doe", "Checking", 1000.0, 0.01},
        {"Jane Smith", "Saving", 1500.0, 0.02},
        {"Alice Johnson", "Checking", 2000.0, 0.01},
        {"Robert Brown", "Saving", 2500.0, 0.02},
        {"Emily Davis", "Checking", 3000.0, 0.01},
        {"Michael Wilson", "Saving", 3500.0, 0.02},
        {"Sarah Miller", "Checking", 4000.0, 0.01},
        {"David Moore", "Saving", 4500.0, 0.02},
        {"Laura Taylor", "Checking", 5000.0, 0.01},
        {"James Anderson", "Saving", 5500.0, 0.02}
    };

    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        cout << accounts[i].getAccountDetails() << endl;
        accounts[i].deposit(500.0); // Example deposit
        accounts[i].withdraw(200.0); // Example withdrawal
        accounts[i].addInterest(); // Add interest
        cout << "Updated Account Details:\n" << accounts[i].getAccountDetails() << endl;
    }

    return 0;
}*/

/*#include <iostream>
#include <random>

using namespace std;

int main() {
    // Seed with a real random value, if available
    random_device rd;

    // Initialize the random number generator with the seed
    mt19937 gen(rd());

    // Define the range for the random numbers (10 to 100)
    uniform_real_distribution<> dis(10.0, 100.0);

    // Generate and print 25 random real numbers
    for (int i = 0; i < 25; ++i) {
        double random_number = dis(gen);
        cout << random_number << endl;
    }

    return 0;
}*/











