#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>vec;
    cout<<"The size of vector is " << vec.size() <<endl;
    cout << "The capacity of vector is " << vec.capacity() << endl;

    vec.push_back(1);
    cout<<"The size of vector is " << vec.size() <<endl;
    cout << "The capacity of vector is " << vec.capacity() << endl;

    vec.push_back(2);
    cout<<"The size of vector is " << vec.size() <<endl;
    cout << "The capacity of vector is " << vec.capacity() << endl;

    vec.push_back(3);
    cout<<"The size of vector is " << vec.size() <<endl;
    cout << "The capacity of vector is " << vec.capacity() << endl;

    cout <<"The last element "<<vec.front() << endl;
    cout << "The element on third index is " << vec.at(2) << endl;

    for(auto it : vec){
        cout << it << " ";
    }
    cout <<endl;
    vec.pop_back();
    for(auto it : vec)
        cout << it << " ";

    vector<int>a(5,1);
    for(auto it : a)
        cout<< it << " ";
    cout << endl;
    
    vector<int>b(a);
    for(auto it: b)
        cout << it << " ";
}