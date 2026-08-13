#include <iostream>
using namespace std;

int main() {
    // Step 1: Prompt the user to enter the population and growth rate of town A.
    cout<<"Enter the population of Town A:";
    int populationA;
    cin >> populationA;
    cout << "Enter the growth rate of town A (in percentage): ";
    float growthRateA;
    cin >> growthRateA;

    // Step 2: Prompt the user to enter the population and growth rate of town B.
    cout << "Enter the population of town B: ";
    int populationB;
    cin >> populationB;
    cout << "Enter the growth rate of town B (in percentage): ";
    float growthRateB;
    cin >> growthRateB;

    // Step 3: Initialize variables for populations and growth rates of towns A and B.
    int years = 0;

    // Step 4: Use a loop to calculate the population of each town for each year until town A's population exceeds or equals town B's population.
    while (populationA < populationB) {
        populationA = populationA * (1 + growthRateA / 100);
        populationB = populationB * (1 + growthRateB / 100);
        years++;

        if(populationA==populationB){
            cout<<"The number of years are:"<<years;
        }


    }

    // Step 5: Output the number of years it took for town A's population to exceed or equal town B's population.
    cout << "After " << years << " years," << endl;

    // Step 6: Output the populations of town A and town B at that time.
    cout << "Population of town A: " << populationA << endl;
    cout << "Population of town B: " << populationB << endl;

    return 0;
}
