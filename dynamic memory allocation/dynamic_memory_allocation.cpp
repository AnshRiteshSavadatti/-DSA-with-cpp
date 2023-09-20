#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    // dynamic memory allocation
    int* ptr = new int[n];

    for(int i = 0; i<n; i++){
        cin >> i[ptr];
    }

    for(int i =0; i<n; i++)
        cout << i[ptr] << " ";
    cout << endl;
    delete []ptr;
    
    return 0;
}