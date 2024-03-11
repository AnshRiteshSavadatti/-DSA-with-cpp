#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int n ;
    cout << "Enter the value of n" << endl;
    cin >> n ;
    for(int i=0; i <= (1 << n)-1; i++){
        for(int d = 0; d <= n-1; d++){
            if(i & (1 << d)){
                cout << a[d] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}