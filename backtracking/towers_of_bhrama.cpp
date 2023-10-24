// The Towers Of BHRAMA
#include<iostream>
#include<stack>
using namespace std;

void print(stack<int>s){
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}

void solve(int n, stack<int>s1, stack<int>s3, stack<int>s2){
    if(n == 0){
        print(s3);
        return;
    }

    // moving the n-1 disks form source to auxillary via destination
    solve(n-1, s1, s2, s3);

    // moving the last disk
        int temp = s1.top();
        s1.pop();
        s3.push(temp);

    // moving the last n-1 disks from auxillary to destination via source
    solve(n-1, s2, s3, s1);
    return;
}

int main(){
    int n;
    cout << "Enter the number of plates" << endl;
    cin >> n;
    stack<int>s1;
    for(int i=n; i>=1; i--)
        s1.push(i);
    stack<int>s2;
    stack<int>s3;

    cout << "The initial state is " << endl;
    print(s1);
    print(s2);
    print(s3);
    cout << "-----" << endl;
    solve(n,s1,s3,s2);
    return 0;
}