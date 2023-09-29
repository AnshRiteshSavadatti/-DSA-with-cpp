#include <iostream>
using namespace std;


// the size of empty class is 1 byte the storage is given to track the class
// by default the access modifiers of class is private


// padding 
// Structure padding is defined as the process of adding one or more empty bytes between the different data types
//  to align data in memory. Structure padding increases memory consumption but is reduces CPU cycles. Structure 
// contains structure members which can be accessed by a processor in chunks of 4 bytes at a time.


class Hero{
    // properties
    private : // -- > access modifiers 
    int health;
    public :
    char level;

    void print(){
        cout << level << endl;
    }

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setLevel(char l){
        level = l;
    }
};

int main(){
    Hero h;
    cout << sizeof(h) << endl;
    
    h.setHealth(100);
    h.setLevel('A') ;
    cout << "The health is " << h.getHealth() << endl;
    cout << "The level is " << h.getLevel()<< endl;


    //   dynamic memory allocation
    Hero* ptr = new Hero;
    ptr->setHealth(1000);
    cout << "The health of second doctor is " << ptr->getHealth() << endl;
    return 0;
}