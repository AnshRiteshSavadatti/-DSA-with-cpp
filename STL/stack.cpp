#include<iostream>
#include<stack>
#include<bits\stdc++.h>
using namespace std;

int main(){
    stack<string>s; // lifo
    // pop
    // top
    // size
    // empty
    // push
    s.push("Ansh");
    s.push("Savadatti");
    s.push("Sakshi");
    cout << "The top most element " << s.top() << endl;
    // for(auto it : s)
    //     cout << it << " ";
    cout << endl;
    s.pop();
    bool flag = s.empty(); // returns 1 if stack is empty and 0 if stack is not empty
    while(!s.empty()){ // to empty the stack
        s.pop();
    }
    cout << "The top most element " << s.top() << endl;
    cout << "The size of stack is " <<s.size() << endl;
}