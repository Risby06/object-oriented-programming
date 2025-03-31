/*Russel Makani
  B00164413
  */
#include <iostream>
#include <iomanip>

using namespace std;

class negative_currency{ };

float from_euro(float value, string currency);
float to_euro(float value, string currency);

int main() {
    float value, euro_value;
    string currency;
    float largest = -1000000.0; // A very small initial value
    float smallest = 1000000.0; // A very large initial value

    while (1) {
        cout << "Enter value (or 0 to exit): ";
        cin >> value;
        if (value == 0) break;

        cout << "Enter currency (usd, cny, jpy, stg): ";
        cin >> currency;

        euro_value = to_euro(value, currency);
        
        cout << fixed << setprecision(2);          /// prints to 2 decimal places
        cout << "Value in euros: " << euro_value << endl;

        // if the new input value is larger than previous largest value, it becomes the new largest
        if (euro_value > largest) {
            largest = euro_value;
        }

        // if the new input value is smaller than previous smallest value, it becomes new smallest
        if (euro_value < smallest) {
            smallest = euro_value;
        }

        cout << "Current largest value in euros: " << largest << endl;
        cout << "Current smallest value in euros: " << smallest << endl;
    }

    cout << "Final largest value in euros: " << largest << endl;
    cout << "Final smallest value in euros: " << smallest << endl;

    return 0;
}

float from_euro(float value, string currency) {
    float conversion;
    if ((currency == "usd") || (currency == "USD")) {
        conversion = value * 1.05;
    }
    else if ((currency == "cny") || (currency == "CNY")) {
        conversion = value * 7.59;
    }
    else if ((currency == "jpy") || (currency == "JPY")) {
        conversion = value * 156.28;
    }
    else if ((currency == "stg") || (currency == "STG")) {
        conversion = value * 0.83;
    }
    else {
        cerr << "\nInvalid input\n";
    }
    if (conversion < 0){
        throw negative_currency();
}
    return conversion;
}

float to_euro(float value, string currency) {
    float conversion;
    if ((currency == "usd") || (currency == "USD")) {
        conversion = value / 1.05;
    }
    else if ((currency == "cny") || (currency == "CNY")) {
        conversion = value / 7.59;
    }
    else if ((currency == "jpy") || (currency == "JPY")) {
        conversion = value / 156.28;
    }
    else if ((currency == "stg") || (currency == "STG")) {
        conversion = value / 0.83;
    }
    else {
        cout << "\nInvalid input\n";
    }

    if (conversion < 0){
            throw negative_currency();
           
    }
    return conversion;
}
