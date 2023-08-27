#include<iostream>
#include<map>

using namespace std;

int main(){
    map<int,string>m;
    m[1] = "Ansh";
    m[2] = "Savadatti";
    m[3] = "ABCD";
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
    auto it = m.find(26);
    for(auto i = it; i != m.end(); i++)
        cout << (*i).second << " ";


}