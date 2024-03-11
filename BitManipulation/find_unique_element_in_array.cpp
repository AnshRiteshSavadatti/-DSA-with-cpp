#include<bits/stdc++.h>
using namespace std;

int UniqueNum(int * arr, int n){
    int XOR = 0;
    for(int i=0; i<n; i++){
        XOR ^= i[arr];
    }
    return XOR;
}

int main(){
    int arr[] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,14};
    int n = 19;
    cout << "The unique number is " << UniqueNum(arr,n) << endl;
    return 0;
}