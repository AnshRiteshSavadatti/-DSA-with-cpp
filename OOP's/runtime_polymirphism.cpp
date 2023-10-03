#include<iostream>
using namespace std;

class Human{
    public:
    void speak(){
        cout << "Hello " << endl;
    }
};

class Dog: public Human{
    public:
    void speak(){
        cout << "Bow bow" << endl;
    }
};

class Cat: public Human{
    public:
    void speak(){
        cout << "mew mew" << endl;
    }
};

int main(){
    Dog d1;
    d1.speak();
    Cat c1;
    c1.speak();
    Human h1;
    h1.speak();
    return 0;
}