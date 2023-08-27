#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    for(int i = 3; i< 5; i++)
        q.push(i);
    cout << "The first element " << q.front() << endl;
    cout << "size " << q.size() << endl;
    q.pop();
    cout << "Size after pop " << q.size() << endl; 


}