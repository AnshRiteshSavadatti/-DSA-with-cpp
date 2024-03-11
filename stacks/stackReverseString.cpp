#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<char>s;
    string str;
    str = "Ansh Savadatti";

    for(int i=0; i<str.size(); i++){
        s.push(str[i]);
    }

    string ans = "";
    while(!s.empty()){
        char ch = s.top();
        s.pop();
        ans.push_back(ch);
    }
    cout << "The name is " << str << " The reversed name is " << ans << endl;

    return 0;
}