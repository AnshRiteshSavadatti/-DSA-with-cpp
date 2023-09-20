// macros  ----> a piece of code in progroam which is replaced by value of macros
//    https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/

////A macro is a piece of code in a program that is replaced by the value of the macro. 
//Macro is defined by #define directive. Whenever a macro name is encountered by the compiler, it replaces the name with the 
//definition of the macro. Macro definitions need not be terminated by a semi-colon(;).
//

#include<iostream>
using namespace std;
#define pi 3.14
#define area(l,b) (l*b)
#define ansh 1,2,3,4,5

int main(){
    cout << pi << endl;
    cout << area(3,4) << endl;
    int arr[] = {ansh};
    for(int i=0; i<5; i++)
        cout << arr[i] << " ";
    cout << endl; 

    return 0;
}