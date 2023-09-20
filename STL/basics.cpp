#include<bits/stdc++.h>
using namespace std;

namespace ansh{
    int val = 50;
    int getVal(){
        return 100 * val;
    }
}

struct node{
    int i;
    string s;
    double d;
    float f;
    node(int i_, string s_, double d_, float f_){
        i = i_;
        s = s_;
        d = d_;
        f = f_;
    }
};

int main(){
    cout << ansh :: val << endl;
    cout << ansh :: getVal() << endl;
    // node s;
    // // wrong way of declaring
    // s.d = 14;
    // s.f = 14;
    // s.i = 14;
    // s.s = "forteen" ;

    node *s = new node(14, "s", 2004, 12);
    node a = node(24, "a", 2004, 03);


    return 0;
}