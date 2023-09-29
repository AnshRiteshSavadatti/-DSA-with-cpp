#include<iostream>
using namespace std;

// In C++, an initialization list is a way to initialize the member variables of a class or struct within the 
// constructor of that class. Initialization lists are commonly used to set the initial values of class members, 
// especially when dealing with complex types or objects that require special initialization.

// Initialization lists are typically placed after the colon : following the constructor's parameter list. Here's a
//  basic syntax of how initialization lists are used in C++ constructors:

class MyClass {
public:
    MyClass(int value1, double value2) : member1(value1), member2(value2) {
        // Constructor code
    }

private:
    int member1;
    double member2;
};

class Base {
public:
    Base(int value) : baseValue(value) {}
private:
    int baseValue;
};

class Derived : public Base {
public:
    Derived(int value1, double value2) : Base(value1), derivedValue(value2) {
        // Constructor code for Derived
    }
private:
    double derivedValue;
};
