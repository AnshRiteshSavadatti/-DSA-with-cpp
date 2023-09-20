#include<iostream>
using namespace std;

int main(){
    int i = 14;
    int& j = i;  // creation a referenc variable
    cout << "the value of i is -->" << i << endl;
    cout << "the value of j is -->" << j << endl;
    i++;j++;
    cout << "the value of i is -->" << i << endl;
    cout << "the value of j is -->" << j << endl;

    return 0;
}