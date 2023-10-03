#include<iostream>
using namespace std;

class Human{
    public :
    int weight;
    int height;
    string name;
};

class Male : public Human{
    public : 
    string clour;
    
    void sleep(){
        cout << "Male sleeping " << endl;
    }
};

int main(){
    Male object1;
    cout << object1.weight << endl;
    object1.sleep() ;
    return 0;
}