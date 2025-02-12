/*  Russel Makani
    B00164413
    Exercise 3
    Tiny Calculator programm
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    char operation;
    float valA , valB;

    cout << "\nEnter the operation you would like to use ";
    cin >> operation ;
    cout << "\n Enter the two values seperated by a space ";
    cin >> valA >> valB ;
 
    switch(operation){
        case '+':
            cout << valA + valB ;
            break;
        case '-':
            cout << valA - valB ;
            break;
        case '*':
            cout << valA * valB ;
            break;
        case '/':
            cout << valA * valB ;
            break;

        default :
            cout << "\n Invalid Operation" ;
            break;
    }
    return 0;
}