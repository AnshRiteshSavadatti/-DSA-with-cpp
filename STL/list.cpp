#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int>l;
     // push_front()
    // push_ back();
    // pop_front();
    // pop_back();
    // begin, end, rbegin, rend;
    // size
    // clear
    // empty
    // at
    // remove o(1);
    l.push_back(1);
    l.push_front(0);
    l.push_back(2);
    l.remove(2);
    cout << "The size is "<< l.size() << endl;
    for(auto it : l){
        cout << it << " ";
    }
    cout << endl;
    l.erase(l.begin());
    cout<< "After erase "<<endl;
    for(auto it : l)
        cout << it << " ";
    l.push_back(3);
    l.pop_back();
    l.pop_front();
    cout << endl;
    for(auto it : l)
        cout << it << " ";
    cout << endl;
    list<int> n(5,100);
    for(auto it : n)
        cout << it << " ";
    cout << endl;


}