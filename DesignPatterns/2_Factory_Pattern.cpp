/*
    In Factory pattern, we create object without exposing the creation logic to the client and 
    refer to newly created object using a common interface.

    The idea is to use a static/non-static member-function (static factory method) which creates 
    & returns instances, hiding the details of class modules from user.

    The Factory Method pattern is a design pattern used to define a runtime interface for creating 
    an object. It’s called a factory because it creates various types of objects without necessarily 
    knowing what kind of object it creates or how to create it.

    The Factory design pattern is a creational pattern that provides a way to create objects without 
    specifying the exact class of object that will be created. Instead of directly instantiating 
    objects, you call a factory method, which returns an instance of the appropriate class.

    Key Concepts of the Factory Pattern

    1.Factory Method: This is a method in a class that is responsible for creating objects.

    2.Product: This is the interface or abstract class that defines the type of objects the factory 
    method will create.

    3.Concrete Products: These are the concrete classes that implement the Product interface.

    When to Use the Factory Pattern?
    
    1.When you need to decouple the client code from the object creation code.
    2.When the exact types of objects to be created are determined at runtime.
    3.When a class cannot anticipate the class of objects it must create.
    4.When you want to provide a library of objects that needs to be created in a standard way.

*/

#include <iostream>

class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};

class ShapeFactory {
public:
    enum ShapeType {
        CIRCLE,
        RECTANGLE
    };

    Shape* createShape(ShapeType type) {
        switch (type) {
            case CIRCLE:
                return new Circle();
            case RECTANGLE:
                return new Rectangle();
            default:
                return nullptr;
        }
    }
};

int main() {
    ShapeFactory factory;

    // Create a Circle
    Shape* shape1 = factory.createShape(ShapeFactory::CIRCLE);
    shape1->draw();  // Output: Drawing a Circle
    delete shape1;

    // Create a Rectangle
    Shape* shape2 = factory.createShape(ShapeFactory::RECTANGLE);
    shape2->draw();  // Output: Drawing a Rectangle
    delete shape2;

    return 0;
}


/*
    Explanation

    Product Interface (Shape): 
    Defines a common interface for all shapes, ensuring that they all have a draw method.

    Concrete Products (Circle and Rectangle): 
        Implement the Shape interface and provide specific behavior for the draw method.

    Factory Class (ShapeFactory): 
        Contains a method createShape that takes an enum value ShapeType and returns a pointer 
        to a Shape object. This method uses a switch statement to decide which type of shape to 
        create.

    Client Code: 
        Uses the ShapeFactory to create instances of Circle and Rectangle without knowing the 
        exact classes that are being instantiated.



    
    Benefits of the Factory Pattern

    Decoupling: 
        The client code is decoupled from the concrete classes it needs to instantiate.

    Flexibility: 
        New types of products can be added without modifying the client code.

    Single Responsibility:
        The factory handles the responsibility of creating objects, adhering to the Single Responsibility 
        Principle.

By using the Factory pattern, you can make your code more modular, flexible, and easier to maintain.

*/