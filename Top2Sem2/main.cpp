/*
3.My answer:
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<float> decNum;
    decNum.size(50);
    for(int i=0; i<decNum.size(50);i++){
    cout<<"Enter a number:";
    cin>> decNum;
    cout<<decNum.push_back(decNum)<<endl;
    }

    return 0;
}*/

/* Correction
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Declare a vector that can store 50 decimal numbers
    vector<float> decNum;
    decNum.resize(50);  // Resize the vector to hold 50 elements

    // Input loop to enter numbers into the vector
    for(int i = 0; i < 50; i++) {
        float num;
        cout << "Enter a number: ";
        cin >> num;
        decNum[i] = num;  // Store the input number at index i
    }

    // Display the entered numbers
    cout << "You entered: ";
    for(int i = 0; i < 50; i++) {
        cout << decNum[i] << " ";
    }
    cout << endl;

    return 0;
}*/

/*4.
#include <iostream>
#include <vector>
using namespace std;

int main()
{
vector <char> vowels[5] = {'a','e','i','o','u',};
for(int i = 0; i<5 ; i++){
    cout<< vowels[i];
}

    cout << endl;

    return 0;
}*/

/*Correction
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Declare and initialize a vector of characters with vowel elements
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    // Loop through the vector and print each element
    for(int i = 0; i < vowels.size(); i++){
        cout << vowels[i] << " ";
    }

    cout << endl;

    return 0;
}*/

/*5.
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> iNum;
    for(int i = 0; i<5; i++){
        cout<< "Enter a number:";
        cin>>iNum;
    }
    for(i=0; i<5; i++){
        cout<<iNum<<endl;
    }
    cout << endl;

    return 0;
}*/

/*Correction
#include <iostream>
#include <vector>
#include <iterator>  // For ostream_iterator
using namespace std;

int main()
{
    vector<int> iNum;

    // Input 5 integers into the vector
    for (int i = 0; i < 5; i++) {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        iNum.push_back(num);  // Store each number in the vector
    }

    // Declare an ostream_iterator to output to the standard output (cout)
    ostream_iterator<int> screen(cout, " ");

    // Output the elements of the vector using the ostream_iterator
    copy(iNum.begin(), iNum.end(), screen);

    cout << endl;

    return 0;
}*/

/*6. generated answer
#include <iostream>
#include <vector>
#include <iterator>  // For ostream_iterator
#include <algorithm> // For copy()

using namespace std;

int main() {
    // Step 1: Initialize the vector with values
    vector<int> intVector = {5, 7, 9, 11, 13};

    // Step 2: Initialize the ostream_iterator to output to cout
    ostream_iterator<int> screen(cout, " ");  // Output to standard output (cout), with a space separator

    // Step 3: Copy the contents of the vector to the output stream using copy()
    copy(intVector.begin(), intVector.end(), screen);  // Outputs elements to cout separated by a space

    cout << endl;  // Move to the next line after output

    return 0;
}*/

/*7.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vecList(5);

for (int j = 0; j < 5; j++) vecList[j]
= 2 * j;
for (int j = 0; j < 5; j++) cout <<
vecList[j] << " ";
cout << endl;

    return 0;
}*/

/*8.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vecList = {12, 16, 8, 23, 40, 6, 18, 9, 75};

    // Copy elements in reverse from the third element from the end.
    copy(vecList.rbegin() + 3, vecList.rend(), vecList.rbegin());

    // Output the modified vector
    for (int val : vecList) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}*/

/*9.
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    deque<int> intDeq;
    ostream_iterator<int> screen(cout, " ");
    deque<int>::iterator deqIt;

    // Initial insertions into the deque
    intDeq.push_back(5);
    intDeq.push_front(23);
    intDeq.push_front(45);
    intDeq.push_back(35);
    intDeq.push_front(0);
    intDeq.push_back(50);
    intDeq.push_front(34);

    // Insert 76 at the beginning
    deqIt = intDeq.begin();
    intDeq.insert(deqIt, 76);

    // Remove the last element (50)
    intDeq.pop_back();

    // Remove the 3rd element (0)
    deqIt = intDeq.begin();
    ++deqIt;
    ++deqIt;
    intDeq.erase(deqIt);

    // Insert twice the last element (35 * 2 = 70) at the front
    intDeq.push_front(2 * intDeq.back());

    // Insert three times the first element (70 * 3 = 210) at the back
    intDeq.push_back(3 * intDeq.front());

    // Output the deque using copy
    copy(intDeq.begin(), intDeq.end(), screen);
    cout << endl;

    return 0;
}

*/

