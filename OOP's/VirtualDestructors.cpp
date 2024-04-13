

/*
    Virtual destructors are used in C++ when you have a base class with virtual functions and you expect 
    to delete derived class objects through a pointer to the base class. 

    Here's why you need a virtual destructor:

    1. Proper Cleanup:
            When you delete an object through a pointer to its base class, but the object is of a 
            derived class, having a virtual destructor ensures that the destructor of the most derived 
            class is called. This is crucial for proper cleanup, especially if the derived class has 
            allocated resources that need to be deallocated.

    2. Avoid Memory Leaks:
            Without a virtual destructor, if you delete an object through a base class pointer and that 
            object is actually of a derived class, only the base class destructor would be called. This 
            can lead to memory leaks if the derived class has dynamically allocated memory that 
            isn't freed.

    3. Polymorphic Behavior:
        Virtual destructors are part of polymorphism in C++. They enable dynamic binding, ensuring that 
        the correct destructor is called based on the actual type of the object.

*/

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor called." << endl;
    }

    virtual ~Base() {
        cout << "Base destructor called." << endl;
    }

    virtual void display() {
        cout << "Displaying from Base class." << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor called." << endl;
    }

    ~Derived() override {
        cout << "Derived destructor called." << endl;
    }

    void display() override {
        cout << "Displaying from Derived class." << endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    basePtr->display();  // Calls the overridden display() in Derived

    delete basePtr;  // Calls the destructor of Derived and then Base

    return 0;
}

