// Hybride inheritance is inheritance of any two types 
// here we will combine hirercial and multilevel inheritance

#include<iostream>
using namespace std;

class NetWorth{
    public:
    int networth;
};

class Animal{
    public:
    int weight;
};

class Dog: public Animal{
    public:
    void bark(){
        cout << "bow bow" << endl;
    }
};

class Human: public Animal, public NetWorth{
    public:
    void speak(){
        cout << "Namaste" << endl;
    }
};

int main(){
    Human h1;
    h1.speak();
    cout << h1.networth << endl;
    return 0;
}