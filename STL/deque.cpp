#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int>d;
    // push_front()
    // push_ back();
    // pop_front();
    // pop_back();
    // begin, end, rbegin, rend;
    // size
    // clear
    // empty
    // at
     
    d.push_back(1);
    d.push_front(0);
    d.push_back(2);
    d.push_front(100);
    for(auto it: d)
        cout << it << " ";
    cout <<endl;
    d.pop_back();
    d.pop_front();
    for(auto it : d)
        cout << it << " ";
    cout << endl;
    cout << "First element " << d.at(0) << endl;
    cout << "first " << d.front() << endl;
    cout << "last " << d.back() << endl;
    d.erase(d.begin() , d.begin() + 1);
    for(auto it : d)
        cout << it << " ";
    // erase function makes size 0 but not capacity

}