/* Russel Makani
B00164413
*/

#include <iostream>
#include <iomanip>


using namespace std ;

class negative_currency{ };

float from_euro(float value, string currency);
float to_euro(float value, string currency);

int main(){
float value;
string currency;
string from;
float conversion;
    cout << "please enter the currency you would like to convert to: "<< endl;
    cin >> from ;
    cout << "Please enter the value followed by the currency you would like to convert from: "<< endl;
    cin >> value >> currency;

if (from == "euro")  {
       conversion = to_euro(value, currency);
        cout << value <<" "<< currency << " "<< "is equivalent to " << conversion << " euros\n";
}
else{
    conversion = from_euro(value, currency);

    cout << value <<" euros is equivalent to " << conversion << " "<< currency << endl;
}
    return 0;
}

// Function to convert from euro to selected currency
float from_euro(float value, string currency){
  float conversion;
    if ((currency == "usd")||(currency == "USD")){
        conversion = value*1.05 ;
       
    }
        else if((currency == "cny")||(currency == "CNY")){
            conversion = value*7.59 ;

        }
        else if((currency == "jpy")||(currency == "JPY")){
            conversion = value*156.28 ;

        }
        else if((currency == "stg")||(currency == "STG")){
            conversion = value*0.83 ;
        }
        else{
            cerr << "\nInvalid input\n";
        }

        // this will throw int negativive currency class if the currency is negative
        if (conversion < 0){
            throw negative_currency();
    }
    return conversion;
}
// Function to convert from selected currency to euro
float to_euro(float value, string currency){
    float conversion;
    if ((currency == "usd")||(currency == "USD")){
        conversion = value/1.05 ;
       
    }
        else if((currency == "cny")||(currency == "CNY")){
            conversion = value/7.59 ;

        }
        else if((currency == "jpy")||(currency == "JPY")){
            conversion = value/156.28 ;

        }
        else if((currency == "stg")||(currency == "STG")){
            conversion = value/0.83 ;
        }
        else{
            cerr << "\nInvalid input\n";
        }

        if (conversion < 0){
            throw negative_currency();
    }
    return conversion;
}