#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> class A{
    public:
    T1 a;
    T2 b;

    A(T1 a, T2 b){
        this ->a = a;
        this ->b = b;
    }

    void print(){
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        return;
    }
};

template <typename T1> void print(T1 &obj){
    obj.print();
    return;
}

int main(){
    A <int, int>obj1(10, 20);
    A <string, string>obj2 ("Ansh", "Savadatti");
    A <string, int>obj3("Hello", 100);

    print(obj1);
    obj1.print();
    obj2.print();
    obj3.print();

    return 0;
}