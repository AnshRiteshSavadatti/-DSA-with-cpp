#include<iostream>
using namespace std;

class A{
    public:
    int a;
    int b;
    void operator+ (A &a){
        cout << "output "<< this->a - a.a << endl;
    }

    void operator()(){
        cout << "Hi I am Ansh" << endl;
    }
};

int main(){
    A a,b;
    a.a = 100;
    b.a = 10;
    a+b;
    a();
    return 0;
}