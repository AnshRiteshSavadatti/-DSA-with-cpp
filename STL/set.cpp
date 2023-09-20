#include<iostream>
#include<set>
#include<unordered_set>

using namespace std;

int main(){
    set<int>s;
    for(int i = 0 ;i <10; i++)
        s.insert(i);
    for(auto it : s)
        cout << it << " ";
    cout <<endl;
    s.erase(s.begin()); // will erase the first element
    s.erase(6);  // ---> will delete the key if it is present
    // to erase entire set
    s.erase(s.begin(),s.end());

    cout << "The set after erase function is " << endl;
    for(auto it : s)
        cout << it << " ";
    cout << endl;
    set<int > :: iterator itr = s.begin();
    advance(itr, s.size());
    cout << "The value pointing by the iterator is " << *itr << endl;
    // cout will return 1 if element is present and 0 if element is absent
    cout << "To check if 3 is present or not " << s.count(3) << endl;
    cout << "To check if 7 is present or not " << s.count(70) << endl;

    auto it = s.find(9); // returns iterator to index of 9  // log(n)
    // if the element dosent not exists then it will point at s.end()

    s.emplace(11); // same as s.inert(11);

    // unordered set
    unordered_set<int>uns;
    multiset<int>ms;
    // multiset allows duplicate element to be stored

    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(3); // ---> { 1, 1, 2, 3}

    ms.erase(1); // --> erases all the instances of 1;
    ms.find(1);  // --> returns iterator pointing to first occurance of 1;
    

    return 0;
}