#include<bits\stdc++.h>
using namespace std;

int main(){
    int n ;
    cout<<"Enter the value of n\n";
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j = 0; j<n-i-1; j++)
            cout<<" ";
        for(int j=0; j<=i;j++)
            cout<<"*";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++)
            cout<<" ";
        for(int j=0; j<n-i; j++)
            cout<<"*";
        cout<<endl;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++)
            cout<<" ";
        for(int j=0; j<=i; j++)
            cout<<1+j;
        for(int j=0; j<i; j++)
            cout<<i-j;
        cout<<endl;
    }
cout<<endl;
    for(int i=0; i<n; i++){
        for(int j =0; j<n-i; j++)
            cout<<j+1;
        for(int j=0; j<i;j++)
            cout<<"**";
        for(int j=0; j<n-i;j++)
            cout<<n-j-i;
        cout<<endl;
    }
    return 0;
}