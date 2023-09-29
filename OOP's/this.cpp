#include<iostream>
using namespace std;

class Hero{
    private :
    int health;

    public : 
    char level;
    
    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int health){
        cout << "The address of this is " << this << endl;
        this->health = health;
    }

    void setLevel(char level){
        this->level = level;
    }
};



int main(){
    Hero h;
    h.setHealth(100);
    h.setLevel('A');
    cout << "The address of h is " << &h << endl; 

    cout << "The health is " << h.getHealth() << endl;
    cout << "The level is " << h.getLevel() << endl;

    return 0;
}