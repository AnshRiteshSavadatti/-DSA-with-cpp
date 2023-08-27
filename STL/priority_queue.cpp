#include<iostream>
#include<queue>
using namespace std;

int main(){
    // max heap
    priority_queue<int>maxi;
    // decending heap

    // min heap
    priority_queue<int , vector<int>, greater<int>> mini;
    for(int i=0; i < 5; i++)
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