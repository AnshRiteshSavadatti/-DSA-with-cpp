#include <iostream>
#include <array>
using namespace std;

int main(){
     int basic[5] = {1,2,3,4,5};
     array<int,4>arr = {1,2,3,4};
     int size = arr.size();

     cout << "The element index 2 is " << arr.at(2) << endl;
     cout << "The starting element is " << arr.front() << endl;
     cout << "The element at end is " << arr.back() << endl;
     cout << "Empty or not " << arr.empty() << endl;
}