#include <iostream>
#include <array>
using namespace std;

array<int, 4> a; // ---> { 0,0,0,0} if you declare outside int main initialized by zero
  // 10^7 is the maximum size of array which can be declared globally  for bool it is 10^8

int main(){
  // 10^6 is the maximum size of array which can be declared in int main for bool it is 10^7
     int basic[5] = {1,2,3,4,5};
     array<int,4>arr = {1,2,3,4};
     int size = arr.size();

     array<int , 10> ansh;
     ansh.fill(10); // {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}

     cout << "The element index 2 is " << arr.at(2) << endl;
     cout << "The starting element is " << arr.front() << endl;
     cout << "The element at end is " << arr.back() << endl;
     cout << "Empty or not " << arr.empty() << endl;

     // iterators 
     array< int, 5> s = {1,2,3,4,5};
     for(auto it = s.begin(); it != s.end(); it++)
          cout << *it << " ";
     cout << endl;
     for(auto it = s.rbegin(); it != s.rend(); it++)
          cout << *it << " ";
     cout << endl;



}