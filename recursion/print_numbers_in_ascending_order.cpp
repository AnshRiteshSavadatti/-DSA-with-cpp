#include<iostream>
using namespace std;

void ascending(int n){
    if(n == -1)
        return;
    cout << n << " ";
    ascending(n-1);
    return;
}

void decending(int d){
    if(d == -1)
        return;
    decending(d-1);
    cout << d << " " ;
    return;
}

int main(){
    int n;
    cout << "Enter the number which has to be printed n ascending order " << endl;
    cin >> n;
    ascending(n);

    int d;
    cout << endl << "Enter the numbe which is to be printed in decending order " << endl;
    cin >> d;
    decending(d);
    return 0;
}