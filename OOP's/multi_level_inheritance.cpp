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
    public : 
    void sleep(){
        cout << "Male sleeping " << endl;
    }
};

class Boy : public Male{

};
int main(){
    Boy object1;
    cout << object1.name << endl;
    object1.sleep() ;
    return 0;
}