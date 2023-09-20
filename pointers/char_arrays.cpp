#include<iostream>
using namespace std;

int main(){
    char name[20] = "ansh";
    cout << "The output of name is " << name << endl;  // will print the entire string 
cout << endl;
    int arr[10] = {1,2,3};
    cout << "The output of arr is " << arr << endl; // will print the address

    int* arrptr = &arr[0];
    char* nameptr = &name[0];

    cout << "integer " << arrptr << endl;   // prints address
    cout << "char array " << nameptr << endl; // prints name

    return 0;
}