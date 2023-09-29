#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout << "Enter sakshis name " << endl;
    cin >> s;
    reverse(s.begin(),s.end());
    cout << s << endl;
    return 0;
}