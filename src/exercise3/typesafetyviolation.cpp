/*  Russel Makani
    B00164413
    exercise 3 
    Type-safety violation
*/

#include <iostream>

using namespace std;

int main(){
    int a = 20000 ;
    char c = a;
    int b = c;

    if(a != b){
        cout << "Oops!:" << a << "!=" << b << "\n\n";
    }
    else{
        cout <<"Wow! We have large characters\n\n";
    }

 // This section prints the values of a , b ,c
    cout << "a: " << a <<"\n"
         << "b: " << b <<"\n"
         << "c: " << c <<"\n";

    return 0 ; 
}