#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "The the number till where you need XOR operation" << endl;
    cout << "For Example" << endl;
    cout << "1^2^3^4 = 0" << endl << "If 4 is Input 0 must be output" << endl;  
    cin >> n;
    if(n % 4 == 0){
        cout << n << endl;
    }else if(n % 4 == 1){
        cout << 1 << endl;
    }else if(n % 4 == 2){
        cout << n+1 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}