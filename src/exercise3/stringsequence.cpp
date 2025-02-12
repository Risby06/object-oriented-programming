#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
/*  This code will ask user to enter 3 words 
    Store them in strings
    add strings together
    print final string

*/

int main() {
    string name;
    string middlename;
    string lastname;
    cout << "Enter your first, middle and last names seperated by a space ";
    cin >> name >> middlename >> lastname;


   
    // Output the values in numerical sequence separated by commas
   cout << "Your full name is: ";
   cout << name << ", " << middlename << ", " << lastname << endl;

    return 0;
}
