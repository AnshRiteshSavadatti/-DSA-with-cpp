//bad allocation

/*
    std::cerr is an output stream in C++ that is used specifically for writing error messages 
    and diagnostic information to the standard error device. In most operating systems, the 
    standard error device is typically associated with the console or terminal where the program 
    is running.

    std::cerr is specifically designed for writing error messages and diagnostic information. Unlike std::cout, 
    which is the standard output stream used for general program output, std::cerr is unbuffered by default. 
    This means that the data written to std::cerr is immediately flushed to the output device, ensuring that 
    error messages are displayed promptly, even if the program crashes or exits unexpectedly.
*/


#include <iostream>
#include <new>
using namespace std;

int main(){
    try{
        int * arr = new int[10000000000000000];
    }
    catch(bad_alloc & obj){
        std :: cerr << "Bad alloc caught : " << obj.what() << endl;
    }
    return 0;
}