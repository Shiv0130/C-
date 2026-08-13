/*#include <iostream>
using namespace std;

int main()
{
    int i;
    int j;
    int temp;

    int arr[8] = {12,3,1,5,18,10,7,35};
    cout << "Unsorted array" << endl;

    for(int i = 0; i<8;i++){
        cout<< arr[i]<<"\t";
    }
    cout << endl;

    for(int i = 0; i<8; i++)
        {
        for(int j =i+1;j<8;j++)
        {
         if(arr[j]<arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<< "Sorted element:"<<endl;
    for(int i =0; i<8; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    return 0;
}*/

// Insertion sort
/*#include <iostream>
using namespace std;

int main()
{
    int i;          // Loop control variable
    int j;          // Inner loop control variable
    int num;        // Variable to store the number of elements
    int temp;       // Temporary variable used for swapping
    int arr[30];    // Array to hold up to 30 elements

    // Prompt user to enter the number of elements in the array
    cout << "Enter the number of elements of the array: ";
    cin >> num;

    // Prompt user to enter the elements of the array
    cout << "Enter the elements: ";
    for (int i = 0; i < num; i++) {
        cin >> arr[i]; // Read each element into the array
    }

    // Insertion sort algorithm
    for (int i = 1; i < num; i++) { // Start from the second element
        temp = arr[i]; // Store the current element in a temporary variable
        j = i - 1;     // Set j to the previous element's index

        // Shift elements of arr[0..i-1], that are greater than temp,
        // to one position ahead of their current position
        while ((j >= 0) && (arr[j] > temp)) {
            arr[j + 1] = arr[j]; // Move element one position ahead
            j = j - 1;           // Move to the previous element
        }
        arr[j + 1] = temp; // Insert temp in the correct position
    }

    // Output the sorted array
    cout << "Sorted elements: ";
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " "; // Display each element
    }
    cout << endl; // New line after the sorted array output

    system("pause>0"); // Pause the console (for Windows users)
    return 0;
}*/

// Selection sort
/*#include <iostream>
using namespace std;

int main()
{
    int i, j;         // Loop control variables
    int temp;         // Temporary variable used for swapping
    int num;          // Variable to store the number of elements
    int minIndex;     // Variable to store the index of the minimum element
    int arr[10];      // Array to hold up to 10 elements

    // Prompt the user to enter the number of elements in the array
    cout << "Enter the number of elements: ";
    cin >> num;

    // Prompt the user to enter the elements of the array
    cout << "Enter the elements:" << endl;
    for (i = 0; i < num; i++) {
        cin >> arr[i];  // Read each element into the array
    }

    // Selection sort algorithm
    for (i = 0; i < num - 1; i++) {  // Outer loop to iterate over each element
        minIndex = i;                // Assume the minimum element is at the current index

        // Inner loop to find the index of the minimum element in the unsorted portion
        for (j = i + 1; j < num; j++) {
            if (arr[j] < arr[minIndex]) {  // If a smaller element is found
                minIndex = j;              // Update minIndex to the new minimum
            }
        }

        // Swap the found minimum element with the element at index i
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Output the sorted array
    cout << "Sorted elements are:" << endl;
    for (i = 0; i < num; i++) {
        cout << arr[i] << " ";  // Display each element
    }
    cout << endl;

    return 0;
}*/

#include <iostream>
using namespace std;

// Function to partition the array and return the pivot index
int divide(int arr[], int start, int end) {
    int pivot = arr[end];  // Choose the last element as the pivot
    int index = start;      // Initialize index to start

    // Loop to partition the array based on the pivot
    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {  // Change '>' to '<' for ascending sort
            int temp = arr[i];
            arr[i] = arr[index];  // Fix 'arr[j]' to 'arr[i]'
            arr[index] = temp;
            index++;
        }
    }

    // Place the pivot in its correct position
    int temp = arr[end];
    arr[end] = arr[index];  // Corrected from 'arr[i]' to 'arr[end]'
    arr[index] = temp;

    return index;  // Return pivot index after partitioning
}

// Quick sort function
void Quick(int arr[], int start, int end) {  // Fix 'Void' to 'void'
    if (start < end) {
        int d = divide(arr, start, end);      // Partition the array
        Quick(arr, start, d - 1);             // Recursively sort left part
        Quick(arr, d + 1, end);               // Recursively sort right part
    }
}

int main() {
    int num;
    int arr[10];

    cout << "Enter the number of elements:" << endl;
    cin >> num;

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    Quick(arr, 0, num - 1);  // Call Quick sort on entire array

    cout << "After sorting, elements are:" << endl;
    for (int i = 0; i < num; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;

    return 0;
}

