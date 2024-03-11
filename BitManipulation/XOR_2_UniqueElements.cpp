#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,1,2,4,5,6,8,9};
    int n = 18-2;
    int XOR = 0;
    for(int i=0; i<n; i++){
        XOR ^= arr[i];
    }
    int cnt = 0;
    int temp = XOR;
    while (temp){
        if(temp & 1){
            break;
        }
        cnt++;
        temp = temp >> 1;
    }
    int mask = 1 << cnt;
    int XOR1 = 0, XOR2 = 0;
    for(int i=0; i<n; i++){
        if(mask & arr[i]){
            XOR1 ^= arr[i];
        }else{
            XOR2 ^= arr[i];
        }
    }
    cout << XOR1 << " " << XOR2 << endl;
    return 0;
}