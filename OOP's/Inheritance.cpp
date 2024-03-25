#include<iostream>
using namespace std;

class Human{
    public :
    int weight;
    int height;
    string name;
    
    Human():weight(100){}

    void sleep(){
        cout << "Human sleeping" << endl;
        return;
    }
};

class Male : public Human{
    public : 
    string clour;
    
    void sleep(){
        cout << "Male sleeping " << endl;
        return;
    }
};

class Female : public Human{
    public:
    float height;

    void sleep(){
        cout << "Female sleeping" << endl;
        return;
    }
    
};

int main(){
    Male object1;
    cout << object1.weight << endl;
    object1.sleep() ;

    Female object2;
    cout << object2.weight << endl;
    object2.sleep();
    return 0;
}