#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number " << endl;
    cin >> n;
    int a = 1, b = 1 , c = 1;
    for(int i = 2; i*i<= n; i++){
        if(n % i == 0){
            a = i;
            break;
        }
    }
    int p = n/a;
    for(int i=2; i*i<=n; i++){
        if(n % i == 0 && i != a){
            b = i;
            break;
        }
    }
    c = n/(a*b);
    cout << a <<" " <<  b << " " <<  c << endl;
    return 0; 
}