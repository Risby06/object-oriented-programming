#include <iostream>
#include <algorithm>

using namespace std;
/*  This code will ask user to enter 3 integers
    Store the as variables
    store them in an array
    sort array
    print sorted array

*/

int main() {
    int a, b, c;

    cout << "Enter three integer values: ";
    cin >> a >> b >> c;

    // Store the values in an array
    int values[] = {a, b, c};

    // Sort the array
    sort(values, values + 3);      // reference from geeks for geeks https://www.geeksforgeeks.org/sort-c-stl/#sort-array-in-ascending-order

    // Output the values in numerical sequence separated by commas
   cout << "The values in numerical sequence are: ";
   cout << values[0] << ", " << values[1] << ", " << values[2] << std::endl;

    return 0;
}
