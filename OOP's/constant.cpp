#include<iostream>

class MyClass {
public:
    MyClass(int value) : data(value) {}

    void printData() const {
        std::cout << data << std::endl;
    }

private:
    int data;
};


// Using the const Keyword:
// You can use the const keyword to declare a constant value. Once a variable is declared as const,
//  its value cannot be modified after initialization.

int main() {
    const MyClass obj(42);  // Creating a constant object
    obj.printData();  // Calling a const member function

    // You cannot modify the object's state, e.g., obj.data = 10; // This would result in a compilation error

    return 0;
}
