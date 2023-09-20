#include<iostream>
using namespace std;

int main(){
    int n = 10;

    // address operator   ampersand sign (&), known as theaddress-of operator.
    //    dereference operator (*).
    int* nptr = &n;
    cout << "The value is " << *nptr << endl;
    cout << "The address is " << nptr << endl;
    
    // size of a pointer of any type is 8 bytes

    // int *ptr = NULL;
    // cout << *ptr << endl;  // sometimes it showes segmentation fault some times the code stops


    
    return 0;
}