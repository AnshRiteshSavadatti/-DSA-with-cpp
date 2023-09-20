#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    map<int,string>m;
    m[1] = "Ansh";
    m[2] = "Savadatti";
    m[3] = "ABCD";
    m[3] = "three"; // this will over write ABCD;
    m.insert({26,"sakshi"});
    m.insert({100, "century"});
    cout << "before erase " << endl;
    for(auto it : m){
        cout << it.first << " ";
        cout << it.second << endl;
    }
    cout<< " finding 26 -->" << m.count(26)<< endl;
    m.erase(3);
    for(auto it : m){
        cout << it.first << " ";
        cout<< it.second<< endl;
        }
    auto it = m.find(26); // find returnes the iterator

    for(auto i = it; i != m.end(); i++)
        cout << i->first << " ";
    m.erase(m.begin()); // here we give iterator
    m.clear(); // here the entire map is cleared

    //  to check if map is empty
    if(m.empty())
        cout << "yes" << endl;
    else    
        cout << "no" << endl;
        
    unordered_map<int, int> um;
    // same as map
    // o(1) in all the cases
    // o(n) in worse case where n is size of cointainer
    // not sorted but unique keys


    multimap <string, int> mm;
    mm.emplace("ansh", 1);
    mm.emplace("ansh", 2);
    mm.emplace("ansh", 3);
    // can store multiple value for keys
    // sorted but not unique keys
    




}