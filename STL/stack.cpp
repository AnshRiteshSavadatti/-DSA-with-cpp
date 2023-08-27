#include<iostream>
#include<stack>
#include<bits\stdc++.h>
using namespace std;

int main(){
    stack<string>s;
    s.push("Ansh");
    s.push("Savadatti");
    s.push("Sakshi");
    cout << "The top most element " << s.top() << endl;
    // for(auto it : s)
    //     cout << it << " ";
    cout << endl;
    s.pop();
    cout << "The top most element " << s.top() << endl;
    cout << "The size of stack is " <<s.size() << endl;
}