/*10.
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    int list[5] = {2, 4, 6, 8, 10};
    vector<int> vecList(7); // Initialize a vector of size 7.

    // Copy the array elements into the vector.
    copy(list, list + 5, vecList.begin());

    // Push the value 12 to the vector.
    vecList.push_back(12);

    // Output the vector contents using copy and ostream_iterator.
    ostream_iterator<int> screen(cout, " ");
    copy(vecList.begin(), vecList.end(), screen);
    cout << endl;

    return 0;
}
*/

/*11.
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    vector<double> sales(3);

    // Assigning initial values
    sales[0] = 50.00;
    sales[1] = 75.00;
    sales[2] = 100.00;

    // Resizing the vector to hold 5 elements
    sales.resize(5);

    // Assign values to the new elements
    sales[3] = 200.00;
    sales[4] = 95.00;

    // Output the sales vector using copy and ostream_iterator
    ostream_iterator<double> screen(cout, " ");
    copy(sales.begin(), sales.end(), screen);
    cout << endl;

    return 0;
}
*/

/*
12.
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    vector<int> intVector;
    vector<int>::iterator vecIt;

    // Pushing elements into the vector
    intVector.push_back(15);
    intVector.push_back(2);
    intVector.push_back(10);
    intVector.push_back(7);

    // Move the iterator to the second element and erase it (2)
    vecIt = intVector.begin();
    vecIt++;
    intVector.erase(vecIt);

    // Remove the last element (7)
    intVector.pop_back();

    // Output the vector using copy
    ostream_iterator<int> screen(cout, " ");
    copy(intVector.begin(), intVector.end(), screen);
    cout << endl;

    return 0;
}

*/

/*
13.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vecList = {12, 16, 8, 23, 40, 6, 18, 9, 75};

    // Copying elements from vecList starting at index 2 to the end,
    // and placing them starting from the beginning of vecList
    copy(vecList.begin() + 2, vecList.end(), vecList.begin());

    // Output the modified vecList
    for (int val : vecList) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

*/

/*
14.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vecList = {12, 16, 8, 23, 40, 6, 18, 9, 75};

    // Copying elements from the reverse beginning + 3, i.e., starting from 18
    // and overwriting starting from the reverse beginning of vecList
    copy(vecList.rbegin() + 3, vecList.rend(), vecList.rbegin());

    // Output the modified vecList
    for (int val : vecList) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

*/

/*
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    deque<int> intDeq;
    ostream_iterator<int> screen(cout, " ");
    deque<int>::iterator deqIt;

    // Initial insertions into the deque
    intDeq.push_back(5);
    intDeq.push_front(23);
    intDeq.push_front(45);
    intDeq.push_back(35);
    intDeq.push_front(0);
    intDeq.push_back(50);
    intDeq.push_front(34);

    // Insert 76 at the beginning
    deqIt = intDeq.begin();
    intDeq.insert(deqIt, 76);

    // Remove the last element (50)
    intDeq.pop_back();

    // Move the iterator to the third element and erase it
    deqIt = intDeq.begin();
    advance(deqIt, 2);
    intDeq.erase(deqIt);

    // Push twice the last element at the front
    intDeq.push_front(2 * intDeq.back());

    // Push three times the first element at the back
    intDeq.push_back(3 * intDeq.front());

    // Output the deque using copy and ostream_iterator
    copy(intDeq.begin(), intDeq.end(), screen);
    cout << endl;

    return 0;
}

*/

/*15.
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    deque<int> intDeq;
    ostream_iterator<int> screen(cout, " ");
    deque<int>::iterator deqIt;

    // Initial insertions into the deque
    intDeq.push_back(5);
    intDeq.push_front(23);
    intDeq.push_front(45);
    intDeq.push_back(35);
    intDeq.push_front(0);
    intDeq.push_back(50);
    intDeq.push_front(34);

    // Insert 76 at the beginning
    deqIt = intDeq.begin();
    intDeq.insert(deqIt, 76);

    // Remove the last element (50)
    intDeq.pop_back();

    // Move the iterator to the third element and erase it
    deqIt = intDeq.begin();
    advance(deqIt, 2);
    intDeq.erase(deqIt);

    // Push twice the last element at the front
    intDeq.push_front(2 * intDeq.back());

    // Push three times the first element at the back
    intDeq.push_back(3 * intDeq.front());

    // Output the deque using copy and ostream_iterator
    copy(intDeq.begin(), intDeq.end(), screen);
    cout << endl;

    return 0;
}

*/





