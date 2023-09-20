#include<iostream>
#include<vector>
using namespace std;
 
 // the size of vectors is same as arrays globally as well as in int main

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
     
    vec.pop_back(); // removes last element
    for(auto it : vec)
        cout << it << " ";

    vector<int>a(5,1);  // --> {1,1,1,1,1}
    for(auto it : a)
        cout<< it << " ";
    cout << endl;
    
    // making copy of a
    vector<int>b(a);
    for(auto it: b)
        cout << it << " ";

    vec.clear();   // erases all the elements

    vector<int> v(4,0); // ---> {0, 0, 0, 0}

     // making copy of v
     vector<int> vec1(v);
     vector<int> vec2(v.begin(), v.end());  // ---> ( ]

     // vec.push_back(10) is same as vec.emplace_back(10) -- > emplace_back takes less space


     // 2D vectors
    for(int i = 10; i <= 100; i += 10){
        vec.push_back(i);
    }
     vector<vector<int>> sak;
     sak.push_back(vec);
     sak.push_back(a);
     sak.push_back(b);
     sak.pop_back();


    cout << endl << " Printing the 2d vector " << endl;
     for(auto it : sak){
        for(auto i : it)
            cout << i << " ";
        cout << endl;
     }

    for(int i = 0; i < sak.size(); i++){
        for(int j = 0; j < sak[i].size(); j++)
            cout << sak[i][j];
        cout << endl;
    }

    vector<vector<int>> vec3(10,vector<int>(10,100));
    for(int i = 0; i < vec3.size(); i++){
        for(int j = 0; j < vec3[i].size(); j++)
            cout << vec3[i][j] << " ";
        cout << endl;
    }

    return 0;
}