#include<iostream>
#include<set>

using namespace std;

int main(){
    set<int>s;
    for(int i=0 ;i<5; i++)
        s.insert(i);
    for(auto it : s)
        cout << it << " ";
    cout <<endl;
    s.erase(s.begin());
    cout << "The set after erase function is " << endl;
    for(auto it : s)
        cout << it << " ";
    cout << endl;
    set<int > :: iterator itr;
    advance(itr, s.size());
    cout << "The value pointing by the iterator is " << *itr << endl;
    cout << "To check if 3 is present or not " << s.count(3) << endl;
    cout << "To check if 7 is present or not " << s.count(7) << endl;
    cout << "hi" << endl;
    return 0;
}