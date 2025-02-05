/*  Russel Makani
    B00164413
    exercise 3 
    constant modifier code
*/
#include <iostream>

using namespace std ;

// inch to cm and cm to inch conversion:
// keep reading as long as the user inputs an int and a char ok
// 'i' for inch
// 'c' for cm
// terminate on a “bad unit”, e.g. 'q'
int main()
{
const double cm_per_inch = 2.54;
int val;
char unit;
cm_per_inch *= 2.0
while (cin >> val >> unit) {
if (unit == 'i') {
cout << val << "in == " << val*cm_per_inch << "cm\n";
} 
    else if (unit == 'c') {
cout << val << "cm == " << val/cm_per_inch << "in\n";
} else {
   return 0;
   }
  }
}

