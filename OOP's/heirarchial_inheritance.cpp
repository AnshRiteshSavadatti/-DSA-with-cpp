#include<iostream>
using namespace std;

class Animal{
    public:
    int weight;
};

class Dog : public Animal{
    public:
    void bark(){
        cout << "Bark" << endl;
    }
};

class Cat : public Animal{
    public:
    void meow(){
        cout << "meow" << endl;
    }
};

int main(){
    Cat c1;
    c1.meow();
    return 0;
}