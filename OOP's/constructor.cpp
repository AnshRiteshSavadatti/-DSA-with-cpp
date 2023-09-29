#include<iostream>
#include<string.h>
#include "class.cpp"
using namespace std;

class sa{
    // when we make our own constructer the default constructer made by compiler is gone  
    public:
    int health;
    char level;
    char* name;
    sa(){ // this is the constructor which we made
        cout << "Constructer called" << endl;
        name = new char[15];
    }  

    // parametarized constructor

    sa(int health){
        this->name = new char[15];
        cout << "parametarised constructor called" << endl;
        this->health = health;
    }

    sa(int health, char level){
        this->name = new char[15];
        cout << "parametarised constructor called" << endl;
        this->health = health;
        this->level = level;
    }

    sa(int health, char level,const char name[]){
        this->name = new char[15];
        cout << "parametarised constructor called" << endl;
        this->health = health;
        this->level = level;
        strcpy(this->name, name);
    }
    void setName(const char name[]){
        strcpy(this->name, name);
    }

    // copy consstructor
    //here we are passing by reference as we dont want to end up in an infinite loop
    // default copy constructor makes a shallow copy

    sa(sa& temp){
        // copy constructor called

        // to make a deep copy;
        char* ch = new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->health = temp.health;
        this->level = temp.level;
        name = new char[15];
        strcpy(this->name, ch);
    }


    void print(){
        cout << "The name is " << this->name << endl;
        cout << "The health is " << this->health << endl;
        cout << "The level is " << this->level << endl;
        }
};

int main(){
   sa sakshi(100,'A',"sakshi");
   sakshi.print();

   sa ansh(sakshi); // copy constructor deep copy in this case

   sakshi.name[0] = 'd';
   cout << endl;
   sakshi.print();
   cout << endl;

//    ansh.setName("ansh");
   ansh.print(); 
    return 0;
}

