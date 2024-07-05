/*
    The Template Method pattern is a behavioral design pattern that defines the skeleton of an 
    algorithm in a method, deferring some steps to subclasses. It allows subclasses to redefine 
    certain steps of the algorithm without changing its structure. This pattern promotes code reuse 
    and ensures that the overall algorithm remains consistent across subclasses.


    Key Components of the Template Method Pattern

    Abstract Base Class: 
        This is a class that declares the template method and defines abstract methods or hooks that 
        the template method relies on. The abstract methods are implemented by subclasses.

    Concrete Subclasses: 
        These are subclasses that implement the abstract methods defined in the abstract base class. 
        They provide concrete implementations for the steps of the algorithm

    When to Use the Template Method Pattern?

    When you want to define the overall structure of an algorithm but allow subclasses to provide 
    specific implementations for certain steps.
    When you have multiple classes that share common behavior but have variations in certain steps 
    of the algorithm.
    When you want to avoid code duplication and enforce consistency in the algorithm across subclasses.


*/

#include <iostream>

class Beverage {
public:
    void prepareBeverage() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

    virtual void brew() = 0;  // Abstract method
    virtual void addCondiments() = 0;  // Abstract method

    void boilWater() {
        std::cout << "Boiling water" << std::endl;
    }

    void pourInCup() {
        std::cout << "Pouring into cup" << std::endl;
    }
};

class Tea : public Beverage {
public:
    void brew() override {
        std::cout << "Steeping the tea" << std::endl;
    }

    void addCondiments() override {
        std::cout << "Adding lemon" << std::endl;
    }
};

class Coffee : public Beverage {
public:
    void brew() override {
        std::cout << "Dripping coffee through filter" << std::endl;
    }

    void addCondiments() override {
        std::cout << "Adding sugar and milk" << std::endl;
    }
};

int main() {
    Beverage* tea = new Tea();
    Beverage* coffee = new Coffee();

    std::cout << "Making tea..." << std::endl;
    tea->prepareBeverage();

    std::cout << "\nMaking coffee..." << std::endl;
    coffee->prepareBeverage();

    delete tea;
    delete coffee;

    return 0;
}


/*
    Explanation
    Abstract Base Class (Beverage): 
        Defines the template method prepareBeverage() that orchestrates the preparation process. 
        It also provides common methods like boilWater() and pourInCup().
        
    Concrete Subclasses (Tea and Coffee): 
        Implement the abstract methods brew() and addCondiments() specific to each beverage type.

    When prepareBeverage() is called on instances of Tea and Coffee, the steps of the preparation 
    process are executed according to the implementations provided by each subclass. The template 
    method (prepareBeverage()) ensures the overall structure of the algorithm remains consistent, 
    while the subclasses provide custom behavior for specific steps.
*/