#include<bits/stdc++.h>
using namespace std;

int XOR(int n){
    if(n % 4 == 0){
        return n;
    }else if(n % 4 == 1){  
        return 1;
    }else if(n % 4 == 2){
        return n + 1;  
    }else{
        return 0;
    }
}

int main(){
    int r,l;
    cout << "Enter the range where you want to find XOR" << endl;
    cin >> l >> r;
    int ans1 = XOR(l-1);
    int ans2 = XOR(r);
    cout << ans1 << " " << ans2 << endl;
    cout << (ans1 ^ ans2) << endl;
    return 0;
}