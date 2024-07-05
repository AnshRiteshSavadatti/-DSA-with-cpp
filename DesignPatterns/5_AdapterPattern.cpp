/*
    The Adapter pattern is a structural design pattern that allows objects with incompatible 
    interfaces to work together. It acts as a bridge between two incompatible interfaces by 
    providing a wrapper class that implements the expected interface and delegates the calls 
    to the actual implementation.

    Key Components of the Adapter Pattern
    Target Interface: 
        This is the interface that the client expects to interact with. It defines the operations 
        that the client code uses.

    Adaptee: 
        This is the class that has the functionality that the client code needs but doesn't match 
        the target interface.

    Adapter: 
        This is the class that implements the target interface and wraps around the adaptee, 
        translating the calls from the target interface to the adaptee's interface.
*/

class Shape {
public:
    virtual void draw() = 0;
    virtual void resize() = 0;
};

#include <iostream>

class Rectangle {
public:
    void drawRectangle() {
        std::cout << "Drawing a rectangle" << std::endl;
    }

    void resizeRectangle() {
        std::cout << "Resizing the rectangle" << std::endl;
    }
};

class RectangleAdapter : public Shape {
private:
    Rectangle rectangle;

public:
    void draw() override {
        rectangle.drawRectangle();
    }

    void resize() override {
        rectangle.resizeRectangle();
    }
};

int main() {
    Shape* shape = new RectangleAdapter();

    shape->draw();    // Calls drawRectangle() in RectangleAdapter
    shape->resize();  // Calls resizeRectangle() in RectangleAdapter

    delete shape;

    return 0;
}


/*
    Explanation
    Target Interface (Shape): 
        Defines the operations that the client code expects to interact with, such as draw() and resize().
    Adaptee (Rectangle): 
        Represents the existing class with incompatible interfaces (drawRectangle() and resizeRectangle()
    Adapter (RectangleAdapter): 
        Implements the target interface (Shape) and internally uses the adaptee (Rectangle) to perform 
        the required operations.
    
    When draw() or resize() is called on the RectangleAdapter, the adapter internally delegates the 
    calls to the corresponding methods in the Rectangle class, making it possible to use the legacy 
    functionality through the new Shape interface.


*/