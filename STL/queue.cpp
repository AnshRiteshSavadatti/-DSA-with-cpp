#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int>q;

    // push
    // front
    // pop
    // size
    // empty
    // all are o(1) only empting is o(n) as we dont have function as clear in queue ans stack
    q.push(1);
    q.push(2);
    for(int i = 3; i< 5; i++)
        q.push(i);
    cout << "The first element " << q.front() << endl;
    cout << "size " << q.size() << endl;
    q.pop();
    cout << "Size after pop " << q.size() << endl; 
    while(!q.empty()) // top empty the queue as we dont have a specific function 
        q.pop();


}