/*
    A call to typeid(*a) is made. This operation is used to get type information at runtime. 
    However, since a is pointing to nullptr and is dereferenced (*a), it leads to undefined 
    behavior and typically results in a bad_typeid exception.

    std::cerr is specifically designed for writing error messages and diagnostic information. 
    Unlike std::cout, which is the standard output stream used for general program output, std::cerr 
    is unbuffered by default. This means that the data written to std::cerr is immediately flushed 
    to the output device, ensuring that error messages are displayed promptly, even if the program 
    crashes or exits unexpectedly.
    
*/

#include <iostream> // std::cerr
#include <typeinfo> // operator typeid
#include <exception> // std::exception
using namespace std;


class A{virtual void member(){}};

int main(){
    A * a = nullptr;

    try{
        typeid(*a);
    }
    catch(exception& a){
        cerr << "Error --> " << a.what() << endl;
    }
    return 0;
}
