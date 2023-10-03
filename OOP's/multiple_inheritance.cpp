#include<iostream>
using namespace std;

class Animal{
    public:
    int weight;
};

class Dog{
    public:
    void bark(){
        cout << "Bark" << endl;
    }
};

class Germanshepard : public Dog , public Animal{
    
};

int main(){
    Germanshepard d1;
    d1.bark();
    return 0;
}