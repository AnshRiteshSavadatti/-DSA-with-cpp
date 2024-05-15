/*
    In C++, catching exceptions by string is not directly supported. When you throw "Yo", you're 
    throwing a string literal, which cannot be caught directly by catch(string s).
*/

/*
    Meanings of few of the keywords used in the program

    const: 
        This indicates that the function does not modify any member variables of the class. 
        It's a const member function, meaning it can be called on const objects of the class 
        and within other const member functions.

    noexcept: 
        This is a specifier that indicates that the function does not throw any exceptions. 
        It's good practice to mark functions that don't throw exceptions with noexcept, as it 
        helps compilers optimize code and can provide information to programmers about the behavior 
        of the function.

    override: 
        This is a C++11 keyword used to explicitly specify that this function is overriding a 
        virtual function from a base class. In this case, what() is a virtual function in std::exception, 
        and override ensures that you're correctly overriding it in your derived class (MyException).

    std::exception:
        In C++, std::exception is a standard library class that serves as a base class for defining custom 
        exception types. It is defined in the <stdexcept> header and is part of the C++ Standard Library.
*/


#include <iostream>
#include <stdexcept>
using namespace std;

class MyException : public exception {
public:
    MyException(const char* msg) : message(msg) {}
    const char* what() const noexcept override {
        return message;
    }


private:
    int d;
    const char* message;
};

int main() {
    int a, b;
    cin >> a >> b;

    float d;

    try {
        if (b == 0) {
            throw 10;
        } else if (b == 1) {
            throw 'e';
        } else if (b < 0) {
            throw MyException("Dekh bhai less than 0 mat dal");
        }
    } catch (char ch) {
        cout << "Divided by one, ha !! :)" << endl;
        cout << a << endl;
        exit(0);
    } catch (const MyException& e) {
        cout << e.what() << endl;
        exit(0);
    } 

    d = a / b;
    cout << d << endl;

    return 0;
}
