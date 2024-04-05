/*
     you can declare a member function as virtual without explicitly using the override keyword in C++. 
     However, using override explicitly is a good practice as it helps improve code readability and 
     makes it clear that you are overriding a virtual function from a base class.
*/

#include <iostream>

// Base class Shape
class Shape {
public:
    // Virtual function to calculate area
    virtual double calculateArea() const {
        return 0.0; // Default implementation for base class
    }
};

// Derived class Rectangle inheriting from Shape
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Override the calculateArea function
    double calculateArea() const override {
        return length * width;
    }
};

// Derived class Circle inheriting from Shape
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Override the calculateArea function
    double calculateArea() const override {
        return 3.14 * radius * radius;
    }
};

int main() {
    // Create instances of Rectangle and Circle
    Rectangle rectangle(5.0, 3.0);
    Circle circle(2.5);

    // Use the virtual function to calculate area
    std::cout << "Area of Rectangle: " << rectangle.calculateArea() << std::endl;
    std::cout << "Area of Circle: " << circle.calculateArea() << std::endl;

    return 0;
}
