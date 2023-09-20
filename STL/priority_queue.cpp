#include<iostream>
#include<queue>
using namespace std;

int main(){
    // push
    // size
    // pop
    // top
    // empty
    // almost all the functions are long(n)
    // max heap
    priority_queue<int>maxi;  // stores in decending order
    // decending heap

    // min heap
    priority_queue<int , vector<int>, greater<int>> mini;   // miminum priority queue
    for(int i=0; i < 5; i++)    // stores in ascending  order
        maxi.push(i);
    cout <<" The size of max heap is " <<  maxi.size() << endl;
    int n = maxi.size();
    for(int i =0 ; i<n; i++){
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;
    for(int i=0; i<5; i++)
        mini.push(i);
    n = mini.size();
    for(int i=0; i<n; i++){
        cout << mini.top() << " ";
        mini.pop();
    }

    cout << "Khali hai kya bhai ?? " << mini.empty() << endl;
}