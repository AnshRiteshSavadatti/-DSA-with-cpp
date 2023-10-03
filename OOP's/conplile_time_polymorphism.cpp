#include<iostream>
using namespace std;

// if i want to do function overloading we need to change parameters ie add or remove parameters
class A{
    public:
    void hello(){
        cout << "Hello Ansh" << endl;
    }

    void hello(string n){
        cout << "Hello " << n << endl;
    }
};

int main(){
    A a;
    a.hello("ansh"); 
    a.hello();
    return 0;
}