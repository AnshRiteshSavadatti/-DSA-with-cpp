#include<iostream>
using namespace std;

class A{
    public:
    void abc(){
        cout << "mai A hu" << endl;
    }
};

class S{
    public:
    void abc(){
        cout << "Nannu b" << endl;
    }
};

class C : public A, public S{

};

int main(){
    C c1;
    c1.S :: abc();
    return 0;
}