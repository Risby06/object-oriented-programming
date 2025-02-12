/*  Russel Makani
    B00164413
    Exercise 3
    two ints programm
*/

#include <iostream>
using namespace std;

/*  This programm will ask the user to enter two floats
    store the floats as variables
    find the smaller and lager number
    find the difference 
    find the product
    find the ratio
    print them on screeeen
*/
float valA , valB ;

void sort();
void sum();
void diff();
void product();
void ratio();
int main(){
    
    cout << "\nEnter the first Value: ";
    cin >> valA ;
    cout << "\nEnter 2nd value: ";
    cin >> valB;

    sort();
    sum();
    diff();
    product();
    ratio();

    return 0;
}

void sort(){
    if (valA > valB){
        cout << "\n" << valA <<"Is the greater than " << valB;
    }
    else{
        cout << "\nThe values are equal\n";
    }
    
}

void sum(){
    cout << "\nThe sum is " << valA + valB;
   
}

void diff(){
    cout << "\nThe difference is " << valA - valB;
   
}

void product(){
    cout << "\nThe product is " << valA * valB;
  
}
void ratio(){
    cout << "\nThe ratio is " << valA/valB;
  
}