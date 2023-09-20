#include<iostream>
using namespace std;

inline int getmax(int& a, int& b){
    return (a>b) ? a : b;
}

int main(){
    int a;
    int b;
    cout << "Enter the value of a and b "<<endl;
    cin >> a >> b;
    int max = getmax(a,b);
    cout <<"The maximum aint "<< a << " and " << b << " is " <<  max << endl;
    return 0;
}