#include<bits\stdc++.h>
using namespace std;

int main(){
    unsigned int i;
    // unsigned int only stores the positive value of int increases the range
    i = 100;
    cout<<i<<endl;
    char a = 123456;
    cout<<a<<endl;
    int x = 12345;
    float y = (float)x;
    cout<<y<<endl;
    cout<<sizeof((double)x)<<endl;
    int A;
    A = cin.get();
    cout<<A<<endl;
    int arr[15];
    fill_n(arr,15,1); // fills the entire array with value 1
    for(int i=0; i<15; i++)
        cout<< arr[i] << " ";
    cout << endl;
    cout << sizeof(arr) << endl;
    cout << sizeof(arr) / sizeof(int) << endl;
    
    return 0;
}