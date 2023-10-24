#include<iostream>
#include<time.h>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

void fun(){
    cout << "EVIL LAUGH" << endl;
    int d;
    while(1){
        if(cin >> d){
            break;
        }
    }
    cout << " fun ends" << endl;
    return;
}

int main(){
    clock_t s, e;
    s = clock();
    fun();
    e = clock();
    double d = e - s;
    cout << d/1000 << endl;
    return 0;
}