/*
    In this example, the Shape class is an abstract class because it contains a pure 
    virtual function area(). Pure virtual functions are declared with "= 0" and have 
    no implementation in the base class. Derived classes like Rectangle and Circle 
    must override the pure virtual function area() to provide their own implementation.
*/

#include <iostream>
using namespace std;

/*      Abstract class Shape : Abstract class is a class whose object cant be created 
        because of pure virtual funcions
*/
class Shape {
public:
    // Pure virtual function to calculate area
    virtual float area() const = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

// Concrete class Rectangle, derived from Shape
class Rectangle : public Shape {
private:
    float length;
    float width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}

    // Implementation of area for Rectangle
    float area() const override {
        return length * width;
    }
};

// Concrete class Circle, derived from Shape
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : radius(r) {}

    // Implementation of area for Circle
    float area() const override {
        return 3.14f * radius * radius;
    }
};

int main() {
    // Shape* pointers can hold instances of derived classes
    Shape* shape1 = new Rectangle(5, 3);
    Shape* shape2 = new Circle(4);

    // Calling area() will invoke the appropriate derived class method
    cout << "Area of Rectangle: " << shape1->area() << endl;
    cout << "Area of Circle: " << shape2->area() << endl;

    delete shape1;
    delete shape2;

    return 0;
}
