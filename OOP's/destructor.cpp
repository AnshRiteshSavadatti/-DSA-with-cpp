#include<iostream>
using namespace std;


// Using the const Keyword:
// You can use the const keyword to declare a constant value. Once a variable is declared as const,
//  its value cannot be modified after initialization.
class Hero{
    public :
    int health;
    char level;
    
    // manual constrictor
    Hero(){
        cout << "constructor called" << endl;
    }
    ~Hero(){
        cout << "destructor called bhai" << endl;
    }
};

int main(){
    Hero a;  // destructor is automatically called for statically initialized objects

    Hero* s = new Hero;
    delete s;  // we have to manually create destructor for dynamically allocated objects

    return 0;
}